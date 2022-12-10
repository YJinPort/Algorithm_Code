#include <iostream>

using namespace std;

int riceCake[35];

int main()
{
	int day = 0, total = 0;
	int a, b;

	cin >> day >> total;

	riceCake[1] = riceCake[2] = 1;

	for (int i = 3; i <= day; i++)
	{
		riceCake[i] = riceCake[i - 2] + riceCake[i - 1];
	}

	int a_profit = riceCake[day - 2];
	int b_profit = riceCake[day - 1];

	for (int i = 1;; i++)
	{
		a = i;
		if ((total - a_profit * a) % b_profit)
			continue;
		b = (total - a_profit * a) / b_profit;
		break;
	}
	cout << a << endl << b << endl;

	return 0;
}