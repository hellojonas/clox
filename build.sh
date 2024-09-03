#!/usr/bin/env bash

SOURCE=$1

if [[ ! -d "./bin" ]]; then
    mkdir ./bin
fi

gcc -o ./bin/clox ./src/*.c
chmod u+x ./bin/clox

if [[ -n "$SOURCE" ]]; then
    ./bin/clox "$SOURCE"
fi
