#ifndef CREATE_SQ_C
#define CREATE_SQ_C

Piece *create_sq()
{
  Piece *piece = malloc(sizeof(Piece));

  piece->type = sq_t;

  int in[8]  = {
                  -2, -3,
                  -2, -3,
                  -2, -3,
                  -2, -3
               };

  // The matrix is the same for all
  // rotations m1, m2, m3, m4
  int m1[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0,
                  0, 0, 2, 1, 0,
                  0, 0, 1, 1, 0,
                  0, 0, 0, 0, 0   
               };

  memcpy(piece->in, in, 8);
  memcpy(piece->m1, m1, 25);
  memcpy(piece->m2, m1, 25);
  memcpy(piece->m3, m1, 25);
  memcpy(piece->m4, m1, 25);

  return piece;

}

#endif
