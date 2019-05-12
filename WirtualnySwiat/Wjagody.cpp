#include "Wjagody.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;
Wjagody::Wjagody(int x, int y, Swiat *glownySwiat)
	: Roslina(99, x, y, glownySwiat)
{}

void Wjagody::rysowanie()
{
	cout << inicjal();
}

void Wjagody::kolizja(Organizm *oponent, bool atakuje = false) {
	Zwierze* zw;
	zw = dynamic_cast<Zwierze*>(oponent);
	if(zw) zw->zjadlJagody();
	doUsuniecia = true;
}

std::string Wjagody::przedstawSie()
{
	return "wilcze jagody";
}

char Wjagody::inicjal()
{
	return 'J';
}
