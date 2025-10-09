#!/usr/bin/python3
#
# Script for installing library on server

import os
import time

from datetime import datetime
from shutil import copytree
from shutil import rmtree

# Parameters to configure
script_version          = "1.1"

runtime_version         = "3.5"

deploy_path_on_server   = "/mnt/commetud/2emeAnneeIMACS/ADA/"

directories_to_deploy   = ["./tools",
                           "./lib/arm/embedded-stm32f746disco-armada",
                           "./lib/lib_TP",
                           "./lib/arm/insa",
                           "./TP",
                           "./arm-ada-setup",
                           "./README.md",
                           "./LICENSE.txt",
                           "./settings-armada.sh",
                           "./update-tp"]

# applis_to_rebuild         = ["gprbuild ./TP/TP1/mission_pacman.gpr",
#                            "gprbuild ./TP/TP2/mission_simon.gpr",
#                            "gprbuild ./TP/TP3.1/mission_dicho.gpr",
#                            "gprbuild ./TP/TP3.2/mission_koch.gpr",
#                            "gprbuild ./TP/TP4.1/mission_snake.gpr",
#                            "gprbuild ./TP/TP4.2/mission_morse.gpr"]

applis_to_rebuild       = ["gprbuild %sTP/TP1/mission_pacman.gpr",
                            "gprbuild %sTP/TP2/mission_simon.gpr",
                            "gprbuild %sTP/TP3.1/mission_dicho.gpr",
                            "gprbuild %sTP/TP3.2/mission_koch.gpr",
                            "gprbuild %sTP/TP4.1/mission_snake.gpr",
                            "gprbuild %sTP/TP4.2/mission_morse.gpr"
                           ]

runtime_to_rebuild      = ["gprclean %slib/arm/runtime/libgnat_build.gpr",
                           "gprclean %slib/arm/runtime/libgnarl_build.gpr",
                           "gprbuild %slib/arm/runtime/libgnat_build.gpr",
                           "gprbuild %slib/arm/runtime/libgnarl_build.gpr"
                           ]

libs_to_rebuild         = ["gprclean %slib/arm/insa/insa_dev.gpr",
                           "gprbuild %slib/arm/insa/insa_dev.gpr"
                           ]

cleanup_commands        = [ # On renomme les solutions des TP en solution.elf
                            "mv %s/TP/TP1/obj/mission_pacman.elf %s/TP/TP1/obj/solution.elf",
                            "mv %s/TP/TP2/obj/mission_simon.elf %s/TP/TP2/obj/solution.elf",
                            "mv %s/TP/TP3.1/obj/mission_dicho.elf %s/TP/TP3.1/obj/solution.elf",
                            "mv %s/TP/TP3.2/obj/mission_koch.elf %s/TP/TP3.2/obj/solution.elf",
                            "mv %s/TP/TP4.1/obj/mission_snake.elf %s/TP/TP4.1/obj/solution.elf",
                            "mv %s/TP/TP4.2/obj/mission_morse.elf %s/TP/TP4.2/obj/solution.elf",

                            # On copie les fichiers de depart dans le répertoire src
                            "cp %s/TP/TP1/src_etudiant/mission_pacman.adb %s/TP/TP1/src/mission_pacman.adb",
                            "cp %s/TP/TP2/src_etudiant/mission_simon.adb %s/TP/TP2/src/mission_simon.adb",
                            "cp %s/TP/TP3.1/src_etudiant/mission_dicho.adb %s/TP/TP3.1/src/mission_dicho.adb",
                            "cp %s/TP/TP3.2/src_etudiant/mission_koch.adb %s/TP/TP3.2/src/mission_koch.adb",
                            "cp %s/TP/TP4.1/src_etudiant/mission_snake.adb %s/TP/TP4.1/src/mission_snake.adb",
                            "cp %s/TP/TP4.2/src_etudiant/mission_morse.adb %s/TP/TP4.2/src/mission_morse.adb",

                            # On supprime les répertoires src_etudiant  
                            "rm -rf %s/TP/TP1/src_etudiant",
                            "rm -rf %s/TP/TP2/src_etudiant",
                            "rm -rf %s/TP/TP3.1/src_etudiant",
                            "rm -rf %s/TP/TP3.2/src_etudiant",
                            "rm -rf %s/TP/TP4.1/src_etudiant",
                            "rm -rf %s/TP/TP4.2/src_etudiant",

                            # On supprime les fichiers objets
                            "gprclean %sTP/TP1/mission_pacman.gpr",
                            "gprclean %sTP/TP2/mission_simon.gpr",
                            "gprclean %sTP/TP3.1/mission_dicho.gpr",
                            "gprclean %sTP/TP3.2/mission_koch.gpr",
                            "gprclean %sTP/TP4.1/mission_snake.gpr",
                            "gprclean %sTP/TP4.2/mission_morse.gpr",

                            # On rend le script d'installation exécutable
                            "chmod +x %s/arm-ada-setup"]

# 
# Nothing to configure or modify under this line
#

def run_commands(commands, directory = ""):
    for command in commands:
        if directory != "":
            print ("Command = " + command % directory)
            os.system (command % directory)
        else:
            print ("Command = " + command)
            os.system (command)

def cp_files(commands, directory = ""):
    for command in commands:
        if directory != "":
            print ("Copying: " + command + " to " + directory)
            if os.path.isdir(command):
                copytree (command, directory + command[2:], dirs_exist_ok=True)
            else:
                os.system ("cp " + command + " " + directory)
        else:
            print ("Copying: " + command)
            if os.path.isdir(command):
                copytree (command, command[2:], dirs_exist_ok=True)
            else:
                os.system ("cp " + command + " .")

def run_cleanup_commands(commands, directory = ""):
    for command in commands:
         # Compter le nombre d'occurrences de "%s"
        count = command.count("%s")

        try:
            if count == 2:
                formatted = command % (directory, directory)
            elif count == 1:
                formatted = command % directory
            else:
                formatted = command

            print(f"Cleanup Command ({count}) = {formatted}")
            os.system(formatted)
        except Exception as e:
            print(f"Erreur lors du traitement de la commande '{command}': {e}")

def main():
    print ("Install script for ARM-ADA library, version " + script_version)
    print ("S. Di Mercurio 2025")
    print ("=====================================================\n")

    print ("Start installation procedure")

    now = datetime.now()
    temp_dir = os.path.expanduser ("~/tmp/armada-" + now.strftime("%Y%m%d-%H%M%S") + "/")
    #temp_dir = "/home/dimercur/tmp/armada-20211124-170312/"

    print ("\nTemp directory : " + temp_dir)
    print ("Install directory : " + deploy_path_on_server)

    print ("\nArchive old ADA directory to ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S"))
    run_commands (["mv "+ deploy_path_on_server + " " + deploy_path_on_server + "../ADA_" + datetime.now().strftime("%Y%m%d-%H%M%S")])
    time.sleep(1) # wait 1 second in order for "mv" command to complete
    run_commands (["mkdir " + deploy_path_on_server])

    print ("\nCopy files")
    cp_files (directories_to_deploy, deploy_path_on_server)

    print ("\nCreate symlinks for runtime")
    os.system  ("ln -s %s/lib/arm/embedded-stm32f746disco-armada %s/lib/arm/runtime" % (deploy_path_on_server, deploy_path_on_server))
    os.system  ("ln -s %s/lib/arm/embedded-stm32f746disco-armada %s/lib/arm/runtime-%s" % (deploy_path_on_server, deploy_path_on_server, runtime_version))

    print ("\nBuild runtime")
    run_commands(runtime_to_rebuild, deploy_path_on_server)

    print ("\nBuild support libraries")
    run_commands(libs_to_rebuild, deploy_path_on_server)

    print ("\nBuild applications")
    run_commands(applis_to_rebuild, deploy_path_on_server)

    print ("\nCleanup")
    run_cleanup_commands(cleanup_commands, deploy_path_on_server)

    print ("\nAll done")

main()