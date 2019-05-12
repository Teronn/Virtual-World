#include "Barszcz.h"
#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
using namespace std;
Barszcz::Barszcz(int x, int y, Swiat *glownySwiat)
	: Roslina(10, x, y, glownySwiat)
{}

void Barszcz::rysowanie()
{
	cout << inicjal();
}

void Barszcz::akcja() {
	Zwierze *cel;
	cel = dynamic_cast<Zwierze*>(ref->dajOrg(polozenie.x, polozenie.y-1));
	if (cel && !(cel->odbilAtak(this))) cel->zjadlBarszcz();
	cel = dynamic_cast<Zwierze*>(ref->dajOrg(polozenie.x, polozenie.y+1));
	if (cel && !(cel->odbilAtak(this))) cel->zjadlBarszcz();
	cel = dynamic_cast<Zwierze*>(ref->dajOrg(polozenie.x+1, polozenie.y));
	if (cel && !(cel->odbilAtak(this))) cel->zjadlBarszcz();
	cel = dynamic_cast<Zwierze*>(ref->dajOrg(polozenie.x-1, polozenie.y));
	if (cel && !(cel->odbilAtak(this))) cel->zjadlBarszcz();


	Roslina::akcja();
}

void Barszcz::kolizja(Organizm *org, bool atakuje) {
	Zwierze *z1;
	if (!atakuje) {
		if (z1 = dynamic_cast<Zwierze*>(org)) {
			z1->zjadlBarszcz();
			doUsuniecia = true;
		}
	}
}

std::string Barszcz::przedstawSie()
{
	return "barszcz sosnowskiego";
}

char Barszcz::inicjal()
{
	return 'B';
}
