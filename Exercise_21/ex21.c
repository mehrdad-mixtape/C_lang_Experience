#include <stdio.h>

#define True 1;
#define False 0;

int main()
{
    int a = 172938740;
    long b = (long)a;
    int c = (int)b;
    double d = 100000.121212;
    long e = (long)d;
    char f = 'C';
    int g = (int)f;
    int i = 90;
    char j = (char)i;
    long int k = 273984792379472938;
    double l = (double)k;
    int m = -238774;
    unsigned int n = (unsigned int)m;

    printf("%d %ld %d %f %ld %c %d %i %c %ld %f %d %d\n", a, b, c, d, e, f, g, i, j, k, l, m, n);
    return 0;
}