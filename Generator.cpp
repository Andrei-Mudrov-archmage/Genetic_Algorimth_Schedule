#include "Generator.h"

void Loader::load()
{
	string input;
	m_sections = new string[1];
	m_instructors = new string[1];
	string* temp = new string[1];
	sections.open(FILE_NAME);
	int i = 0;
	size = 0;
	while (sections.peek() != EOF)
	{
		if (i > 0)
		{
			delete[] temp;
			temp = new string[i];
			for (int ii = 0; ii < i; ii++)
			{
				temp[ii] = m_sections[ii];
			}
			delete[] m_sections;
			m_sections = new string[i + 1];
			for (int ii = 0; ii < i; ii++)
			{
				m_sections[ii] = temp[ii];
			}
			delete[] temp;
			temp = new string[i];
			for (int ii = 0; ii < i; ii++)
			{
				temp[ii] = m_instructors[ii];
			}
			delete[] m_instructors;
			m_instructors = new string[i + 1];
			for (int ii = 0; ii < i; ii++)
			{
				m_instructors[ii] = temp[ii];
			}
		}
		sections >> input;
		m_sections[i] = input;
		input = "";
		sections >> input;
		m_instructors[i] = input;
		i++;
		size++;
	}
}

void Loader::generate_schedule(Schedule& to_be_generated)
{
	for (int i = 0; i < size; i++)
	{
		Meeting meeting;
		meeting.randomize();
		Section section;
		section.m_course_identifier = m_sections[i];
		section.m_instructor_last_name = m_instructors[i];
		section.m_meeting = meeting;
		section.m_next_section = nullptr;
		section.m_previous_section = nullptr;
		to_be_generated.add_section(section);
	}
}
