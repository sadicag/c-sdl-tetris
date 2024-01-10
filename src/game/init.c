
/**
 *  Initialize the game board for Tetris.
 */
Tetris *init_board()
{
  Tetris *game = malloc(sizeof(Tetris));
  
  for(int h = 0; h < BOARD_HEIGHT; h++)
  {
    for(int w = 0; w < BOARD_WIDTH; w++)
    {
      game->board[h][w] = POSITION_FREE;
    }
  }
 
  return game; 
}
