#ifndef CREATE_SE_C
#define CREATE_SE_C

Piece *create_se()
{
  Piece *piece = malloc(sizeof(Piece));

  piece->type = se_t;

  int in[8]  = {
                  -2, -3,
                  -2, -3,
                  -2, -3,
                  -2, -2
               };

  int m1[25] = {
                  0, 0, 0, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 2, 1, 0,
                  0, 0, 0, 1, 0,
                  0, 0, 0, 0, 0
               };

  int m2[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0,
                  0, 0, 2, 1, 0,
                  0, 1, 1, 0, 0,
                  0, 0, 0, 0, 0
               };

  int m3[25] = {  
                  0, 0, 0, 0, 0,
                  0, 1, 0, 0, 0,
                  0, 1, 2, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 0, 0, 0
               };

  int m4[25] = {  
                  0, 0, 0, 0, 0,
                  0, 0, 1, 1, 0,
                  0, 1, 2, 0, 0,
                  0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0
               };

  for(int i = 0; i < 8; i++)
    piece->in[i] = in[i];
  for(int i = 0; i < 25; i++)
    piece->m1[i] = m1[i];
  for(int i = 0; i < 25; i++)
    piece->m2[i] = m2[i];
  for(int i = 0; i < 25; i++)
    piece->m3[i] = m3[i];
  for(int i = 0; i < 25; i++)
    piece->m4[i] = m4[i];


  return piece;

}

#endif
