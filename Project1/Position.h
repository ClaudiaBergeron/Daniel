#pragma once
#include "Random.h"

class Position {
private:
	int ligne;
	int colonne;
public:
	Position();
	Position(int l, int c);

	int getLine() const;
	int getColumn() const;

	void set(int l, int c);
	void setLine(int l);
	void setColumn(int c);

	Position North() const;
	Position South() const;
	Position West() const;
	Position East() const;

	void Randomize();

	bool operator==(Position pos) const;
	bool operator!=(Position pos) const;
}; #pragma once
