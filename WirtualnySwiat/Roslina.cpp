#include "Roslina.h"
#include "Swiat.h"
#include "utils.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Wjagody.h"
#include "Barszcz.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Roslina::Roslina(int sila, int x, int y, Swiat* glownySwiat)
	:Organizm(sila, 0, x, y, glownySwiat) {}

void Roslina::akcja(){
	Organizm *temp = NULL;
	struct pole *pozycja;
	int los = rand() % 1000;
	if (los < 10) {
		pozycja = dajWolnePoleObok(this);
		if (pozycja) {
			if (dynamic_cast<Mlecz*>(this)) {
				temp = new Mlecz(pozycja->x, pozycja->y, ref);
			}
			else if (dynamic_cast<Trawa*>(this)) {
				temp = new Trawa(pozycja->x, pozycja->y, ref);
			}
			else if (dynamic_cast<Guarana*>(this)) {
				temp = new Guarana(pozycja->x, pozycja->y, ref);
			}
			else if (dynamic_cast<Wjagody*>(this)) {
				temp = new Wjagody(pozycja->x, pozycja->y, ref);
			}
			else if (dynamic_cast<Barszcz*>(this)) {
				temp = new Barszcz(pozycja->x, pozycja->y, ref);
			}
		}
		if (pozycja) delete pozycja;
		if(temp)ref->dodajOrg(temp);
	}
}

void Roslina::kolizja(Organizm *oponent, bool atakuje){
	doUsuniecia = true;
}

bool Roslina::odbilAtak(Organizm *org)
{
	return false;
}


void Roslina::zjadlGuarane() {}

void Roslina::zjadlBarszcz() {}

void Roslina::zjadlJagody() {}
