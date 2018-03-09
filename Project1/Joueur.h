#pragma once
#ifndef JOUEUR_H
#define JOUEUR_H

#include "Grille.h"

class Joueur
{
private:
	Grille tirs;
	Grille bateaux;
	Grille courant;

	bool ValiderPositionBateau(int ligne, int colonne, int taille, bool horizontal) const;
public:
	Joueur();

	void PlacerBateaux();

	void AfficherTirs() const;
	void AfficherBateaux() const;

	void Touche(int ligne, int colonne, bool coule);
	void Tir(int ligne, int colonne);

	bool TirValide(int ligne, int colonne) const;

	bool ValiderAttaqueOpposant(int ligne, int colonne, bool& coule);

	bool aPerdu() const;

	bool ValiderCoule(int ligne, int colonne) const;
};

#endif