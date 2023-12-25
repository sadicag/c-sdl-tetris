#ifndef APP_PRESENT_SCENE_C
#define APP_PRESENT_SCENE_C

/**
 *  The prepared scene of App
 *  is presented using the renderer.
 */
void present_app_scene(App *app)
{
  SDL_RenderPresent(app->renderer);
}

#endif
