#include <iostream>
#include <cstdlib>
 
using namespace std;
 
struct List
{
	int disk;
	List *next;
};

int		count = 0;

void	show(List **disks)
{
	List *currents[3];
	for (int i = 0; i < 3; i++)
		currents[i] = disks[i];
	while (currents[0] || currents[1] || currents[2])
	{
		for (int i = 0; i < 3; i++)
		{
			if (currents[i] != NULL)
				cout << currents[i]->disk << "        ";
			else 
				cout << "-" << "        ";
		}
		for (int i = 0; i < 3; i++)
			if (currents[i])
				currents[i] = currents[i]->next;
		cout << endl;
	}
}

void	throw_disk(int from, int to, List **disks)
{
	List *tempfrom = disks[from];
	disks[from] = disks[from]->next;
	tempfrom->next = disks[to];
	disks[to] = tempfrom;
}

	hanoi_towers(int quantity, int from, int to, int buf_peg, List **disks)   //quantity-????? ?????, from-????????? ????????? ?????(1-3),to-???????? ????????? ?????(1-3)
{                                                         //buf_peg - ????????????? ???????(1-3)
        if (quantity != 0)
        {
        		count++;
                hanoi_towers(quantity-1, from, buf_peg, to, disks);
                
                show(disks);
                cout << from << " -> " << to << endl;
                
                throw_disk(from, to, disks);
                hanoi_towers(quantity-1, buf_peg, to, from, disks);
        }
}

List	*get_new_list(int plate, List **disks)
{
	List *disk = (List*)malloc(sizeof(List));
	disk->disk = plate;
	disk->next = *disks;
	*disks = disk;
}

List	**get_towers(int plate)
{
	List *current;
	List **disks = (List**)malloc(sizeof(List*) * 3);
	disks[0] = (List*)malloc(sizeof(List));
	disks[0]->disk = plate;
	disks[0]->next = NULL;
	cout << "smth" << endl;
	current = disks[0];
	for(int i = plate - 1; i > 0; i--)
		get_new_list(i, &(disks[0]));
	disks[1] = NULL;
	disks[2] = NULL;
	return (disks);
}

void	freemem(List *disks)
{
	if (disks)
		freemem(disks->next);
	free(disks);
}

int		main()
{
    int start_peg, destination_peg, buffer_peg, plate_quantity;

	List **disks;
    cout << "count" << endl;
    cin  >> plate_quantity;
	disks = get_towers(plate_quantity);
    hanoi_towers(plate_quantity, 0, 2, 1, disks);
    show(disks);
    cout << count << endl;
    freemem(disks[2]);
    free(disks);
	return 0;
}
