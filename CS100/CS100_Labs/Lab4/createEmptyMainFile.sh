#!/bin/sh

touch main.cc

cat Angel_861179692.txt > main.cc
echo "int main(int argc, const char** argv)" >> main.cc
echo "{}" >> main.cc
cat main.cc
