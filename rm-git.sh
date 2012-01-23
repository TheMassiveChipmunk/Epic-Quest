#!/bin/bash

rm $1
git add . -A
git commit -m "Removed some files"
git push origin master
