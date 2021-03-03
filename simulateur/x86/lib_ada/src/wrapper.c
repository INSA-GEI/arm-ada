#include <stdio.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>

//char *socket_path = "./socket";
char *socket_path = "/home/dimercur/armada.sock";

struct sockaddr_un addr;
char buf[100];
int fd,rc;

int socket_init (void) {
  if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    // perror("socket error");
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
    // perror("connect error");
    return -2;
  }

  int flags = fcntl(fd, F_GETFL, 0);
  fcntl(fd, F_SETFL, flags | O_NONBLOCK);

  return 0;
}

int socket_write (char *msg, int len) {
  if (write(fd, msg, len) != len) {
    if (len > 0) fprintf(stderr,"partial write");
    else {
      // perror("write error");
      return -3;
    }
  }

  return 0;
}

int socket_close (void) {
  if (close (fd) == -1)
    // perror ("close error");
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

void test(void) {
  printf ("Hello\n");
}
