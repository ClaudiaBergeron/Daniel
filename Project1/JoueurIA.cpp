#include "JoueurIA.h"

#include "Constantes.h"
#include "Random.h"

#include <iostream>

using namespace std;

JoueurIA::JoueurIA() {
	attackMode = false;
	orientation = 0;
	nextHit.Randomize();
	realorientation = -1;
}

void JoueurIA::AfficherTirs() {
	self.AfficherTirs();
}

void JoueurIA::AfficherBateaux() {
	self.AfficherBateaux();
}

void JoueurIA::Touche(int ligne, int colonne, bool coule) {
	self.Touche(ligne, colonne, coule);
	if (coule) {
		attackMode = !attackMode;
		realorientation = -1;
		orientation = -1;
	}
	else {
		if (!attackMode) {             // premiere attaque qui touche
			initialHit.set(ligne, colonne);
			nextHit = initialHit;
			lastHit = nextHit;
			attackMode = !attackMode;
			orientation = 0;
		}
		else {						// attaque subsequente qui touche
			if (realorientation == -1) {
				if (initialHit.North() == nextHit) {
					realorientation = 0;
				}
				else if (initialHit.East() == nextHit) {
					realorientation = 1;
				}
				else if (initialHit.South() == nextHit) {
					realorientation = 2;
				}
				else {
					realorientation = 3;
				}
			}

			switch (realorientation) {
			case 0:
				nextHit = lastHit.North();
				break;
			case 1:
				nextHit = lastHit.East();
				break;
			case 2:
				nextHit = lastHit.South();
				break;
			case 3:
				nextHit = lastHit.West();
				break;
			default:
				break;
			}
		}
	}
}

void JoueurIA::Tir(int ligne, int colonne) {
	self.Tir(ligne, colonne);
}

bool JoueurIA::TirValide(int ligne, int colonne) const {
	return self.TirValide(ligne, colonne);
}

bool JoueurIA::ValiderAttaqueOpposant(int ligne, int colonne, bool& coule) {
	return self.ValiderAttaqueOpposant(ligne, colonne, coule);
}

bool JoueurIA::aPerdu() const {
	return self.aPerdu();
}

bool JoueurIA::ValiderCoule(int ligne, int colonne) const {
	return self.ValiderCoule(ligne, colonne);
}

void JoueurIA::GenereAttaque(int &ligne, int &colonne) {
	if (!attackMode) {
		do {
			nextHit.Randomize();
		} while (!self.TirValide(nextHit.getLine(), nextHit.getColumn()));
	}
	else {
		if (lastHit == nextHit) {
			if (realorientation == -1) {
				nextHit = initialHit;
				if (self.TirValide(nextHit.North().getLine(), nextHit.North().getColumn())) {
					orientation = 0;
					nextHit = nextHit.North();
				}
				else if (self.TirValide(nextHit.East().getLine(), nextHit.East().getColumn())) {
					orientation = 1;
					nextHit = nextHit.East();
				}
				else if (self.TirValide(nextHit.South().getLine(), nextHit.South().getColumn())) {
					orientation = 2;
					nextHit = nextHit.South();
				}
				else {
					orientation = 3;
					nextHit = nextHit.West();
				}
			}
			else {
				switch (realorientation) {
				case 0:
					realorientation = 2;
					nextHit = initialHit.South();
					break;
				case 1:
					realorientation = 3;
					nextHit = initialHit.West();
					break;
				default:
					attackMode = false;
					realorientation = -1;
					break;
				}
			}
		}
	}
	lastHit = nextHit;
	ligne = nextHit.getLine();
	colonne = nextHit.getColumn();
}
