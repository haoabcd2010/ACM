#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int f[40];
int main()
{
    f[0]=1;
    f[1]=1;
    for (int i=2;i<40;i++)
        f[i]=f[i-1]+f[i-2];
    for (int i=1;i<40;i++)
    {
        printf("%-10d",f[i]);
        if (i%5==0) cout<<endl;
    }
    return 0;
}
