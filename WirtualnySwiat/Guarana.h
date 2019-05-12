#ifndef GUARANA_H
#define GUARANA_H
#include "Roslina.h"

class Swiat;
class Guarana : public Roslina {
private:
	int zdolnosc;
public:
	Guarana(int, int, Swiat*);
	void rysowanie() override;
	void kolizja(Organizm*, bool) override;
	char inicjal() override;
	std::string przedstawSie() override;

};

#endif