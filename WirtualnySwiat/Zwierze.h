#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {

public:
	Zwierze(int, int, int, int, Swiat*);
	void akcja() override;
	void zjadlGuarane() override;
	void zjadlBarszcz() override;
	void zjadlJagody() override;
	void kolizja(Organizm*, bool) override;
	bool odbilAtak(Organizm *);
	virtual void rysowanie()=0;

};

#endif