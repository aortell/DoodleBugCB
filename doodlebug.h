#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"


namespace DoodleBugGameOrtell
{
	class DoodleBug : public Organism
	{
	public:
		DoodleBug( );
		DoodleBug(Location postion, char species, int steps_till_breed, int steps_till_death);
		char get_species( );
		Location& get_location( );
		void set_steps_till_breed(const int count);
		void set_steps_till_death(const int count);
		int get_steps_till_breed( ) const;
		int get_steps_till_death( ) const;

	private:
		int m_steps_till_breed;
		int m_steps_till_death;
	};
} // DoodleBugGameOrtell

#endif // DOODLEBUG_H
