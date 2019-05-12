#ifndef WJAGODY_H
#define WJAGODY_H
#include "Roslina.h"

class Swiat;
class Wjagody : public Roslina {
private:
	int zdolnosc;
public:
	Wjagody(int, int, Swiat*);
	void rysowanie() override;
	void kolizja(Organizm*, bool) override;
	std::string przedstawSie() override;
	char inicjal() override;
};

#endif