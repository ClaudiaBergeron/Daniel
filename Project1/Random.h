#ifndef RANDOM_H
#define RANDOM_H

#include <random>

using namespace std;

class Random
{
public:
	static int GenereValeur(int min, int max)
	{
		static mt19937 generateur(0);
		uniform_int_distribution<> distribution(min, max);
		return distribution(generateur);
	}
};

#endif