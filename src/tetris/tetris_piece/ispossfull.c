
/**
 *  Returns 1 if the position in an active piece is full.
 *  Returns 0 if the position in an active piece is free.
 */
int is_position_full(ActivePiece *active_piece, int x, int y)
{
  switch(active_piece->rotation)
  {
    case 1:
      if(active_piece->piece->
          m1[y*5+x] != 0) {return 1;}
    break;
    case 2:
      if(active_piece->piece->
          m2[y*5+x] != 0) {return 1;}
    break;
    case 3:
      if(active_piece->piece->
          m3[y*5+x] != 0) {return 1;}
    break;
    case 4:
      if(active_piece->piece->
          m4[y*5+x] != 0) {return 1;}
    break;
    default:
    break;
  }
  return 0;
}
