#include "Swiat.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Wilk.h"
#include "Zolw.h"
#include "Owca.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Wjagody.h"
#include "Barszcz.h"
using namespace std;

Swiat::Swiat(int w, int h)
	: gridSize{ w,h }, input(0), message("")
{
	cout << "Stworzono swiat o wymiarach w: " << gridSize.width << " h: " << gridSize.height << endl;
}

Swiat::~Swiat(){
	cout << "Destruktor swiatow ;)" << endl;
	for (Organizm *org : organizmy) {
		delete org;
	}
}

Swiat & Swiat::operator=(Swiat other)
{
	organizmy.swap(other.organizmy);
	gridSize.width = other.gridSize.width;
	gridSize.height = other.gridSize.height;
	return *this;
}


void Swiat::rysujSwiat() {
	this->clearScreen();
	for (int j = 0; j < gridSize.width+2; j++) {
		cout << "-";
	}
	cout << endl;
	for (int y = 0; y < gridSize.height; y++) {
		cout << "|";
		for (int x = 0; x < gridSize.width; x++) {
			bool empty = true;
			for (Organizm * org : organizmy) {
				if (org->dajPolozenie()->x == x && org->dajPolozenie()->y == y) {
					org->rysowanie();
					empty = false;
				}
			}
			if (empty) cout << " ";
		}
		cout << "|" << endl;
	}
	for (int j = 0; j < gridSize.width+2; j++) {
		cout << "-";
	}
	cout << endl;
	cout << "DOMINK NIEMIRO 165290" << endl << endl;
}

void Swiat::clearScreen() {
	for (int i = 0; i < 100; i++) {
		cout << endl;
	}
}

Organizm* Swiat::dajOrg(int x, int y) {
	for (Organizm *org:organizmy) {
		if (org->dajPolozenie()->x == x && org->dajPolozenie()->y == y)
			return org;
	}
	return NULL;
}


int Swiat::dajWidth() {
	return this->gridSize.width;
}

int Swiat::dajHeight() {
	return this->gridSize.height;
}

void Swiat::sortujOrganizmy(){
	for (int i = 0; i < organizmy.size(); i++) {
		for (int j = 0; j < organizmy.size()-1; j++) {
			if ((organizmy[j])->dajInicjatywe() <= (organizmy[j + 1])->dajInicjatywe()) {
				if ((organizmy[j])->dajInicjatywe() == (organizmy[j + 1])->dajInicjatywe()) {
					if((organizmy[j])->dajWiek() < (organizmy[j+1])->dajWiek())
						swap(organizmy[j], organizmy[j + 1]);
				}
				else {
					swap(organizmy[j], organizmy[j + 1]);
				}
			}
		}
	}
}

void Swiat::zapiszSwiat()
{
	ofstream plik;
	plik.open("swiat.txt");

	plik << gridSize.width << " " << gridSize.height << endl;
	for (Organizm *org : organizmy) {
		if (!org->czyDoUsuniecia()) {
			plik << org->inicjal() << " " << org->dajPolozenie()->x << 
				" " << org->dajPolozenie()->y << " " <<
				org->dajSile() << " " << org->dajWiek() << " ";
		}
	}
	plik.close();
}

Swiat* Swiat::wczytajSwiat(){
	ifstream plik;
	Swiat *nowy;
	int w, h;
	char inicjal;
	plik.open("swiat.txt");
	plik >> w >> h;
	nowy = new Swiat(w, h);
	while (plik >> inicjal) {
		int x, y, sila, wiek;
		Organizm *temp;
		plik >> x >> y >> sila >> wiek;
		switch (inicjal) {
		case 'A':
			temp = new Antylopa(x, y, nowy);
			break;
		case 'B':
			temp = new Barszcz(x, y, nowy);
			break;
		case 'C':
			temp = new Czlowiek(x, y, nowy);
			break;
		case 'G':
			temp = new Guarana(x, y, nowy);
			break;
		case 'L':
			temp = new Lis(x, y, nowy);
			break;
		case 'M':
			temp = new Mlecz(x, y, nowy);
			break;
		case 'O':
			temp = new Owca(x, y, nowy);
			break;
		case 'T':
			temp = new Trawa(x, y, nowy);
			break;
		case 'W':
			temp = new Wilk(x, y, nowy);
			break;
		case 'J':
			temp = new Wjagody(x, y, nowy);
			break;
		case 'Z':
			temp = new Zolw(x, y, nowy);
			break;
		}
		temp->ustawSile(sila);
		temp->ustawWiek(wiek);
		nowy->dodajOrg(temp);
	}
	return nowy;
}

void Swiat::dodajOrg(Organizm *org){
	organizmy.push_back(org);
}

void Swiat::usunOrg(Organizm *org){
	organizmy.erase(std::find(organizmy.begin(), organizmy.end(), org));
	delete org;
}

void Swiat::wypiszMess(){
	cout << message << endl;
	message = "";
	Czlowiek *c1;
	for (Organizm *org : organizmy) {
		if (c1 = dynamic_cast<Czlowiek*>(org)) {
			if (c1->sprawdzZdolnosc() == 0) cout << "Zdolnosc gotowa do uzycia" << endl;
			else if (c1->sprawdzZdolnosc() == 1) cout << "Zdolnosc aktywna" << endl;
			else cout << "Nie mozna uzyc zdolnosci" << endl;
		}
	}
}

void Swiat::dodajDoWiadomosci(string a)
{
	message += a;
}

void Swiat::wyczyscWiadomosc()
{
	message = "";
}

void Swiat::wykonajTure(){
	vector <Organizm*> doUsuniecia;
	int size = organizmy.size();
	sortujOrganizmy();


	for(int i = 0; i < size; i++){
		if (!(organizmy[i]->czyDoUsuniecia())) {
			organizmy[i]->akcja();
			organizmy[i]->rosnij();
		}
	}
	for (Organizm *org : organizmy) {
		if (org->czyDoUsuniecia())
			doUsuniecia.push_back(org);
	}

	for (Organizm* org : doUsuniecia) {
		usunOrg(org);
	}
	
}