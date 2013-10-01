#include "location.h"

namespace DoodleBugGameOrtell
{
	Location::Location( )
	{  }

	Location::Location(		int x,
							int y):
							m_x ((x - 1) <= 19 && (x + 1) >= 0 ? x : 0),
							m_y ((y - 1) <= 19 && (y + 1) >= 0 ? y : 0)
	{  }

	Location::Location(const Location& other)
	{
		this->m_x = other.m_x;
		this->m_y = other.m_y;
	}

	Location& Location::operator=(const Location& other)
	{
		this->m_x = other.m_x;
		this->m_y = other.m_y;
		return *this;
	}

	int Location::get_xpoint( ) const
	{
		return m_x;
	}

	int Location::get_ypoint( ) const
	{
		return m_y;
	}

	void Location::set_xpoint(const int x)
	{
		m_x = x;
	}

	void Location::set_ypoint(const int y)
	{
		m_y = y;
	}

	bool operator==(const Location& lhs, const Location& rhs)
	{
		return (lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y);
	}

	bool operator!=(const Location& lhs, const Location& rhs)
	{
		return !(lhs == rhs);
	}
}//DoodleBugGameOrtell
