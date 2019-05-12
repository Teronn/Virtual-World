#ifndef WILK_H
#define WILK_H

#include "Zwierze.h"
class Swiat;
class Wilk : public Zwierze {
public:
	void rysowanie() override;
	Wilk(int, int, Swiat*);
	std::string przedstawSie() override;
	char inicjal() override;
};



#endif // !WILK_H
