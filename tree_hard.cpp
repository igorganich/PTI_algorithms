#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct	node
{
	char	*data;
	int		key;
	node	*parent;
	node	*left;
	node	*right;
};

void	print_tree(node *p, int level, node *current, int flag)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    if(p)
    {
        print_tree(p->right,level + 1, current, flag);
        for(int i = 0;i< level;i++) 
			cout<<"   ";
		if (p == current)
			SetConsoleTextAttribute(console, FOREGROUND_RED);
		if (flag == 1)
        	cout << p->data << endl;
        if (flag == 2)
        	cout << p->key << endl;
        print_tree(p->left,level + 1, current, flag);
    }
}

node	*insert_new_node(node **first, char *buff)
{
	node *newmem = new node;
	node *current;
	newmem->left = NULL;
	newmem->right = NULL;
	char	buffer[11] = "smth";
	newmem->data = strdup(buff);
	cout << "enter key" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	newmem->key = data;
	if (*first == NULL)
		*first = newmem;
	else
	{
		current = *first;
		while (1337)
		{
			if (current->key == newmem->key)
			{
				cout << "Error! Key already exists!" << endl;
				free (newmem->data);
				delete newmem;
				return (insert_new_node(first, buff));
			}
			if (current->key > newmem->key)
			{
				if (current->left == NULL)
				{
					current->left = newmem;
					newmem->parent = current;
					break ;
				}
				else
				{
					current = current->left;
					continue;
				}
			}
			if (current->key < newmem->key)
			{
				if (current->right == NULL)
				{
					current->right = newmem;
					newmem->parent = current;
					break ;
				}
				else
				{
					current = current->right;
					continue;
				}
			}
		}
	}
	return (newmem);
}

void 	delete_tree(node *first)
{
	if (first)
	{
		delete_tree(first->left);
		delete_tree(first->right);
		free (first->data);
		delete (first);
	}
}

node	*get_most_left(node *first)
{
	if (first->left != NULL)
		return (get_most_left(first->left));
	return (first);
	
}

void	swap_with_parent(node *current, node *whatswap)
{
	if (current->parent->left == current)
		current->parent->left = whatswap;
	else
		current->parent->right = whatswap;
	if (whatswap != NULL)
		whatswap->parent = current->parent;
	delete current;
}

node	*delete_current_node(node *first, node *current)
{
	node *temp;
	if (first == current)
	{
		temp = first;
		if (first->left == NULL && first->right == NULL)
			first = NULL;
		else if (first->left == NULL && first->right != NULL)
			first = first->right;
		else if (first->right == NULL && first->left != NULL)
			first = first->left;
		else if (first->right != NULL && first->left != NULL)
		{
			node *future = get_most_left(first->right);
			future->left = first->left;
			future->right = first->right;
			if (future == first->right)
				future->right = NULL;
			else
				future->parent->left = NULL;
			first = future;
		}
		if (first != NULL)
		{
			first->parent = NULL;
			if (first->left)
				first->left->parent = first;
			if (first->right)
				first->right->parent = first;
		}
		delete temp;
	}
	else
	{
		if (current->left == NULL && current->right == NULL)
			swap_with_parent(current, NULL);
		else if (current->left != NULL && current->right == NULL)
		{
			swap_with_parent(current, current->left);	
		}
		else if (current->left == NULL && current->right != NULL)
		{
			swap_with_parent(current, current->right);
		}
		else if (current->left != NULL && current->right != NULL)
		{
			node *future = get_most_left(current->right);
			future->left = current->left;
			future->right = current->right;
			if (future == current->right)
				future->right = NULL;
			else
				future->parent->left = NULL;
			swap_with_parent(current, future);
		}
	}
	return (first);
}

int		freewords(node **first ,node *current, char c)
{
	static int count = 0;
	node *temp;
	if (current)
	{
		if ((current->data)[0] == c && (count = count + 1))
		{
			temp = current->parent;
			*first = delete_current_node(*first, current);
			current = temp;
		}	
		freewords(first, current->left, c);
		freewords(first, current->right, c);
	}
	return (count);
}


int		main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	node *first = NULL;
	node *current;
	ifstream file("words.txt");
	char buff[50] = "\0";
	file >> buff;
	while (strlen(buff) > 0)
	{
		SetConsoleTextAttribute(console, 15);
		current = insert_new_node(&first, buff);
		buff[0] = '\0';
		file >> buff;
		cout << "printing tree by values" << endl;
		print_tree(first, 0, current, 1);
		cout << "printing tree by keys"<< endl;
		print_tree(first, 0, current, 2);
	}
	SetConsoleTextAttribute(console, 15);
	cout << "enter char for deleting words" << endl;
	char buffer[11];	
	cin.getline(buffer, 11);
	char c = buffer[0];
	int count = freewords(&first, first, c);
	cout << "number of deleted words: " << count << endl;
	cout << "printing tree by values" << endl;
	print_tree(first, 0, current, 1);
	SetConsoleTextAttribute(console, 15);
	cout << "printing tree by keys"<< endl;
	print_tree(first, 0, current, 2);
	SetConsoleTextAttribute(console, 15);
	delete_tree(first);
}
