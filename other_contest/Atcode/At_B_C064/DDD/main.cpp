#include<cstdio>
using namespace std;

int n;
char a[105];

int main()
{
    scanf("%d", &n);
    scanf("%s", &a);
    int l=0,r=0;
    for (int i=0;i<n;i++)
    {
        if (a[i] == '(') r++;
        else
        {
            if (r == 0) l++;
                    else r--;
        }
    }
    for (int i = 1; i <= l; i++)
        printf("(");

    printf("%s", a);

    for (int i = 1; i <= r; i++)
        printf(")");

    return 0;
}
