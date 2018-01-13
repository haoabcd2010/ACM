#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;
int cnt;
struct node{
    node *next[26];
    node *fail;
    int sum;
};

int N;
node *root;
char key[MX];
node *q[MX];
int head,tail;
node *newnode;
char pattern[MX];

void Insert(char *s)
{
    node *p = root;
    for(int i = 0; s[i]; i++)
    {
        int x = s[i] - 'a';
        if(p->next[x] == NULL)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            for(int j=0;j<26;j++) newnode->next[j] = 0;
            newnode->sum = 0;newnode->fail = 0;
            p->next[x]=newnode;
        }
        p = p->next[x];
    }
    p->sum++;
}
void build_fail_pointer()
{
    head = 0;
    tail = 1;
    q[head] = root;
    node *p;
    node *temp;
    while(head < tail)
    {
        temp = q[head++];
        for(int i = 0; i <= 25; i++)
        {
            if(temp->next[i])
            {
                if(temp == root)
                {
                    temp->next[i]->fail = root;
                }
                else
                {
                    p = temp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q[tail++] = temp->next[i];
            }
        }
    }
}
void ac_automation(char *ch)
{
    node *p = root;
    int len = strlen(ch);
    for(int i = 0; i < len; i++)
    {
        int x = ch[i] - 'a';
        while(!p->next[x] && p != root) p = p->fail;
        p = p->next[x];
        if(!p) p = root;
        node *temp = p;
        while(temp != root)
        {
           if(temp->sum >= 0)
           {
               cnt += temp->sum;
               temp->sum = -1;
           }
           else break;
           temp = temp->fail;
        }
    }
}

void _delete(node *p)
{
    for (int i=0;i<26;i++)
    {
        if (p->next[i]!=NULL)
            _delete(p->next[i]);
    }
    delete(p);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        root=(struct node *)malloc(sizeof(struct node));
        for(int j=0;j<26;j++) root->next[j] = 0;
        root->fail = 0;
        root->sum = 0;
        scanf("%d",&N);
        getchar();
        int mxlen=0;
        for(int i = 1; i <= N; i++)
        {
            gets(key);
            Insert(key);
            int len=strlen(key);
            if (len>mxlen)
            {
                mxlen=len;
                strcpy(pattern,key);
            }
        }
        cnt = 0;
        build_fail_pointer();
        ac_automation(pattern);
        if (cnt==N)
            puts(pattern);
        else printf("No\n");
        _delete(root);
    }
    return 0;
}
