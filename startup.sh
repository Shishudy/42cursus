#!/bin/bash
cd ..
cd ..
user=$(whoami)
cd sgoinfre/$user/42cursus
code .
gnome-terminal
pid=$(ps | grep 'zsh' | awk '{print $1}')
kill -SIGKILL $pid
