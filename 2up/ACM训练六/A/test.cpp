#include <stdio.h>

int flag[4]={0,0,0,0};
int ans[4];
int ok=0;

int DFS(int step)
{
    if (step==4)
    {
        int mm=0;
        for (int i=0;i<4;i++)
        {
            mm*=10;
            mm+=ans[i];
        }
        printf("%d%%7==%d\n",mm,mm%7);
    }
    for (int i=0;i<4;i++)
    {
        if (flag[i]==0)
        {
            ans[step]=i+1;
            flag[i]=1;
            DFS(step+1);
            flag[i]=0;
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}
