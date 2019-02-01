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

list *push_one(list *queue)
{
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	list *newmem = getmem(data);
	if (queue == NULL)
		return (newmem);
	list *cur = queue;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newmem;
	return (queue);
}

int pop_one(list **queue)
{
	if (*queue != NULL)
	{
		int returned = (*queue)->data;
		list *temp = *queue;
		*queue = (*queue)->next;
		delete temp;
		return (returned);
	}
	cout << "nothing to return from buffer. 0 returned" << endl;
	return (0);
}

void show_queue(list *queue)
{
	list *cur = queue;
	int i = 0;
	cout << "your queue: \n";
	while (cur != NULL)
	{
		cout << i++ << " " << (int)cur->data << endl;
		cur = cur->next;
	}
}

void freemem(list *queue)
{
	if (queue)
		freemem(queue->next);
	free(queue);
}

int main()
{
	char	buffer[11] = "smth";
	list	*queue = NULL;
	while (buffer[0] != 4)
	{
		cout << "choose next operation or ctrl + D to end" << endl;
		cout << "1 - push item" << endl;
		cout << "2 - pop and operation plus for 2 elements in queue" << endl;
		cout << "3 - delete one element" << endl;
		cout << "4 - show current queue" << endl;
		cin.getline(buffer, 11);
		int choose = atoi(buffer);
		switch(choose)
		{
			case 1:
			{
				queue = push_one(queue);
				break;
			}
			case 2:
			{
				int a = pop_one(&queue);
				int b = pop_one(&queue);
				cout << "rezult is " << a + b << endl;
				break;
			}
			case 3:
			{
				pop_one(&queue);
				break;
			}
			case 4:
			{
				show_queue(queue);
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
	freemem(queue);
}
