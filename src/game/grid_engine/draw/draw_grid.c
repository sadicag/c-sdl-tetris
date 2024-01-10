
void draw_grid(GridEngine *engine, int W, int H, int board[H][W])
{
  // Draw a Rectangle
  SDL_SetRenderDrawColor(engine->renderer, 255, 255, 255, 255);
  SDL_Rect rect;
   
  // Find the size of blocks dynamically
  int size = W > H ? (engine->SCR_Width/(W*1.2)) : (engine->SCR_Height/(H*1.2));   

  rect.w = size;
  rect.h = size;
   
  // The center point
  int center_x = (engine->SCR_Width   - rect.w)/2 + rect.w/2;
  int center_y = (engine->SCR_Height  - rect.h)/2 + rect.h/2;
  
  for(int h = 0; h < H; h++)
  {
    for(int w = 0; w < W; w++)
    {
      rect.y = center_y - ((H/2)*size) + (h)*size;
      rect.x = center_x - ((W/2)*size) + (w)*size;
      SDL_RenderDrawRect(engine->renderer, &rect);
      // If full in board, fill in the rectangle
      if (board[h][w]) SDL_RenderFillRect(engine->renderer, &rect);
    }
  }
  
  
}
