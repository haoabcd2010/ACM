#include <stdio.h>
#include <iostream>
using namespace std;

int num[35];
int op[1000];
int N,times;

int Read(char str[])
{
    int i=0;
    while (str[i++]==' ');
    i--;
    int k=1;
    for (i=i;str[i];i++)
    {
        if (str[i]!=' ')
        {
            int j,res=0;
            for (j=i;str[j]!=' ';j++)
            {
                if (str[j]=='\0') break;
                res+=str[j]-'0';
                res*=10;
            }
            i=j-1;
            num[k++]=res/10;
        }
    }
    return k-1;
}

void Ni(int x)
{
    int i=1,j=x;
    while (1)
    {
        swap(num[i],num[j]);
        if (i+1==j) break;
        if (i<j) i++;
        if (j>i) j++;
    }
}

void Func()
{
    int n=N;
    while (n--)
    {
        int x=1,mmm=num[1];
        for (int i=1;i<=n;i++)
        {
            if (num[i]>mmm)
            {
                mmm=num[i];
                x=i;
            }
        }
        if (x!=n)//最大的不在n的位置
        {
            if (x==1)
            {
                Ni(n);
                op[times++]=N-n+1;
            }
            else
            {
                Ni(x);
                op[times++]=N-x+1;
                Ni(n);
                op[times++]=N-n+1;
            }
        }
    }
}

int main()
{
    char strnum[200];
    while (gets(strnum))
    {
        N=Read(strnum);//读数
        times=0;
        Func();//不断将最大的放到最下面去
        for (int i=0;i<times;i++)
        printf("%d ",op[i]);
        printf("0\n");
    }
    return 0;
}
