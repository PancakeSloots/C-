//Flip Coin Counter Program
//Utilizes srand to flip a virtual coin
//Counts the number of heads vs tails
//Trials count 10, 100, 1000, 10,000, 100,000, and 1,000,000.
//Outputs percentages 
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/8/19

#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>

void doFlips(int count)
{
	int i, flip;
	int head = 0;
	int tail = 0;
	float perHead;
	float perTail;
	for (i = 0; i < count; ++i) //use of for loop
	{
		flip = 1 + (rand() % 2);//adding 1 to rand to make case 1 and 2
		switch (flip) //use of switch statement
		{
		case 1: //if rand equation comes up 1
			head++;
			break;
		case 2: //
			tail++;
			break; //if rand equation comes up 2
		}
		int total;
		total = head + tail;
		perHead = ((1.0*head / (head + tail))*100.0);
		perTail = ((1.0*tail / (head + tail))*100.0);
	}
	printf("Trials: %8d: \n", count); //prompt
	printf("Head count: %8d Percent head: %.2f \n", head, perHead); //heads readout
	printf("Tail count: %8d Percent tail: %.2f \n", tail, perTail); //tails readout
	printf("\n"); 
}

int main(void) //main function of the program
{
	int i, ch;
	do
	{
		srand(time(NULL));
		for (i = 10; i <= 1000000; i *= 10)//Each trial is just 10x the previous trial
		{
			doFlips(i);//doFlips method from above 
		}
		printf("Try Again (1) Exit (0)");//user determines repeat
		scanf("%d", &ch);
	} while (ch != 0);
	getchar();
	system("pause");
	return 0;
}