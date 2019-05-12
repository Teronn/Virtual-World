#ifndef SWIAT_H
#define SWIAT_H

#include <vector>
#include "Organizm.h"
class Swiat {
private:
	struct Size {
		int width;
		int height;
	} gridSize;
	void sortujOrganizmy();
	std::string message;
	std::vector <Organizm*>  organizmy;
public:
	char input;
	void zapiszSwiat();
	Swiat* wczytajSwiat();
	void dodajOrg(Organizm *);
	void usunOrg(Organizm *);
	void wypiszMess();
	void dodajDoWiadomosci(std::string a);
	void wyczyscWiadomosc();
	Organizm* dajOrg(int, int);
	void wykonajTure();
	void rysujSwiat();
	void clearScreen();
	int dajWidth();
	int dajHeight();
	Swiat(int, int);
	~Swiat();
	Swiat& operator=(Swiat other);
};


#endif
