#ifndef APP_INIT_FAILURE_PRINT_C
#define APP_INIT_FAILURE_PRINT_C

/**
 *  Prints an Error specific to initialization of the App.
 */
void app_init_failure_print(int is_exit, char* suffix)
{
  fprintf(stderr, "ERROR : Failure to Initialize App\n%s\nSDL_Error: %s\n", 
                                                        suffix,
                                                        SDL_GetError());
  if (is_exit) exit(1);
}

#endif
