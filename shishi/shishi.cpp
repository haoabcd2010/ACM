#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
const int M = 500;

int z1_n,x1_n,z2_n,x2_n;
int z1[M];
int x1[M];
int z2[M];
int x2[M];

int z_n,x_n;
int zz[M];
int xx[M];

char s1[M];
char s2[M];

int main()
{
    while (scanf("%s %s",s1,s2)!=EOF)
    {
        memset(z1,0,sizeof(z1));memset(x1,0,sizeof(x1));
        memset(z2,0,sizeof(z2));memset(x2,0,sizeof(x2));

        int len1 = strlen(s1);
        int len2 = strlen(s2);
        z1_n=0;
        for (int i=0;i<len1;i++)
            if (s1[i]!='.') z1[z1_n++]=s1[i]-'0';
            else break;
        for (int i=0;i<z1_n/2;i++)
            swap(z1[i],z1[z1_n-1-i]);
        if (z1_n==len1) x1_n=0;
        else
        {
            x1_n=0;
            for (int i=z1_n+1;i<len1;i++)
                x1[x1_n++]=s1[i]-'0';
        }

        z2_n=0;
        for (int i=0;i<len2;i++)
            if (s2[i]!='.') z2[z2_n++]=s2[i]-'0';
            else break;
        for (int i=0;i<z2_n/2;i++)
            swap(z2[i],z2[z2_n-1-i]);
        if (z2_n==len2) x2_n=0;
        else
        {
            x2_n=0;
            for (int i=z2_n+1;i<len2;i++)
                x2[x2_n++]=s2[i]-'0';
        }

        memset(zz,0,sizeof(zz));
        memset(xx,0,sizeof(xx));

        int x_n=max(x1_n,x2_n);
        int jin=0;
        for (int i=x_n-1;i>=0;i--)
        {
            xx[i]=x1[i]+x2[i]+jin;
            if (xx[i]>=10)
            {
                xx[i]-=10;
                jin=1;
            }
            else jin=0;
        }
        while (x_n>0&&xx[x_n-1]==0) x_n--;

        int z_n=max(z1_n,z2_n);
        for (int i=0;i<z_n;i++)
        {
            zz[i]=z1[i]+z2[i]+jin;
            if (zz[i]>=10)
            {
                zz[i]-=10;
                jin=1;
            }
            else jin=0;
        }
        if (jin) zz[z_n++]=jin;

        for (int i=z_n-1;i>=0;i--)
            printf("%d",zz[i]);

        if (x_n!=0)
        {
            printf(".");
            for (int i=0;i<x_n;i++)
                printf("%d",xx[i]);
        }
        printf("\n");
    }
    return 0;
}
