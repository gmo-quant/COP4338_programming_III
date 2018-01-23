#!/bin/sh
# generate a new file with the documentation template.
# param: 
# $1 file name
# $2 program #
# $3 title 
# $4 author name, Guangzhuan Mo by default

if [ $1 == 'help' ]
then 
	echo "./new.file.sh filename program# title [author.name]"
elif [ -f $1 ]
then
	echo "file: $1  is already exist"
else 
	touch $1
	python ./document.template.py $1 $2 $3 $4
fi

