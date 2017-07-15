#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 21252

int main()
{
    int a,b,c,d;
    int cas=1;
    while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        if (a==-1&&b==-1&&c==-1&&d==-1)
            break;
        a%=23;
        b%=28;
        c%=33;
        for (int i=c;i<=MAX+33;i+=33)
        {
            if ((i-a)%23==0 && (i-b)%28==0 && (i-c)%33==0)
            {
                if (i<=d)
                    i+=MAX;
                printf("Case %d: the next triple peak occurs in %d days.\n",cas++,i-d);
                break;
            }
        }
    }
    return 0;
}
