#ifndef JEU_H
#define JEU_H

#include "Joueur.h"
#include "JoueurIA.h"

class Jeu
{
private:
    Joueur joueur;
    JoueurIA ordinateur;

    bool PositionValide(int ligne, char colonne) const;

public:
    Jeu();

    void Jouer();
};

#endif