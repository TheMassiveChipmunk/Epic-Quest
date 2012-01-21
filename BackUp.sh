#!/bin/bash

if [ -d ../LIB_BACKUP ]; then

    cp -f *.hpp *.cpp ../LIB_BACKUP

else

    mkdir ../LIB_BACKUP
    cp -f *.hpp *.cpp ../LIB_BACKUP

fi
