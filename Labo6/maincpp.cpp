//
//  main.cpp
//  MAP-AVL
//
//  Aida Ouangraoua 23-11-17.
//  Copyleft 2017 UdeS
//

#include <string>
#include <iostream>
#include "map.h"

using namespace std;

int main(int argc, const char * argv[]) {
	map<double, double> M;
	M.afficher();
	M.verifier_hauteurs();
	auto i = M.begin();
	double x;
	for (x = 5; x <= 50; x += 5) {
		cout << "Insert " << x << endl;
		M.insert(x);
		M[x] = -x;
		M.afficher();
		M.verifier_hauteurs();
	}
	for (x = 50; x > 0; x -= 10) {
		cout << "Erase " << x << endl;
		M.erase(x);
	}
	M.afficher();
	cout << "Fin normale du programme" << endl;
	return 0;
}
