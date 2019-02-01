#include <iostream>

using namespace std;

int		fibonacci(int number)
{
	if (number == 0 || number == 1)
		return (1);
	return (fibonacci(number - 1) + fibonacci(number - 2));
}

int		main()
{
	int number;
	cout << "enter number" << endl;
	cin >> number;
	if (number < 0)
		cout << "Wrong number" << endl;
	for (int i = 0; i <= number; i++)
		cout << fibonacci(i) << endl;
	return (1);
}
