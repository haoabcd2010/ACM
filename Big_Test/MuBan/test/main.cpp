#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXS 5000
#define MAXT 500

char S[MAXS];
char T[MAXT];
int next[MAXT];

// �ؼ�����next������Ƶ���next[i] �����������:�������ƥ��ʧ�䣬j Ӧ�ñ�Ϊ����
//���Ƶ�nextʱ��ʹ�����Ѿ��Ƶ��˵�next���飬�����Ҹо���dp��˼��������
void get_next(char * t,int l)   //û�Ż������׳�����ʵ���Ż�����������
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<l)
    {
        if (j==-1||T[i]==T[j])
            next[++i]=++j;
        else
            j=next[j];  //����
    }
}

/*
//�Ż���next������˼�����ظ���״̬����һ����
void get_next(char * t,int l)   //�Ż��ģ�һ��ע�⣬Ҫ����ʹ��
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

int KMP(char *s,char *t)    //��ƥ������
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

int KMP_count(char *s,char *t) //��ƥ����,һ��Ҫ��û�Ż���
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
