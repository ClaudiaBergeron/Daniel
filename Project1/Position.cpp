#include "Position.h"
#include "Random.h"
#include "Grille.h"

Position::Position(int l, int c) {
	set(l, c);
}

Position::Position() {
	Position(0, 0);
}

int Position::getLine() const {
	return ligne;
}

int Position::getColumn() const {
	return colonne;
}

void Position::setLine(int l) {
	ligne = l;
}

void Position::setColumn(int c) {
	colonne = c;
}

void Position::set(int l, int c) {
	setLine(l);
	setColumn(c);
}

Position Position::East() const {
	return Position(ligne, colonne + 1);
}

Position Position::North() const {
	return Position(ligne - 1, colonne);
}

Position Position::South() const {
	return Position(ligne + 1, colonne);
}

Position Position::West() const {
	return Position(ligne, colonne - 1);
}

void Position::Randomize() {
	set(Random::GenereValeur(0, Grille::NB_LIGNE), Random::GenereValeur(0, Grille::NB_COLONNE));
}

bool Position::operator==(Position pos) const {
	return pos.getLine() == ligne && pos.getColumn() == colonne;
}

bool Position::operator!=(Position pos) const {
	return !operator==(pos);
}