#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <deque>
#include "ant.h"
#include "doodlebug.h"
#include "gameboard.h"
#include "constants.h"

namespace DoodleBugGameOrtell
{
	class GameEngine
	{
	public:
		GameEngine( );
		Ant& get_ant_from_ants_deque(int index);
		DoodleBug& get_doodleBug_from_doodlebugs_deque(int index);
		void move_ant(Ant& ant_2_move);
		void breed_ant(Ant& ant_2_move);
		void move_doodleBug(DoodleBug& doodleBug_2_move, int index);
		void randomly_move_doodleBug(DoodleBug& doodleBug_2_move, int index);
		void eat_ant(Location& location_of_ant_2_eat);
		void breed_doodleBug(DoodleBug& doodleBug_2_breed);
		void kill_doodlebug(DoodleBug& doodleBug_2_kill, int index);
		void populate_gameBoard( );
		void draw_gameBoard_2_console( );
		int get_size_of_ants_deque( );
		int get_size_of_doodleBugs_deque( );

	private:
		GameBoard m_gameBoard;
		std::deque<Ant> m_ants;
		std::deque<DoodleBug> m_doodleBugs;
	};
}//DoodlebugGameOrtell

#endif // GAMEENGINE_H
