#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans[200];

int main()
{
    int N;
    int a,b;
    while (cin>>N&&N)
    {
        int res=0;
        for (int i=1;i<=N;i*=10)
        {
            a=(N/i)/11;
            b=(N/i)%11;
            int c;
            if (b<10)
            {
                c =(N - N/i*i)/2;
                if ( ( (11*a+b)*i+2*c )==N)
                ans[res++]=a*i*10+b*i+c;
            }
            b--;
            if (a+b&&b>=0)
            {
                c =(N - N/i*i+ i)/2;
                if (((11*a+b)*i+2*c )==N)
                ans[res++]=a*i*10+b*i+c;
            }
        }

        if (res)
        {
            sort(ans,ans+res);
            cout<<ans[0];
            for (int i=1;i<res;i++)
                if(ans[i]!=ans[i-1])
                    cout<<' '<<ans[i];
            cout<<endl;
        }
        else
            printf("No solution.\n");
    }
    return 0;
}
