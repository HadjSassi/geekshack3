#include <stdio.h>
#include <string.h>
char main()
{ char r[10];
char k[10];
char w[10];
char r1[10];
char r2[10];
char test[10];
    fgets(r,5,stdin);
    fgets(k,5,stdin);
    fgets(w,5,stdin);
    strcpy(r1,r);
    strcpy(r2,r);
    r1[2]=w[2];
    r2[1]=w[1];
    if (k[1]==r[1] && k[2]==r[2])
    {
        strcpy(test,"NO");
        printf("%s",test);
        
    }
    else {strcpy(test,"YES");
    printf("%s",test);
    }

return 0;

}
 