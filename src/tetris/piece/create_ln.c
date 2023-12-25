#ifndef CREATE_LN
#define CREATE_LN

Piece *create_ln()
{
  Piece *piece = malloc(sizeof(Piece));

  piece->type = ln_t;

  int in[8]  = {
                  -2, -2,
                  -2, -3,
                  -2, -2,
                  -2, -3
               };

  int m1[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0,
                  0, 1, 2, 1, 1,
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0
               };

  int m2[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 2, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 1, 0, 0
               };

  int m3[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0,
                  1, 1, 2, 1, 0,
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0
               };

  int m4[25] = {  
                  0, 0, 1, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 2, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 0, 0, 0
               };

  memcpy(piece->in, in, 8);
  memcpy(piece->m1, m1, 25);
  memcpy(piece->m2, m2, 25);
  memcpy(piece->m3, m3, 25);
  memcpy(piece->m4, m4, 25);

  return piece;

}

#endif
