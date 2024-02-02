
Tetris *copy(Tetris *game)
{
  Tetris *c_game = malloc(sizeof(Tetris));
  
  for(int h = 0; h < BOARD_HEIGHT; h++)
  {
    for(int w = 0; w < BOARD_WIDTH; w++)
    {
      c_game->board[h][w] = game->board[h][w];
    }
  }
 
  return c_game; 
}
