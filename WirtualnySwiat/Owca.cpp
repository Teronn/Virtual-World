#include "Owca.h"
#include "Swiat.h"
#include <iostream>
using namespace std;
Owca::Owca(int x, int y, Swiat* glownySwiat)
	: Zwierze(4, 4, x, y, glownySwiat) {}

void Owca::rysowanie() {
	cout << inicjal();
}

std::string Owca::przedstawSie()
{
	return "owca";
}

char Owca::inicjal()
{
	return 'O';
}
