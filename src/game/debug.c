
Tetris *debug(Tetris *game, int rotation)
{
  for (int h = 0; h <  BOARD_HEIGHT; h++)
  {
    for (int w = 0; w < BOARD_WIDTH; w++)
    {
      game->board[h][w] = POSITION_FREE;
    }
  }
  // DEBUGGING:
  ActivePiece *active_piece;
  // Left

  active_piece = create_active_piece(6);
  active_piece->y = 0;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(1);
  active_piece->y = 4;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(2);
  active_piece->y = 9;
  active_piece->x = 0;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(0);
  active_piece->y = 14;
  active_piece->x = 2;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  // Right

  active_piece = create_active_piece(4);
  active_piece->y = 0;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(5);
  active_piece->y = 5;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  active_piece = create_active_piece(3);
  active_piece->y = 10;
  active_piece->x = 5;
  active_piece->rotation = rotation;
  game = store_piece(game, active_piece);
  free_active_piece(active_piece);

  return game;

}
