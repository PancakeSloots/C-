
#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
//Random Sentance Generator
//program initializes 4 arrays, article, noun, verb and preposition
//Builds sentance in the format: article, noun, verb, preposition, article, noun.
//Pointers can be repeated.
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 6/15/19

int main(void)
{
	srand(time(NULL)); //random generator

	//these are arrays of the different words as listed in the assignment
	const char *article[] = { "the", "a", "one", "some", "any" };
	const char *noun[] = { "boy", "girl", "dog", "town", "car" };
	const char *verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
	const char *preposition[] = { "to", "from", "over", "under", "on" };

	//this labels max length. wont be reached in this program, but it allows for changes
	char sentence[50] = "";

	for (int i = 0; i < 20; i++) //20 is the number of sentences
	{
		strcat(sentence, article[rand() % 5]);
		strcat(sentence, " "); //replaces the last character of the string instead of null

		sentence[0] = toupper(sentence[0]); //makes the first letter capitalized, comment out if not wanted. 

		strcat(sentence, noun[rand() % 5]); //looks for a noun as listed
		strcat(sentence, " ");

		strcat(sentence, verb[rand() % 5]); //looks for a verb as listed
		strcat(sentence, " ");

		strcat(sentence, preposition[rand() % 5]); //looks for a preopsition as listed
		strcat(sentence, " ");

		strcat(sentence, article[rand() % 5]); //looks for an article as listed
		strcat(sentence, " ");

		strcat(sentence, noun[rand() % 5]); //looks for another noun as listed
		strcat(sentence, ".");

		printf("%s\n", sentence); //prints the final result of the sentences

		sentence[0] = '\0'; //separates the setences and does not delete previous sentence

	}
	system("pause");
	return(0);
} //end