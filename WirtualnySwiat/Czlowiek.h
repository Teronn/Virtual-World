#ifndef CZLOWIEK_H
#define CZLOWIEK_H
#include "Zwierze.h"

class Swiat;
class Czlowiek : public Zwierze {
private:
	int zdolnosc;
public:
	int sprawdzZdolnosc();
	Czlowiek(int, int, Swiat*);
	void rysowanie() override;
	void akcja() override;
	void kolizja(Organizm *, bool) override;
	char inicjal() override;
	void zjadlBarszcz() override;
	void zjadlJagody() override;
	std::string przedstawSie() override;
};

#endif