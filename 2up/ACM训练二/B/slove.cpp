
#include <bits/stdc++.h>
using namespace std;

vector<int> word[26];
int vis[26];
string str;

int dfs(int t)
{
    vis[t]=2;//已经拓扑过了
    int i;
    for (i=0;i<word[t].size();i++)
    {
        if (vis[word[t][i]]==3)
        {
            dfs(word[t][i]);
        }
    }
    str+=t+'a';
}

int main()
{
    int n;
    while (cin>>n)
    {
        string DNA;
        memset(vis,0,sizeof(vis));
        int i;
        while(n--)
        {

            cin>>DNA;
            for (i=0;i<DNA.size()-1;i++)
            {
                word[DNA[i]-'a'].push_back(DNA[i+1]-'a');
                vis[DNA[i+1]-'a']=3;//标记已有排序
            }
            if (vis[DNA[0]-'a']!=3)//标记拓扑起点
                vis[DNA[0]-'a']=1;
        }
        str.clear();
        for (i=0;i<26;i++)
        {
            if (vis[i]==1)//可以拓扑
            dfs(i);
        }
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
const int maxn = 250;
vector<int>e[26];
int vis[maxn];
string ans;
void dfs(int x)
{
	vis[x]=2;//正在拓扑
	for (int i = 0;i<e[x].size();i++)
	{
		if (vis[e[x][i]]==2)//防止无线循环
			continue;
		dfs(e[x][i]);
	}
	ans+=(char)('a'+x);
}
int main()
{
    int n;
	while (scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for (int i = 1;i<=n;i++)
        {
            string s;
            cin >> s;
            for (int j = 0;j<s.size()-1;j++)
                e[s[j]-'a'].push_back(s[j+1]-'a'),vis[s[j+1]-'a']=3;//将字符1-size标记为在序列里
            if (vis[s[0]-'a']!=3)
                vis[s[0]-'a']=1;
        }
        ans.clear();
        for (int i = 0;i<26;i++)
            if (vis[i]==1)
			dfs(i);
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
}
*/

