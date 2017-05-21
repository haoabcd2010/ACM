#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int x;
    bool operator <(const Node& b)const{
        return x<b.x;
    }
    bool operator >(const Node& b)const{
        return x>b.x;
    }
};

int main()
{
    // �����Ҳ����ô�ľ�����
    priority_queue<Node> Q1; // �ṹ��Ĭ������,Ȩ���ȵĳ���
    priority_queue<Node ,vector<Node> ,greater<Node> > Q2; // �ٶ������˳��ȨС���ȳ���

    for (int i=1;i<=10;i++)
    Q2.push((Node){i});
    while (!Q2.empty())
    {
        int x = Q2.top().x; Q2.pop(); // Q.size() ���г���
        cout <<x<<' ';
    }
    return 0;
}
