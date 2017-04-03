/*********************************************************************************************
*
* Created By: Ferrin Katz
* Date Created: 3/1/17
*
*********************************************************************************************/

#include "PokerGame.h"
using namespace std;

int main()
{
	Table* table;

	try
	{
		table = new Table;
	}
	catch (int& x)
	{
		cout << x << " is not a valid number of players." << endl << endl;
		return 1;
	}
	catch (string& err)
	{
		cout << err << endl << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return 2;
	}

	table->playGame();
	delete table;
	return 0;
}

