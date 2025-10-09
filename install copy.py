#!/usr/bin/python3
#
# Script for installing library on server

import os
import time

from datetime import datetime
from shutil import copytree
from shutil import rmtree

import paramiko
from getpass import getpass

# Parameters to configure
directories_to_archive  = ["./tools",
                           "./lib",
                           "./TP_templates"]

# applis_to_rebuild         = ["gprbuild ./TP/TP1/mission_pacman.gpr",
#                            "gprbuild ./TP/TP2/mission_simon.gpr",
#                            "gprbuild ./TP/TP3.1/mission_dicho.gpr",
#                            "gprbuild ./TP/TP3.2/mission_koch.gpr",
#                            "gprbuild ./TP/TP4.1/mission_snake.gpr",
#                            "gprbuild ./TP/TP4.2/mission_morse.gpr"]

applis_to_rebuild         = ["gprbuild ./TP/TP1/mission_pacman.gpr"
                           ]

runtime_to_rebuild         = ["gprclean ./lib/arm/runtime/libgnat_build.gpr",
                           "gprclean ./lib/arm/runtime/libgnarl_build.gpr",
                           "gprbuild ./lib/arm/runtime/libgnat_build.gpr",
                           "gprbuild ./lib/arm/runtime/libgnarl_build.gpr"
                           ]

libs_to_rebuild         = ["gprclean ./lib/arm/insa/insa_dev.gpr",
                           "gprbuild ./lib/arm/insa/insa_dev.gpr"
                           ]

preparation_commands    = ["unzip -fq %s/tools/bin/ST-LINK_gdbserver.zip",
                           "rm %s/tools/bin/ST-LINK_gdbserver.zip",
                           "rm -rf %s/lib/arm/ravenscar-full-armada/debug_cubeide",
                           "rm -rf %s/lib/arm/insa/donotuse",
                           "cp ./TP/TP1/obj/mission_pacman.elf %s/TP_templates/TP1/obj/solution.elf",
                           "cp ./TP/TP2/obj/mission_simon.elf %s/TP_templates/TP2/obj/solution.elf",
                           "cp ./TP/TP3.1/obj/mission_dicho.elf %s/TP_templates/TP3.1/obj/solution.elf",
                           "cp ./TP/TP3.2/obj/mission_koch.elf %s/TP_templates/TP3.2/obj/solution.elf",
                           "cp ./TP/TP4.1/obj/mission_snake.elf %s/TP_templates/TP4.1/obj/solution.elf",
                           "cp ./TP/TP4.2/obj/mission_morse.elf %s/TP_templates/TP4.2/obj/solution.elf",
                           "cp ./arm-ada-setup %s",
                           "chmod +x %s/arm-ada-setup"]

server_name             = "srv-ens-calcul"

deploy_path_on_server   = "/mnt/commetud/2emeAnneeIMACS/ADA/"

download_path_on_server = "/home_pers/"

temp_archive            = "armada.zip"

# 
# Nothing to configure or modify under this line
#

def run_commands(commands):
    for command in commands:
        print ("Command = " + command)
        os.system (command)

def rebuildlibs(commands):
    for command in commands:
        print ("Command = " + command)
        os.system (command)

def rebuildruntime(commands):
    for command in commands:
        print ("Command = " + command)
        os.system (command)

def copyfilestoarchive(treetocopy, tempdir):
    for treetocopy in treetocopy:
        print ("Copying " + treetocopy + " to " + tempdir+treetocopy)
        copytree (treetocopy, tempdir+treetocopy)


def preparearchive(tempdir,temparchive,cmdlist):
    for cmd in cmdlist:
        print (cmd % tempdir)
        os.system (cmd % tempdir)

    currentdir = os.getcwd()
    os.chdir(tempdir)
    os.system ("zip -qr " + temparchive + " *")
    os.chdir(currentdir)

def removetempdir(tempdir):
    print ("Remove " + tempdir)
    rmtree (tempdir)

def transferprogress(transferred, tobetransfered):
    print("Upload: " + str(int(transferred*100/tobetransfered))+"%", end = "\r")

def deploy(servername, deploydir, downloaddir, tempdir, temparchive):
    print ("Connection to " + server_name)
    username = input("Enter user name: ")
    password = getpass("Enter password: ")

    ssh_client= paramiko.SSHClient()
    ssh_client.load_system_host_keys()
    ssh_client.connect (servername, 22, username, password)
    sftp_client = ssh_client.open_sftp()
    
    print ("Send "+ tempdir+ temparchive + " to " + downloaddir + username + "/" + temparchive)
    sftp_client.put(tempdir+ temparchive ,downloaddir + username + "/" + temparchive, transferprogress)
    sftp_client.close()

    print ("Archive old ADA directory to ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S"))
    ssh_stdin, ssh_stdout, ssh_stderr = ssh_client.exec_command("mv "+ deploydir + " " + deploydir + "/../ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S"),get_pty=True)
    time.sleep(1) # wait 1 second in order for "mv" command to complete

    print ("Create empty directory " + deploydir)
    ssh_stdin, ssh_stdout, ssh_stderr = ssh_client.exec_command("mkdir " + deploydir,get_pty=True)
    time.sleep(1) # wait 1 second in order for "mkdir" command to complete

    print ("Move " + downloaddir + username + "/" + temparchive + " to " + deploydir)
    ssh_stdin, ssh_stdout, ssh_stderr = ssh_client.exec_command("mv "+ downloaddir + username + "/"  + temparchive + " " + deploydir,get_pty=True)
    time.sleep(2) # wait 2 second in order for "mv" command to complete

    print ("unzip "+ temparchive)
    ssh_stdin, ssh_stdout, ssh_stderr = ssh_client.exec_command("cd " + deploydir + ";unzip "+ temparchive + " -d ./",get_pty=True)
    ssh_stdin.close()
    for line in iter(ssh_stdout.readline, ""):
        print(line, end="")

    print ("rm "+ temparchive)
    ssh_stdin, ssh_stdout, ssh_stderr = ssh_client.exec_command("cd " + deploydir + ";rm -v "+ temparchive,get_pty=True)
    for line in iter(ssh_stdout.readline, ""):
       print(line, end="")

    ssh_client.close()

def main():
    print ("Start installation procedure")

    now = datetime.now()
    temp_dir = os.path.expanduser ("~/tmp/armada-" + now.strftime("%Y%m%d-%H%M%S") + "/")
    #temp_dir = "/home/dimercur/tmp/armada-20211124-170312/"

    print ("Temp directory : " + temp_dir)
    print ("Install directory : " + deploy_path_on_server)

    print ("\nArchive old ADA directory to ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S"))
    run_commands (["mv "+ deploy_path_on_server + " " + deploy_path_on_server + "../ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S")])
    time.sleep(1) # wait 1 second in order for "mv" command to complete
    run_commands (["mkdir " + deploy_path_on_server])

    print ("\nBuild runtime")
    run_commands(runtime_to_rebuild)
    run_commands (["mkdir -p " + deploy_path_on_server + "/lib/arm"])
    run_commands (["cp -r ./lib/arm/embedded-stm32f746disco-armada " + deploy_path_on_server + "lib/arm/"])
    run_commands (["ln -s " + deploy_path_on_server + "lib/arm/embedded-stm32f746disco-armada " + deploy_path_on_server + "lib/arm/runtime"])
    run_commands (["ln -s " + deploy_path_on_server + "lib/arm/embedded-stm32f746disco-armada " + deploy_path_on_server + "lib/arm/runtime-3.5"])

    print ("\nBuild support libraries")
    run_commands(libs_to_rebuild)
    run_commands (["cp -r ./lib/arm/insa " + deploy_path_on_server + "lib/arm/"])
    run_commands (["cp -r ./lib/lib_TP " + deploy_path_on_server + "lib/"])

    print ("\nBuild applications")
    run_commands(applis_to_rebuild)
    run_commands (["mkdir -p " + deploy_path_on_server + "TP/"])
    run_commands (["cp -r ./TP/TP* " + deploy_path_on_server + "TP/"])

    exit()
    print ("\nPrepare archive")
    run_commands (applis_to_rebuild)
    copyfilestoarchive (directories_to_archive, temp_dir)
    preparearchive (temp_dir, temp_archive, preparation_commands)

    print ("\nDeploy on commetud")
    deploy (server_name, deploy_path_on_server, download_path_on_server,  temp_dir, temp_archive)

    print ("\nCleanup")
    removetempdir (temp_dir)

main()