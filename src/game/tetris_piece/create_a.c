#ifndef CREATE_A_C
#define CREATE_A_C

ActivePiece *create_active_piece(int idx)
{
  ActivePiece *a = malloc(sizeof(ActivePiece));
  a->rotation = 1;
  a->x = 0;
  a->y = 0;
  a->piece = create_piece( idx == -1 ? (rand() % 7) : idx); // Create a piece randomly
  return a;
}

#endif
