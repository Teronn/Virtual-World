#include "Antylopa.h"
#include <ctime>
#include "Const.h"
#include "Swiat.h"
#include <iostream>
#include <cstdlib>
#include "utils.h"
using namespace std;
Antylopa::Antylopa(int x, int y, Swiat* glownySwiat)
	: Zwierze(4, 4, x, y, glownySwiat) {}

char Antylopa::inicjal()
{
	return 'A';
}

void Antylopa::rysowanie() {
	cout << inicjal();
}

void Antylopa::akcja(){
	struct pole* pozycja;
	int dx, dy;
	Organizm* cel;
	pozycja = dajPoleObok(this);
	if (pozycja->org && pozycja->org->czyDoUsuniecia() == false) {
		this->kolizja(pozycja->org, ATAKUJE);
	}
	else {
		dx = (pozycja->x - polozenie.x) * 2;
		dy = (pozycja->y - polozenie.y) * 2;
		cel = ref->dajOrg(polozenie.x + dx,polozenie.y +  dy);
		if (!cel && dx != 0 && polozenie.x + dx >= 0 && polozenie.x + dx < ref->dajWidth()) {
			polozenie.x = polozenie.x + dx;
		}
		else if (!cel && dy != 0 && polozenie.y + dy >= 0 && polozenie.y + dy < ref->dajHeight()) {
			polozenie.y = polozenie.y + dy;
		}
		else {
			if (!cel) {
				polozenie.x = pozycja->x;
				polozenie.y = pozycja->y;
			}
			else {
				if (cel->czyDoUsuniecia() == false && cel != this)
				kolizja(cel, ATAKUJE);
			}

		}
	}
	delete pozycja;
}

void Antylopa::kolizja(Organizm *oponent, bool atakuje){
	Organizm* cel;
	struct pole *pozycja;
	int ucieczka = rand() % 2;
	if(!ucieczka) Zwierze::kolizja(oponent, atakuje);
	else {
		cel = (atakuje) ? oponent : this;
		pozycja = dajWolnePoleObok(cel);
		if (pozycja) {
			polozenie.x = pozycja->x;
			polozenie.y = pozycja->y;
			delete pozycja;
		}
		else {
			cel = (atakuje) ? this : oponent;
			pozycja = dajWolnePoleObok(cel);
			if (pozycja) {
				polozenie.x = pozycja->x;
				polozenie.y = pozycja->y;
				delete pozycja;
			}
		}
	}
}

std::string Antylopa::przedstawSie()
{
	return "antylopa";
}
