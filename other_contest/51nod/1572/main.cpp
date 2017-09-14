#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define LL long long
#define MX 1005

struct Node
{
    char c;
    int l,u,r,d;
}mp[MX][MX];
struct Step
{
    char dir;
    int tim;
};

int n,m;
vector<Step> st;

void Init()
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (j!=0&&mp[i][j].c!='#')
                mp[i][j].l=mp[i][j-1].l+1;
            else
                mp[i][j].l=-1;
        }

    for (int i=0;i<n;i++)
        for (int j=m-1;j>=0;j--)
        {
            if (j!=m-1&&mp[i][j].c!='#')
                mp[i][j].r=mp[i][j+1].r+1;
            else
                mp[i][j].r=-1;
        }

    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
        {
            if (j!=0&&mp[j][i].c!='#')
                mp[j][i].u=mp[j-1][i].u+1;
            else
                mp[j][i].u=-1;
        }

    for (int i=0;i<m;i++)
        for (int j=n-1;j>=0;j--)
        {
            if (j!=n-1&&mp[j][i].c!='#')
                mp[j][i].d=mp[j+1][i].d+1;
            else
                mp[j][i].d=-1;
        }
}

int moni(int x,int y)
{
    int siz = st.size();
    for (int i=0;i<siz;i++)
    {
        if (st[i].dir=='N')
        {
            if (mp[x][y].u>=st[i].tim)
                x-=st[i].tim;
            else return 0;
        }
        if (st[i].dir=='S')
        {
            if (mp[x][y].d>=st[i].tim)
                x+=st[i].tim;
            else return 0;
        }
        if (st[i].dir=='W')
        {
            if (mp[x][y].l>=st[i].tim)
                y-=st[i].tim;
            else return 0;
        }
        if (st[i].dir=='E')
        {
            if (mp[x][y].r>=st[i].tim)
                y+=st[i].tim;
            else return 0;
        }
    }
    return 1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        char str[MX];
        scanf("%s",str);
        for (int j=0;j<m;j++)
            mp[i][j].c=str[j];
    }

    Init();

    int k;
    scanf("%d",&k);
    while (k--)
    {
        char ss[5];
        int sp;
        scanf("%s%d",ss,&sp);
        st.push_back((Step){ss[0],sp});
    }

    char ans[30];
    int num=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (mp[i][j].c<='Z'&&mp[i][j].c>='A')
            {
                if (moni(i,j)) ans[num++]=mp[i][j].c;
            }
        }
    }
    sort(ans,ans+num);
    ans[num]='\0';
    if (num==0)
        printf("no solution\n");
    else
        printf("%s\n",ans);

    return 0;
}
/*

##########
#K#..#####
#.#..##.##
#..L.#...#
###D###A.#
##########

*/
