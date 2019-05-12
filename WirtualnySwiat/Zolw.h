#ifndef ZOLW_H
#define ZOLW_H
#include "Zwierze.h"
class Swiat;
class Zolw : public Zwierze {
	
public:
	Zolw(int, int, Swiat*);
	void rysowanie() override;
	void akcja() override;
	bool odbilAtak(Organizm*) override;
	char inicjal() override;
	std::string przedstawSie() override;
};

#endif