#ifndef BARSZCZ_H
#define BARSZCZ_H
#include "Roslina.h"

class Swiat;
class Barszcz : public Roslina {
private:
	int zdolnosc;
public:
	Barszcz(int, int, Swiat*);
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm*, bool) override;
	std::string przedstawSie() override;
	char inicjal() override;

};

#endif