#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn=505;
char mat[maxn][maxn], pat[maxn][maxn];
int vis[maxn][maxn], n, ans;
char di[maxn];int din[maxn];
int row[maxn], col[maxn];

bool dfs(int x, char c){
    if(c=='R'){
        for(int i=1;i<=n;i++){
            pat[x][i]='#';
            vis[x][i]++;
            if(vis[x][i]==2&&pat[x][i]!=mat[x][i])return false;
        }
    }
    for(int i=1;i<=n;i++){
        if(row[i]==0){
            row[i]=1;
            dfs(i, 'R');
        }
        else row[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            col[i]=1;
            dfs(i, 'C');
        }
        else col[i]=0;
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%s", mat[i][1]);
        }
        ans=0;
        memset(vis, 0, sizeof(vis));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i=1;i<=n;i++){
            row[i]=1;
            if(dfs(i, 'R')){
                ans=1;break;
            }
        }
        if(!ans){
            for(int i=1;i<=n;i++){
                col[i]=1;
                if(dfs(i, 'C')){
                    ans=1;break;
                }
            }
        }
        if(!ans){
            printf("No solution\n");
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    printf("%c", pat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
