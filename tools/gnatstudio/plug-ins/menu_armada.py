"""Run Python Script

This plug-in executes a python script.
"""

###########################################################################
# No user customization below this line
###########################################################################

import os

import GPS
import subprocess
import time

#from gs_utils import interactive
import gs_utils

SOLUTION_FILE_NAME = "solution.elf"

def get_gdb_server_pid():
    stream = os.popen("ps -ef | grep ST-LINK_gdbserver\ -c | grep -v grep | grep -v /bin | awk '{print $2}'")
    pid = stream.read()
    
    if pid == '':
        return -1
    else:
        return int(pid)


def get_arm_eabi_gdb_pid():
    stream = os.popen("ps -ef | grep arm-eabi-gdb | grep -v grep | grep -v defunct | awk '{print $2}'")
    pid = stream.read()
    GPS.Console("Messages").write("Debugger PID: " + pid)

    if pid == '':
        return -1
    else:
        return int(pid)


def kill_gdb_server(pid):
    if pid != -1:
        GPS.Console("Messages").write("Kill running GDB server\n")
        stream = os.popen("kill " + str(pid))
        GPS.Console("Messages").write(stream.read() + "\n")
        time.sleep(0.5)


def kill_arm_eabi_gdb_server(pid):
    if pid != -1:
        GPS.Console("Messages").write("Kill running debugger server\n")
        stream = os.popen("kill " + str(pid))
        GPS.Console("Messages").write(stream.read() + "\n")
        time.sleep(0.5)


def spawn_gdb_server():
    GPS.Console("Messages").write("Spawn gdbserver\n")
    #info = subprocess.Popen(["/home_pers/dimercur/.gnatstudio/ST-LINK_gdbserver.sh"],shell=True)
    info = subprocess.Popen("./ST-LINK_gdbserver -c ./config.txt",cwd="/mnt/commetud/2eme Annee IMACS/ADA/tools/bin/",shell=True)
    time.sleep(1)

def download_program(name):
    GPS.Console("Messages").write("File to program: " + name + "\n")

    # For downloading only program, GDB server must not be running
    gdb_pid = get_gdb_server_pid()
    if gdb_pid != -1:
        kill_gdb_server(gdb_pid)

    # Now programming
    stream = os.popen("/usr/local/insa/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD -d " +
                      name + " -hardRst")
    GPS.Console("Messages").write(stream.read() + "\n")


#@interactive("Editor", menu="/ArmAda/Download Only")
def Download_Only():
    project_name = GPS.Project.root().name()
    executable_dir = GPS.Project(project_name).exec_dir()
    main_file = GPS.Project(project_name).get_attribute_as_string("Main")
    executable_path = GPS.File(main_file).executable_path
    executable_name = executable_path.name()

    download_program (executable_name)


#@interactive("Editor", menu="/ArmAda/Download Solution")
def Download_Solution():
    project_name = GPS.Project.root().name()
    executable_dir = GPS.Project(project_name).exec_dir()
    
    download_program (executable_dir + SOLUTION_FILE_NAME)
    #GPS.Console("Messages").write("Solution:"+ executable_dir + SOLUTION_FILE_NAME +"\n")


#@interactive("Editor", menu="/ArmAda/Download and Debug")
def Download_And_Debug():
    if (get_gdb_server_pid() == -1):
        #print("GDB server not running")
        spawn_gdb_server()

    if (get_gdb_server_pid() != -1):
        GPS.Action("Debug on Board Number 1").execute_if_possible()


#@interactive("Editor", menu="/ArmAda/Remove GDB server")
#def Kill_GdbServer():
#    gdb_pid = get_gdb_server_pid()
#    if gdb_pid != -1:
#        kill_gdb_server(gdb_pid)

#@interactive("Editor", menu="/ArmAda/Remove GDB server")
#def Kill_Debugger():
#    debugger_pid = get_arm_eabi_gdb_pid()
#    if debugger_pid != -1:
#        kill_arm_eabi_gdb_server(debugger_pid)


#def init():
GPS.Console("Messages").write("Load: armada menu\n")
gs_utils.make_interactive(callback=Download_Only,icon="insa-download-only",name='Download Only',description="Download project to console",toolbar='main',menu="ArmAda/Download only",before="Help")
gs_utils.make_interactive(callback=Download_And_Debug,icon="insa-download-debug",name='Download and Debug',description="Download then debug project on console",toolbar='main',menu="ArmAda/Download and debug",before="Help")
gs_utils.make_interactive(callback=Download_Solution,icon="insa-question",name='Download Solution',description="Download solution to console",toolbar='main',menu="ArmAda/Download solution",before="Help")
GPS.Action.destroy_ui(GPS.Action("Debug with Emulator Number 1"))
GPS.Action.destroy_ui(GPS.Action("Run with Emulator Number 1"))
#GPS.Action.destroy_ui(GPS.Action("Debug on Board Number 1"))

#init()
