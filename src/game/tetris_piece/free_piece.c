#ifndef FREE_PIECE_C
#define FREE_PIECE_C

void free_piece(Piece *piece)
{
  piece->type = 0x00;
  free(piece);
}

#endif
