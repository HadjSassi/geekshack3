#include <stdio.h>
#include <stdlib.h>

int main()
{
    char kc[5],rc[5],wc[5];
    scanf("%s %s %s ",rc,kc,wc);
    if(kc[2]!=rc[2] && kc[1]!=wc[1])
        printf("YES");
    else if (kc[1]!=rc[1] && kc[2]!=wc[2])
        printf("YES");
    else
        printf("No");
    return 0;
}
