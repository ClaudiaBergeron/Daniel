#include "Joueur.h"

#include "Constantes.h"
#include "Random.h"

#include <iostream>

using namespace std;

Joueur::Joueur()
	: tirs()
	, bateaux()
	, courant()
{
	PlacerBateaux();
}

void Joueur::AfficherTirs() const
{
	cout << tirs;
}

void Joueur::AfficherBateaux() const
{
	cout << courant;
}

bool Joueur::TirValide(int ligne, int colonne) const
{
	return tirs.get(ligne, colonne) == Grille::EAU && ligne >= 0 && ligne < 10 && colonne >= 0 && colonne < 10;
}

void Joueur::Touche(int ligne, int colonne, bool coule)
{
	tirs.set(ligne, colonne, Grille::TOUCHE);
}

void Joueur::Tir(int ligne, int colonne)
{
	tirs.set(ligne, colonne, Grille::TIR);
}

bool Joueur::aPerdu() const
{
	for (int i = 0; i < Grille::NB_LIGNE; ++i)
	{
		for (int j = 0; j < Grille::NB_COLONNE; ++j)
		{
			if (courant.get(i, j) != Grille::EAU && courant.get(i, j) != Grille::TOUCHE)
				return false;
		}
	}

	return true;
}

bool Joueur::ValiderAttaqueOpposant(int ligne, int colonne, bool& coule)
{
	coule = false;
	if (bateaux.get(ligne, colonne) != Grille::EAU)
	{
		cout << "************************" << endl;
		cout << "Touche!!" << endl;

		courant.set(ligne, colonne, Grille::TOUCHE);

		if (ValiderCoule(ligne, colonne))
		{
			cout << "Coule!!" << endl;
			coule = true;
		}

		cout << "************************" << endl << endl;
		return true;
	}
	else
	{
		cout << "++++++++++++++++++++++++" << endl;
		cout << "A l'eau!!" << endl;
		cout << "++++++++++++++++++++++++" << endl << endl;
		return false;
	}
}

bool Joueur::ValiderCoule(int ligne, int colonne) const
{
	bool coule = true;
	int l = ligne;
	int c = colonne;
	Grille::Cases idBateau = bateaux.get(ligne, colonne);

	bool horizontal = false;
	if (colonne == 0)
		horizontal = bateaux.get(ligne, colonne + 1) == idBateau;
	else if (colonne == Grille::NB_COLONNE - 1)
		horizontal = bateaux.get(ligne, colonne - 1) == idBateau;
	else
		horizontal = bateaux.get(ligne, colonne - 1) == idBateau || bateaux.get(ligne, colonne + 1) == idBateau;

	if (horizontal)
	{
		while (c > 0 && bateaux.get(l, c - 1) == idBateau)
			c--;

		for (int i = 0; i < TAILLE_BATEAUX[idBateau]; ++i)
		{
			coule = coule && courant.get(l, c + i) == Grille::TOUCHE;
		}
	}
	else
	{
		while (l > 0 && bateaux.get(l - 1, c) == idBateau)
			l--;

		for (int i = 0; i < TAILLE_BATEAUX[idBateau]; ++i)
		{
			coule = coule && courant.get(l + i, c) == Grille::TOUCHE;
		}
	}
	return coule;
}

bool Joueur::ValiderPositionBateau(int ligne, int colonne, int taille, bool horizontal) const
{
	bool valide = true;
	if (horizontal)
	{
		if (colonne + taille > Grille::NB_COLONNE - 1)
			return false;
	}
	else
	{
		if (ligne + taille > Grille::NB_LIGNE - 1)
			return false;
	}

	for (int i = 0; i < taille; ++i)
	{
		if (horizontal)
			valide = valide && (bateaux.get(ligne, colonne + i) == Grille::EAU);
		else
			valide = valide && (bateaux.get(ligne + i, colonne) == Grille::EAU);
	}
	return valide;
}

void Joueur::PlacerBateaux()
{
	int noBateau = NB_BATEAU;
	while (noBateau > 0)
	{
		int ligne;
		int colonne;
		bool horiontal;

		do
		{
			ligne = Random::GenereValeur(0, Grille::NB_LIGNE - 1);
			colonne = Random::GenereValeur(0, Grille::NB_COLONNE - 1);
			horiontal = Random::GenereValeur(HORIZONTAL, VERTICAL) == HORIZONTAL;
		} while (!ValiderPositionBateau(ligne, colonne, TAILLE_BATEAUX[noBateau], horiontal));

		if (horiontal)
		{
			for (int i = 0; i < TAILLE_BATEAUX[noBateau]; ++i)
			{
				bateaux.set(ligne, colonne + i, (Grille::Cases)noBateau);
			}
		}
		else
		{
			for (int i = 0; i < TAILLE_BATEAUX[noBateau]; ++i)
			{
				bateaux.set(ligne + i, colonne, (Grille::Cases)noBateau);
			}
		}

		--noBateau;
	}

	for (int i = 0; i < Grille::NB_LIGNE; ++i)
	{
		for (int j = 0; j < Grille::NB_COLONNE; ++j)
		{
			courant.set(i, j, bateaux.get(i, j));
		}
	}
}