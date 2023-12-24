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
  
  // Draw a Rectangle
  SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
  SDL_Rect rect;
  rect.w = 50;
  rect.h = 50;
  // Center the rectangle to the screen
  rect.x = (app->SCR_Width - rect.w)/2;
  rect.y = (app->SCR_Height - rect.h)/2;
  SDL_RenderDrawRect(app->renderer, &rect);
  SDL_RenderFillRect(app->renderer, &rect);
  

}

#endif
