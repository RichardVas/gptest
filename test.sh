#!/bin/bash

rm -f output.txt

./a.out input.json >> output.txt

diff --strip-trailing-cr output.txt expected_output.txt

if [ $? -eq 0 ]
then
echo "No differences. The test was OK!"
else
echo "Test failed."
fi
