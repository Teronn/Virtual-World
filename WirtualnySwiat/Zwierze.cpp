#include <iostream>
#include "Swiat.h"
#include "Zwierze.h"
#include "Const.h"
#include "Roslina.h"
#include <ctime>
#include "utils.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Lis.h"
using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, int x, int y, Swiat* glownySwiat)
	:Organizm(sila, inicjatywa, x, y, glownySwiat){}

void Zwierze::akcja() {
	struct pole* pozycja;
	
	pozycja = dajPoleObok(this);
	if (pozycja->org && pozycja->org->czyDoUsuniecia() == false) {
		this->kolizja(pozycja->org, ATAKUJE);
	}
	else {
		polozenie.x = pozycja -> x;
		polozenie.y = pozycja -> y;
	}
	delete pozycja;
}

void Zwierze::kolizja(Organizm *oponent, bool atakuje){
	struct pole* wolne;
	Organizm *nowy = NULL;

	wolne = dajWolnePoleObok(this);
	if (!wolne) {
		wolne = dajWolnePoleObok(oponent);
	}
	if (wolne) {
		if (dynamic_cast<Wilk*>(this) && dynamic_cast<Wilk*>(oponent)) {
			nowy = new Wilk(wolne->x, wolne->y, ref);
		}
		else if (dynamic_cast<Owca*>(this) && dynamic_cast<Owca*>(oponent)) {
			nowy = new Owca(wolne->x, wolne->y, ref);
		}
		else if (dynamic_cast<Zolw*>(this) && dynamic_cast<Zolw*>(oponent)) {
			nowy = new Zolw(wolne->x, wolne->y, ref);
		}
		else if (dynamic_cast<Lis*>(this) && dynamic_cast<Lis*>(oponent)) {
			nowy = new Lis(wolne->x, wolne->y, ref);
		}
		else if (dynamic_cast<Antylopa*>(this) && dynamic_cast<Antylopa*>(oponent)) {
			nowy = new Antylopa(wolne->x, wolne->y, ref);
		}
		delete wolne;
		if (nowy) {
			ref->wyczyscWiadomosc();
			ref->dodajDoWiadomosci(przedstawSie());
			ref->dodajDoWiadomosci(" rozmnozyl sie");
			if (!ref->dajOrg(nowy->dajPolozenie()->x, nowy->dajPolozenie()->y)) {
				ref->dodajOrg(nowy);
			}
			else delete nowy;
			return;
		}
	}
	else if ((dynamic_cast<Wilk*>(this) && dynamic_cast<Wilk*>(oponent)) ||
		(dynamic_cast<Owca*>(this) && dynamic_cast<Owca*>(oponent)) ||
		(dynamic_cast<Lis*>(this) && dynamic_cast<Lis*>(oponent)) ||
		(dynamic_cast<Zolw*>(this) && dynamic_cast<Zolw*>(oponent)) ||
		(dynamic_cast<Antylopa*>(this) && dynamic_cast<Antylopa*>(oponent)))
	{
		return;
	}

	if (atakuje == ATAKUJE) {
		if (oponent->odbilAtak(this)) {
			ref->wyczyscWiadomosc();
			ref->dodajDoWiadomosci(oponent->przedstawSie());
			ref->dodajDoWiadomosci(" odbil atak wyprowadzony przez ");
			ref->dodajDoWiadomosci(przedstawSie());
			return;
		}
		oponent->kolizja(this, NIE_ATAKUJE);
		if (sila < oponent->dajSile() && dynamic_cast<Zwierze*>(oponent)) {
			doUsuniecia = true;
			ref->wyczyscWiadomosc();
			ref->dodajDoWiadomosci(oponent->przedstawSie());
			ref->dodajDoWiadomosci(" zabil ");
			ref->dodajDoWiadomosci(przedstawSie());
			return;
		}
		else {
			if (dynamic_cast<Roslina*>(oponent)) {
				ref->wyczyscWiadomosc();
				ref->dodajDoWiadomosci(przedstawSie());
				ref->dodajDoWiadomosci(" zjadl ");
				ref->dodajDoWiadomosci(oponent->przedstawSie());
			}
			polozenie.x = oponent->dajPolozenie()->x;
			polozenie.y = oponent->dajPolozenie()->y;
		}
	}
	else {
		if (sila <= oponent->dajSile()) {
			doUsuniecia = true;
			ref->wyczyscWiadomosc();
			ref->dodajDoWiadomosci(oponent->przedstawSie());
			ref->dodajDoWiadomosci(" zabil ");
			ref->dodajDoWiadomosci(przedstawSie());
		}
	}
}

bool Zwierze::odbilAtak(Organizm *atakujacy) {
	return false;
}

void Zwierze::zjadlGuarane() {
	sila += 3;
}

void Zwierze::zjadlBarszcz(){
	doUsuniecia = true;
}

void Zwierze::zjadlJagody() {
	doUsuniecia = true;

}