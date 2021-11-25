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

from gs_utils import interactive


def get_gdb_server_pid():
    stream = os.popen("ps -ef | grep ST-LINK_gdbserver\ -c | grep -v grep | awk '{print $2}'")
    pid = stream.read()

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


def spawn_gdb_server():
    GPS.Console("Messages").write("Spawn gdbserver\n")
    #info = subprocess.Popen(["/home_pers/dimercur/.gnatstudio/ST-LINK_gdbserver.sh"],shell=True)
    info = subprocess.Popen(["/mnt/commetud/2eme\ Annee\ IMACS/ADA/tools/bin/ST-LINK_gdbserver.sh"],shell=True)
    time.sleep(1)


@interactive("Editor", menu="/ArmAda/Download Only")
def on_menu_download_only():
    project_name = GPS.Project.root().name()
    executable_dir = GPS.Project(project_name).exec_dir()
    main_file = GPS.Project(project_name).get_attribute_as_string("Main")
    executable_path = GPS.File(main_file).executable_path
    executable_name = executable_path.name()
    GPS.Console("Messages").write("File to program: " + executable_name + "\n")

    # For downloading only program, GDB server must not be running
    gdb_pid = get_gdb_server_pid()
    if gdb_pid != -1:
        kill_gdb_server(gdb_pid)

    # Now programming
    stream = os.popen("/usr/local/insa/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD -d " +
                      executable_name + " -hardRst")
    GPS.Console("Messages").write(stream.read() + "\n")


@interactive("Editor", menu="/ArmAda/Download and Debug")
def on_menu_download_and_debug():
    if (get_gdb_server_pid() == -1):
        #print("GDB server not running")
        spawn_gdb_server()

    if (get_gdb_server_pid() != -1):
        GPS.Action("Debug on Board Number 1").execute_if_possible()


@interactive("Editor", menu="/ArmAda/Remove GDB server")
def on_menu_kill_gdbserver():
    gdb_pid = get_gdb_server_pid()
    if gdb_pid != -1:
        kill_gdb_server(gdb_pid)


def init():
    GPS.Console("Messages").write("Load: armada menu\n")
    GPS.Action("on_menu_download_only").button(icon="insa-download-only", label='Download only')
    GPS.Action("on_menu_download_and_debug").button(icon="insa-download-debug", label='Download and Debug')
    GPS.Action("on_menu_kill_gdbserver").button(icon="insa-trash", label='Remove GDB server')

init()
