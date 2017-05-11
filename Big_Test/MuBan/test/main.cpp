#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXS 5000
#define MAXT 500

char S[MAXS];
char T[MAXT];
int next[MAXT];

// 关键在于next数组的推导，next[i] 代表的意义是:如果朴素匹配失配，j 应该变为多少
//在推导next时，使用了已经推导了的next数组，所以我感觉有dp的思想在里面
void get_next(char * t,int l)   //没优化但不易出错，其实不优化不会慢多少
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<l)
    {
        if (j==-1||T[i]==T[j])
            next[++i]=++j;
        else
            j=next[j];  //回溯
    }
}

/*
//优化的next很有意思，将重复的状态叠在一起了
void get_next(char * t,int l)   //优化的，一定注意，要慎重使用
{
    int i=0,j=-1;
    next[0]=-1;
    while (i<l)
    {
        if (j==-1||T[i]==T[j])
        {
            i++;j++;
            if (T[i]!=T[j]) next[i]=j;
            else next[i]=next[j];
        }
        else j = next[j];
    }
}
*/

int KMP(char *s,char *t)    //求匹配索引
{
    int lens = strlen(s);
    int lent = strlen(t);
    get_next(t,lent);
    int i=-1,j=-1;
    while (i<lens&&j<lent)
    {
        if (j==-1||S[i]==T[j])
            i++,j++;
        else
            j = next[j];

    }
    if (j==lent)
        return i-lent;
    return -1;
}

int KMP_count(char *s,char *t) //求匹配数,一定要用没优化的
{
    int res = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    get_next(t,lent);
    int i=-1,j=-1;
    while (i<lens)
    {
        if (j==-1||S[i]==T[j])
            i++,j++;
        else
            j = next[j];
        if (j==lent)
        {
            res++;
            j = next[j];
        }
    }
    return res;
}

int main()
{
    scanf("%s",S);
    scanf("%s",T);
    int p = KMP_count(S,T);
    printf("%d\n",p);
    return 0;
}
