#include <iostream>
#include <ctime>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int map[12][12];
	int emap[12][12];

	wall(map,emap);
	f_deck(map);
	tree_deck(map);
	two_deck(map);
	one_deck(map);
	ef_deck(emap);
	etree_deck(emap);
	etwo_deck(emap);
	eone_deck(emap);
	flex(emap, map);
	shoot(emap, map);
}