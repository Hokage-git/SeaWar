#include <iostream> 
#include <ctime>
#include "Header.h"

using namespace std;

void draw(int n)
{
	if (n == 0) { cout << " "; } //ÏÓÑÒÎÒÀ
	if (n == -1) { cout << "-"; } //ÑÒÅÍÀ (ÃÎÐÈÇÎÍÒÀËÜ)
	if (n == -2) { cout << "|"; } //ÑÒÅÍÀ (ÂÅÐÒÈÊÀËÜ)
	if (n == -3) { cout << "+"; } //ÑÒÅÍÀ (ÓÃÎË)
	if (n == 1) { cout << "1"; } //ÊÎÐÀÁËÜ (1 ÏÀËÓÁÀ)
	if (n == 2) { cout << "2"; } //ÊÎÐÀÁËÜ (2 ÏÀËÓÁÛ)
	if (n == 3) { cout << "3"; } //ÊÎÐÀÁËÜ (3 ÏÀËÓÁÛ)
	if (n == 4) { cout << "4"; } //ÊÎÐÀÁËÜ (4 ÏÀËÓÁÛ)
	if (n == 5) { cout << " "; } //ÎÁËÀÑÒÜ ÂÎÊÐÓÃ ÊÎÐÀÁËß
	if (n == 6) { cout << " "; } //ÊÎÐÀÁËÜ (1 ÏÀËÓÁÀ)(ÂÐÀÃ)
	if (n == 7) { cout << " "; } //ÊÎÐÀÁËÜ (2 ÏÀËÓÁÛ)(ÂÐÀÃ)
	if (n == 8) { cout << " "; } //ÊÎÐÀÁËÜ (3 ÏÀËÓÁÛ)(ÂÐÀÃ)
	if (n == 9) { cout << " "; } //ÊÎÐÀÁËÜ (4 ÏÀËÓÁÛ)(ÂÐÀÃ)
	if (n == 10) { cout << "#"; } //ÏÎÏÀË
	if (n == 11) { cout << "*"; } //ÓÁÈÒ
	if (n == 12) { cout << "@"; } //ÌÅÑÒÎ ÂÛÑÒÐÅËÀ
}

void interfaceA(int(&a)[12][12])
{
	int x, y;
	cout << "   ";
	for (x = 1; x <= 10; x++)
	{
		cout << x;
	}
	cout << endl;
	for (x = 0; x < 12; x++)
	{
		if (x == 0 || x == 12 || x == 11) { cout << "  "; }
		else if (x == 10) { cout << x; }
		else { cout << " " << x; }
		for (y = 0; y < 12; y++)

			for (y = 0; y < 12; y++)
			{
				draw(a[x][y]);
			}
		if (x == 12) {}
		else { cout << endl; }
	}
}
void interfaceB(int(&a)[12][12])
{
	int x, y;

	for (x = 0; x < 12; x++)
	{
		if (x == 0 || x == 12 || x == 11) { cout << "  "; }
		else if (x == 10) { cout << x; }
		else { cout << " " << x; }
		for (y = 0; y < 12; y++)
		{
			draw(a[x][y]);
		}
		if (x < 12) { cout << endl; }
	}
}

void wall(int(&map)[12][12], int(&emap)[12][12]) {
	int x = 0;
	int	y = 0;

	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 12; y++)
		{
			map[x][y] = 0;
			if ((x == 0) || (x == 11)) { map[x][y] -= 1; }
			if ((y == 0) || (y == 11)) { map[x][y] -= 2; }
		}
	}

	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 12; y++)
		{
			emap[x][y] = 0;
			if ((x == 0) || (x == 11)) { emap[x][y] -= 1; }
			if ((y == 0) || (y == 11)) { emap[x][y] -= 2; }
		}
	}
}

void f_deck(int(&map)[12][12]){
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;
	if (r == 0)
	{
		x = 1 + rand() % 7;
		y = 1 + rand() % 10;
		map[y][x] = 4;
		map[y][x + 1] = 4;
		map[y][x + 2] = 4;
		map[y][x + 3] = 4;


		if (map[y][x - 1] == -1 || map[y][x - 1] == -2) {}
		else { map[y][x - 1] = 5; }
		if (map[y][x + 4] == -1 || map[y][x + 4] == -2) {}
		else { map[y][x + 4] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (map[y + 1][x + q] == -1 || map[y + 1][x + q] == -2 || map[y + 1][x + q] == -3) {}
			else { map[y + 1][x + q] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (map[y - 1][x + q] == -1 || map[y - 1][x + q] == -2 || map[y - 1][x + q] == -3) {}
			else { map[y - 1][x + q] = 5; }
		}
		system("cls");
		interfaceA(map);
	}
	if (r == 1)
	{
		x = 1 + rand() % 10;
		y = 1 + rand() % 7;
		map[y][x] = 4;
		map[y + 1][x] = 4;
		map[y + 2][x] = 4;
		map[y + 3][x] = 4;

		if (map[y - 1][x] == -1 || map[y - 1][x] == -2) {}
		else { map[y - 1][x] = 5; }
		if (map[y + 4][x] == -1 || map[y + 4][x] == -2) {}
		else { map[y + 4][x] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (map[y + q][x + 1] == -1 || map[y + q][x + 1] == -2 || map[y + q][x + 1] == -3) {}
			else { map[y + q][x + 1] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (map[y + q][x - 1] == -1 || map[y + q][x - 1] == -2 || map[y + q][x - 1] == -3) {}
			else { map[y + q][x - 1] = 5; }
		}
		system("cls");
		interfaceA(map);
	}
	if (r == 2)
	{
		x = 4 + rand() % 7;
		y = 1 + rand() % 10;
		map[y][x] = 4;
		map[y][x - 1] = 4;
		map[y][x - 2] = 4;
		map[y][x - 3] = 4;

		if (map[y][x - 4] == -1 || map[y][x - 4] == -2) {}
		else { map[y][x - 4] = 5; }
		if (map[y][x + 1] == -1 || map[y][x + 1] == -2) {}
		else { map[y][x + 1] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (map[y - 1][x - q] == -1 || map[y - 1][x - q] == -2 || map[y - 1][x - q] == -3) {}
			else { map[y - 1][x - q] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (map[y + 1][x - q] == -1 || map[y + 1][x - q] == -2 || map[y + 1][x - q] == -3) {}
			else { map[y + 1][x - q] = 5; }
		}
		system("cls");
		interfaceA(map);
	}
	if (r == 3)
	{
		x = 1 + rand() % 10;
		y = 4 + rand() % 7;
		map[y][x] = 4;
		map[y - 1][x] = 4;
		map[y - 2][x] = 4;
		map[y - 3][x] = 4;

		if (map[y + 1][x] == -1 || map[y + 1][x] == -2) {}
		else { map[y + 1][x] = 5; }
		if (map[y - 4][x] == -1 || map[y - 4][x] == -2) {}
		else { map[y - 4][x] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (map[y - q][x - 1] == -1 || map[y - q][x - 1] == -2 || map[y - q][x - 1] == -3) {}
			else { map[y - q][x - 1] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (map[y - q][x + 1] == -1 || map[y - q][x + 1] == -2 || map[y - q][x + 1] == -3) {}
			else { map[y - q][x + 1] = 5; }
		}
		system("cls");
		interfaceA(map);
	}
}


void tree_deck(int(&map)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 2; i++)
	{
		r = rand() % 4;

		if (r == 0)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((map[y][x] == 0) && (map[y][x + 1] == 0)) && (map[y][x + 2] == 0));

			} while (!z);
			map[y][x] = 3;
			map[y][x + 1] = 3;
			map[y][x + 2] = 3;

			if (map[y][x - 1] == -1 || map[y][x - 1] == -2) {}
			else { map[y][x - 1] = 5; }
			if (map[y][x + 3] == -1 || map[y][x + 3] == -2) {}
			else { map[y][x + 3] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (map[y + 1][x + q] == -1 || map[y + 1][x + q] == -2 || map[y + 1][x + q] == -3) {}
				else { map[y + 1][x + q] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (map[y - 1][x + q] == -1 || map[y - 1][x + q] == -2 || map[y - 1][x + q] == -3) {}
				else { map[y - 1][x + q] = 5; }
			}


			system("cls");
			interfaceA(map);

		}
		if (r == 1)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((map[y][x] == 0) && (map[y + 1][x] == 0)) && (map[y + 2][x] == 0));
			} while (!z);
			map[y][x] = 3;
			map[y + 1][x] = 3;
			map[y + 2][x] = 3;

			if (map[y - 1][x] == -1 || map[y - 1][x] == -2) {}
			else { map[y - 1][x] = 5; }
			if (map[y + 3][x] == -1 || map[y + 3][x] == -2) {}
			else { map[y + 3][x] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (map[y + q][x + 1] == -1 || map[y + q][x + 1] == -2 || map[y + q][x + 1] == -3) {}
				else { map[y + q][x + 1] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (map[y + q][x - 1] == -1 || map[y + q][x - 1] == -2 || map[y + q][x - 1] == -3) {}
				else { map[y + q][x - 1] = 5; }
			}
			system("cls");
			interfaceA(map);
		}
		if (r == 2)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((map[y][x] == 0) && (map[y][x - 1] == 0)) && (map[y][x - 2] == 0));
			} while (!z);
			map[y][x] = 3;
			map[y][x - 1] = 3;
			map[y][x - 2] = 3;

			if (map[y][x - 3] == -1 || map[y][x - 3] == -2) {}
			else { map[y][x - 3] = 5; }
			if (map[y][x + 1] == -1 || map[y][x + 1] == -2) {}
			else { map[y][x + 1] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (map[y - 1][x - q] == -1 || map[y - 1][x - q] == -2 || map[y - 1][x - q] == -3) {}
				else { map[y - 1][x - q] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (map[y + 1][x - q] == -1 || map[y + 1][x - q] == -2 || map[y + 1][x - q] == -3) {}
				else { map[y + 1][x - q] = 5; }
			}
			system("cls");
			interfaceA(map);

		}
		if (r == 3)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((map[y][x] == 0) && (map[y - 1][x] == 0)) && (map[y - 2][x] == 0));
			} while (!z);
			map[y][x] = 3;
			map[y - 1][x] = 3;
			map[y - 2][x] = 3;

			if (map[y + 1][x] == -1 || map[y + 1][x] == -2) {}
			else { map[y + 1][x] = 5; }
			if (map[y - 3][x] == -1 || map[y - 3][x] == -2) {}
			else { map[y - 3][x] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (map[y - q][x - 1] == -1 || map[y - q][x - 1] == -2 || map[y - q][x - 1] == -3) {}
				else { map[y - q][x - 1] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (map[y - q][x + 1] == -1 || map[y - q][x + 1] == -2 || map[y - q][x + 1] == -3) {}
				else { map[y - q][x + 1] = 5; }
			}
			system("cls");
			interfaceA(map);
		}

	}
}

void two_deck(int(&map)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 3; i++)
	{

		r = rand() % 4;

		if (r == 0)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((map[y][x] == 0) && (map[y][x + 1] == 0));
			} while (!z);
			map[y][x] = 2;
			map[y][x + 1] = 2;

			if (map[y][x - 1] == -1 || map[y][x - 1] == -2) {}
			else { map[y][x - 1] = 5; }
			if (map[y][x + 2] == -1 || map[y][x + 2] == -2) {}
			else { map[y][x + 2] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (map[y + 1][x + q] == -1 || map[y + 1][x + q] == -2 || map[y + 1][x + q] == -3) {}
				else { map[y + 1][x + q] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (map[y - 1][x + q] == -1 || map[y - 1][x + q] == -2 || map[y - 1][x + q] == -3) {}
				else { map[y - 1][x + q] = 5; }
			}


			system("cls");
			interfaceA(map);
		}
		if (r == 1)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((map[y][x] == 0) && (map[y + 1][x] == 0));
			} while (!z);
			map[y][x] = 2;
			map[y + 1][x] = 2;

			if (map[y - 1][x] == -1 || map[y - 1][x] == -2) {}
			else { map[y - 1][x] = 5; }
			if (map[y + 2][x] == -1 || map[y + 2][x] == -2) {}
			else { map[y + 2][x] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (map[y + q][x + 1] == -1 || map[y + q][x + 1] == -2 || map[y + q][x + 1] == -3) {}
				else { map[y + q][x + 1] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (map[y + q][x - 1] == -1 || map[y + q][x - 1] == -2 || map[y + q][x - 1] == -3) {}
				else { map[y + q][x - 1] = 5; }
			}
			system("cls");
			interfaceA(map);
		}
		if (r == 2)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((map[y][x] == 0) && (map[y][x - 1] == 0));
			} while (!z);
			map[y][x] = 2;
			map[y][x - 1] = 2;

			if (map[y][x - 2] == -1 || map[y][x - 2] == -2) {}
			else { map[y][x - 2] = 5; }
			if (map[y][x + 1] == -1 || map[y][x + 1] == -2) {}
			else { map[y][x + 1] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (map[y - 1][x - q] == -1 || map[y - 1][x - q] == -2 || map[y - 1][x - q] == -3) {}
				else { map[y - 1][x - q] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (map[y + 1][x - q] == -1 || map[y + 1][x - q] == -2 || map[y + 1][x - q] == -3) {}
				else { map[y + 1][x - q] = 5; }
			}
			system("cls");
			interfaceA(map);

		}
		if (r == 3)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((map[y][x] == 0) && (map[y - 1][x] == 0));
			} while (!z);
			map[y][x] = 2;
			map[y - 1][x] = 2;

			if (map[y + 1][x] == -1 || map[y + 1][x] == -2) {}
			else { map[y + 1][x] = 5; }
			if (map[y - 2][x] == -1 || map[y - 2][x] == -2) {}
			else { map[y - 2][x] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (map[y - q][x - 1] == -1 || map[y - q][x - 1] == -2 || map[y - q][x - 1] == -3) {}
				else { map[y - q][x - 1] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (map[y - q][x + 1] == -1 || map[y - q][x + 1] == -2 || map[y - q][x + 1] == -3) {}
				else { map[y - q][x + 1] = 5; }
			}
			system("cls");
			interfaceA(map);

		}
	}
}

void one_deck(int(&map)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 4; i++)
	{
		do
		{
			x = 1 + rand() % 10;
			y = 1 + rand() % 10;
			z = (map[y][x] == 0);
		} while (!z);
		map[y][x] = 1;

		if (map[y][x - 1] == -1 || map[y][x - 1] == -2) {}
		else { map[y][x - 1] = 5; }
		if (map[y][x + 1] == -1 || map[y][x + 1] == -2) {}
		else { map[y][x + 1] = 5; }

		for (q = -1; q <= 1; q++)
		{
			if (map[y + 1][x + q] == -1 || map[y + 1][x + q] == -2 || map[y + 1][x + q] == -3) {}
			else { map[y + 1][x + q] = 5; }
		}
		for (q = -1; q <= 1; q++)
		{
			if (map[y - 1][x + q] == -1 || map[y - 1][x + q] == -2 || map[y - 1][x + q] == -3) {}
			else { map[y - 1][x + q] = 5; }
		}


		system("cls");
		interfaceA(map);
	}
	system("cls");
	interfaceA(map);
}

void ef_deck(int(&emap)[12][12]) {
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	r = rand() % 4;
	if (r == 0)
	{
		x = 1 + rand() % 7;
		y = 1 + rand() % 10;
		emap[y][x] = 9;
		emap[y][x + 1] = 9;
		emap[y][x + 2] = 9;
		emap[y][x + 3] = 9;


		if (emap[y][x - 1] == -1 || emap[y][x - 1] == -2) {}
		else { emap[y][x - 1] = 5; }
		if (emap[y][x + 4] == -1 || emap[y][x + 4] == -2) {}
		else { emap[y][x + 4] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (emap[y + 1][x + q] == -1 || emap[y + 1][x + q] == -2 || emap[y + 1][x + q] == -3) {}
			else { emap[y + 1][x + q] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (emap[y - 1][x + q] == -1 || emap[y - 1][x + q] == -2 || emap[y - 1][x + q] == -3) {}
			else { emap[y - 1][x + q] = 5; }
		}
		system("cls");
		interfaceB(emap);
	}
	if (r == 1)
	{
		x = 1 + rand() % 10;
		y = 1 + rand() % 7;
		emap[y][x] = 9;
		emap[y + 1][x] = 9;
		emap[y + 2][x] = 9;
		emap[y + 3][x] = 9;

		if (emap[y - 1][x] == -1 || emap[y - 1][x] == -2) {}
		else { emap[y - 1][x] = 5; }
		if (emap[y + 4][x] == -1 || emap[y + 4][x] == -2) {}
		else { emap[y + 4][x] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (emap[y + q][x + 1] == -1 || emap[y + q][x + 1] == -2 || emap[y + q][x + 1] == -3) {}
			else { emap[y + q][x + 1] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (emap[y + q][x - 1] == -1 || emap[y + q][x - 1] == -2 || emap[y + q][x - 1] == -3) {}
			else { emap[y + q][x - 1] = 5; }
		}
		system("cls");
		interfaceB(emap);
	}
	if (r == 2)
	{
		x = 4 + rand() % 7;
		y = 1 + rand() % 10;
		emap[y][x] = 9;
		emap[y][x - 1] = 9;
		emap[y][x - 2] = 9;
		emap[y][x - 3] = 9;

		if (emap[y][x - 4] == -1 || emap[y][x - 4] == -2) {}
		else { emap[y][x - 4] = 5; }
		if (emap[y][x + 1] == -1 || emap[y][x + 1] == -2) {}
		else { emap[y][x + 1] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (emap[y - 1][x - q] == -1 || emap[y - 1][x - q] == -2 || emap[y - 1][x - q] == -3) {}
			else { emap[y - 1][x - q] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (emap[y + 1][x - q] == -1 || emap[y + 1][x - q] == -2 || emap[y + 1][x - q] == -3) {}
			else { emap[y + 1][x - q] = 5; }
		}
		system("cls");
		interfaceB(emap);
	}
	if (r == 3)
	{
		x = 1 + rand() % 10;
		y = 4 + rand() % 7;
		emap[y][x] = 9;
		emap[y - 1][x] = 9;
		emap[y - 2][x] = 9;
		emap[y - 3][x] = 9;

		if (emap[y + 1][x] == -1 || emap[y + 1][x] == -2) {}
		else { emap[y + 1][x] = 5; }
		if (emap[y - 4][x] == -1 || emap[y - 4][x] == -2) {}
		else { emap[y - 4][x] = 5; }

		for (q = -1; q <= 4; q++)
		{
			if (emap[y - q][x - 1] == -1 || emap[y - q][x - 1] == -2 || emap[y - q][x - 1] == -3) {}
			else { emap[y - q][x - 1] = 5; }
		}
		for (q = -1; q <= 4; q++)
		{
			if (emap[y - q][x + 1] == -1 || emap[y - q][x + 1] == -2 || emap[y - q][x + 1] == -3) {}
			else { emap[y - q][x + 1] = 5; }
		}
		system("cls");
		interfaceB(emap);
	}
}

void etree_deck(int(&emap)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 2; i++)
	{
		r = rand() % 4;

		if (r == 0)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((emap[y][x] == 0) && (emap[y][x + 1] == 0)) && (emap[y][x + 2] == 0));

			} while (!z);
			emap[y][x] = 8;
			emap[y][x + 1] = 8;
			emap[y][x + 2] = 8;

			if (emap[y][x - 1] == -1 || emap[y][x - 1] == -2) {}
			else { emap[y][x - 1] = 5; }
			if (emap[y][x + 3] == -1 || emap[y][x + 3] == -2) {}
			else { emap[y][x + 3] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (emap[y + 1][x + q] == -1 || emap[y + 1][x + q] == -2 || emap[y + 1][x + q] == -3) {}
				else { emap[y + 1][x + q] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (emap[y - 1][x + q] == -1 || emap[y - 1][x + q] == -2 || emap[y - 1][x + q] == -3) {}
				else { emap[y - 1][x + q] = 5; }
			}


			system("cls");
			interfaceB(emap);

		}
		if (r == 1)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((emap[y][x] == 0) && (emap[y + 1][x] == 0)) && (emap[y + 2][x] == 0));
			} while (!z);
			emap[y][x] = 8;
			emap[y + 1][x] = 8;
			emap[y + 2][x] = 8;

			if (emap[y - 1][x] == -1 || emap[y - 1][x] == -2) {}
			else { emap[y - 1][x] = 5; }
			if (emap[y + 3][x] == -1 || emap[y + 3][x] == -2) {}
			else { emap[y + 3][x] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (emap[y + q][x + 1] == -1 || emap[y + q][x + 1] == -2 || emap[y + q][x + 1] == -3) {}
				else { emap[y + q][x + 1] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (emap[y + q][x - 1] == -1 || emap[y + q][x - 1] == -2 || emap[y + q][x - 1] == -3) {}
				else { emap[y + q][x - 1] = 5; }
			}
			system("cls");
			interfaceB(emap);
		}
		if (r == 2)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((emap[y][x] == 0) && (emap[y][x - 1] == 0)) && (emap[y][x - 2] == 0));
			} while (!z);
			emap[y][x] = 8;
			emap[y][x - 1] = 8;
			emap[y][x - 2] = 8;

			if (emap[y][x - 3] == -1 || emap[y][x - 3] == -2) {}
			else { emap[y][x - 3] = 5; }
			if (emap[y][x + 1] == -1 || emap[y][x + 1] == -2) {}
			else { emap[y][x + 1] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (emap[y - 1][x - q] == -1 || emap[y - 1][x - q] == -2 || emap[y - 1][x - q] == -3) {}
				else { emap[y - 1][x - q] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (emap[y + 1][x - q] == -1 || emap[y + 1][x - q] == -2 || emap[y + 1][x - q] == -3) {}
				else { emap[y + 1][x - q] = 5; }
			}
			system("cls");
			interfaceB(emap);

		}
		if (r == 3)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = (((emap[y][x] == 0) && (emap[y - 1][x] == 0)) && (emap[y - 2][x] == 0));
			} while (!z);
			emap[y][x] = 8;
			emap[y - 1][x] = 8;
			emap[y - 2][x] = 8;

			if (emap[y + 1][x] == -1 || emap[y + 1][x] == -2) {}
			else { emap[y + 1][x] = 5; }
			if (emap[y - 3][x] == -1 || emap[y - 3][x] == -2) {}
			else { emap[y - 3][x] = 5; }

			for (q = -1; q <= 3; q++)
			{
				if (emap[y - q][x - 1] == -1 || emap[y - q][x - 1] == -2 || emap[y - q][x - 1] == -3) {}
				else { emap[y - q][x - 1] = 5; }
			}
			for (q = -1; q <= 3; q++)
			{
				if (emap[y - q][x + 1] == -1 || emap[y - q][x + 1] == -2 || emap[y - q][x + 1] == -3) {}
				else { emap[y - q][x + 1] = 5; }
			}
			system("cls");
			interfaceB(emap);
		}

	}
}

void etwo_deck(int(&emap)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 3; i++)
	{

		r = rand() % 4;

		if (r == 0)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((emap[y][x] == 0) && (emap[y][x + 1] == 0));
			} while (!z);
			emap[y][x] = 7;
			emap[y][x + 1] = 7;

			if (emap[y][x - 1] == -1 || emap[y][x - 1] == -2) {}
			else { emap[y][x - 1] = 5; }
			if (emap[y][x + 2] == -1 || emap[y][x + 2] == -2) {}
			else { emap[y][x + 2] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (emap[y + 1][x + q] == -1 || emap[y + 1][x + q] == -2 || emap[y + 1][x + q] == -3) {}
				else { emap[y + 1][x + q] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (emap[y - 1][x + q] == -1 || emap[y - 1][x + q] == -2 || emap[y - 1][x + q] == -3) {}
				else { emap[y - 1][x + q] = 5; }
			}


			system("cls");
			interfaceB(emap);
		}
		if (r == 1)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((emap[y][x] == 0) && (emap[y + 1][x] == 0));
			} while (!z);
			emap[y][x] = 7;
			emap[y + 1][x] = 7;

			if (emap[y - 1][x] == -1 || emap[y - 1][x] == -2) {}
			else { emap[y - 1][x] = 5; }
			if (emap[y + 2][x] == -1 || emap[y + 2][x] == -2) {}
			else { emap[y + 2][x] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (emap[y + q][x + 1] == -1 || emap[y + q][x + 1] == -2 || emap[y + q][x + 1] == -3) {}
				else { emap[y + q][x + 1] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (emap[y + q][x - 1] == -1 || emap[y + q][x - 1] == -2 || emap[y + q][x - 1] == -3) {}
				else { emap[y + q][x - 1] = 5; }
			}
			system("cls");
			interfaceB(emap);
		}
		if (r == 2)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((emap[y][x] == 0) && (emap[y][x - 1] == 0));
			} while (!z);
			emap[y][x] = 7;
			emap[y][x - 1] = 7;

			if (emap[y][x - 2] == -1 || emap[y][x - 2] == -2) {}
			else { emap[y][x - 2] = 5; }
			if (emap[y][x + 1] == -1 || emap[y][x + 1] == -2) {}
			else { emap[y][x + 1] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (emap[y - 1][x - q] == -1 || emap[y - 1][x - q] == -2 || emap[y - 1][x - q] == -3) {}
				else { emap[y - 1][x - q] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (emap[y + 1][x - q] == -1 || emap[y + 1][x - q] == -2 || emap[y + 1][x - q] == -3) {}
				else { emap[y + 1][x - q] = 5; }
			}
			system("cls");
			interfaceB(emap);

		}
		if (r == 3)
		{
			do
			{
				x = 1 + rand() % 10;
				y = 1 + rand() % 10;
				z = ((emap[y][x] == 0) && (emap[y - 1][x] == 0));
			} while (!z);
			emap[y][x] = 7;
			emap[y - 1][x] = 7;

			if (emap[y + 1][x] == -1 || emap[y + 1][x] == -2) {}
			else { emap[y + 1][x] = 5; }
			if (emap[y - 2][x] == -1 || emap[y - 2][x] == -2) {}
			else { emap[y - 2][x] = 5; }

			for (q = -1; q <= 2; q++)
			{
				if (emap[y - q][x - 1] == -1 || emap[y - q][x - 1] == -2 || emap[y - q][x - 1] == -3) {}
				else { emap[y - q][x - 1] = 5; }
			}
			for (q = -1; q <= 2; q++)
			{
				if (emap[y - q][x + 1] == -1 || emap[y - q][x + 1] == -2 || emap[y - q][x + 1] == -3) {}
				else { emap[y - q][x + 1] = 5; }
			}
			system("cls");
			interfaceB(emap);

		}
	}
}

void eone_deck(int(&emap)[12][12]) {
	bool z = true;
	int x = 0;
	int	y = 0;
	int	i = 0;
	srand(time(0));

	int q = 0;
	int r = rand() % 4;

	for (i = 1; i <= 4; i++)
	{
		do
		{
			x = 1 + rand() % 10;
			y = 1 + rand() % 10;
			z = (emap[y][x] == 0);
		} while (!z);
		emap[y][x] = 6;

		if (emap[y][x - 1] == -1 || emap[y][x - 1] == -2) {}
		else { emap[y][x - 1] = 5; }
		if (emap[y][x + 1] == -1 || emap[y][x + 1] == -2) {}
		else { emap[y][x + 1] = 5; }

		for (q = -1; q <= 1; q++)
		{
			if (emap[y + 1][x + q] == -1 || emap[y + 1][x + q] == -2 || emap[y + 1][x + q] == -3) {}
			else { emap[y + 1][x + q] = 5; }
		}
		for (q = -1; q <= 1; q++)
		{
			if (emap[y - 1][x + q] == -1 || emap[y - 1][x + q] == -2 || emap[y - 1][x + q] == -3) {}
			else { emap[y - 1][x + q] = 5; }
		}


		system("cls");
		interfaceB(emap);
	}
}

void flex(int(&emap)[12][12],int(&map)[12][12]) {
	system("cls");
	interfaceB(emap);
	interfaceA(map);
}

void shoot(int(&emap)[12][12], int(&map)[12][12]){

	
	int shot = 0;
	int hit = 0;
	int eshot = 0;
	int ehit = 0;
	int hurt = 0;
	int x = 0;
	int y = 0;
	cout << endl << "Ïîïàäàíèé: " << hit << "  Âûñòðåëîâ: " << shot << endl;

	do
	{
		do
		{
			cout << "Ñòðåëÿòü â: ";
			cin >> x >> y;
			system("cls");
			interfaceB(emap);
			interfaceA(map);
			cout << endl << "Ïîïàäàíèé: " << hit << "  Âûñòðåëîâ: " << shot << endl;
			if (emap[y][x] == 0 || emap[y][x] == 5 || emap[y][x] == 9 || emap[y][x] == 8 || emap[y][x] == 7 || emap[y][x] == 6) { break; }
		} while (emap[y][x] != 0 || emap[y][x] != 5);
		if (((emap[y][x] == 9) || (emap[y][x] == 8)) || ((emap[y][x] == 7)))
		{
			emap[y][x] = 10;
			hit++;
			shot++;
		}
		else if (emap[y][x] == 6)
		{
			emap[y][x] = 10;
			hit++;
			shot++;
		}
		else if ((emap[y][x] == 0) || (emap[y][x] == 5))
		{
			emap[y][x] = 12;
			shot++;
		}
		system("cls");
		interfaceB(emap);
		interfaceA(map);
		cout << "Ïîïàäàíèé: " << hit << "  Âûñòðåëîâ: " << shot << endl;

		x = 1 + rand() % 10;
		y = 1 + rand() % 10;

		if (((map[y][x] == 4) || (map[y][x] == 3)) || ((map[y][x] == 2)))
		{
			map[y][x] = 10;
			ehit++;
			eshot++;
			hurt++;
		}
		else if (map[y][x] == 1)
		{
			map[y][x] = 11;
			ehit++;
			eshot++;
			hurt++;
		}
		else if ((map[y][x] == 0) || (map[y][x] == 5))
		{
			map[y][x] = 12;
			eshot++;
		}
		system("cls");
		interfaceB(emap);
		interfaceA(map);
		if (hurt > 0) { cout << "Âðàã Ïîïàë:" << hurt << endl; }
		else { cout << endl; }
		cout << "Ïîïàäàíèé: " << hit << "  Âûñòðåëîâ: " << shot << endl;
		hurt = 0;
		if (hit == 20) {
			cout << "Âû ïîáåäèëè" << endl;
		}
		if (shot == 100) {
			cout << "Âû ïîáåäèëè" << endl;
		}
		if (ehit == 20) {
			cout << "Âû ïðîèãðàëè" << endl;
		}
		if (eshot == 100) {
			cout << "Âû ïðîèãðàëè" << endl;
		}
	} while ((shot < 100) || (hit < 5));
	system("pause");
}