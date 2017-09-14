#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define LL long long
#define MOD 1000000007
#define MX 100100

int n;
int al_n[26];
LL num[26][MX];
LL quan[26];
char temp[MX];
bool ok[26];

bool cmp(int a,int b)
{
    if (al_n[a]!=al_n[b])
        return al_n[a]>al_n[b];

    for (int i=al_n[a];i>=0;i--)
        if (num[a][i]!=num[b][i])
        return num[a][i]>num[b][i];

    return 0;
}

int main()
{
    int cnt=1;
    while (scanf("%d",&n)!=EOF)
    {
        memset(quan,0,sizeof(quan));
        memset(num,0,sizeof(num));
        memset(ok,0,sizeof(ok));

        for (int i=0;i<n;i++)
        {
            scanf("%s",temp);
            int len = strlen(temp);
            LL k=1;
            for (int j=len-1;j>=0;j--)
            {
                num[temp[j]-'a'][k]++;
                k++;
            }
            if (len!=1)
                ok[temp[0]-'a']=1;
        }

        for (int i=0;i<26;i++)//×ÖÄ¸
        {
            al_n[i]=0;
            for (int j=1;j<MX;j++) //³¤¶È
            {
                if (num[i][j]) al_n[i]=j;
                if (num[i][j]>=26)
                {
                    int jin = num[i][j]/26;
                    num[i][j+1]+=jin;
                    num[i][j]%=26;
                }
            }
        }

        int alpa[26];
        for (int i=0;i<26;i++) alpa[i]=i;
        sort(alpa,alpa+26,cmp);

        if (al_n[alpa[25]]!=0&&ok[alpa[25]]==1)
        {
            for (int i=25;i>=0;i--)
            {
                if (ok[alpa[i]]==0)
                {
                    int sbsb=alpa[i];
                    for (int j=i+1;j<=25;j++)
                        alpa[j-1]=alpa[j];
                    alpa[25]=sbsb;
                    break;
                }
            }
        }

        LL ans = 0;
        LL qqq = 25;
        for (int i=0;i<26;i++)
        {
            int zimu = alpa[i];
            if (al_n[zimu]==0) continue;
            LL tp=qqq;
            for (int j=1;j<=al_n[zimu];j++)
            {
                ans = (ans + (tp * num[zimu][j])%MOD)%MOD;
                tp=(tp*26)%MOD;
            }
            qqq--;
        }
        printf("Case #%d: %lld\n",cnt++,ans);
    }
    return 0;
}
