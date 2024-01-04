

void engine_log(char* suffix)
{
  unsigned long long int ms = SDL_GetTicks();
  unsigned int h = ((ms/1000)/60)/60; 
  unsigned int m = (ms/1000/60)%60;
  unsigned int s = (ms/1000)%60;
  fprintf(stderr, "LOG (%02llu:%02llu:%02llu)\t:\t%s\n", h, m, s, suffix);
}

