#include <stdio.h>
#include "tetris/tetris.h"

/**
 *  The main function, creates an App
 *  and currently holds the main app
 *  loop.
 *
 *  The app is made sure to be freed after 
 *  initialization before exit.
 */
int main(int argc, char* args[])
{
  // This will be the title of the Window
  char app_title[256] = "Tetris"; 

  engine_log("Creating and Initializing App"); 

  // Create and Initialize an App window
  // with the default values
  GridEngine* engine = init_engine(app_title, 480, 640);
  
  // Create and initialize the Game board
  Tetris *game = init_board();
  
  engine_log("Executing the App Loop"); 
  // Start the main app loop
  while(1)
  {
    // Take Input and Apply
    INPUT_FLAG inf = basic_engine_input();
    if (inf != inf_none)
    {
      if (inf == inf_quit)  break; // If input flag is quit, break the loop
      if (inf == win_evnt)   
      { // Update the app screen height if necessary
        SDL_GetWindowSize(engine->window, &engine->SCR_Width, &engine->SCR_Height);
      }
    }
  
    // Prepare the scene to be presented
    prepare_engine_scene(engine);
    
    // Draw the game grid on the window
    draw_grid(engine, BOARD_WIDTH, BOARD_HEIGHT, game->board);

    // Present the prepared scene
    present_engine_scene(engine);
    
    // Delay with a value of 16 milliseconds
    // to limit the loop for around 62 frames
    // per second. Also prevents the app from
    // running at full tilt and consuming too
    // much CPU time.
    SDL_Delay(16);
  }

  engine_log("Quitting App"); 

  // Free the contents of the game  
  free_board(game);
  
  // Free the contents of the App
  free_engine(engine);

  return EXIT_SUCCESS;
}
