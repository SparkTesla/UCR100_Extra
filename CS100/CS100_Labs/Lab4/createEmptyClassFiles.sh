#!/bin/sh

touch "$1".cc
touch "$1".hh

cat Angel_861179692.txt >> "$1".hh
cat Angel_861179692.txt >> "$1".cc

echo "#ifndef $1_hh" >> "$1".hh
echo "#define $1_hh" >> "$1".hh
echo -e "\nclass $1\n{\n\tpublic:\n\t $1();\n\t ~$1();\nprivate:\n};\n#endif" >> "$1".hh
echo -e "\n#include \"./$1.hh\"\n$1::$1()\n{}\n\n$1::~$1()\n{}\n" >> "$1".cc
