#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int Longest_Increasing(int num[],int n){
    stack<int> st;
    st.push(1);
    for (int i = 1; i < n; ++i) {
        if(num[i] > num[i-1]){
            st.push(st.top()+1);
        }
        else
            st.push(st.top());
    }
    return st.top();
}

int num[1010];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&num[i]);
        printf("%d\n",Longest_Increasing(num,n));
    }

    return 0;
}
