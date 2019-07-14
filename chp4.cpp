#include <iostream>

using namespace std;

int main()

{

	double amt;

	double rate = 0.05;

	cout << "\nCompunt interest: " << endl << endl;

	cout << "Rate\tTotal" << endl << endl;

	for (int i = 0; i < 6; i++)

	{

		amt = 1000;

		for (int j = 0; j < 10; j++)

		{

			amt = (rate * amt) + amt;

		}

		cout << rate << "\t$" << amt << endl;

		rate = rate + 0.01;

	}

	system("pause");

}