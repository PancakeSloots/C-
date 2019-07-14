#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>

//Encryption and Decryption Program
//Takes in a 4 digit number and either decrypts it or
//encrypts it.
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/1/19

int main() {
	
}
	int mystery(const char *s1, const char *s2)
	{
		for ( ; *s1 != '\0' && *s2 != '\0'; s1++, s2++) {
			if (*s1 != *s2) {
				return 0;
			}//end if
		}//end for
		return 1;
	}

