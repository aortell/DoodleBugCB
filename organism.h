#ifndef ORGANISM_H
#define ORGANISM_H


#include "location.h"
#include <iostream>

namespace DoodleBugGameOrtell
{
	class Organism
	{
	public:
		Organism( );
		Organism(Location postion, char species);
		Organism(const Organism& other);
		Organism& operator=(const Organism& other);
		void set_location(Location new_location);
		virtual Location& get_location( );
		virtual char get_species( );

	private:
		Location m_points;
		char m_species;
	};
}//DoodleBugGameOrtell
#endif // ORGANISM_H
