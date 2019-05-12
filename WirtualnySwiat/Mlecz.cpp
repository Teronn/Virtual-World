#include "Mlecz.h"
#include <iostream>
using namespace std;
Mlecz::Mlecz(int x, int y, Swiat *glownySwiat)
	: Roslina(0,x, y, glownySwiat)
{}

void Mlecz::rysowanie()
{
	cout << inicjal();
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}

char Mlecz::inicjal()
{
	return 'M';
}

std::string Mlecz::przedstawSie()
{
	return "mlecz";
}
