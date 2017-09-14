#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=10005;
int data[maxn];

int main()
{
    int n;
    for(n=3;n<15;n++){
        for(int i=1;i<=n;i++){
            data[i-1]=i;
        }
        int cnt=0;
        while(next_permutation(data, data+n)){
//            for(int i=0;i<n;i++){
//                cout<<data[i]<<" ";
//            }
//            cout<<endl;
            bool is=1;
            for(int i=1;i<n-1;i++){
                bool p1=data[i]>data[i-1]&&data[i]>data[i+1];
                bool p2=data[i]<data[i-1]&&data[i]<data[i+1];
                if(!(p1||p2)){
                    is=0;break;
                }
            }
            if(is)cnt++;
        }
        cout<<"n:"<<n<<"  v:"<<cnt<<endl;
    }
    return 0;
}
