#pragma once
#include "Meeting.h"
#include "Section.h"

class Schedule
{
public:
	void add_section(Section section_to_add);
	void add_schedule(Schedule schedule_to_add);
	void split(Schedule parent_B);
	Section operator[](int index) const;
	string display() const;
	Schedule();
	~Schedule();
	Schedule(const Schedule& schedule);
	int get_size() const;
	int score;
private:
	int size;
	Section* m_head;
};