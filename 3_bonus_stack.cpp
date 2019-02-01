#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


void push_one(vector<int> *stack)
{
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	(*stack).push_back(data);
}

int pop_one(vector<int> *stack)
{
	if ((*stack).size() == 0)
	{
		cout << "nothing to return from buffer. 0 returned" << endl;
		return (0); 
	}
	int returned = (*stack)[(*stack).size() - 1];
	(*stack).pop_back();
	return (returned);
}

void show_stack(vector<int> *stack)
{
	cout << "your stack: " << endl;
	for (int i = (*stack).size() - 1; i >= 0; i--)
	{
		cout << (*stack).size() - i - 1 << " " << (*stack)[i] << endl;
	}
}

int main()
{
	char	buffer[11] = "smth";
	vector<int>	stack;
	while (buffer[0] != 4)
	{
		cout << "choose next operation or ctrl + D to end" << endl;
		cout << "1 - push item" << endl;
		cout << "2 - pop and operation plus for 2 elements in stack" << endl;
		cout << "3 - delete one element" << endl;
		cout << "4 - show current stack" << endl;
		cin.getline(buffer, 11);
		int choose = atoi(buffer);
		switch(choose)
		{
			case 1:
			{
				push_one(&stack);
				break;
			}
			case 2:
			{
				int a = pop_one(&stack);
				int b = pop_one(&stack);
				cout << "rezult is " << a + b << endl;
				break;
			}
			case 3:
			{
				pop_one(&stack);
				break;
			}
			case 4:
			{
				show_stack(&stack);
				break;
			}
			default:
			{
				if (buffer[0] == 4)
					break;
				cout << "wrong operation. Retry" << endl;
				break;
			}
		}
	}
}
