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

int searchCardNumbers(const int cards[], int SIZE, int cardNumber);
void sortCards(int cards[], int SIZE);

const int SIZE = 18;

int main() {
	int cardNumber, result;
	int cards[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
					   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
					   1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
	cout << "\n   "
		 << "What is the account number: ";
	cin >> cardNumber;
	sortCards(cards, SIZE);
	result = searchCardNumbers(cards, SIZE, cardNumber);
	if(result == -1)
		{
			cout << "   "
				 << "The account number is invalid." << endl;

		}
	else
		{
			cout << "   "
				 << "The account number is valid." << endl;
		}
	return 0;
}

int searchCardNumbers(const int cards[], int SIZE, int cardNumber)
{
	int first = 0,
		last = SIZE -1,
		middle,
		position = -1;

	bool found = false;

	while (!found && first <= last)
	{
		middle = first + last / 2;
		if (cards[middle] == cardNumber)
		{
			found = true;
			position = middle;
		}
		else if (cards[middle] > cardNumber)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}

void sortCards(int cards[], int SIZE)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = cards[startScan];
		for(int index = startScan + 1; index < SIZE; index++)
		{
			if (cards[index] < minValue)
			{
				minValue = cards[index];
				minIndex = index;
			}
		}
		cards[minIndex] = cards[startScan];
		cards[startScan] = minValue;
	}
}




