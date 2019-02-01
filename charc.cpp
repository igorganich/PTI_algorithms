#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

char *getmem(int size)
{
	char *first = new char[size];
	return (first);
}

int custom_strlen(char *string)
{
	int i = 0;
	for (i = 0; string[i] != '\0'; i++)
		;
	return (i);			
}

char *custom_realloc(char *string, int size)
{
	char *newstring = getmem(size + 2);
	int i = -1;
	while(string[++i] != '\0')
		newstring[i] = string[i];
	delete[] string;
	return (newstring);
}

int custom_cmp(char *first, char *second)
{
	int i = 0;
	while (first[i] != '\0' && second[i] != '\0')
		i++;
	if (first[i] == second[i])
		return (0);
	return (1);
}

int check_cur (char *cur)
{
	int i = -1;
	while (cur[++i] != '\0')
	{
		if (cur[i] != ('a' + i))
			return (0);
	}
	return (1);
}

char *custom_strchr(char *string)
{
	int i;

	for (i = 0; string[i] > ' '; i++)
		if (string[i] == '.')
			break;
	return (string + i + 1);
}

void delete_one(char *string)
{
	while (*string != '\0')
	{
		string[0] = string[1];
		string++;
	}
	string[-1] = '\0';
}

void print_to_space(char *string)
{
	cout << "your word:\n";
	for (int i = 0; string[i] != ' ' && string[i] != '.'; i++)
		cout << string[i];
	cout << endl;
}

char *insert_tochka(char *string)
{
	int spaces = 0;
	int i;
	for (i = 0; string[i] != '\0'; i++)
		if (string[i] == ' ')
			spaces++;
	//cout << "spaces + u" << spaces + i << endl;
	char *newstr = getmem(i + spaces + 2);
	for (int l = 0, j = 0; string[l] != '\0'; l++)
	{
		if (string[l] == ' ')
		{
			newstr[l + j] = '.';
			j++;
		}
		newstr[l + j] = string[l];
		newstr[l + j + 1] = 0;
	}
	delete[] string;
	return (newstr);
}

int main()
{
	char	*string = getmem(1);
	string[0] = '\0';
	char	c[10] = "smth";
	int		size;
	char	*cur;

	size = 0;
	cout << "enter text by 1 symbol a-z" << endl;
	while (c[0] != '.')
	{
		int flag = 0;
		cin.getline(c, sizeof(c));
		if (c[1] != '\0' && (flag = 1))
			cout << "enter 1 symbol" << endl;
		if ((c[0] < 'a' || c[0] > 'z') && c[0] != ' ' && c[0] != '.' && (flag = 1))
			cout << "enter symbol a-z" << endl;
		if (flag == 0)
		{
			string = custom_realloc(string, ++size);
			string[size - 1] = c[0];
			string[size] = '\0';
			cout << string << endl;
		}
	}
	if (size != 1)
		cout << " your string\n" << string << endl;
	cur = string;
	while (*cur != '\0' && *cur != '.')
	{
		cur = custom_strchr(cur);
		int flag1 = 0;
		int flag2 = 1;
	//	cout << "cur is" <<cur << endl;
		for (int i = 0; cur[i] != ' ' && cur[i] != '.'; i++)
		{
			if (cur[i] != string[i])
				flag1 = 1;
			if (cur[i] != ('a' + i))
				flag2 = 0;
		}
//			if ((cur[i] != string[i] || cur[i] != ('a' + i)) && (flag = 1))
//				break ;
		if (flag1 == 1 && flag2 == 1)
		{
			print_to_space(cur);
			delete_one(cur);
	//		cout << "new str is" << string << endl;
		}
	}
	string = insert_tochka(string);
	if (size != 1)
		cout << string << endl;
	else
		cout << "empty!" << endl;
	cout << "memory is " << sizeof (char) * custom_strlen(string) << endl;
	delete[] string;
}
