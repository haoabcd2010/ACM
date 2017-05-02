#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[120],t[120];
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%s%s",&s,t);
        int lens=strlen(s);
        int lent=strlen(t);
        int i,j,ok=0;
        int ans;
        for (i=0;i<lens;i++)
        {
            if (ok==1) break;
            for (j=0;j<lent;j++)
            {
                if (s[i+j]=='\0')//³¬¹ýs»¹ÊÇÆ¥Åä
                {
                    ans=lens+lent-j;
                    ok=1;
                    break;
                }
                if (s[i+j]==t[j])
                {
                    if (s[i+j+1]=='\0')
                    {
                        ans=lens+lent-(j+1);
                        ok=1;
                    }
                    continue;
                }
                else break;
            }
        }
        if (ok==0)
            ans=lens+lent;
        printf("%d\n",ans);
    }
    return 0;
}
