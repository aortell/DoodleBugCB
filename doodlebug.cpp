#include "doodlebug.h"

namespace DoodleBugGameOrtell
{
	DoodleBug::DoodleBug( )
	{  }

	DoodleBug::DoodleBug(	Location postion,
							char species,
							int till_breed,
							int till_death):
							Organism(postion, species),
							m_steps_till_breed(till_breed),
							m_steps_till_death(till_death)
	{  }

	char DoodleBug::get_species( )
	{
		return 'D';
	}

	Location& DoodleBug::get_location( )
	{
		return Organism::get_location( );
	}

	void DoodleBug::set_steps_till_breed(const int count)
	{
		m_steps_till_breed = count;
	}

	void DoodleBug::set_steps_till_death(const int count)
	{
		m_steps_till_death = count;
	}

	int DoodleBug::get_steps_till_breed( ) const
	{
		return m_steps_till_breed;
	}

	int DoodleBug::get_steps_till_death( ) const
	{
		return m_steps_till_death;
	}
}//DoodlebugGameOrtell
