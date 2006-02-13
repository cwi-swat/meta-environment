
/* This file contains all the hacks I could find */

#ifdef A
static int a = 0;
static int f(int a, int b);
#elif 1+1 == 1
int f();
#else
typedef int Aap;
#endif

static Aap g(void a, void b);
char * aap(noot t) ;
char * aap(noot t) { int i = 1; }
aap (*noot) ();
static int fiets;

/* TODO: pickaboo */
f()
{
  char a[] = "Hello, world!";
}

static int expressions(char static typedef **argv[2+9][])
{
  int a[] = {1,2,3,4};

  1 + 2 * 3;
  1 + 2 [3];
  *1 - --2 + ++2;
  *(1 << 2 << 3)[3] += 5 += 9; 
  1 & 2 ^ 7 ++ +12.34, 67;

  while (++*c = *d++);
}

int main(int **[][], char *argv[]) 
{
  int a = 1, c[3];
  f(a, b?a:v, c);
  i - 1;
  sjaak[i] = (int**) i;
  sjaak[i - 1] = 0.E-1; 
#if 0
  cur->start[j];
#ifdef JURGEN
  f != LENSPEC+1;
#endif
  start == NULL || x;
#else
  /* a ++ b;  is illegal */
  aap & & aap;
  aap && aap;
  a+++b;
  a+(++b++);
#endif
  !aap->mies++;
  aap[noot]->mies++;
  !aap[noot];
  !aap[noot]->mies++;

  { a b; b const *const *const b; }
  { a b; b *b; a;}
  { b *b = c; a; } /* works because of injection counting */
  /* { a b; b *b = c; a; }  ambiguous assignment expression or initializer */
  { a b; b *b = c; int b; a; } /* no problem because not latest decl... */

  h, a + b ? a : b ? a + b + c , v : z + d, d;

  {
    typedef int a;
    (a) (a);
    (a) ( (a) b );
  }

  if (a = b = c);

  /* { aap (noot(t)); } ambiguous declaration or statement */

  a = *--b;


}




