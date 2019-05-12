#ifndef TRAWA_H
#define TRAWA_H
#include "Roslina.h"

class Swiat;
class Trawa : public Roslina {
private:
	int zdolnosc;
public:
	Trawa(int, int, Swiat*);
	void rysowanie() override;
	std::string przedstawSie() override;
	char inicjal() override;
};

#endif