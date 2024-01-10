
/**
 *  Returns 1 if the game is over.
 *  Returns 0 if the game is continuing.
 */
int is_game_over(Tetris *game)
{
  for(int w = 0; w < BOARD_WIDTH; w++)
  {
    if (game->board[0][w] == POSITION_FULL) {return 1;}
  }
  return 0;
}
