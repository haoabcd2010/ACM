#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 120000

char str[MAX];

char temp[MAX*2];
int p[MAX*2];
int Manacher(char *s)
{
    temp[0]='$';
    int pos=1;
    for (int i=0;s[i]!='\0';i++)
    {
        temp[pos++]='#';
        temp[pos++]=s[i];
    }
    temp[pos++]='#';
    temp[pos++]='\0';

    int Mx=0,id;
    int res=0;
    for (int i=1;i<pos;i++)
    {
        if (Mx>i)
            p[i]=min(p[2*id-i],Mx-i);
        else
            p[i]=1;
        while(temp[i+p[i]]==temp[i-p[i]])
            p[i]++;
        if (p[i]+i>Mx)
        {
            Mx=p[i]+i;
            id=i;
        }
        if (p[i]-1>res) res=p[i]-1;
    }
    return res;
}

int main()
{
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",Manacher(str));
    }
    return 0;
}
