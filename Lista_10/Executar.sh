#!/bin/bash

echo "Compilando..."
make
echo "Compilado "

echo "Executando..."
valgrind ./Executavel

echo "Finalizado"
rm Executavel