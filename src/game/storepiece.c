
/**
 *  Store the active piece into the board by filling
 *  the appropiate blocks as POSITION FULL
 */
Tetris *store_piece(Tetris *game, ActivePiece *active_piece)
{
  if (active_piece == NULL) {return game;}

  for(int i1 = active_piece->x, i2 = 0; i1 < active_piece->x + 5; i1++, i2++)
  {
    for(int j1 = active_piece->y, j2 = 0; j1 < active_piece->y + 5; j1++, j2++)
    {
      if(is_position_full(active_piece, i2, j2)) 
      { 
        game->board[j1][i1] = POSITION_FULL; 
      }     
    }
  }
  return game;
}
