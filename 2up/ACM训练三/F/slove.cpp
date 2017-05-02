/*
//�Լ�д�� TLE
//�ҵ�����ô���ģ���L�����Ե����������dfsһ�飬�����յ�� ans=max(ans,sc);
//�����֪��Ч�ʱȽϵ�
#include <stdio.h>
#include <string.h>

char map[55][55];
int jewel[12];//���ؼ�ֵ
bool vis [12];

int W,H,L,M;
int star_x,star_y;
int end_x,end_y;
int ans;

bool check(int x,int y)
{
    if (x<1||x>H||y<1||y>W)
        return 0;
    if (map[x][y]=='*')
        return 0;
    return 1;
}

void dfs(int x,int y,int step,int sc,int pre_x,int pre_y)
{      //λ��x��λ��y����������������һ����x����һ����y
    if (step>L) return ;
    if (x==end_x&&y==end_y)
    {
        if (sc>ans)
            ans=sc;
        return;
    }

    int re=0;
    if (map[x][y]<='J'&&map[x][y]>='A'&&vis[map[x][y]-'A']==0)//������鱦�����һ�û�ù�
    {
        sc+=jewel[map[x][y]-'A'];
        vis[map[x][y]-'A']=1;
        re=1;
    }

    if (re==1) //����������
    {
        dfs(pre_x,pre_y,step+1,sc,x,y);
    }

    int n_x,n_y;
    n_x=x;
    n_y=y+1;
    if (check(n_x,n_y)&&!(n_x==pre_x&&n_y==pre_y))//�����߲��Ҳ���ͷ
    {
        dfs(n_x,n_y,step+1,sc,x,y);
    }

    n_x=x+1;
    n_y=y;
    if (check(n_x,n_y)&&!(n_x==pre_x&&n_y==pre_y))//�����߲��Ҳ���ͷ
    {
        dfs(n_x,n_y,step+1,sc,x,y);
    }

    n_x=x;
    n_y=y-1;
    if (check(n_x,n_y)&&!(n_x==pre_x&&n_y==pre_y))//�����߲��Ҳ���ͷ
    {
        dfs(n_x,n_y,step+1,sc,x,y);
    }

    n_x=x-1;
    n_y=y;
    if (check(n_x,n_y)&&!(n_x==pre_x&&n_y==pre_y))//�����߲��Ҳ���ͷ
    {
        dfs(n_x,n_y,step+1,sc,x,y);
    }

    if (re==1)//���鱦�Ż�ȥ
    {
        vis[map[x][y]-'A']=0;
    }

}

int main()
{
	int T;
	int cas;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&W,&H);
		scanf("%d%d",&L,&M);
		for (int i=0;i<M;i++)
		scanf("%d",&jewel[i]);
		getchar();//���ջس�

		for (int i=1;i<=H;i++)
		{
			for (int j=1;j<=W;j++)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='@')
                {
                    star_x=i;
                    star_y=j;
                }
                if (map[i][j]=='<')
                {
                    end_x=i;
                    end_y=j;
                }
			}
			getchar();
		}
		ans=-1;
		memset(vis,0,sizeof(vis));//�鱦��û���ù�
		dfs(star_x,star_y,0,0,0,0);//���x�����y����������������һ����x����һ����y
		printf("Case %d:\n",cas);
		if (ans==-1)
            printf("Impossible\n");
        else
            printf("The best score is %d.\n",ans);
        if(cas!=T)
            printf("\n");
	}
	return 0;
}
*/


//BFS+DFS so good!
//BFS ��ÿ����������ҵ�����㵽����������·
//��һ����ά���鱣�����أ���ڣ�����֮�����̾���
//DFS ����������ȥ��������ֵ��Ȼ��ȥ����

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 52
using namespace std;


int n,m,l,cnt,ans,sum;
int sx,sy,ex,ey;

int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,-1,1};

char mp[maxn][maxn];
int jewel[15];//�鱦��ֵ

struct Node
{
    int x,y;
    int step;
};
int bvis[maxn][maxn];//bfs��ʱ��vis
int min_d[12][12];   //���أ������֮����С����

int b_check(int x,int y)
{
    if (x<0||x>=n||y<0||y>=m)
        return 0;
    if (mp[x][y]=='*'||bvis[x][y]==1)
        return 0;
    return 1;
}


int bfs(int x,int y,int k)
{
    Node now,next;
    now.x=x;
    now.y=y;
    now.step=0;
    queue<Node> Q;
    bvis[now.x][now.y]=1;
    Q.push(now);
    memset(bvis,0,sizeof(bvis));
    while (!Q.empty())
    {
        now=Q.front();
        Q.pop();
        if (now.step>l) break;
        int n_x,n_y;
        for (int i=0;i<4;i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.step=now.step+1;

            if (b_check(next.x,next.y))//���������
            {
                if (mp[next.x][next.y]>='A'&&mp[next.x][next.y]<='J')
                {
                    min_d[k][mp[next.x][next.y]-'A']=next.step;
                    min_d[mp[next.x][next.y]-'A'][k]=next.step;
                }
                else if(mp[next.x][next.y]=='@')
                {
                    min_d[k][10]=next.step;
                    min_d[10][k]=next.step;
                }
                else if(mp[next.x][next.y]=='<')
                {
                    min_d[k][11]=next.step;
                    min_d[11][k]=next.step;
                }
                bvis[next.x][next.y]=1;
                Q.push(next);
            }
        }
    }
}

int dvis[12];

int dfs(int now,int sc,int step)
{
    if (sc<10) sc+=jewel[now];

    if (step>l||ans==sum) return 0;

    if (now==11&&sc>ans)
    {
        ans=sc;
        return 0;
    }


    for (int i=0;i<12;i++)
    {
        if (min_d[now][i]!=-1&&dvis[i]==0)//�������ȥ������û���ù�
        {
            dvis[i]=1;
            dfs(i,sc,step+min_d[now][i]);
            dvis[i]=0;
        }
    }
}

int main()
{
    int t,t1=0;
    scanf("%d",&t);
    while(t--)
    {
        t1++;

        sum=0;//�鱦�ܼ�ֵ
        int i,j;

        scanf("%d%d%d%d",&m,&n,&l,&cnt);
        for (i=0;i<cnt;i++)
        {
            scanf("%d",&jewel[i]);
            sum+=jewel[i];
        }
        getchar();
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                scanf("%c",&mp[i][j]);
                if (mp[i][j]=='@') sx=i,sy=j;
                if (mp[i][j]=='<') ex=i,ey=j;
            }
            getchar();
        }

        memset(min_d,-1,sizeof(min_d));//��ʽͼ����
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (mp[i][j]>='A'&&mp[i][j]<='J') bfs(i,j,mp[i][j]-'A');
                else if (mp[i][j]=='@') bfs(i,j,10);
            }
        }

        /*
        //�����ʽͼ
        for (i=0;i<12;i++)
        {
            for (j=0;j<12;j++)
                printf("%d\t",min_d[i][j]);
            printf("\n");
        }
        */


        ans=-1;
        memset(dvis,0,sizeof(dvis));
        dvis[10]=1;
        dfs(10,0,0);//����ڿ�ʼ����ʼ����Ϊ0������0
        printf("Case %d:\n",t1);
        if(ans!=-1) printf("The best score is %d.\n",ans);
        else printf("Impossible\n");
        if(t) printf("\n");
    }
    return 0;
}
