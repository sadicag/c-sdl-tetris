
/**
 *  The prepared scene of App
 *  is presented using the renderer.
 */
void present_engine_scene(GridEngine *engine)
{
  SDL_RenderPresent(engine->renderer);
}

