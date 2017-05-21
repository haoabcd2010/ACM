#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

char str[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void print(int w)
{
    stack<int> st;
    while (w)
    {
        st.push(w%10);
        w/=10;
    }
    while (!st.empty())
    {
        printf("%s",str[st.top()]);
        st.pop();
    }
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        int s1=0,s2=0;
        char str[105];
        scanf("%s",str);
        for (int i=0;i<n;i++)
            s1+=str[i]-'0'+1;
        scanf("%s",str);
        for (int i=0;i<m;i++)
            s2+=str[i]-'0'+1;
        if (s1%3!=s2%3)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
