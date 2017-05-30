#include <iostream>
using namespace std;
#define MOD 9973

int exgcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r = exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return r;
}

int main()
{
    cout<<endl;
    int T;
    cin>>T;
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        int x,y;
        int r = exgcd(b,MOD,x,y);
        x = (x+MOD)%MOD;
        cout<<(a*x)%MOD<<endl;
    }
    return 0;
}
