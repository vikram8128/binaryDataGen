//
//  binaryDataGen.cpp
//
//  Created by Vikram Singh on 13/02/2017.
//  Copyright © 2017 Vikram Singh.
//
//  This program will generate any binary pattern. To use it, specify the number of repeats, and then the pattern.
//  eg. to generate 10010000 10010010 01000100 010
//       testGenerator 2 100 3 001 3 0010
//  Note: The end of the file will be padded with 0 to a full byte. 
//

#include <iostream>
using namespace std;

void printError() {
    cout << "Incorrect arguments" << endl;
    cout << "This program will generate any binary pattern. To use it, specify the number of repeats, and then the pattern." << endl;
    cout << "eg. to generate 10010000 10010010 01000100 010" << endl;
    cout << "     testGenerator 2 100 3 001 3 0010" << endl;
    cout << "Note: The end of the file will be padded with 0 to a full byte." << endl;
    exit(5);
}

void writec(unsigned char c) {
    //printf("%02x\n", c);
    cout.put(c);
}

int main(int argc, const char * argv[]) {
    if (!(argc%2)) {
	printError();
    }
    unsigned char c = 0;
    long cBit = 7;
    for (long i = 1; i < argc; i+=2) {
	long reps = stoi(argv[i]);
	const char* pattern = argv[i+1];
	long len = strlen(pattern);
	for (long j = 0; j < len; j++) {
	    if (pattern[j] != '0' && pattern[j] != '1') printError();
	}
    }
    for (long i = 1; i < argc; i+=2) {
        long reps = stoi(argv[i]);
        const char* pattern = argv[i+1];
        long len = strlen(pattern);
    	for (long repn = 0; repn < reps; repn++) {
	    for (long si = 0; si < len; si++) {
	        if (pattern[si] == '1') {
		    c |= (1 << cBit);
		}
		cBit--;
		if (cBit < 0) {
		    cBit = 7;
		    writec(c);
		    c = 0;
		}
	    }
	}


    }

    if (cBit != 7) {
	writec(c);
    }

    return 0;
}
