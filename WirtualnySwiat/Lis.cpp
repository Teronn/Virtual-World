#include "Lis.h"
#include <ctime>
#include "Const.h"
#include "Swiat.h"
#include "utils.h"
#include <iostream>
using namespace std;
Lis::Lis(int x, int y, Swiat* glownySwiat)
	: Zwierze(3, 7, x, y, glownySwiat) {}

void Lis::rysowanie() {
	cout << inicjal();
}

void Lis::akcja(){
	struct pole* pozycja;

	do {
		pozycja = dajPoleObok(this);
	} while (pozycja->org && pozycja->org->dajSile() > sila);

	if (pozycja->org && pozycja->org->czyDoUsuniecia() == false) {
		this->kolizja(pozycja->org, ATAKUJE);
	}
	else {
		polozenie.x = pozycja->x;
		polozenie.y = pozycja->y;
	}
	delete pozycja;
}

char Lis::inicjal()
{
	return 'L';
}

std::string Lis::przedstawSie()
{
	return "lis";
}
