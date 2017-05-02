#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MX 205
char A[MX],B[MX],C[MX*2];
int dp[MX][MX]; //dp[i][j] 意为 A的前i位，B的前j位能否组成C的前i+j位

int main()
{
    int T;
    cin>>T;
    for (int cnt=1;cnt<=T;cnt++)
    {
        scanf("%s %s %s",A,B,C);
        int lena = strlen(A);
        int lenb = strlen(B);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1;i<=lena;i++)
            if (A[i-1]==C[i-1]&&dp[i-1][0])
                dp[i][0]=1;
        for (int i=1;i<=lenb;i++)
            if (B[i-1]==C[i-1]&&dp[0][i-1])
                dp[0][i]=1;
        for (int i=1;i<=lena;i++)
            for (int j=1;j<=lenb;j++)
                dp[i][j] = (dp[i-1][j]&&A[i-1]==C[i+j-1])||(dp[i][j-1]&&B[j-1]==C[i+j-1]);
        printf("Data set %d: ",cnt);
        if (dp[lena][lenb])
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
