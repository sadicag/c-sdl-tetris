
// Debug
#include <stdio.h>

Tetris *next_step(Tetris *game, Coordinate *_transform)
{

  if (active_piece != NULL) { active_piece->y++; }

  // Beyond this point we know that the active piece will not be NULL
  if (active_piece == NULL) { active_piece=create_active_piece(-1); }
 
  Coordinate transform = *_transform;  

  // There is a movement, check if possible!
  if (transform.x > 0) 
  {
    active_piece->x = active_piece->x + 1;
  }
  if (transform.x < 0) 
  {
    active_piece->x = active_piece->x - 1;
  }
  if (transform.y < 0) 
  {
    active_piece->y = active_piece->y + 1;
  }

  printf("x:%d\ty:%d\n", active_piece->x, active_piece->y);

  // if lines touch, free and declare active_piece = NULL again

  return game;

}
