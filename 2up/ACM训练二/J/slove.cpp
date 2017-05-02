#include <stdio.h>
#include <string.h>

int ball[1005];

int main()
{
    int n;
	while(scanf("%d",&n)!=EOF)
	{
	    memset(ball,0,sizeof(ball));
	    int i;
	    int a;
	    for (i=1;i<=n;i++)
        {
            scanf("%d",&a);
            ball[a]++;
        }
        int ok=0;
        for (i=1;i<=998;i++)
        {
            if (ball[i]>0&&ball[i+1]>0&&ball[i+2]>0)
            {
                ok=1;
                break;
            }
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
	}
	return 0;
}
