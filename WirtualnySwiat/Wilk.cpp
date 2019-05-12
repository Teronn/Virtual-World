#include "Wilk.h"
#include "Swiat.h"
#include <iostream>
using namespace std;
Wilk::Wilk(int x, int y, Swiat* glownySwiat)
	: Zwierze(9, 5, x, y, glownySwiat) 
{}

std::string Wilk::przedstawSie()
{
	return "wilk";
}

char Wilk::inicjal()
{
	return 'W';
}

void Wilk::rysowanie(){
	cout << inicjal();
}
