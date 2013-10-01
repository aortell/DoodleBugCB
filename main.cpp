#include "gameengine.h"
#include <unistd.h>

using namespace DoodleBugGameOrtell;

int main( )
{
    int loop_iterations =0;
    GameEngine test_engine;
    test_engine.draw_gameBoard_2_console( );

    std::cout << std::endl;

    while (test_engine.get_size_of_ants_deque( ) > 0 && test_engine.get_size_of_doodleBugs_deque( ) > 0)
    {
        for (int i =0; i < test_engine.get_size_of_doodleBugs_deque( ); i++)
             test_engine.move_doodleBug(test_engine.get_doodleBug_from_doodlebugs_deque(i), i);

        for (int i =0; i < test_engine.get_size_of_ants_deque( ); i++)
             test_engine.move_ant(test_engine.get_ant_from_ants_deque(i));

        test_engine.draw_gameBoard_2_console( );
        std::cout << "Ants: " << test_engine.get_size_of_ants_deque( ) << " "
                  << "DoodleBugs: " << test_engine.get_size_of_doodleBugs_deque( )
                  << " "  << "Loop Iterations: " << loop_iterations << std::endl;
        const int sleep_time = 1000;
        std::cout << std::endl;
        sleep(1);
        loop_iterations++;
     }
     (test_engine.get_size_of_ants_deque( ) == 0) ? std::cout << "DoodleBugs Win!\n" :
         std::cout << "Ants Win!\n";

    return 0;
}
