#!/bin/bash

GDB_SERVER_PATH="/mnt/commetud/2eme Annee IMACS/ADA/tools/bin"
echo $GDB_SERVER_PATH
cd "$GDB_SERVER_PATH"

pwd

ST-LINK_gdbserver -c ./config.txt

# read -p "Press Enter to exit"
