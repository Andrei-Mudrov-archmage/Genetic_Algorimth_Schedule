#include "Meeting.h"

int Meeting::get_start_time()
{
	return m_start_time;
}

int Meeting::get_end_time()
{
	return m_end_time;
}

day_type Meeting::get_day_type()
{
	return m_day;
}

void Meeting::randomize()
{
	int which_day = rand() % 8 + 1;
	int which_time;
	switch (which_day)
	{
	case 1:
		m_day = MWF;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 1;
		while (m_start_time == 12 || m_start_time == 24)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 1;
		}
		break;
	case 2:
		m_day = MW;
		which_time = rand() % 6;
		switch (which_time)
		{
			case 0:
				m_start_time = 8;
				break;
			case 1:
				m_start_time = 10;
				break;
			case 2:
				m_start_time = 13;
				break;
			case 3:
				m_start_time = 15;
				break;
			case 4:
				m_start_time = 17;
				break;
			case 5:
				m_start_time = 19;
				break;
		}
		m_end_time = m_start_time + 2;
		break;
	case 3:
		m_day = TR;
		which_time = rand() % 6;
		switch (which_time)
		{
		case 0:
			m_start_time = 8;
			break;
		case 1:
			m_start_time = 10;
			break;
		case 2:
			m_start_time = 13;
			break;
		case 3:
			m_start_time = 15;
			break;
		case 4:
			m_start_time = 17;
			break;
		case 5:
			m_start_time = 19;
			break;
		}
		m_end_time = m_start_time + 2;
		break;
	case 4:
		m_day = M;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 3;
		while ( (9 < m_start_time && m_start_time < 13) || m_start_time > 21)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 3;
		}
		break;
	case 5:
		m_day = T;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 3;
		while ((9 < m_start_time && m_start_time < 13) || m_start_time > 21)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 3;
		}
		break;
	case 6:
		m_day = W;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 3;
		while ((9 < m_start_time && m_start_time < 13) || m_start_time > 21)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 3;
		}
		break;
	case 7:
		m_day = R;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 3;
		while ((9 < m_start_time && m_start_time < 13) || m_start_time > 21)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 3;
		}
		break;
	case 8:
		m_day = F;
		m_start_time = rand() % 24;
		m_end_time = m_start_time + 3;
		while ((9 < m_start_time && m_start_time < 13) || m_start_time > 21)
		{
			m_start_time = rand() % 24;
			m_end_time = m_start_time + 3;
		}
		break;
	}
}
