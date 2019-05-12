#include "Guarana.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;
Guarana::Guarana(int x, int y, Swiat *glownySwiat)
	: Roslina(0, x, y, glownySwiat)
{}

void Guarana::rysowanie()
{
	cout << inicjal();
}

void Guarana::kolizja(Organizm *org, bool atakuje) {
	Zwierze *z1;
	if (z1 = dynamic_cast<Zwierze*>(org)) {
		z1->zjadlGuarane();
		doUsuniecia = true;
	}
}

char Guarana::inicjal()
{
	return 'G';
}

std::string Guarana::przedstawSie()
{
	return "Guarana";
}
