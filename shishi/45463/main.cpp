#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;
const int MX=5000010;

int lens,lent;
char T[MX];
char S[MX];
int l[MX];
int r[MX];
int fail[MX];

void getfail()
{
    int i,j;
    i=1,j=0;
    fail[1]=0;
    while(i<lent)
    {
        if (j==0||T[i]==T[j])
        {
            i++,j++;
            fail[i]=j;
        }
        else j = fail[j];
    }
}

void kmp()
{
    int i=1;
    int j=1;
    while(i<=lens&&j<=lent)
    {
        if (j==0||S[i]==T[j])
        {
            i=r[i];
            j++;
        }
        else j = fail[j];

        if (j>lent)
        {
            int num=0;
            int pos=i;
            while (num<lent)
            {
                pos = l[pos];
                num++;
            }
            r [ l[ pos ] ] = i;
            l [ i ] = l[ pos ];
            j=1;

            num=0;
            pos=i;
            while (num<lent)
            {
                pos = l[pos];
                if (pos==0) break;
                num++;
            }
            if (l[pos]!=0)
                i = l[pos];
        }
    }
}

int main()
{
    while(scanf("%s",T+1)!=EOF)
    {
        scanf("%s",S+1);
        lens = strlen(&S[1]);
        lent = strlen(&T[1]);

        getfail();

        for (int i=0;i<=lens+1;i++)
        {
            l[i] = i-1;
            r[i] = i+1;
        }

        kmp();
        for (int i = r[0];S[i];i = r[i])
        {
            printf("%c",S[i]);
        }
        printf("\n");
    }
    return 0;
}
