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

  for(int i = 0; i < 8; i++)
    piece->in[i] = in[i];
  for(int i = 0; i < 25; i++)
    piece->m1[i] = m1[i];
  for(int i = 0; i < 25; i++)
    piece->m2[i] = m1[i];
  for(int i = 0; i < 25; i++)
    piece->m3[i] = m1[i];
  for(int i = 0; i < 25; i++)
    piece->m4[i] = m1[i];


  return piece;

}

#endif
