#pragma once
#include "Schedule.h"
#include "Config.h"
class Rule
{
public:
	virtual int grade(Schedule& to_grade) = 0;
};

class Rule_Overlap : public Rule
{
	virtual int grade(Schedule& to_grade);
};

class Rule_Max_Working_Hours : public Rule
{
	virtual int grade(Schedule& to_grade);
};

class Rule_Evening_Morning_Overlap : public Rule
{
	virtual int grade(Schedule& to_grade);
};

class Rule_Back_Back_Classes : public Rule
{
	virtual int grade(Schedule& to_grade);
};

class Rule_After_Common_Hours : public Rule
{
	virtual int grade(Schedule& to_grade);
};

class Rule_More_Than_Three_Classes_Per_Day : public Rule
{
	virtual int grade(Schedule& to_grade);
};
class Rule_More_Than_One_Three_Hour_Class_Per_Day : public Rule
{
	virtual int grade(Schedule& to_grade);
};
class Rule_More_Than_two_Evenings : public Rule
{
	virtual int grade(Schedule& to_grade);
};