#ifndef ORGANIZM_H
#define ORGANIZM_H
#include <string>
class Swiat;
struct pole;
class Organizm {
protected:
	int sila;
	int inicjatywa;
	struct cords {
		int x;
		int y;
	} polozenie;
	int wiek;
	Swiat *ref;
	bool doUsuniecia;

public:
	void usun();
	bool czyDoUsuniecia();
	Organizm(int, int, int, int, Swiat*);
	struct cords* dajPolozenie(); 
	int dajInicjatywe();
	int dajWiek();
	int dajSile();
	virtual char inicjal() = 0;
	void ustawSile(int);
	void ustawWiek(int);
	virtual bool odbilAtak(Organizm *) = 0;
	virtual void zjadlGuarane() = 0;
	virtual void zjadlBarszcz() = 0;
	virtual void zjadlJagody() = 0;
	virtual std::string przedstawSie() = 0;
	void rosnij();
	struct pole* dajPoleObok(Organizm*);
	struct pole* dajWolnePoleObok(Organizm*);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm*, bool) = 0;
	virtual void rysowanie() = 0;
};

#endif