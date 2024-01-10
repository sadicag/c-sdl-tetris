
/**
 *  Returns 1 if block specified is free.
 *  Returns 0 if block specified is full.
 */
int is_block_free(Tetris *game, int x, int y)
{
  if(game->board[y][x] == POSITION_FULL) {return 0;}
  return 1;
}

/**
 *  Return 1 if move is possible in coordinates (x,y)
 *  Return 0 if move is not possible in coordinates (x,y)
 */
int is_move_possible(Tetris *game, ActivePiece *active_piece, int x, int y)
{

  // Check for collisions with
  // filled positions inside the board
  for(int i1 = active_piece->x, i2 = 0; i1 < active_piece->x + 5; i1++, i2++)
  {
    for(int j1 = active_piece->y, j2 = 0; j1 < active_piece->y + 5; j1++, j2++)
    {
      if(i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
      {
        if(is_position_full(active_piece, j2, i2) != 0) {return 0;}       
      }
      if (j1 >= 0)
      {
        if(is_position_full(active_piece, j2, i2) != 0 && is_block_free(game, i1, j1))
        {
          return 0;
        }
      }
    }
  }
  // No collisions found for move
  return 1;
}
