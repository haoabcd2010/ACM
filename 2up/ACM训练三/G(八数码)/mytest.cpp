#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int maxn=4e5+10;// 400010 最多不超过这么多状态 362880
const int hash_[9]={1,1,2,6,24,120,720,5040,40320};
struct Node
{
    int state[3][3];
    int x,y;
    int g,h;        //g代表已耗费,h代表估计耗费
    int hash_num;   //这个状态的 hash 值
    bool operator < (const Node PP) const
    {
        //return g+h > PP.g+PP.h;
        //1638ms
        return h==PP.h ? g>PP.g : h>PP.h;
        //686ms
    }
}star,ans;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char op_c[8]={"durl"};
struct Node2
{
    int pre_hash;
    char op;
}p[maxn];
int vis[maxn];


int count_hash(Node p)//获得hash值,计算的是 0-8 排列的hash
{
    int i,j,k,hash_num=0;
    for (i=0;i<9;i++)
    {
        k=0;
        for (j=0;j<i;j++)
        {
            if (p.state[j/3][j%3]>p.state[i/3][i%3])
                k++;
        }
        hash_num+=k*hash_[i];
    }
    return hash_num;
}

int count_h(Node p)//注意位置，要细致
{
    int i,all=0;
    for (i=0;i<9;i++)
    {
        int e=p.state[i/3][i%3];
        if (e)
        {
            e-=1;
            all+=abs(i/3-e/3)+abs(i%3-e%3);
        }
    }
    return all;
}


void print(int h)
{
    if (p[h].pre_hash==-1) return;
    print(p[h].pre_hash);
    printf("%c",p[h].op);
}

void A_star()
{
    int i;

    star.hash_num = count_hash(star);
    star.g=0;
    star.h=count_h(star);

    memset(vis,0,sizeof(vis));
    vis[star.hash_num]=1;
    p[star.hash_num].pre_hash=-1; //头节点

    priority_queue <Node> Q;
    Q.push(star);

    Node e,n;
    int xx,yy;

    if (star.hash_num==ans.hash_num)//这个不能丢
    {
        printf("\n");
        return;
    }
    while (!Q.empty())
    {
        e=Q.top();
        Q.pop();

        for (i=0;i<4;i++)
        {
            xx=e.x+dx[i];
            yy=e.y+dy[i];
            if (xx<0||yy<0||xx>=3||yy>=3) continue;

            n=e;
            n.x=xx;
            n.y=yy;
            swap(n.state[xx][yy],n.state[e.x][e.y]);
            n.g++;
            n.h=count_h(n);
            n.hash_num=count_hash(n);

            if (vis[n.hash_num]) continue;

            p[n.hash_num].pre_hash=e.hash_num;  //记录这个状态的的父 hash
            p[n.hash_num].op=op_c[i];           //记录怎么由父hash移动来的

            vis[n.hash_num]=1;
            if (n.hash_num==ans.hash_num)//说明到了
            {
                print(n.hash_num);
                printf("\n");
                return;
            }
            Q.push(n);
        }
    }
}

int main()
{
    char str[30];
    int i;

    for(i=0;i<9;i++)                    //终点
        ans.state[i/3][i%3]=(i+1)%9;
    ans.hash_num=count_hash(ans);       //终点

    while(gets(str))
    {
        int i;
        int len=strlen(str);

        int j=0;
        for(i=0,j=0;i<len;i++)
        {
            if(str[i]==' ')continue;
            if(str[i]=='x')
            {
                star.state[j/3][j%3]=0;
                star.x=j/3;
                star.y=j%3;
            }
            else star.state[j/3][j%3]=str[i]-'0';
            j++;                         // j/3 记录行数
        }

        //判断逆序数
        int temp [9],k=0;
        for (i=0;i<9;i++)
            temp[i]=star.state[i/3][i%3];
        for (i=0;i<9;i++)
        {
            if (temp[i]==0) continue;
            for (int j=0;j<i;j++)
                if (temp[j]>temp[i]) k++;
        }
        if (k%2)
            printf("unsolvable\n");
        else
            A_star();
    }
    return 0;
}

/*//错在这，浪费我一下午，才找出来！ == 竟然不报错，而且是全局变量，第一次也不会错！！！

        for (i=0,j=0;i<len;i++)
        {
            if (str[i]==' ')continue;
            else if (str[i]=='x')
            {
                star.x=j/3;
                star.y=j%3;
                star.state[j/3][j%3]==0;
            }
            else star.state[j/3][j%3]=str[i]-'0';
            j++;
        }
*/
