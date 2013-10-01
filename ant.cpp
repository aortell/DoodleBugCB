#include "ant.h"
#include <cstdlib>

namespace DoodleBugGameOrtell
{
	Ant::Ant( )
	{  }

	Ant::Ant(	Location points,
				char species,
				int steps_till_breed):
				Organism(points, species),
				m_steps_till_breed(steps_till_breed)
	{  }

	char Ant::get_species( )
	{
		return 'A';
	}

	Location& Ant::get_location( )
	{
		return Organism::get_location( );
	}

	void Ant::set_steps_till_breed(const int count)
	{
		m_steps_till_breed = count;
	}

	int Ant::get_steps_till_breed( ) const
	{
		return m_steps_till_breed;
	}
}//DoodleBugGameOrtell
