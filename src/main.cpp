//============================================================================
// PC 8.1 - Charge account validation
// -------------------------
// Programmer: Jeremy F McKay
// Date: October 31, 2012
// -------------------------
// This program will ask the user for an account number then
// validate it agains a array of numbers using a linear search
// ---------1---------2---------3---------4---------5---------6---------7
// 1234567890123456789012345678901234567890123456789012345678901234567890

#include <iostream>
using namespace std;
bool searchCardNumbers(const int cards[], int SIZE, int cardNumber);
const int SIZE = 18;

int main() {
	int cardNumber;
	int cards[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
					   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
					   1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
	cout << "\n   "
		 << "What is the account number: ";
	cin >> cardNumber;
	if(searchCardNumbers(cards, SIZE, cardNumber))
		{
			cout << "   "
				 << "The account number is valid." << endl;

		} else {
			cout << "   "
				 << "The account number is invalid." << endl;
		}
	return 0;
}

bool searchCardNumbers(const int cards[], int SIZE, int cardNumber)
{
	int index = 0;

	while (index < SIZE)
	{
		if (cards[index] == cardNumber)
		{
			return true;
		}
		index++;
	}
	return false;
}
