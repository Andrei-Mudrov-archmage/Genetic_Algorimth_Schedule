#pragma once
#include <string>
using namespace std;

enum day_type { MWF, TR, MW, M, T, W, R, F };

class Meeting
{
public:
	int get_start_time();
	int get_end_time();
	day_type get_day_type();
	void randomize();
private:
	day_type m_day;
	int m_start_time;
	int m_end_time;
};