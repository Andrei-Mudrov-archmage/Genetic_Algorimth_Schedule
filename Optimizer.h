#pragma once
#include "Generator.h"
#include "Rules.h"

class Optimizer
{
private:
	void score();
	void find_elite();
	Schedule population[POPULATION_SIZE];
	Schedule elite[ELITE_SIZE];
	Loader loader;
	Rule* rules[8];
public:
	void repopulate();
	Optimizer();
};