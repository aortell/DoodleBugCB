#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include <iostream>
#include "location.h"
#include "constants.h"
#include "ant.h"
#include "doodlebug.h"

namespace DoodleBugGameOrtell
{
	class GameBoard
	{
	public:
		GameBoard( );
		Location check_for_empty_cell(Location& current_cell);
		Location check_for_ant_cell(Location& current_cell);
		Location pick_random_surrounding_cell(Location& current_cell);
		char get_contents_of_chosen_cell(Location chosen_cell);
		void remove_organism_from_gameBoard(Location& cell);
		void add_ant_to_gameBoard(Ant ant);
		void add_doodleBug_to_gameBoard(DoodleBug player);

	private:
		Organism m_gameBoard[ROWS][COLUMNS];
	};
}//DoodleBugGameOrtell

#endif // GAMEBOARD_H
