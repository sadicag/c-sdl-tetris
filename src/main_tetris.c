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

  app_status_print("Creating and Initializing App"); 

  // Create and Initialize an App window
  // with the default values
  App* app = init_app(app_title, 640, 480);

  app_status_print("Executing the App Loop"); 
  // Start the main app loop
  while(1)
          {
    // Prepare the scene to be presented
    prepare_app_scene(app);
    
    // Take Input and Apply
    INPUT_FLAG inf = basic_app_input();
    if (inf != inf_none)
    {
      if (inf == inf_quit) break;
    }
  
    // Present the prepared scene
    present_app_scene(app);
    
    // Delay with a value of 16 milliseconds
    // to limit the loop for around 62 frames
    // per second. Also prevents the app from
    // running at full tilt and consuming too
    // much CPU time.
    SDL_Delay(16);
  }

  app_status_print("Quitting App"); 
  
  // Free the contents of the App
  free_app(app);
  
  return EXIT_SUCCESS;
}
