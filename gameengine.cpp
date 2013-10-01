#include "gameengine.h"

namespace DoodleBugGameOrtell
{
	GameEngine::GameEngine( )
	{
		populate_gameBoard( );
	}

	Ant& GameEngine::get_ant_from_ants_deque(int index)
	{
		return m_ants[index];
	}

	DoodleBug& GameEngine::get_doodleBug_from_doodlebugs_deque(int index)
	{
		return m_doodleBugs[index];
	}

	void GameEngine::populate_gameBoard( )
	{

		while(m_ants.size( ) < STARTING_SIZE_OF_ANTS)
		{
			int x = rand( ) % ROWS;
			int y = rand( ) % COLUMNS;

			if (m_gameBoard.get_contents_of_chosen_cell(Location(x, y)) == '*')
			{
				m_ants.push_back(Ant(Location(x, y), 'A', 0));
				m_gameBoard.add_ant_to_gameBoard(Ant(Location(x, y), 'A', 0));
			}
		}

		while (m_doodleBugs.size( ) < STARTING_SIZE_OF_DOODLEBUGS)
		{
			int x = rand( ) % ROWS;
			int y = rand( ) % COLUMNS;

			if (m_gameBoard.get_contents_of_chosen_cell(Location(x, y)) == '*')
			{
				m_doodleBugs.push_back(DoodleBug(Location(x, y), 'D', 0, 0));
				m_gameBoard.add_doodleBug_to_gameBoard(DoodleBug(Location(x, y), 'D', 0, 0));
			}
		}
	}

	void GameEngine::move_ant(Ant& ant_2_move)
	{
		Location desired_cell = m_gameBoard.pick_random_surrounding_cell(ant_2_move.get_location( ));

		if (m_gameBoard.get_contents_of_chosen_cell(desired_cell) == '*')
		{
			m_gameBoard.remove_organism_from_gameBoard(ant_2_move.get_location( ));
			ant_2_move.set_location(desired_cell);
			m_gameBoard.add_ant_to_gameBoard(ant_2_move);

			(ant_2_move.get_steps_till_breed( ) == ANTS_STEPS_TILL_BREED) ? breed_ant(ant_2_move) :
				ant_2_move.set_steps_till_breed(ant_2_move.get_steps_till_breed( )+1);
		}
	}

	void GameEngine::breed_ant(Ant& ant_2_move)
	{
		Location spawns_cell = m_gameBoard.check_for_empty_cell(ant_2_move.get_location( ));

		if (spawns_cell != ant_2_move.get_location( ))
		{
			m_ants.push_back(Ant(spawns_cell, 'A', 0));
			m_gameBoard.add_ant_to_gameBoard(Ant(spawns_cell, 'A', 0));
			ant_2_move.set_steps_till_breed(0);
		}
	}

	void GameEngine::eat_ant(Location& location_of_ant_2_eat)
	{
		for (unsigned int i =0; i < m_ants.size(); i++)
		{
			if (m_ants[i].get_location( ) == location_of_ant_2_eat)
			{
				m_ants.erase(m_ants.begin( ) + i);
			}
		}
	}

	void GameEngine::move_doodleBug(DoodleBug& doodleBug_2_move, int index)
	{
		Location desired_cell = m_gameBoard.check_for_ant_cell(doodleBug_2_move.get_location( ));

		if (m_gameBoard.get_contents_of_chosen_cell(desired_cell) == 'A')
		{
			m_gameBoard.remove_organism_from_gameBoard(desired_cell);
			m_gameBoard.remove_organism_from_gameBoard(doodleBug_2_move.get_location( ));

			eat_ant(desired_cell);

			doodleBug_2_move.set_location(desired_cell);
			m_gameBoard.add_doodleBug_to_gameBoard(doodleBug_2_move);

			doodleBug_2_move.set_steps_till_death(0);

			(doodleBug_2_move.get_steps_till_breed( ) == DOODLEBUGS_STEPS_TILL_BREED) ?
				breed_doodleBug(doodleBug_2_move) :
				doodleBug_2_move.set_steps_till_breed(doodleBug_2_move.get_steps_till_breed( )+1);
		}
		else
			randomly_move_doodleBug(doodleBug_2_move, index);
	}

	void GameEngine::randomly_move_doodleBug(DoodleBug& doodleBug_2_move, int index)
	{
		Location desired_cell = m_gameBoard.check_for_empty_cell(doodleBug_2_move.get_location( ));

		if (desired_cell != doodleBug_2_move.get_location( ))
		{
			m_gameBoard.remove_organism_from_gameBoard(doodleBug_2_move.get_location( ));
			doodleBug_2_move.set_location(desired_cell);
			m_gameBoard.add_doodleBug_to_gameBoard(doodleBug_2_move);

			(doodleBug_2_move.get_steps_till_death( ) == DOODLEBUGS_STEPS_TILL_DEATH) ?
				kill_doodlebug(doodleBug_2_move, index) :
				doodleBug_2_move.set_steps_till_death(doodleBug_2_move.get_steps_till_death( )+1);

			(doodleBug_2_move.get_steps_till_breed( ) == DOODLEBUGS_STEPS_TILL_BREED) ?
				breed_doodleBug(doodleBug_2_move) :
				doodleBug_2_move.set_steps_till_breed(doodleBug_2_move.get_steps_till_breed( )+1);
		}
	}

	void GameEngine::breed_doodleBug(DoodleBug& doodleBug_2_breed)
	{
		Location spawns_cell = m_gameBoard.check_for_empty_cell(doodleBug_2_breed.get_location( ));

		if (spawns_cell != doodleBug_2_breed.get_location( ))
		{
			m_gameBoard.add_doodleBug_to_gameBoard(DoodleBug(spawns_cell, 'D', 0, 0));
			m_doodleBugs.push_back(DoodleBug(spawns_cell, 'D', 0, 0));
			doodleBug_2_breed.set_steps_till_breed(0);
		}
	}

	void GameEngine::kill_doodlebug(DoodleBug& doodleBug_2_kill, int index)
	{
		m_gameBoard.remove_organism_from_gameBoard(doodleBug_2_kill.get_location( ));
		m_doodleBugs.erase(m_doodleBugs.begin( ) + index);
	}

	void GameEngine::draw_gameBoard_2_console( )
	{
		for(int i =0; i < ROWS; i++)
		{
			for(int j =0; j < COLUMNS; j++)
			{
				std::cout << m_gameBoard.get_contents_of_chosen_cell(Location(i, j)) << " ";
			}
			std::cout << std::endl;
		}
	}

	int GameEngine::get_size_of_ants_deque( )
	{
		return m_ants.size( );
	}

	int GameEngine::get_size_of_doodleBugs_deque( )
	{
		return m_doodleBugs.size( );
	}

}//DoodlebugGameOrtell
