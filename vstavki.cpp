#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int best;
	int temp;
	int copies = 0;
	int compare = 0;
	int n;
	int *massiv = new int[n];// (int*)malloc(sizeof(int) * n);
	cin >> n;
	
//	for (int i = n - 1; i >= 0; i--)
//		massiv[n - i - 1] = i;
	for (int i = 0; i < n; i++)
		massiv[i] = rand();
	//cout << "not sorted massive" << endl;
	//for (int i = 0; i < 100; i++)
	//	cout << massiv[i] << endl;
	//cout << "~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < n - 1; i++, compare++)
	{
		best = i;
		copies++;
		for (int l = i + 1; l < n; l++, compare++)
			if (massiv[l] < massiv[best] && compare++)
				best = l;
		if (best == i && compare++)
			continue;
		temp = massiv[i];
		massiv[i] = massiv[best];
		massiv[best] = temp;
		copies+=3;
	}
	for (int i = 0; i < n; i++)
		cout << massiv[i] << endl;
	cout << copies << "     " << compare << endl;
	delete[] massiv;
	return (0);
}
