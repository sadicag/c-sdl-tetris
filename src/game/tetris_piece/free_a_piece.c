#ifndef FREE_ACTIVE_PIECE_C
#define FREE_ACTIVE_PIECE_C

void free_active_piece(ActivePiece *a)
{
  free_piece(a->piece);
  free(a);
}

#endif
