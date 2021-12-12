#pragma once
#include "Schedule.h";
#include "Config.h"
#include <fstream>
#include<iostream>

using namespace std;

class Loader
{
public:
	void load();
	void generate_schedule(Schedule& to_be_generated);
private:
	string* m_instructors;
	string* m_sections;
	ifstream sections;
	int size = 0;

};