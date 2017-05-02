#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int map_[150][150];
int x,y;

int DiGui(int k)
{
    if (k==1)
    {
        //zou
    }
    else
    {

    }
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int N=pow(2.0,n);
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                scanf("%d",&map_[i][j]);
        x=1;y=1;
        DiGui(n);
    }

    return 0;
}
