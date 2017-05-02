#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int k;

int num[4002][4];
int s[16000005];

int erfen(int t)
{
    int l=0,r=k-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (s[mid]==t)
        {
            int e = mid-1;
            int  all=1;
            while (e>=0&&s[e]==t)
                e--,all++;
            e=mid+1;
            while (e<k&&s[e]==t)
                e++,all++;
            return all;
        }
        else if (s[mid]>t)
            r=mid-1;
        else
            l=mid+1;
    }
    return 0;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d%d%d%d",&num[i][0],&num[i][1],&num[i][2],&num[i][3]);
        k=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            s[k++]=-(num[i][2]+num[j][3]);
        sort(s,s+k);
        int total=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int left=num[i][0]+num[j][1];
                total+=erfen(left);
            }
        }
        printf("%d\n",total);
    }
    return 0;
}
