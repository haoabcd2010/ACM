#include <iostream>
#include <cmath>
using namespace std;

int ans, x, n;

int main()
{
    while(cin>>n){
        ans=0;
        while(n--){
            cin>>x;
            ans=max(ans, x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
