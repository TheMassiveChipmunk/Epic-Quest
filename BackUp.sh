#!/bin/bash

if [ -d ../LIB_BACKUP ]; then

    cp -f *.hpp *.cpp ../BACKUP

else

    mkdir ../LIB_BACKUP
    cp -f *.hpp *.cpp ../BACKUP

fi
