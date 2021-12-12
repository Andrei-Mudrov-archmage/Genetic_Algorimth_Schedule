// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "Optimizer.h"

using namespace std;



int main()
{
    srand(time(NULL));
    Optimizer optimizer;
    optimizer.repopulate();
	/*Loader loader;
	Rule* rules[8];
	rules[0] = new Rule_After_Common_Hours;
	rules[1] = new Rule_Back_Back_Classes;
	rules[2] = new Rule_Evening_Morning_Overlap;
	rules[3] = new Rule_Max_Working_Hours;
	rules[4] = new Rule_More_Than_One_Three_Hour_Class_Per_Day;
	rules[5] = new Rule_More_Than_Three_Classes_Per_Day;
	rules[6] = new Rule_More_Than_two_Evenings;
	rules[7] = new Rule_Overlap;
	loader.load();
	int score = 0;
	Schedule test;
	while (score == 0)
	{
		test = loader.generate_schedule();
		score = rules[7]->grade(test);
		test.score = score;
		cout << test.display() << endl;
	}*/


}
