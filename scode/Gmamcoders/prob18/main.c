#include <stdio.h>
#define nmax 500

int main()
{int n, aux, i, a, t[nmax], count = 0, c, s = 0;
scanf("%d", &n);
for (i = 0; i < n; i++)
{scanf("%d", &a);
t[i] = a;}

c = t[0];

for (i = 0; i < n; i++)
if (t[i] == c)
count++;

for (i = 1; i < n-1; i++)
{
if ((t[i] == c)&&(t[i+1]!=c)&&(count>0))
{aux = t[i];
t[i] = t[i+1];
t[i + 1] = aux;
ind = i;
count--;
s++;
}
else if((t[i]== c)&&(t[i+1]==c)&&(count>0))
count--;
}
printf("%d", s);
return 0;
}

  