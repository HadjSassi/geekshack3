#include <stdio.h>
int main()
{
  int test;
  scanf("%d", &test);
  while(test--){
    char a[10000001];
    scanf("%s", a);
    int no_of_operations = 0;
    for(int i=0; i<strlen(a)/2; i++){
      no_of_operations += abs( a[strlen(a)-i-1] - a[i] );
    }
    printf("%d\n", no_of_operations);
  }
}