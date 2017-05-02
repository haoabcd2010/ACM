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
����˼·��
1.���Ա�����N�Ľ׹Ե�λ������LOG10(N!)==LOG10(1)+.....LOG10(N);
2.Stirling��ʽ: n! �� ��(2��n) * n^n * e^(-n)��ֵʮ�ֽӽ�
��log10(n!) = log(n!) / log(10) = ( n*log(n) - n + 0.5*log(2*��*n))/log(n);
*/
