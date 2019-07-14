#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
//Fahrenheit to Celsius 
//Fahrenheit 0-212 to Celsius with precision
//to three decimals.
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/22/19


int main()
{
	float temp_c;//celsius
	int temp_f;//fahrenheit temp

	printf("% 10s  % 10s\n\n", "Fahrenheit", "Celsius");//table heading

	for (temp_f = 0; temp_f <= 212; temp_f++)//loop 0 to 212 fahrenheit to celsius
	{
		temp_c = 5.0 / 9.0 * (temp_f - 32);//conversion
		printf("%+10d  %+10.3f\n", temp_f, temp_c);//print in tabular format including positive and negative values
	}
	system("pause");
	return 0;
}//written in Visual Studio 2017