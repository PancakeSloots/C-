//Sieve of Eratosthenes
//User inputs max number
//program counts prime numbers up to max
//and displays them.
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/8/19

#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>

int main() {

	int limit;
	printf("Enter the limit:  ");
	scanf("%d", &limit);
	char* p;
	limit++;
	p = (char*)malloc(sizeof(char)*limit);//allocating dynamic memory, char size big
	int i;	

	for (i = 2; i < limit; i++)//seive of eratosthenes
		p[i] = 0;
	i = 2;
	printf("Primes up to %d \n", limit - 1);
	int total = 0;

	while (i < limit)
	{
		if (p[i] == 0) 
		{
			printf("%i  ", i);
			total++;
		}
		int j;
		for (j = 1; i*j < limit; j++)
			p[i*j] = 1;
		i++;
	}
	printf("\nNumber of primes: %d\n", total);
	system("pause");
	return(0);
}