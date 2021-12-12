#include "Schedule.h"
#include "Schedule.h"

void Schedule::add_section(Section section_to_add)
{
	if (m_head == nullptr)
	{
		m_head = new Section;
		m_head->m_course_identifier = section_to_add.m_course_identifier;
		m_head->m_instructor_last_name = section_to_add.m_instructor_last_name;
		m_head->m_meeting = section_to_add.m_meeting;
		m_head->m_next_section = nullptr;
		m_head->m_previous_section = nullptr;
	}
	else
	{
		Section* moving_object = m_head;
		while (!(moving_object->m_next_section == nullptr))
		{
			moving_object = moving_object->m_next_section;
		}
		moving_object->m_next_section = new Section;
		moving_object->m_next_section->m_previous_section = moving_object;
		moving_object->m_next_section->m_course_identifier = section_to_add.m_course_identifier;
		moving_object->m_next_section->m_instructor_last_name = section_to_add.m_instructor_last_name;
		moving_object->m_next_section->m_meeting = section_to_add.m_meeting;
		moving_object->m_next_section->m_next_section = nullptr;
	}
	size++;
}

void Schedule::add_schedule(Schedule schedule_to_add)
{

	if (m_head == nullptr)
	{
		m_head = schedule_to_add.m_head;
	}
	else
	{
		Section* moving_object = m_head;
		while (!(moving_object->m_next_section == nullptr))
		{
			moving_object = moving_object->m_next_section;
		}
		moving_object->m_next_section = schedule_to_add.m_head;
		moving_object->m_next_section->m_previous_section = moving_object;
	}

	
}

void Schedule::split(Schedule parent_B)
{
	Section* moving_object_split_A =this->m_head;
	Section* moving_object_split_B = parent_B.m_head;
	int point_of_split = 0;
	int number_of_genes_exchanged = rand() % int(this->get_size() / 2);
	for (int i = 0; i < number_of_genes_exchanged; i++)
	{
		point_of_split = rand() % this->get_size();
		moving_object_split_A = this->m_head;
		moving_object_split_B = parent_B.m_head;
		if (point_of_split != 0 && point_of_split != (this->get_size()-1))
		{
			for (int ii = 0; ii < point_of_split; ii++)
			{
				moving_object_split_A = moving_object_split_A->m_next_section;
				moving_object_split_B = moving_object_split_B->m_next_section;
			}
			Section* moving_object_previous_A = moving_object_split_A->m_previous_section;
			Section* moving_object_previous_B = moving_object_split_B->m_previous_section;
			Section* moving_object_next_A = moving_object_split_A->m_next_section;
			Section* moving_object_next_B = moving_object_split_B->m_next_section;
			moving_object_previous_A->m_next_section = moving_object_split_B;
			moving_object_split_B->m_previous_section = moving_object_previous_A;
			moving_object_next_A->m_previous_section = moving_object_split_B;
			moving_object_split_B->m_next_section = moving_object_next_A;
			moving_object_previous_B->m_next_section = moving_object_split_A;
			moving_object_split_A->m_previous_section = moving_object_previous_B;
			moving_object_next_B->m_previous_section = moving_object_split_A;
			moving_object_split_A->m_next_section = moving_object_next_B;
		}
		else if (this->get_size() - 1 == point_of_split)
		{
			for (int ii = 0; ii < point_of_split; ii++)
			{
				moving_object_split_A = moving_object_split_A->m_next_section;
				moving_object_split_B = moving_object_split_B->m_next_section;
			}
			Section* moving_object_previous_A = moving_object_split_A->m_previous_section;
			Section* moving_object_previous_B = moving_object_split_B->m_previous_section;
			moving_object_previous_A->m_next_section = moving_object_split_B;
			moving_object_split_B->m_previous_section = moving_object_previous_A;
			moving_object_previous_B->m_next_section = moving_object_split_A;
			moving_object_split_A->m_previous_section = moving_object_previous_B;
		}
		else
		{
			Section* moving_object_next_A = moving_object_split_A->m_next_section;
			Section* moving_object_next_B = moving_object_split_B->m_next_section;
			moving_object_next_A->m_previous_section = moving_object_split_B;
			moving_object_split_B->m_next_section = moving_object_next_A;
			moving_object_next_B->m_previous_section = moving_object_split_A;
			moving_object_split_A->m_next_section = moving_object_next_B;
			this->m_head = moving_object_split_B;
			parent_B.m_head = moving_object_split_A;
		}
	}

}

Section Schedule::operator[](int index) const
{
	Section* moving_object = m_head;

	for(int i = 0; i < index;i++)
	{
		moving_object = moving_object->m_next_section;
	}
	return *moving_object;
}

string Schedule::display() const
{
	string result;
	Section* moving_object = m_head;
	Section to_display;
	result = "Schedule: \n";
	for (int i = 0; i < size; i++)
	{
		to_display = *moving_object;
		result += to_display.m_course_identifier;
		result += " ";
		result += to_display.m_instructor_last_name;
		result += " ";
		result += to_string(to_display.m_meeting.get_day_type());
		result += " ";
		result = result + "Starting time: " + to_string(to_display.m_meeting.get_start_time());
		result += " ";
		result = result + "Ending time: " + to_string(to_display.m_meeting.get_end_time());
		result += "\n";
		moving_object = moving_object->m_next_section;

	}
	result = result + "Score: " + to_string(score);
	return result;
}


Schedule::Schedule()
{
	m_head = nullptr;
	size = 0;
}

int Schedule::get_size() const
{
	return size;
}
Schedule::Schedule(const Schedule& schedule)
{
	m_head = nullptr;
	size = 0;
	for (int i = 0; i < schedule.get_size(); i++)
	{
		this->add_section(schedule[i]);
	}
}
Schedule::~Schedule()
{
	Section* moving_object = m_head;
	Section* next;
	/*while (moving_object != nullptr)
	{
		next = moving_object->m_next_section;
		delete moving_object;
		moving_object = next;
	}*/

}

