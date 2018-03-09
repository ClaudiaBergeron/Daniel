#include "Jeu.h"

#include <iostream>

using namespace std;

Jeu::Jeu()
{
}

/**
*  \brief Effectue la boucle de jeu
*  \return Aucun
*/
void Jeu::Jouer()
{
	char colonne;
	int ligne;

	joueur.AfficherTirs();
	joueur.AfficherBateaux();
	ordinateur.AfficherTirs();
	ordinateur.AfficherBateaux();
	cout << "=================================================" << endl;
	cout << "Entrez la position colonne (q pour quitter) : ";
	cin >> colonne;

	while (colonne != 'q')
	{
		cout << "Entrez la position ligne : ";
		cin >> ligne;
		cout << "=================================================" << endl;

		// On s'assure que les positions d'attaque demandees sont dans la grille
		if (PositionValide(ligne, colonne))
		{
			int ligneJoueur = ligne - 1;
			int colonneJoueur = colonne - 'A';
			// On verifie si l'attaque est valide (pas deja tiree)
			if (joueur.TirValide(ligneJoueur, colonneJoueur))
			{
				// Tour du joueur
				bool coule;
				// Verifie si l'attaque touche un bateau de l'adversaire
				if (ordinateur.ValiderAttaqueOpposant(ligneJoueur, colonneJoueur, coule))
				{
					// Si oui, on effectue une touche
					joueur.Touche(ligneJoueur, colonneJoueur, coule);

					// Verifie si l'ordinateur a perdu
					if (ordinateur.aPerdu())
					{
						// Si oui, on a gagne
						cout << "Vous avez gagne!" << endl;
						return;
					}
				}
				else
				{
					// Si non, on effectue un tir a l'eau
					joueur.Tir(ligneJoueur, colonneJoueur);
				}

				// Tour de l'ordinateur
				int ligneIA, colonneIA;
				// Genere l'attaque du joueur
				ordinateur.GenereAttaque(ligneIA, colonneIA);

				// Verifie si l'attaque de l'IA touche un bateau du joueur
				if (joueur.ValiderAttaqueOpposant(ligneIA, colonneIA, coule))
				{
					// Si oui, on effectue une touche
					ordinateur.Touche(ligneIA, colonneIA, coule);

					// Si le joueur a perdu
					if (joueur.aPerdu())
					{
						// L'ordinateur a gagne
						cout << "Vous avez perdu!" << endl;
						return;
					}
				}
				else
				{
					// Si non, on effectue un tir a l'eau
					ordinateur.Tir(ligneIA, colonneIA);
				}
			}
			else
			{
				cout << "/////////////////////////////////////////" << endl;
				cout << "Vous avez deja tire sur cette position!" << endl;
				cout << "Reessayez!" << endl;
				cout << "/////////////////////////////////////////" << endl << endl;
			}
		}
		else
		{
			cout << "/////////////////////////////////////////" << endl;
			cout << "Position invalide! Reessayez!" << endl;
			cout << "/////////////////////////////////////////" << endl << endl;
		}
		cout << "Tir Joueur" << endl;
		joueur.AfficherTirs();
		cout << "Bateau Joueur" << endl;
		joueur.AfficherBateaux();
		cout << "Tir Ordinateur" << endl;
		ordinateur.AfficherTirs();
		cout << "Bateaux Ordinateur" << endl;
		ordinateur.AfficherBateaux();
		cout << "=================================================" << endl;
		cout << "Entrez la position colonne, (q pour quitter) : ";
		cin >> colonne;
	}
}

/**
*  \brief Valide si la position est a l'interieur de la grille de jeu
*  \param[in] Numero de la ligne d'attaque
*  \param[in] Caractere de la colonne d'attaque
*  \return Vrai si la valeur est entre 1 et 10 pour la ligne et entre A et J pour la colonne
*/
bool Jeu::PositionValide(int ligne, char colonne) const
{
	return colonne >= 'A' && colonne <= 'J' && ligne >= 1 && ligne <= Grille::NB_LIGNE;
}