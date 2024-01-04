
/**
 *  Deletes a line and moves all the upper
 *  rows one row downwards.
 */
Tetris *delete_line(Tetris *game, int y)
{
 
  for(int j = y; j > 0; j--)
  {
    for(int i = 0; i < BOARD_WIDTH; i++)
    {
      game->board[i][j] = game->board[i][j-1];
    }
  } 

  return game;
}

/**
 *  Deletes all possible lines in the game board.
 */
Tetris *delete_possible_lines(Tetris *game)
{

  for(int rows = 0; rows < BOARD_HEIGHT; rows++)
  {
    int cols = 0;
    while(cols < BOARD_WIDTH)
    {
      if(game->board[rows][cols] != POSITION_FULL) break;
      cols++;
    }
    if (cols == BOARD_WIDTH) {game = delete_line(game, rows);}
  }
  return game;
}

