#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

struct	node
{
	int		data;
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

/*node	*create_new_node(node *parent1)
{
	node *newmem = new node;
	newmem->parent = parent1;
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	newmem->data = data;
}*/

node	*insert_new_node(node **first)
{
	node *newmem = new node;
	newmem->left = NULL;
	newmem->right = NULL;
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	newmem->data = data;
	cout << "enter key" << endl;
	cin.getline(buffer, 11);
	data = atoi(buffer);
	newmem->key = data;
	if (*first == NULL)
		*first = newmem;
	else
	{
		node *current = *first;
		while (1337)
		{
			if (current->key == newmem->key)
			{
				cout << "Error! Key already exists!" << endl;
				delete newmem;
				return (*first);
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
	return (*first);
}

node	*choose_another_node(node *current)
{
	node *temp;
	cout << "enter 1 to choose parent\n2 to choose left son\n3 to choose right son\n";
	int choose;
	char	buffer[11] = "smth";
	cin.getline(buffer, 11);
	choose = atoi(buffer);
	if (choose == 1)
		temp = current->parent;
	else if (choose == 2)
		temp = current->left;
	else if (choose == 3)
		temp = current->right;
	else
	{
		cout << "bad choose" << endl;
		return (current);
	}
	if (temp == NULL)
	{
		cout << "no node with " << choose << " argument" << endl;
		return (current);
	}
	return (temp);
}

void	change_current_node(node *current)
{
	char	buffer[11] = "smth";
	cout << "enter number" << endl;
	cin.getline(buffer, 11);
	int data = atoi(buffer);
	current->data = data;
}

node 	*find_node_with_number(node *first, int number)
{
	if (first)
	{
		if (first->data == number)
			return (first);
		node *returner = find_node_with_number(first->left, number);
		if (returner == NULL)
			returner = find_node_with_number(first->right, number);
		return (returner);
	}
	return (NULL);
}

void 	delete_tree(node *first)
{
	if (first)
	{
		delete_tree(first->left);
		delete_tree(first->right);
		delete (first);
	}
}

node	*get_most_left(node *first)
{
	if (first->left != NULL)
		return (get_most_left(first->left));
	return (first);
}

node	*get_most_right(node *first)
{
	if (first->right != NULL)
		return (get_most_right(first->right));
	return (first);
}

void	swap_with_parent(node *current, node *whatswap)
{
	if (current->parent->left == current)
		current->parent->left = whatswap;
	else
		current->parent->right = whatswap;
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

node	*max_node(node *a, node *b)
{
    return ((a->data > b->data) ? a : b);
}
 
node	*find_max_node(node *first)
{
    if ((first->left == NULL) && (first->right == NULL))
        return first;
    else
        if (first->left == NULL)
            return max_node(first, find_max_node(first->right));
        else
            if (first->right == NULL)
                return max_node(first, find_max_node(first->left));
            else
                return max_node(first,max_node(find_max_node(first->left), find_max_node(first->right)));
 
}

int		main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	node *first = NULL;
	node *current;
	int option = 0;
	while (option != 7)
	{
		SetConsoleTextAttribute(console, 15);
		if (first == NULL)
		{
			cout << "there is no tree now. Creating first node" << endl;
			insert_new_node(&first);
			current = first;
		}
		cout << "enter option:\n1-print current tree\n2-choose another node\n3-insert new node here\n4-change current node\n5-find node with number\n6-delete current node\n7-find max element and end program" << endl;
		char	buffer[11] = "smth";
		cin.getline(buffer, 11);
		option = atoi(buffer);
		switch (option)
		{
			case 1:
			{
				cout << "printing tree by values" << endl;
				print_tree(first, 0, current, 1);
				SetConsoleTextAttribute(console, 15);
				cout << "printing tree by keys" << endl;
				print_tree(first, 0, current, 2);
				break ;
			}
			case 2:
			{
				current = choose_another_node(current);
				break ;
			}
			case 3:
			{
				insert_new_node(&first);
				break ;
			}
			case 4:
			{
				change_current_node(current);
				break ;
			}
			case 5:
			{
				int number = 0;
				cout << "enter number" << endl;
				cin.getline(buffer, 11);
				number = atoi(buffer);
				node *returner = find_node_with_number(first, number);
				if (returner == NULL)
					cout << "no node " << endl;
				else
				{
					cout << "printing tree by values" << endl;
					print_tree(first, 0, returner, 1);
					SetConsoleTextAttribute(console, 15);
					cout << "printing tree by keys" << endl;
					print_tree(first, 0, returner, 2);
				}
				break ;
			}
			case 6:
			{
				first = delete_current_node(first, current);
				current = first;
				break ;
			}
			default:
			{
				if (option != 7)
					cout << "bad out" << endl;
				break ;
			}
		}
	}
	current = find_max_node(first);
	cout << "max node by value:" << endl;
	print_tree(first, 0, current, 1);
	current = get_most_right(first);
	cout << "max node by key:" << endl;
	print_tree(first, 0, current, 2);
	delete_tree(first);
}
