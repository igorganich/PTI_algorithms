#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
	char buffer[11] = "smth";
	while (buffer[0] != 10)
	{
		int choose = atoi(buffer);
		cout << "choose next operation or ctrl + D to end" << endl;
		cout << "1 - push item";
		cout << "2 pop and operation plus for 2 elements in stack" << endl;
		cout << "3 - delete one operaton" << endl;
		cout << "4 - show current stack" << endl;
	}
}
