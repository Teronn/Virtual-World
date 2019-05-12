#include "Czlowiek.h"
#include "Swiat.h"
#include "Const.h"
#include <iostream>
#include "utils.h"
using namespace std;
int Czlowiek::sprawdzZdolnosc()
{
	if (zdolnosc == 0) return 0;
	else if (zdolnosc > 1) return 1;
	else return -1;
}
Czlowiek::Czlowiek(int x, int y, Swiat* glownySwiat)
	: Zwierze(5, 4, x, y, glownySwiat), zdolnosc(0) {}

void Czlowiek::rysowanie() {
	cout << inicjal();
}

void Czlowiek::akcja() {
	int rx, ry;
	Organizm * cel;
	rx = polozenie.x;
	ry = polozenie.y;
	switch (ref->input) {
	case ARROW_UP:
		if (polozenie.y - 1 < 0) break;
		ry--;
		break;
	case ARROW_LEFT:
		if (polozenie.x - 1 < 0) break;
		rx--;
		break;
	case ARROW_RIGHT:
		if (polozenie.x + 1 >= ref->dajHeight()) break;
		rx++;
		break;
	case ARROW_DOWN:
		if (polozenie.y + 1 >= ref->dajHeight()) break;
		ry++;
		break;
	case POWER_KEY:
		if (zdolnosc == 0) {
			zdolnosc = 7;
		}

		break;
	default:
		break;
	}
	cel = ref->dajOrg(rx, ry);
	if (cel && cel != this) {
		kolizja(cel, ATAKUJE);
	}
	else {
		polozenie.x = rx;
		polozenie.y = ry;
	}
	ref->input = 0;
	if (zdolnosc > 0) {
		zdolnosc--;
		if (zdolnosc == 0) zdolnosc = -5;
	}
	else if (zdolnosc < 0) zdolnosc++;
}

void Czlowiek::kolizja(Organizm *oponent, bool atakuje){
	Organizm* cel;
	struct pole *pozycja;
	if (zdolnosc && oponent->dajSile() > sila && dynamic_cast<Zwierze*>(oponent)){
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
	else Zwierze::kolizja(oponent, atakuje);

}

char Czlowiek::inicjal()
{
	return 'C';
}


void Czlowiek::zjadlBarszcz(){
	if (zdolnosc < 1)doUsuniecia = true;
	else {
		struct pole *pozycja;
		pozycja = dajWolnePoleObok(this);
		if (pozycja) {
			polozenie.x = pozycja->x;
			polozenie.y = pozycja->y;
			delete pozycja;
		}
	}
}

void Czlowiek::zjadlJagody(){
	if (zdolnosc < 1)doUsuniecia = true;
	else {
		struct pole *pozycja;
		pozycja = dajWolnePoleObok(this);
		if (pozycja) {
			polozenie.x = pozycja->x;
			polozenie.y = pozycja->y;
			delete pozycja;
		}
	}
}

std::string Czlowiek::przedstawSie()
{
	return "czlowiek";
}
