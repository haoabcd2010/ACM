#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MEM 0x3f
// * / %
// + -
int check(char c[])
{
    if (c[0]=='*'||c[0]=='/'||c[0]=='%')
        return 2;
    return 1;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        char op1[5];
        char op2[5];
        int num[3];
        scanf("%d",&num[0]);
        scanf("%s",op1);
        scanf("%d",&num[1]);
        scanf("%s",op2);
        scanf("%d",&num[2]);
        int ans;
        if (check(op1)>=check(op2))
        {
            if (op1[0]=='+')
                ans = num[0]+num[1];
            else if(op1[0]=='-')
                ans = num[0]-num[1];
            else if (op1[0]=='*')
                ans = num[0]*num[1];
            else if (op1[0]=='/')
                ans = num[0]/num[1];
            else if (op1[0]=='%')
                ans = num[0]%num[1];

            if (op2[0]=='+')
                ans = ans+num[2];
            else if(op2[0]=='-')
                ans = ans-num[2];
            else if (op2[0]=='*')
                ans = ans*num[2];
            else if (op2[0]=='/')
                ans = ans/num[2];
            else if (op2[0]=='%')
                ans = ans%num[2];
        }
        else if (check(op1)<check(op2))
        {
            if (op2[0]=='+')
                ans = num[1]+num[2];
            else if(op2[0]=='-')
                ans = num[1]-num[2];
            else if (op2[0]=='*')
                ans = num[1]*num[2];
            else if (op2[0]=='/')
                ans = num[1]/num[2];
            else if (op2[0]=='%')
                ans = num[1]%num[2];

            if (op1[0]=='+')
                ans = num[0]+ans;
            else if(op1[0]=='-')
                ans = num[0]-ans;
            else if (op1[0]=='*')
                ans = num[0]*ans;
            else if (op1[0]=='/')
                ans = num[0]/ans;
            else if (op1[0]=='%')
                ans = num[0]%ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
