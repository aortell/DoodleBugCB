#include "organism.h"

namespace DoodleBugGameOrtell
{
	Organism::Organism( )
	{  }

	Organism::Organism(		Location points,
							char species):
							m_points(points),
							m_species(species)
	{  }

	Organism::Organism(const Organism& other)
	{
		this->m_points = other.m_points;
		this->m_species = other.m_species;
	}

	Organism& Organism::operator=(const Organism& other)
	{
		this->m_points = other.m_points;
		this->m_species = other.m_species;
		return *this;
	}

	char Organism::get_species( )
	{
		return m_species;
	}

	Location& Organism::get_location( )
	{
		return m_points;
	}

	void Organism::set_location(Location new_location) //validate x and y are >= 0 && <= 20
	{
		((new_location.get_xpoint( ) - 1) >= 0 && (new_location.get_xpoint( ) + 1) <= 19) ?
			m_points.set_xpoint(new_location.get_xpoint( )) : m_points.set_xpoint(m_points.get_xpoint( ));
		((new_location.get_ypoint( ) - 1) >= 0 && (new_location.get_ypoint( ) + 1) <= 19) ?
			m_points.set_ypoint(new_location.get_ypoint( )) : m_points.set_ypoint(m_points.get_ypoint( ));
	}
}//DoodleBugsGameOrtell
