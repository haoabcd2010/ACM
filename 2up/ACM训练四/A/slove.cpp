#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0);
const double ln_10 = log(10.0);

double reback(int N)
{
    return ceil((N*log(double(N))- N+0.5*log(2.0*N*PI))/ln_10);
}

int main()
{
	int cas,n;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		if(n<=1)printf("1\n");
		else printf("%.0lf\n",reback(n));
	}
	return 0;
}

/*
解题思路：
1.可以暴力，N的阶乖的位数等于LOG10(N!)==LOG10(1)+.....LOG10(N);
2.Stirling公式: n! 与 √(2πn) * n^n * e^(-n)的值十分接近
故log10(n!) = log(n!) / log(10) = ( n*log(n) - n + 0.5*log(2*π*n))/log(n);
*/
