#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define N 105

void add(string &a,string &sum)
{
    int l=min(a.size(),sum.size());
    reverse(a.begin(),a.end());
    reverse(sum.begin(),sum.end());

    char all[N];
    memset(all,0,sizeof(all));

    int i;
    for (i=0;i<l;i++)
    {
        all[i]+=(a[i]-'0')+(sum[i]-'0');
        if (all[i]>=10)
        {
            all[i]-=10;
            all[i+1]++;
        }
    }

    if (l<a.size())//a没加完
    {
        for (;i<a.size();i++)
        {
            all[i]+=a[i]-'0';
            if (all[i]>=10)
            {
                all[i]-=10;
                all[i+1]++;
            }
        }
    }

    if (l<sum.size())
    {
        for (;i<sum.size();i++)
        {
            all[i]+=sum[i]-'0';
            if (all[i]>=10)
            {
                all[i]-=10;
                all[i+1]++;
            }
        }
    }
    if (all[i]!=0) i++;//现在已经超出数据一位了，看是否有进位
    all[i]='\0';
    int m=i;
    reverse(all,all+i);
    for (i=0;i<m;i++)
        all[i]+='0';
    sum=all;
}

int main()
{
    string a,sum;
    int n;
    cin >> n;
    while(n--)
    {
        sum="0";
        while(1)
        {
            cin>>a;
            if (a=="0") break;
            add(a,sum);
        }
        cout<<sum<<endl;
        if(n)
        cout << endl;
    }

    return 0;
}
