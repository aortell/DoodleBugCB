#ifndef ANT_H
#define ANT_H

#include "organism.h"

namespace DoodleBugGameOrtell
{
	class Ant : public Organism
	{
	public:
		Ant( );
		Ant(Location postion, char species, int steps_till_breed);
		char get_species( );
		Location& get_location( );
		void set_steps_till_breed(const int count);
		int get_steps_till_breed( ) const;

	private:
		int m_steps_till_breed;
	};
} // DoodleBugGameOrtell
#endif // ANT_H
