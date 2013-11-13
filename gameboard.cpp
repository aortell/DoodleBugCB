#include "gameboard.h"
#include <stdlib.h>

namespace DoodleBugGameOrtell
{
	GameBoard::GameBoard( )   // populates gameBoard with empty organisms
	{
		for(int i =0; i < ROWS; i++)
			for(int j =0; j < COLUMNS; j++)
				m_gameBoard[i][j] = Organism(Location(i, j),'*');
	}

	void GameBoard::remove_organism_from_gameBoard(Location& cell)
	{
		m_gameBoard[cell.get_xpoint( )][cell.get_ypoint( )] = Organism(cell, '*');
	}

	void GameBoard::add_ant_to_gameBoard(Ant ant)
	{
		m_gameBoard[ant.get_location( ).get_xpoint( )][ant.get_location( ).get_ypoint( )] = ant;
	}

	void GameBoard::add_doodleBug_to_gameBoard(DoodleBug doodleBug)
	{
		m_gameBoard[doodleBug.get_location( ).get_xpoint( )][doodleBug.get_location( ).get_ypoint( )] = doodleBug;
	}

	Location GameBoard::pick_random_surrounding_cell(Location& current_cell)
	{
		switch(rand( ) % 4)
		{
		case 0: //<--- UP
			if(current_cell.get_xpoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE )
				return Location((current_cell.get_xpoint()-1), current_cell.get_ypoint());

		case 1: //<--- DOWN
			if (current_cell.get_xpoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE)
				return Location((current_cell.get_xpoint( )+1), current_cell.get_ypoint( ));

		case 2: //<--- LEFT
			if (current_cell.get_ypoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE)
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )-1);

		case 3: //<--- RIGHT
			if(current_cell.get_ypoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE)
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )+1);
		}
		return current_cell;
	}

	char GameBoard::get_contents_of_chosen_cell(Location chosen_cell)
	{
		return m_gameBoard[chosen_cell.get_xpoint( )][chosen_cell.get_ypoint( )].get_species( );
	}

	Location GameBoard::check_for_empty_cell(Location& current_cell)
	{
		if(current_cell.get_xpoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE) //<--- Up
			if(m_gameBoard[current_cell.get_xpoint( )-1][current_cell.get_ypoint( )].get_species( ) == '*')
				return Location((current_cell.get_xpoint( )-1), current_cell.get_ypoint( ));

		if(current_cell.get_xpoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE) //<--- Down
			if(m_gameBoard[current_cell.get_xpoint( )+1][current_cell.get_ypoint( )].get_species( ) == '*')
				return Location((current_cell.get_xpoint( )+1), current_cell.get_ypoint( ));

		if(current_cell.get_ypoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE) //<--- Left
			if(m_gameBoard[current_cell.get_xpoint( )][current_cell.get_ypoint( )-1].get_species( ) == '*')
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )-1);

		if(current_cell.get_ypoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE) //<--- Right
			if(m_gameBoard[current_cell.get_xpoint( )][current_cell.get_ypoint( )+1].get_species( ) == '*')
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )+1);

		return current_cell; // All are Occupied
	}

	Location GameBoard::check_for_ant_cell(Location& current_cell)
	{
		if(current_cell.get_xpoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE) //<--- Up
			if(m_gameBoard[current_cell.get_xpoint( )-1][current_cell.get_ypoint( )].get_species( ) == 'A')
				return Location((current_cell.get_xpoint( )-1), current_cell.get_ypoint( ));

		if(current_cell.get_xpoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE) //<--- Down
			if(m_gameBoard[current_cell.get_xpoint( )+1][current_cell.get_ypoint( )].get_species( ) == 'A')
				return Location((current_cell.get_xpoint( )+1), current_cell.get_ypoint( ));

		if(current_cell.get_ypoint( ) -1 >= GAMEBOARD_EDGE_BOTTOM_SIDE) //<--- Left
			if(m_gameBoard[current_cell.get_xpoint( )][current_cell.get_ypoint( )-1].get_species( ) == 'A')
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )-1);

		if(current_cell.get_ypoint( ) +1 <= GAMEBOARD_EDGE_HIGH_SIDE) //<--- Right
			if(m_gameBoard[current_cell.get_xpoint( )][current_cell.get_ypoint( )+1].get_species( ) == 'A')
				return Location((current_cell.get_xpoint( )), current_cell.get_ypoint( )+1);

		return current_cell; // All are Occupied
	}

}//DoodleBugGameOrtell
