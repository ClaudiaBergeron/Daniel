#include "Grille.h"

Grille::Grille()
{
	for (int i = 0; i < NB_LIGNE; ++i)
	{
		for (int j = 0; j < NB_COLONNE; ++j)
		{
			cases[i][j] = EAU;
		}
	}
}

Grille::Cases Grille::get(int ligne, int colonne) const
{
	return cases[ligne][colonne];
}

void Grille::set(int ligne, int colonne, Cases val)
{
	cases[ligne][colonne] = val;
}

ostream& operator<<(ostream& out, const Grille& grille)
{
	const char EAU = ' ';
	const char TIR = '0';
	const char TOUCHE = '*';

	out << "    ";
	for (char col = 'A'; col < 'K'; ++col)
	{
		out << col << ' ';
	}

	out << endl << "----";
	for (int i = 0; i < Grille::NB_COLONNE; ++i)
	{
		out << "--";
	}
	out << endl;
	for (int i = 0; i < Grille::NB_LIGNE; ++i)
	{
		out << i + 1;
		if ((i + 1) < 10)
			out << ' ';
		out << "| ";
		for (int j = 0; j < Grille::NB_COLONNE; ++j)
		{
			if (grille.cases[i][j] == Grille::EAU)
				out << EAU << ' ';
			else if (grille.cases[i][j] == Grille::TIR)
				out << TIR << ' ';
			else if (grille.cases[i][j] == Grille::TOUCHE)
				out << TOUCHE << ' ';
			else
				out << (int)grille.cases[i][j] << ' ';
		}
		out << endl;
	}

	out << "----";
	for (int i = 0; i < Grille::NB_COLONNE; ++i)
	{
		out << "--";
	}
	out << endl;

	return out;
}