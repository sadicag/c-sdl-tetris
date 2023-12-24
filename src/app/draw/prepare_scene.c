#ifndef APP_PREPARE_SCENE_C
#define APP_PREPARE_SCENE_C

/**
 *  Scene for the App is prepared
 *  using the renderer.
 */
void prepare_app_scene(App *app)
{
  SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
  SDL_RenderClear(app->renderer);
}

#endif
