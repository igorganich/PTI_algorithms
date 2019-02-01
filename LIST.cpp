#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct list
{
	char	data;
	list	*next;
};

list	*getmem(char c)
{
	list *first = new list;
	first->data = c;
	first->next = NULL;
	return (first);
}

void outthis(list *first)
{
	list *cur = first;
	while (cur != NULL)
	{
		cout << cur->data;
		cur = cur->next;
	}
	cout << endl;
}

list *custom_strchr(list *first)
{
	list *cur = first;
	while (cur->data != '.' && cur->data != ' ')
		cur = cur->next;
	if (cur->data == '.')
		return (cur);
	return (cur->next);
}

void print_to_space(list *first)
{
	cout << "your word:\n";
	while (first->data != ' ' && first->data != '.')
	{
		cout << first->data;
		first = first->next;
	}
	cout << endl;
}

void delete_one(list *first, list *text)
{
	list *cur = first;
	while (cur->next != text)
		cur = cur->next;
	list *temp = cur->next;
	cur->next = cur->next->next;
	delete temp;
}

void insert_tochka(list *first)
{
	list *cur = first;
	while (cur->next != NULL)
	{
		if (cur->next->data == ' ')
		{
			list *temp = cur->next;
			cur->next = getmem('.');
			cur->next->next = temp;
			cur = cur->next;
		}
		cur = cur->next;
	}
}

void	freemem(list *disks)
{
	if (disks)
		freemem(disks->next);
	delete disks;
}

int main()
{
	list	*first;
	list	*text = getmem('.');
	first = text;
	char	c[10] = "smth";
	cout << "enter text by 1 symbol a-z" << endl;
	while (c[0] != '.')
	{
		int flag = 0;
		cin.getline(c, sizeof(c));
		if (c[1] != '\0' && (flag = 1))
			cout << "enter 1 symbol" << endl;
		if ((c[0] < 'a' || c[0] > 'z') && c[0] != ' ' && c[0] != '.' && (flag = 1))
			cout << "enter symbol a-z" << endl;
		if (c[0] == '.')
			break ;
		if (flag == 0)
		{
			text->next = getmem(c[0]);
			text = text->next;
			outthis(first->next);
		}
	}
	text->next = getmem('.');
	cout << "your string:\n";
	outthis(first->next);
	text = custom_strchr(first->next);
	while (text->data != '.')
	{
		int flag1 = 0;
		int flag2 = 1;
		list *cur1 = first->next;
		list *cur2 = text;
		char count = 0;
		while (cur2->data != ' ' && cur2->data != '.')
		{
			if (cur2->data != cur1->data)
				flag1 = 1;
			if (cur2->data != ('a' + count))
				flag2 = 0;
			cur2 = cur2->next;
			cur1 = cur1->next;
			count++;
		}
		if (flag1 == 1 && flag2 == 1)
		{
			list *temp2 = text->next;
			print_to_space(text);
			delete_one(first->next, text);
			text = temp2;
		}
		text = custom_strchr(text);
	}
	insert_tochka(first->next);
	outthis(first->next);
	freemem(first);
}
