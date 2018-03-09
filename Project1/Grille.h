#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>

using namespace std;

class Grille
{
public:

	enum Cases
	{
		EAU = 0,
		TORPILLEUR = 1,
		SOUS_MARIN = 2,
		CONTRE_TORPILLEUR = 3,
		CROISEUR = 4,
		PORTE_AVION = 5,
		TIR = 6,
		TOUCHE = 7
	};

	static const int NB_COLONNE = 10;
	static const int NB_LIGNE = 10;

	Grille();

	Cases get(int ligne, int colonne) const;

	void set(int ligne, int colonne, Cases val);

	friend ostream& operator<<(ostream&, const Grille&);

private:
	Cases cases[NB_LIGNE][NB_COLONNE];
};

ostream& operator<<(ostream&, const Grille&);

#endif #pragma once
