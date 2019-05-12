#include "Trawa.h"
#include <iostream>
using namespace std;
Trawa::Trawa(int x, int y, Swiat *glownySwiat)
	: Roslina(0, x, y, glownySwiat)
{}

void Trawa::rysowanie()
{
	cout << inicjal();
}

std::string Trawa::przedstawSie()
{
	return "trawa";
}

char Trawa::inicjal()
{
	return 'T';
}
