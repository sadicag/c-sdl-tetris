#include "tetris.h"

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
  
  active_piece = NULL;

  // Initialize the transform for block movement 
  Coordinate transform;
  transform.x = 0;
  transform.y = 0;
 
  engine_log("Executing the App Loop");

  // Set the random seed as the device timestamp
  srand((unsigned int)time(NULL));

  time_t time1, time2;
  time(&time1);
  time(&time2);

  // Start the main app loop
  while(1)
  {
    // Take Input and Apply
    // Reset the transform for active piece
    transform.x = 0; transform.y = 0;
    INPUT_FLAG inf = basic_engine_input(&transform);
    if (inf != inf_none)
    {
      if (inf == inf_quit)  break; // If input flag is quit, break the loop
      if (inf == win_evnt) // Update the app screen height if necessary
      {  
        SDL_GetWindowSize(engine->window, &engine->SCR_Width, &engine->SCR_Height);
      }
      if (inf == key_prss)
      {
        if (transform.x > 0) 
        {
          active_piece->x = active_piece->x + 1;
        }
        if (transform.x < 0) 
        {
          active_piece->x = active_piece->x - 1;
        }
        if (transform.y < 0) 
        {
          active_piece->y = active_piece->y + 1;
        }
      }
      if (inf == rot_prss)
      {
        active_piece->rotation++;
        if (active_piece->rotation == 4) { active_piece->rotation = 1; }
      }
    }
  
    // Apply Tetris Logic Here
    
    // Wait for timer 
    time(&time2);
    if (difftime(time2, time1) >= (WAIT_TIME*0.001)) {game=next_step(game); time(&time1);}

    // Prepare the scene to be presented
    prepare_engine_scene(engine);
    
    // Draw the game grid on the window
    // Before drawing it, to also print the active piece
    // store it in the board
    Tetris *temp_game = copy(game);

    store_piece(temp_game, active_piece);
    draw_grid(engine, BOARD_WIDTH, BOARD_HEIGHT, temp_game->board);

    // Present the prepared scene
    present_engine_scene(engine);
    
    free_board(temp_game);

    // Delay with a value of 16 milliseconds
    // to limit the loop for around 62 frames
    // per second. Also prevents the app from
    // running at full tilt and consuming too
    // much CPU time.
    SDL_Delay(16);
  }

  engine_log("Quitting App"); 

  // Free active piece
  free_active_piece(active_piece);

  // Free the contents of the game  
  free_board(game);
  
  // Free the contents of the App
  free_engine(engine);

  return EXIT_SUCCESS;
}
