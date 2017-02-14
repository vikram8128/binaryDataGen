# Binary Data Generator

This program will generate data with any binary pattern. 
To use it, specify the number of repeats, and then the pattern.
It is designed to redirect the output to a file, or pipe it to another program.

eg. to generate the binary pattern 10010000 10010010 01000100 010

     binaryDataGen 2 100 3 001 3 0010

Note: The end of the file will be padded with 0 to a full byte.

eg. to generate an ascii file containing AABBBCCCC use the following

     binaryDataGen 2 01000001 3 01000010 4 01000011
