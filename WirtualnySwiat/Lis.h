#ifndef LIS_H
#define LIS_H
#include "Zwierze.h"
class Swiat;
class Lis : public Zwierze {

public:
	Lis(int, int, Swiat*);
	void rysowanie() override;
	void akcja() override;
	char inicjal() override;
	std::string przedstawSie() override;
};

#endif