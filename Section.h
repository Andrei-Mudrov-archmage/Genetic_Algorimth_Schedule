#pragma once
#include "Meeting.h"
class Section
{
public:
	string m_course_identifier;
	string m_instructor_last_name;
	Meeting m_meeting;
	Section* m_next_section;
	Section* m_previous_section;
};