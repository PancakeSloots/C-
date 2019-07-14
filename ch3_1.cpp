//Encryption and Decryption Program
//Takes in a 4 digit number and either decrypts it or
//encrypts it.
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/1/19

#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	int encrypt;
	int decrypt;
	int e1, e2, e3, e4;
	int d1, d2, d3, d4;
	int a, x;
	int o, d, t, q;

	do
	{
		printf("Encode (1)\t Decode (2): ");//user determines encode or decode  or asks againg
		scanf_s("%d", &a);

		if (a == 1)//encode
		{
			printf("Enter four digit number: ");
			scanf_s("%d", &x);
			q = x % 10;
			x /= 10;
			t = x % 10;
			x /= 10;
			d = x % 10;
			x /= 10;
			o = x % 10;

			e1 = (o + 7) % 10;//adding 7 then remainder by seven
			e2 = (d + 7) % 10;//to each didgit
			e3 = (t + 7) % 10;
			e4 = (q + 7) % 10;

			encrypt = (e3 * 1000) + (e4 * 100) + (e1 * 10) + e2;//encrypt = new 4 dig 



			printf("Encoded Digits: %04d\n", encrypt);
		}
		else if (a == 2)//decode
		{
			printf("Enter four digit number: ");
			scanf_s("%d", &x);
			q = x % 10;
			x /= 10;
			t = x % 10;
			x /= 10;
			d = x % 10;
			x /= 10;
			o = x % 10;

			d1 = (o + 3) % 10;    //+3 = -7 +10 (in case -7 gives a negative)
			d2 = (d + 3) % 10;
			d3 = (t + 3) % 10;
			d4 = (q + 3) % 10;

			decrypt = (d3 * 1000) + (d4 * 100) + (d1 * 10) + d2;//decrypt = decoded 4 dig

			printf("Encoded Digits: %04d\n", decrypt);
		}
		else
		{
			printf("Encode (1)\t Decode (2): \n");
			scanf_s("%d", &a);
		}

		printf("Continue (1)\t Exit (0): ");//continue repeats the program(Exit takes you to pause)
		scanf_s("%d", &a);
	} while (a == 1);
	   
	system("pause");
	return(0);
}
