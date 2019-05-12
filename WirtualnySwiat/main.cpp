#include <iostream>
#include "Swiat.h"
#include "Const.h"
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
#include <conio.h>
using namespace std;

int main() {
	Swiat *s1;
	int width, height;
	do {
		cout << "Prosze podac wymiary swiata." << endl;
		cin >> width >> height;
	} while (width <= 0 || height <= 0);

	s1 = new Swiat(width, height);
	//s1->dodajOrg(new Mlecz(1, 1, s1));
	//s1->dodajOrg(new Trawa(2, 2, s1));
	//s1->dodajOrg(new Guarana(3, 3, s1));
	//s1->dodajOrg(new Guarana(4, 4, s1));
	//s1->dodajOrg(new Wjagody(5, 5, s1));
	//s1->dodajOrg(new Wjagody(6, 6, s1));
	//s1->dodajOrg(new Barszcz(7, 7, s1));
	//s1->dodajOrg(new Wilk(8,8,s1));
	//s1->dodajOrg(new Owca(9, 9, s1));
	//s1->dodajOrg(new Owca(10, 10, s1));
	//s1->dodajOrg(new Czlowiek(11, 11, s1));
	//s1->dodajOrg(new Antylopa(12, 12, s1));
	//s1->dodajOrg(new Lis(13, 13, s1));
	//s1->dodajOrg(new Lis(14, 15, s1));
	//s1->dodajOrg(new Lis(14, 13, s1));
	//s1->dodajOrg(new Zolw(15, 15, s1));

	for (bool i = true; i;) {
		s1->rysujSwiat();
		s1->wypiszMess();

		s1->input = getch();
		if (s1->input == ARROW_INPUT_CODE) {
			s1->input = getch();
		}

		if (s1->input == 's') {
			s1->zapiszSwiat();
		}
		else if (s1->input == 'l') {
			delete s1;
			s1 = s1->wczytajSwiat();
		}
		else{
			s1->wykonajTure();
		}

	}
	return 0;
}
