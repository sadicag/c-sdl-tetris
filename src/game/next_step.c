
Tetris *next_step(Tetris *game)
{

  if (active_piece != NULL) { active_piece->y++; }

  // Beyond this point we know that the active piece will not be NULL
  if (active_piece == NULL) { active_piece=create_active_piece(-1); }
 
  // if lines touch, free and declare active_piece = NULL again
  return game;

}
