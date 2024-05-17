#!/bin/bash

# Package name
PACKAGE="pwntools"

# Check if the package is installed
if ! pip3 list | grep -q "^$PACKAGE "; then
    echo "Package $PACKAGE is not installed. Installing now..."
    pip3 install $PACKAGE
fi

LAB2_="./lab2.py"
LAB2_AGING_="./lab2_aging.py"
if [ ! -f "$LAB2_" ]; then
    wget https://raw.githubusercontent.com/UCRCS153/UCR-CS153.github.io/main/lab2.py
fi

if [ ! -f "$LAB2_AGING_" ]; then
    wget https://raw.githubusercontent.com/UCR-CS153/UCR-CS153.github.io/main/lab2_aging.py 
fi

if [ "$1" = "aging" ]; then
    python3 lab2_aging.py
else
    python3 lab2.py
fi
