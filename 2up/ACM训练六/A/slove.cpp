#include <stdio.h>
#include <math.h>
#include <string.h>

const int remain[7]={3241,3214,3124,2341,2314,1342,2134};

int Yu7(char str[])
{
    int len = strlen(str);
    int y=0;
    for(int i=0;i<len;i++)
    {
        y+=str[i]-'0';
        y%=7;
        y*=10;
    }
    y/=10;
    return y;
}

int main()
{
    int T;
    char str[25];
    char real[25];
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",&str);
        int ti[5]={0};
        int i,len = strlen(str);
        int s=0,ok=0;
        for (i=0;i<len;i++)
        {
            if (ti[str[i]-'0']==0)
            {
                ti[str[i]-'0']=1;
                ok++;
                continue;
            }
            real[s++]=str[i];
        }
        if (ok<4)
        {
            printf("0\n");
            continue;
        }
        for (i=0;i<4;i++)
        real[s++]='0';
        real[s++]='\0';
        int yu = Yu7(real);
        if (yu==0) yu=7;
        len-=4;
        real[len]='\0';
        if (len>0)
            printf("%s",real);
        printf("%d\n",remain[7-yu]);
    }
    return 0;
}
