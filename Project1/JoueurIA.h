#pragma once
#include "Joueur.h"
#include "Position.h"

class JoueurIA {
private:
	Joueur self;
	bool attackMode;
	Position initialHit;
	Position nextHit;
	Position lastHit;
	int orientation;
	int realorientation;

public:
	JoueurIA();

	void AfficherTirs();
	void AfficherBateaux();

	void Touche(int ligne, int colonne, bool coule);
	void Tir(int ligne, int colonne);

	bool TirValide(int ligne, int colonne) const;

	bool ValiderAttaqueOpposant(int ligne, int colonne, bool& coule);

	bool aPerdu() const;

	bool ValiderCoule(int ligne, int colonne) const;

	void GenereAttaque(int &ligne, int &colonne);
};