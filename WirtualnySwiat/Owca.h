#ifndef OWCA_H
#define OWCA_H
#include "Zwierze.h"
class Swiat;
class Owca : public Zwierze {

public:
	Owca(int, int, Swiat*);
	void rysowanie() override;
	std::string przedstawSie() override;
	char inicjal() override;
};

#endif