#ifndef ANTYLOPA_H
#define ANTYLOPA_H
#include "Zwierze.h"
class Swiat;
class Antylopa : public Zwierze {

public:
	Antylopa(int, int, Swiat*);
	char inicjal() override;
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm*, bool) override;
	std::string przedstawSie() override;
};

#endif