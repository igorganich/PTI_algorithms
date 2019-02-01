#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct list
{
	double	data;
	list	*next;
};

list *getmem(int data)
{
	list *newmem = new list;
	newmem->data = data;
	newmem->next = NULL;
	return (newmem);
}

list *push_one(list *stack, double number)
{
	list *newmem = getmem(number);
	newmem->next = stack;
	return (newmem);
}

void operation_plus(list *stack)
{
	cout << "operation plus" << endl;
	stack->data = stack->data + stack->next->data;
	list *temp = stack->next;
	stack->next = stack->next->next;
	delete temp;
}

void operation_minus(list *stack)
{
	cout << "operation minus" << endl;
	stack->data = stack->data - stack->next->data;
	list *temp = stack->next;
	stack->next = stack->next->next;
	delete temp;
}

void operation_pow(list *stack)
{
	cout << "operation pow" << endl;
	stack->data = stack->data * stack->next->data;
	list *temp = stack->next;
	stack->next = stack->next->next;
	delete temp;
}

void operation_division(list *stack)
{
	cout << "operation div" << endl;
	stack->data = stack->data / stack->next->data;
	list *temp = stack->next;
	stack->next = stack->next->next;
	delete temp;
}

void show_stack(list *stack)
{
	list *cur = stack;
	int i = 0;
	cout << "your stack: \n";
	while (cur != NULL)
	{
		cout << i++ << " " << cur->data << endl;
		cur = cur->next;
	}
}

int main()
{
	char	buffer[100];
	char	cur = 'A';
	list	*stack = NULL;
	cout << "enter expression" << endl;
	cin.getline(buffer, 100);
	for (int i = 0; i < strlen(buffer); i++)
		if (buffer[i] == cur + 1)
			cur++;
	double *mas = new double[(int)(cur - 'A' + 1)];
	char c = 'A';
	while (c <= cur)
	{
		cout << "enter number for " << c << endl;
		char	buffer[20];
		cin.getline(buffer, 20);
		mas[(int)(c - 'A')] = atof(buffer);
		c = c + 1;
	}
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			stack = push_one(stack, mas[(int)(buffer[i] - 'A')]);
		else if (buffer[i] == '+')
			operation_plus(stack);
		else if (buffer[i] == '-')
			operation_minus(stack);
		else if (buffer[i] == '*')
			operation_pow(stack);
		else if (buffer[i] == '/')
			operation_division(stack);
		show_stack(stack);
	}
	cout << "rezult is " << stack->data << endl;
	delete stack;
	delete[] mas;
}
