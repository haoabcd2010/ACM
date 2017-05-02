
//A*+hash

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

const int maxn=4e5+10;// 400010 最多不超过这么多状态
int ha[9]={1,1,2,6,24,120,720,5040,40320};
//对hash ha[i]=ha[i-1]*i
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//下一步
char d[10]="udlr";
//下一步
int vis[maxn];
//vis

struct node
{
    int f[3][3];
    int x,y;
    int g,h;
    int hash_num;
    bool operator < (const node a)const
    {
        return h==a.h ? g>a.g : h>a.h; //281MS
        //return h+g>a.h+a.g; //859ms
        //优先队列 h+g 小的先出队
    }
};

struct path
{
    int pre;
    char ch;
}p[maxn];


int get_hash(node e)//康托展开，压缩空间。
{
    int a[9],i,j,k=0,ans=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            a[k++]=e.f[i][j];
    }
    for(i=0;i<9;i++)
    {
        k=0;
        for(j=0;j<i;j++)
            if(a[j]>a[i]) k++;
            // 一个数组 a[9] ... k 代表 a[i] 之前有几个比 a [i] 大的数
        ans+=ha[i]*k;
            // 哈希表 ha[i] * k 之和 ans
    }
    return ans;
}

//评估函数，获得评估值
//计算1~8的数字回到原点需要的步数作为评估值，必定小于实际操作数
int get_h(node e)
{
    int i,j,ans=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(e.f[i][j])
            ans+=abs(i-(e.f[i][j]-1)/3)+abs(j-(e.f[i][j]-1)%3);
        }
    }
    return ans;
}

void print(int x)
{
    if(p[x].pre==-1) return;
    print(p[x].pre);
    printf("%c",p[x].ch);
}



void A_star(node e)
{
    memset(vis,0,sizeof(vis));

    int i,j,k,end_ans,xx,yy;

    node a,b;

    for(i=0;i<9;i++)            //终点
        a.f[i/3][i%3]=(i+1)%9;
    end_ans=get_hash(a);        //终点

    e.hash_num = get_hash(e);
    e.g=0;
    e.h=get_h(e);

    vis[e.hash_num]=1;
    p[e.hash_num].pre=-1; //头节点

    if(e.hash_num==end_ans) //就是答案。。。这可能么
    {
        printf("\n");
        return;
    }

    priority_queue<node>q;
    q.push(e);
    while(!q.empty())
    {
        e=q.top();
        q.pop();
        //printf("%d\n",e.hash_num);
        for(i=0;i<4;i++)
        {
            xx=e.x+dir[i][0];
            yy=e.y+dir[i][1];
            if(xx<0||yy<0||xx>=3||yy>=3)continue;
            //四个方向
            a=e;
            swap(a.f[e.x][e.y],a.f[xx][yy]);
            k=get_hash(a);
            if(vis[k])continue; //如果重复
            vis[k]=1;           //没有重复去试探
            a.hash_num=k;
            a.x=xx;
            a.y=yy;
            a.g++;
            a.h=get_h(a);

            p[k].pre=e.hash_num;//记录父节点的哈希值
            p[k].ch=d[i];       //标记是怎么移动到这的

            if(k==end_ans)      //如果到了终点
            {
                print(k);
                printf("\n");
                return ;
            }
            q.push(a);
        }
    }
}

int main()
{
    char a[30];
    while(gets(a))
    {
        int i,j,k,n;
        node e;
        n=strlen(a);
        for(i=0,j=0;i<n;i++)
        {
            if(a[i]==' ')continue;
            if(a[i]=='x')
            {
                e.f[j/3][j%3]=0;
                e.x=j/3;
                e.y=j%3;
            }
            else e.f[j/3][j%3]=a[i]-'0';
            j++;                         // j/3 记录行数
        }
        //判断逆序数
        for(i=0,k=0;i<9;i++)
        {
            if(e.f[i/3][i%3]==0)continue;//如果是 x
            for(j=0;j<i;j++)
            {
                if(e.f[j/3][j%3]==0)continue;
                if(e.f[j/3][j%3]>e.f[i/3][i%3]) k++;
            }
        }
        if(k&1)printf("unsolvable\n");
        else A_star(e);
    }
    return 0;
}




/******************************************
//BFS逆向打表+康托展开：从1 2 3 4 5 6 7 8 x逆向扩展
//记录哪些状态可以到达，以及到达给状态操作
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int fac[]={1,1,2,6,24,120,720,5040,40320};
int Cantor(int *s,int n){///康托展开
    int i,j,num,temp;
    num=0;
    for(i=0;i<n;++i){
        temp=0;
        for(j=i+1;j<n;++j){
            if(s[j]<s[i])
                temp++;
        }
        num+=fac[n-1-i]*temp;
    }
    return num;
}
void CantorReverse(int index,int *t,int n){///逆康托展开
    index--;///注意index表示第几个，index>=1
    int i,j;
    bool hash[10]={0};
    for(i=0;i<n;++i){
        int tmp=index/fac[n-1-i];
        for(j=0;j<=tmp;++j)
            if(hash[j]) tmp++;
        t[i]=tmp+1;
        hash[tmp]=1;
        index%=fac[n-1-i];
    }
    return;
}
bool can[362880];
char ans[362880][42];
int target[]={1,2,3,4,5,6,7,8,0};
int tt[9];
struct node{
    int key,x,y,tol;
    node(int _key,int _x,int _y,int _tol):key(_key),x(_x),y(_y),tol(_tol){}
};
queue<node> q;
int maxtol;
void bfs(){
    mem(can,false);
    while(!q.empty()) q.pop();
    int tkey=Cantor(target,9);
    can[tkey]=true;
    ans[tkey][0]='\0';
    q.push(node(tkey,2,2,0));
    while(!q.empty()){
        node tmp=q.front();q.pop();
        CantorReverse(tmp.key+1,tt,9);
        int x=tmp.x,y=tmp.y;
        if(x>=1){
            swap(tt[x*3+y],tt[(x-1)*3+y]);
            tkey=Cantor(tt,9);
            if(!can[tkey]){
                q.push(node(tkey,x-1,y,tmp.tol+1));
                can[tkey]=true;
                for(int i=0;i<tmp.tol;++i) ans[tkey][i]=ans[tmp.key][i];
                ans[tkey][tmp.tol]='d';
                ans[tkey][tmp.tol+1]='\0';
            }
            swap(tt[x*3+y],tt[(x-1)*3+y]);
        }
        if(y>=1){
            swap(tt[x*3+y],tt[x*3+y-1]);
            tkey=Cantor(tt,9);
            if(!can[tkey]) {
                q.push(node(tkey,x,y-1,tmp.tol+1));
                can[tkey]=true;
                for(int i=0;i<tmp.tol;++i) ans[tkey][i]=ans[tmp.key][i];
                ans[tkey][tmp.tol]='r';
                ans[tkey][tmp.tol+1]='\0';
            }
            swap(tt[x*3+y],tt[x*3+y-1]);
        }
        if(x<=1){
            swap(tt[x*3+y],tt[(x+1)*3+y]);
            tkey=Cantor(tt,9);
            if(!can[tkey]){
                q.push(node(tkey,x+1,y,tmp.tol+1));can[tkey]=true;
                for(int i=0;i<tmp.tol;++i) ans[tkey][i]=ans[tmp.key][i];
                ans[tkey][tmp.tol]='u';
                ans[tkey][tmp.tol+1]='\0';
            }
            swap(tt[x*3+y],tt[(x+1)*3+y]);
        }
        if(y<=1){
            swap(tt[x*3+y],tt[x*3+y+1]);
            tkey=Cantor(tt,9);
            if(!can[tkey]) {
                q.push(node(tkey,x,y+1,tmp.tol+1));can[tkey]=true;
                for(int i=0;i<tmp.tol;++i) ans[tkey][i]=ans[tmp.key][i];
                ans[tkey][tmp.tol]='l';
                ans[tkey][tmp.tol+1]='\0';
            }
            swap(tt[x*3+y],tt[x*3+y+1]);
        }
    }
}
int d[9];
void solve(){
    int tkey=Cantor(d,9);
    if(!can[tkey]){printf("unsolvable\n");return;}
    int len=strlen(ans[tkey]);
    for(int i=len-1;i>=0;--i)
        printf("%c",ans[tkey][i]);
    printf("\n");
}
char op[3];
int main(){
    bfs();
    while(scanf("%s",op)!=EOF){
        int i;
        for(i=0;i<=7;++i){
            if(op[0]=='x') d[i]=0;
            else d[i]=op[0]-'0';
            scanf("%s",op);
        }
        if(op[0]=='x') d[i]=0;
        else d[i]=op[0]-'0';
        solve();
    }
    return 0;
}
***********************************************/






