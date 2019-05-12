#include "Zolw.h"
#include <ctime>
#include "Const.h"
#include "Swiat.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;
Zolw::Zolw(int x, int y, Swiat *glownySwiat)
	:Zwierze(2, 1, x, y, glownySwiat)
{}

void Zolw::rysowanie(){
	cout << inicjal();
}

void Zolw::akcja() {
	int los = rand() % 100 + 1;
	if (los >= 75) Zwierze::akcja();
}

bool Zolw::odbilAtak(Organizm *org)
{
	if (org->dajSile() < 5) return true;
	else return false;
}

char Zolw::inicjal()
{
	return 'Z';
}

std::string Zolw::przedstawSie()
{
	return "zolw";
}
