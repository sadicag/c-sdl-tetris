#ifndef CREATE_PIECE_C
#define CREATE_PIECE_C

Piece *create_piece(int idx)
{
  switch (idx)
  {
    case 0:
      return create_sq();
    break;
    case 1:
      return create_ln();
    break;
    case 2:
      return create_le();
    break;
    case 3:
      return create_je();
    break;
    case 4:
      return create_ne();
    break;
    case 5:
      return create_se();
    break;
    case 6:
      return create_te();
    break;
    default:
      return NULL;
    break;
  }
}

#endif
