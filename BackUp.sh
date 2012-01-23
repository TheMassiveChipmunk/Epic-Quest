#!/bin/bash

if [ -d ../GAME_BACKUP ]; then

    cp -f *.hpp *.cpp ../GAME_BACKUP

else

    mkdir ../GAME_BACKUP
    cp -f *.hpp *.cpp ../GAME_BACKUP

fi
