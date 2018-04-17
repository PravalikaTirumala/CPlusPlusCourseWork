void quicksort(int a[], int l, int r)

  {

    if (r <= l) return;

   /* call for partition function that you modify */

    quicksort(a, l, i-1);

    quicksort(a, i+1, r);

  }

 

Partition:

int partition(int a[], int l, int r)

  { int i = l-1, j = r; int v = a[r];

    for (;;)

      {

        while (a[++i] < v) ;

        while (v < a[--j]) if (j == l) break;

        if (i >= j) break;

        exch(a[i], a[j]);

      }

    exch(a[i], a[r]);

    return i;

  }










