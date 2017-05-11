#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define lowbit(x) (x&(-x))
#define INF 0x7f7f7f7f      // 21 E
#define MEM 0x7f            // memset 都变为 INF
#define MOD 4999            // 模
#define eps 1e-9            // 精度
#define MX  1000005         // 数据范围

int read() {    //输入外挂
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
// code... ...

int main()
{
    return 0;
}
