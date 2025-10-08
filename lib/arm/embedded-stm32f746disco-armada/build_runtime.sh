#!/bin/sh

# Nettoyage de la runtime
echo "Nettoyage de libgnat et libgnarl"
gprclean libgnat_build.gpr
gprclean libgnarl_build.gpr

# Construction de la runtime
echo "Construction de libgnat et libgnarl"
gprbuild libgnarl_build.gpr