#include <stdio.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

#include <pthread.h>

char *socket_path = "/home/dimercur/armada.sock";
#define SOCKETLISTENER_BUFFER_SIZE 65535

struct sockaddr_un addr;
int fd,rc;

char buf[SOCKETLISTENER_BUFFER_SIZE];
int socketlistener_messagelength=0;

typedef void (*SocketListener_EventCallback)(void);
SocketListener_EventCallback pSocketListenerCallback=NULL;
pthread_t listenerthread_handler;
void *socket_listenerthread (void *args);

typedef void (*Timer_EventCallback)(void);
Timer_EventCallback pTimerCallback=NULL;
pthread_t timerthread_handler;
void *timer_thread (void *args);

int socket_init (void) {
  if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    return -1;
  }

  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;
  if (*socket_path == '\0') {
    *addr.sun_path = '\0';
    strncpy(addr.sun_path+1, socket_path+1, sizeof(addr.sun_path)-2);
  } else {
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
  }

  if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    return -2;
  }

  /* int flags = fcntl(fd, F_GETFL, 0);      */
  /* fcntl(fd, F_SETFL, flags | O_NONBLOCK); */

  return 0;
}

int socket_write (char *msg, int len) {
  if (write(fd, msg, len) != len) {
    if (len > 0)
      return len;
    else {
      return -3;
    }
  }

  return 0;
}

int socket_close (void) {
  if (close (fd) == -1)
    return -4;

  return 0;
}

int socket_read (char *msg, int len) {
  int rc;

  rc = read(fd, msg, len);
  if (rc == -1) rc = 0;
  if (rc < 0) rc = -5;

  return rc;
}

int socket_getlistenermessage(char *msg, int len) {
  strncpy(msg, buf, len);
  memset(buf, 0,SOCKETLISTENER_BUFFER_SIZE);

  return socketlistener_messagelength;
}

void socket_setcallback(SocketListener_EventCallback ptr) {
  pSocketListenerCallback= ptr;
}

void socket_clearcallback(void) {
  pSocketListenerCallback= NULL;
}

int socket_startthread(void) {
  int status = 0;

  if (pthread_create (&listenerthread_handler, NULL, socket_listenerthread, "1") < 0) {
    status=-5;
  }

  return status;
}

int socket_stopthread(void) {
  int status = 0;

  if (pthread_cancel (listenerthread_handler) != 0) {
    status=-6;
  }

  return status;
}

void timer_setcallback(Timer_EventCallback ptr) {
  pTimerCallback= ptr;
}

void timer_clearcallback(void) {
  pTimerCallback= NULL;
}

int timer_startthread(void) {
  int status = 0;

  if (pthread_create (&timerthread_handler, NULL, timer_thread, "1") < 0) {
    status=-5;
  }

  return status;
}

int timer_stopthread(void) {
  int status = 0;

  if (pthread_cancel (timerthread_handler) != 0) {
    status=-6;
  }

  return status;
}

void *socket_listenerthread (void *args) {
  //int rc;

  while (1) {

    socketlistener_messagelength = read(fd, buf, SOCKETLISTENER_BUFFER_SIZE);

    pthread_testcancel (); // stop thread if a cancel event has been sent

    if (socketlistener_messagelength == -1) {
      // Pas de message
      socketlistener_messagelength=0;
    }
    else if (socketlistener_messagelength>0) {
      if (pSocketListenerCallback!=NULL)
        pSocketListenerCallback();
    }
    else pthread_exit (0);

    socketlistener_messagelength=0;
  }
}

void *timer_thread (void *args) {
  while (1) {
    sleep (1);
    if (pTimerCallback!=NULL) pTimerCallback();

    pthread_testcancel (); // stop thread if a cancel event has been sent
  }

  pthread_exit (0);
}

