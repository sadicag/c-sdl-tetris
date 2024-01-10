#include "tetris.h"

Tetris *debug(Tetris *game, int rotation)
{
  for (int h = 0; h <  BOARD_HEIGHT; h++)
  {
    for (int w = 0; w < BOARD_WIDTH; w++)
    {
      game->board[h][w] = POSITION_FREE;
    }
  }
  // DEBUGGING:
  ActivePiece *active_piece;
  // Left

  active_piece = create_active_piece(6);
  active_piece->y = 0;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(1);
  active_piece->y = 4;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(2);
  active_piece->y = 9;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(0);
  active_piece->y = 14;
  active_piece->x = 2;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  // Right

  active_piece = create_active_piece(4);
  active_piece->y = 0;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(5);
  active_piece->y = 5;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(3);
  active_piece->y = 10;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  return game;

}

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
  
  // Initialize the transform for block movement 
  Coordinate transform;
  transform.x = 0;
  transform.y = 0;
 
  engine_log("Executing the App Loop");

  // Set the random seed as the device timestamp
  srand((unsigned int)time(NULL));

  ActivePiece* active_piece; // Set the global active_piece

  time_t time1, time2;
  time(&time1);
  time(&time2);

  // debug:
  int rotat = 1;

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
      { // There is a movement, check if possible!
        if (transform.x > 0) {engine_log("RIGHT\tPRESS");}
        if (transform.x < 0) {engine_log("LEFT\tPRESS");}
        if (transform.y < 0) {engine_log("DOWN\tPRESS");}
      } 
    }
  
    // Apply Tetris Logic Here
    
    time(&time2);
    if (difftime(time2, time1) >= (WAIT_TIME*0.001)) {rotat++; time(&time1);}
    if (rotat > 4) {rotat = 1;}
    game = debug(game, rotat); 

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
