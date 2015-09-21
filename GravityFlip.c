#include "stdio.h"

int compare_ints (const void *a, const void *b)
{
  const int *da = (const int *) a;
  const int *db = (const int *) b;

  return (*da > *db) - (*da < *db);
}
int main(void) 
{
    int n;
    scanf("%d", &n);
    int *ptr;
    ptr=(int*)malloc(n*sizeof(int));
    int i;
    for (i = 0; i < n; i++)
    {
    		int e;
            scanf("%d", &e);
            ptr[i] = e;
    }
    qsort (ptr, n, sizeof (int), compare_ints);
    int r;
    for (r = 0; r < n; r++)
    {
            printf("%d ", ptr[r]);
    }
    return 0;
}