#include "Organizm.h"
#include <ctime>
#include <vector>
#include "Const.h"
#include "Swiat.h"
#include "utils.h"
#include <cstdlib>

void Organizm::usun(){
	doUsuniecia = true;
}

bool Organizm::czyDoUsuniecia() {
	return doUsuniecia;
}

Organizm::Organizm(int sila, int inicjatywa, int x, int y, Swiat *glownySwiat)
	:sila(sila), inicjatywa(inicjatywa), polozenie{ x,y }, wiek(0), ref(glownySwiat), doUsuniecia(false)
{}

Organizm::cords* Organizm::dajPolozenie() {
	return &polozenie;
}

int Organizm::dajInicjatywe(){
	return inicjatywa;
}
int Organizm::dajWiek() {
	return wiek;
}

int Organizm::dajSile(){
	return sila;
}

void Organizm::ustawSile(int nowa)
{
	sila = nowa;
}

void Organizm::ustawWiek(int nowy)
{
	wiek = nowy;
}

void Organizm::rosnij(){
	wiek++;
}

struct pole* Organizm::dajPoleObok(Organizm *org ){
	srand(time(NULL) + polozenie.x + 73 + (polozenie.y + 1) * 173 + inicjatywa * (wiek + 1) * 1231);

	std::vector<pole*> pola;
	int size, los;
	struct pole *temp;
	if (org->polozenie.y - 1 >= 0)
		pola.push_back(new pole{ ref->dajOrg(org->polozenie.x, org->polozenie.y - 1), polozenie.x, polozenie.y - 1 });
	if (org->polozenie.x - 1 >= 0)
		pola.push_back(new pole{ ref->dajOrg(org->polozenie.x - 1, org->polozenie.y), polozenie.x - 1, polozenie.y });
	if (org->polozenie.x + 1 < ref->dajWidth())
		pola.push_back(new pole{ ref->dajOrg(org->polozenie.x + 1, org->polozenie.y), polozenie.x + 1, polozenie.y });
	if (org->polozenie.y + 1 < ref->dajHeight())
		pola.push_back(new pole{ ref->dajOrg(org->polozenie.x, org->polozenie.y + 1), polozenie.x, polozenie.y + 1 });
	size = pola.size();
	if (size > 0) {
		los = rand() % size;
		temp = pola[los];
	}
	else temp = NULL;
	for (int i = 0; i < size; i++) {
		if (pola[i] != temp) delete pola[i];
	}
	return temp;

}

pole * Organizm::dajWolnePoleObok(Organizm *org)
{
	std::vector<pole*> wolne;
	int size, los;
	struct pole *temp;
	if (org->polozenie.y - 1 >= 0 && !(ref->dajOrg(org->polozenie.x, org->polozenie.y - 1)))
		wolne.push_back(new pole{ NULL, polozenie.x, polozenie.y - 1 });
	if (org->polozenie.x - 1 >= 0 && !(ref->dajOrg(org->polozenie.x - 1, org->polozenie.y)))
		wolne.push_back(new pole{ NULL, polozenie.x - 1, polozenie.y});
	if (org->polozenie.x + 1 < ref->dajWidth() && !(ref->dajOrg(org->polozenie.x + 1, org->polozenie.y)))
		wolne.push_back(new pole{ NULL, polozenie.x + 1, polozenie.y });
	if (org->polozenie.y + 1 < ref->dajHeight() && !(ref->dajOrg(org->polozenie.x, org->polozenie.y + 1)))
		wolne.push_back(new pole{ NULL, polozenie.x, polozenie.y + 1 });
	size = wolne.size();
	if (size > 0) {
		los = rand() % size;
		temp = wolne[los];
	}
	else return NULL;
	for (int i = 0; i < size; i++) {
		if (wolne[i] != temp) delete wolne[i];
	}
	return temp;
}
