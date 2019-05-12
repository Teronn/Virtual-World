#ifndef ROSLINA_H
#define ROSLINA_H

#include "Organizm.h"
class Swiat;
class Roslina: public Organizm {

public:
	Roslina(int, int, int, Swiat*);
	void akcja() override;
	void kolizja(Organizm*, bool) override;
	bool odbilAtak(Organizm*) override;
	void zjadlGuarane() override;
	void zjadlBarszcz() override;
	void zjadlJagody() override;
	virtual void rysowanie()= 0;

};

#endif