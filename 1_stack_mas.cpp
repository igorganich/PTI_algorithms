#include <iostream>
#include <cstdlib>

using namespace std;

int *getmem(int size)
{
	int *newmem = new int[size];
	return (newmem);
}

int *custom_realloc_push(int *stack, int size, int new_item)
{
	int *newstack = getmem(size);
	for (int i = 1; i < size; i++)
		newstack[i] = stack[i - 1];
	newstack[0] = new_item;
	if (size != 1)
		delete[] stack;
	return (newstack);
}

int *push_one(int *stack, int size)
{
	char buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	stack = custom_realloc_push(stack, size, atoi(buffer));
	return (stack);
}

void show_stack(int *stack, int size)
{
	for (int i = 0; i < size; i++)
		cout << i << " - " << stack[i] << endl;
}

int *custom_realloc_pop(int *stack, int size)
{
	int *newstack = getmem(size);
	for (int i = 0; i < size; i++)
		newstack[i] = stack[i + 1];
	delete[] stack;
	return (newstack);
}

int pop_one(int **stack, int size)
{
	int returned = 0;
	if (size < 0)
		cout << "nothing to pop" << endl;
	else
	{
		returned = **stack;
		*stack = custom_realloc_pop(*stack, size);
	}
	return (returned);
}

int main()
{
	char	buffer[11] = "smth";
	int		size = 0;
	int		*stack;
	int		flag  = 0;
	while (buffer[0] != 4 && (flag = flag + 1))
	{
		if (size < 1)
			size = 0;
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
				stack = push_one(stack, ++size);
				break;
			}
			case 2:
			{
				int a = pop_one(&stack, --size);
				int b = pop_one(&stack, --size);
				cout << "rezult is " << a + b << endl;
				break;
			}
			case 3:
			{
				pop_one(&stack, --size);
				break;
			}
			case 4:
			{
				show_stack(stack, size);
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
	if (flag > 1)
		delete[] stack;
}
