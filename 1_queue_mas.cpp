#include <iostream>
#include <cstdlib>

using namespace std;

int *getmem(int size)
{
	int *newmem = new int[size];
	return (newmem);
}

int *custom_realloc_push(int *queue, int size, int new_item)
{
	int *newqueue = getmem(size);
	for (int i = 0; i < size - 1; i++)
		newqueue[i] = queue[i];
	newqueue[size - 1] = new_item;
	if (size != 1)
		delete[] queue;
	return (newqueue);
}

int *push_one(int *queue, int size)
{
	char buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	queue = custom_realloc_push(queue, size, atoi(buffer));
	return (queue);
}

int pop_one(int *queue, int size)
{
	if (size == 0)
	{
		cout << "nothing to pop. 0 returned" << endl;
		return (0);
	}
	int returned = queue[0];
	for (int i = 0; i < size - 1; i++)
		queue[i] = queue[i + 1];
	queue[size - 1] = returned;
	return (returned);
}

int *delete_one(int *queue, int size)
{
	if (size <= 0)
		return (queue);
	int *newqueue = getmem(size);
	for (int i = 0; i < size; i++)
		newqueue[i] = queue[i + 1];
	delete[] queue;
	return (newqueue);	
}

void show_queue(int *queue, int size)
{
	for (int i = 0; i < size; i++)
		cout << i << " - " << queue[i] << endl;
}

int main()
{
	char	buffer[11] = "smth";
	int		size = 0;
	int		*queue;
	int		flag  = 0;
	while (buffer[0] != 4 && (flag = flag + 1))
	{
		if (size < 1)
			size = 0;
		cout << "choose next operation or ctrl + D to end" << endl;
		cout << "1 - push item" << endl;
		cout << "2 - pop and operation plus for 2 elements in stack" << endl;
		cout << "3 - delete one element" << endl;
		cout << "4 - show current queue" << endl;
		cin.getline(buffer, 11);
		int choose = atoi(buffer);
		switch(choose)
		{
			case 1:
			{
				queue = push_one(queue, ++size);
				break;
			}
			case 2:
			{
				int a = pop_one(queue, size);
				int b = pop_one(queue, size);
				cout << "rezult is " << a + b << endl;
				break;
			}
			case 3:
			{
				queue = delete_one(queue, --size);
				break;
			}
			case 4:
			{
				show_queue(queue, size);
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
		delete[] queue;
}
