#include <iostream>
using namespace std;
#define LL unsigned long long

LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

int main()
{
   int T;
   cin>>T;
   while(T--)
   {
       LL a,b;
       cin>>a>>b;
       cout<<a*b/gcd(a,b)<<endl;
   }
    return 0;
}
