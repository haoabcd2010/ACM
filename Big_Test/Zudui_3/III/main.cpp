#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int  t,n,k;
    double m,ans;
    char c[4];
    cin>>t;
    while (t--)
    {
        cin>>n>>c;
        ans = 0;
        if (c[0] == 'b')
        {
            k=0;
        }
        else if (c[0] == 'n')
        {
            k=1;
        }
        else
        {
            k=2;
        }
        for (int i=0;i<n;i++)
        {
            cin>>m;
            if (abs(m-0) < 1e-9)
            {
                continue;
            }
            switch(k)
            {
                case 0: ans += (m/100)*log2(m/100); break;
                case 1: ans += (m/100)*log(m/100); break;
                case 2: ans += (m/100)*log10(m/100);
            }
        }
        printf ("%.12lf\n",abs(-ans));
    }
    return 0;
}
