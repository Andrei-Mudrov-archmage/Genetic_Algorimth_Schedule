#include "Rules.h"


int Rule_Overlap::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	for (int i = 0; i < size_of_grading; i++)
	{
		int ED1 = to_grade[i].m_meeting.get_end_time();
		int ST1 = to_grade[i].m_meeting.get_start_time();
		string name1 = to_grade[i].m_instructor_last_name;
		day_type day1 = to_grade[i].m_meeting.get_day_type();
		for (int ii = i +1; ii < size_of_grading; ii++)
		{
			string name2 = to_grade[ii].m_instructor_last_name;
			if (name1 == name2)
			{
				int ST2 = to_grade[ii].m_meeting.get_start_time();
				day_type day2 = to_grade[ii].m_meeting.get_day_type();
				switch (day1)
				{
				case MWF:
					switch (day2)
					{
					case MWF:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case MW:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case M:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case W:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case F:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case MW:
					switch (day2)
					{
					case MWF:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case MW:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case M:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case W:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case TR:
					switch (day2)
					{
					case TR:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case T:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case R:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case M:
					switch (day2)
					{
					case MWF:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case MW:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case M:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case T:
					switch (day2)
					{;
					case TR:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case T:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case W:
					switch (day2)
					{
					case MWF:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case MW:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case W:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case R:
					switch (day2)
					{
					case TR:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case R:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				case F:
					switch (day2)
					{
					case MWF:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					case F:
						if (ST1 <= ST2 && ED1 > ST2)  total_result +=  OVERLAP;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
		}
	}
	return total_result;
}

int Rule_Max_Working_Hours::grade(Schedule& to_grade)
{
	int total_result = 0;
	string checked_instructors = "";
	int number_of_hours[5] = { 0,0,0,0,0 };
	int size_of_grading = to_grade.get_size();
	for (int i = 0; i < size_of_grading; i++)
	{
		size_t found = checked_instructors.find(to_grade[i].m_instructor_last_name);
		if (found == string::npos)
		{
			string name1 = to_grade[i].m_instructor_last_name;
			for (int ii = 0; ii < size_of_grading; ii++)
			{
				string name2 = to_grade[ii].m_instructor_last_name;
				if (name1 == name2)
				{
					day_type day2 = to_grade[ii].m_meeting.get_day_type();
					switch (day2)
					{
					case MWF:
						number_of_hours[0]+= 1;
						number_of_hours[2]+= 1;
						number_of_hours[4]+= 1;
						break;
					case MW:
						number_of_hours[0]+= 2;
						number_of_hours[2]+= 2;
						break;
					case TR:
						number_of_hours[1]+= 2;
						number_of_hours[3]+= 2;
						break;
					case M:
						number_of_hours[0]+= 3;
						break;
					case T:
						number_of_hours[1]+= 3;
						break;
					case W:
						number_of_hours[2]+= 3;
						break;
					case R:
						number_of_hours[3]+= 3;
						break;
					case F:
						number_of_hours[4]+= 3;
						break;
					default:
						break;
					}
				}
			}
			for (int ii = 0; ii < 5; ii++)
			{
				if (number_of_hours[ii] > 9) total_result += MAX_WORKING_HOURS;
			}
			checked_instructors += to_grade[i].m_instructor_last_name + " ";
		}
	}
	return total_result;
}

int Rule_Evening_Morning_Overlap::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	for (int i = 0; i < size_of_grading; i++)
	{
		int ST1 = to_grade[i].m_meeting.get_start_time();
		if (ST1 > 17)
		{
			day_type day1 = to_grade[i].m_meeting.get_day_type();
			string name1 = to_grade[i].m_instructor_last_name;
			for (int ii = 0; ii < size_of_grading; ii++)
			{
				string name2 = to_grade[ii].m_instructor_last_name;
				int ST2 = to_grade[ii].m_meeting.get_start_time();
				if (name1 == name2 && ST2 < 11)
				{
					int ST2 = to_grade[ii].m_meeting.get_start_time();
					day_type day2 = to_grade[ii].m_meeting.get_day_type();
					switch (to_grade[i].m_meeting.get_day_type())
					{
					case MWF:
						switch (day2)
						{
						case TR:
							total_result += EVENING_MORNING_OVERLAP;
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case T:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case R:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case MW:
						switch (day2)
						{
						case TR:
							total_result += EVENING_MORNING_OVERLAP;
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case T:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case R:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case TR:
						switch (day2)
						{
						case MWF:
							total_result += EVENING_MORNING_OVERLAP;
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case MW:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case W:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case F:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case M:
						switch (day2)
						{
						case TR:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case M:
							break;
						case T:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case T:
						switch (day2)
						{
						case MWF:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case MW:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case W:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case W:
						switch (day2)
						{
						case TR:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case T:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					case R:
						switch (day2)
						{
						case MWF:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						case F:
							total_result += EVENING_MORNING_OVERLAP;
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
	return total_result;
}

int Rule_Back_Back_Classes::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	for (int i = 0; i < size_of_grading; i++)
	{
		int ED1 = to_grade[i].m_meeting.get_end_time();
		string name1 = to_grade[i].m_instructor_last_name;
		for (int ii = 0; ii < size_of_grading; ii++)
		{
			string name2 = to_grade[ii].m_instructor_last_name;
			if (name1 == name2)
			{
				int ST2 = to_grade[ii].m_meeting.get_start_time();
				day_type day2 = to_grade[ii].m_meeting.get_day_type();
				switch (to_grade[i].m_meeting.get_day_type())
				{
				case MWF:
					switch (day2)
					{
					case MWF:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case MW:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case M:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case W:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case F:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case MW:
					switch (day2)
					{
					case MWF:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case MW:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case M:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case T:
						break;
					case W:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case TR:
					switch (day2)
					{
					case TR:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case M:
						break;
					case T:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case R:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case M:
					switch (day2)
					{
					case MWF:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case MW:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case M:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case T:
					switch (day2)
					{
					case TR:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case T:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case W:
					switch (day2)
					{
					case MWF:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case MW:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case W:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case R:
					switch (day2)
					{
					case TR:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case R:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				case F:
					switch (day2)
					{
					case MWF:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					case F:
						if (ED1 == ST2)  total_result += BACK_TO_BACK_CLASSES;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
		}
	}
	return total_result;
}

int Rule_After_Common_Hours::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	for (int i = 0; i < size_of_grading; i++)
	{
		int ED1 = to_grade[i].m_meeting.get_end_time();
		int ST1 = to_grade[i].m_meeting.get_start_time();
		if (ST1 == 13 || ED1 == 12) total_result += MAX_WORKING_HOURS;
	}
	return total_result;
}

int Rule_More_Than_Three_Classes_Per_Day::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	string checked_instructors = "";
	int number_of_classes[5] = { 0,0,0,0,0 };
	for (int i = 0; i < size_of_grading ;i++)
	{
		string name1 = to_grade[i].m_instructor_last_name;
		size_t found = checked_instructors.find(name1);
		if (found == string::npos)
		{
			for (int ii = 0; ii < size_of_grading; ii++)
			{
				string name2 = to_grade[ii].m_instructor_last_name;
				if (name1 == name2)
				{
					day_type day2 = to_grade[ii].m_meeting.get_day_type();
					switch (day2)
					{
					case MWF:
						number_of_classes[0]++;
						number_of_classes[2]++;
						number_of_classes[4]++;
						break;
					case MW:
						number_of_classes[0]++;
						number_of_classes[2]++;
						break;
					case TR:
						number_of_classes[1]++;
						number_of_classes[3]++;
						break;
					case M:
						number_of_classes[0]++;
						break;
					case T:
						number_of_classes[1]++;
						break;
					case W:
						number_of_classes[2]++;
						break;
					case R:
						number_of_classes[3]++;
						break;
					case F:
						number_of_classes[4]++;
						break;
					}
				}
			}
			for (int ii = 0; ii < 5; ii++)
			{
				if (number_of_classes[ii] > 3) total_result += MORE_THAN_THREE_CLASSES_PER_DAY;
			}
			checked_instructors += name1 + " ";
		}
	}
	return total_result;
}

int Rule_More_Than_One_Three_Hour_Class_Per_Day::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	string checked_instructors = "";
	int number_of_classes[5] = {0,0,0,0,0};
	for (int i = 0; i < size_of_grading; i++)
	{
		string name1 = to_grade[i].m_instructor_last_name;
		size_t found = checked_instructors.find(name1);
		if (found == string::npos)
		{
			for (int ii = 0; ii < size_of_grading; ii++)
			{
				string name2 = to_grade[ii].m_instructor_last_name;
				if (name1 == name2)
				{
					day_type day2 = to_grade[ii].m_meeting.get_day_type();
					switch (day2)
					{
					case M:
						number_of_classes[0]++;
						break;
					case T:
						number_of_classes[1]++;
						break;
					case W:
						number_of_classes[2]++;
						break;
					case R:
						number_of_classes[3]++;
						break;
					case F:
						number_of_classes[4]++;
						break;
					}
				}
			}
			for (int ii = 0; ii < 5; ii++)
			{
				if(number_of_classes[ii] > 1) total_result += MORE_THAN_ONE_THREE_HOUR_CLASS_PER_DAY;
			}
			checked_instructors += name1 + " ";
		}
	}
	return total_result;
}

int Rule_More_Than_two_Evenings::grade(Schedule& to_grade)
{
	int total_result = 0;
	int size_of_grading = to_grade.get_size();
	string checked_instructors = "";
	int number_of_evenings = 0;
	for (int i = 0; i < size_of_grading; i++)
	{
		string name1 = to_grade[i].m_instructor_last_name;
		size_t found = checked_instructors.find(name1);
		if (found == string::npos)
		{
			for (int ii = 0; ii < size_of_grading; ii++)
			{
				int ST2 = to_grade[ii].m_meeting.get_start_time();
				string name2 = to_grade[ii].m_instructor_last_name;
				if (name1 == name2 && ST2 > 17)
				{
					number_of_evenings++;
				}
			}
			if (number_of_evenings > 2)
			{
				total_result += MORE_THAN_TWO_EVENINGS;
			}
			checked_instructors += name1 + " ";
		}
	}
	return total_result;
}
