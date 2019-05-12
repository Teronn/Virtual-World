#ifndef MLECZ_H
#define MLECZ_H
#include "Roslina.h"

class Swiat;
class Mlecz : public Roslina {
private:
	int zdolnosc;
public:
	Mlecz(int, int, Swiat*);
	void rysowanie() override;
	void akcja() override;
	char inicjal() override;
	std::string przedstawSie() override;
};

#endif