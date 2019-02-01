#include <iostream>
#include <cstdlib>

using namespace std;

struct list
{
	int		data;
	list	*next;
};

list *getmem(int data)
{
	list *newmem = new list;
	newmem->data = data;
	newmem->next = NULL;
	return (newmem);
}

list *push_one(list *stack)
{
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	list *newmem = getmem(data);
	newmem->next = stack;
	return (newmem);
}

int pop_one(list **stack)
{
	if (*stack != NULL)
	{
		int returned = (*stack)->data;
		list *temp = *stack;
		*stack = (*stack)->next;
		delete temp;
		return (returned);
	}
	cout << "nothing to return from buffer. 0 returned" << endl;
	return (0);
}

void show_stack(list *stack)
{
	list *cur = stack;
	int i = 0;
	cout << "your stack: \n";
	while (cur != NULL)
	{
		cout << i++ << " " << (int)cur->data << endl;
		cur = cur->next;
	}
}

void freemem(list *stack)
{
	if (stack)
		freemem(stack->next);
	free(stack);
}

int main()
{
	char	buffer[11] = "smth";
	list	*stack = NULL;
	int		flag  = 0;
	while (buffer[0] != 4 && (flag = flag + 1))
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
				stack = push_one(stack);
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
				show_stack(stack);
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
	freemem(stack);
}
