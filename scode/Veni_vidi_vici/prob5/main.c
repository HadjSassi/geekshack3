#include <stdio.h>
#include <string.h>
char main()
{ char r[4];
char k[4];
char w[4];
char r1[4];
char r2[4];
char test[4];
    fgets(r,5,stdin);
    fgets(k,5,stdin);
    fgets(w,5,stdin);
    strcpy(r1,r);
    strcpy(r2,r);
    r1[2]=w[2];
    r2[1]=w[1];
    if (k[1]==r[1] && k[2]==r[2])
    {
        strcpy(test,"no");
        printf(test);
        return test;
    }
    else {strcpy(test,"yes");
    printf(test);
    return test;}



}
