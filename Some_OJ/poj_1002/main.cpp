#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#define MX 100005

int tel[MX];

int get(char c)
{
    if (c>='A'&&c<='C') return 2;
    if (c>='D'&&c<='F') return 3;
    if (c>='G'&&c<='I') return 4;
    if (c>='J'&&c<='L') return 5;
    if (c>='M'&&c<='O') return 6;
    if (c>='P'&&c<='S') return 7;
    if (c>='T'&&c<='V') return 8;
    if (c>='W'&&c<='Y') return 9;
    return c-'0';
}

void show(int k,int same)
{
    int mod = 1000000;
    for (int i=0;i<3;i++)
    {
        int x = k/mod;
        printf("%d",x);
        k-=x*mod;
        mod/=10;
    }
    printf("-");
    for (int i=0;i<4;i++)
    {
        int x = k/mod;
        printf("%d",x);
        k-=x*mod;
        mod/=10;
    }
    printf(" %d\n",same);
}

int main()
{
    int n;
    cin>>n;
    getchar();

    for (int i=0;i<n;i++)
    {
        char temp[500];
        scanf("%s",temp);
        int s = 0;
        for (int j=0; temp[j] ;j++)
        {
            if (temp[j]=='-') continue;
            s += get(temp[j]);
            s*=10;
        }
        s/=10;
        tel[i]=s;
    }
    sort(tel,tel+n);

    int total=0;
    int same=0;
    tel[n]=111; //bu cun zai de
    for (int i=0;i<=n;i++)
    {
        if (same==0)
        {
            same++;
            continue;
        }
        if (tel[i]==tel[i-1])
            same++;
        else
        {
            if (same!=1)
            {
                show(tel[i-1],same);
                total++;
            }
            same=1;
        }
    }
    if (!total) printf("No duplicates.\n");
    return 0;
}
