#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

const int N = 1005;
int n,H;
vector <int> v[N];

int main()
{
    scanf("%d%d",&n,&H);
    for(int i=0;i<n;i++)
    {
        int h,p;
        scanf("%d%d",&h,&p);
        int x = min(n,H-h); //�����ڵڼ���
        v[x].push_back(p);
    }

    priority_queue<int> q;
    int ans = 0;
    int s = 0;
    for(int i=1;i<=n;i++) //������ i ��ɲ�����Ч��
    {
        while (q.size()>=i)
        {
            s+=q.top();
            q.pop();
        }
        for(int p=0;p<v[i].size();p++) //ȫ������
        {
            q.push(-v[i][p]);
            s += v[i][p];
        }
        while (q.size()>i+1) //���ֻ�ܷ�i+1��
        {
            s+=q.top();
            q.pop();
        }
        ans = max(ans,s);
    }
    printf("%d\n",ans);
}
