#include <stdio.h>
#include <stdlib.h>

#define NUM_CHARS 16 // + - E . ' ' 0-9 \n

typedef struct {
  char label;
  unsigned long int count;
} symbol;

symbol symbols[NUM_CHARS] = {{'+', 0},
                             {'-', 0},
                             {'e', 0},
                             {'.', 0},
                             {' ', 0},
                             {'\n',0},
                             {'0', 0},
                             {'1', 0},
                             {'2', 0},
                             {'3', 0},
                             {'4', 0},
                             {'5', 0},
                             {'6', 0},
                             {'7', 0},
                             {'8', 0},
                             {'9', 0}};

int CompareSymbol (const void * a, const void * b)
{

  symbol *c = (symbol *)a;
  symbol *d = (symbol *)b;

  return ( c->count - d->count );
}

int Counted(char c) {
  int i;
  for(i=NUM_CHARS;i--;) {
    if (c==symbols[i].label){
      return i;
      break;
    }
  }
  return -1;
}
          
void Print(unsigned long int total) {
  int i;
  for(i=NUM_CHARS;i--;)
    if (symbols[i].label == '\n')
      printf("%6s    %6ld    %6.4f \n", "\\n", symbols[i].count, ((double)(symbols[i].count))/total);
    else
      printf("%6c    %6ld    %6.4f\n", symbols[i].label, symbols[i].count, ((double)(symbols[i].count))/total);
  return;
}

int main() {

  char c;
  unsigned long int nc = 0;

  int i;
  
  while ((c=getchar()) != EOF) {
    if ((i=Counted(c)) != -1) 
      (symbols[i].count)++;
    nc++;
  }

  qsort(symbols, NUM_CHARS, sizeof(symbol), CompareSymbol);
  Print(nc);
  printf("\n%ld",nc);
  
  return 0;

}
