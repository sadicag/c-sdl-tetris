
/**
 *  Scene for the App is prepared
 *  using the renderer.
 */
void prepare_engine_scene(GridEngine *engine)
{
  SDL_SetRenderDrawColor(engine->renderer, 96, 128, 255, 255);
  SDL_RenderClear(engine->renderer);
}

