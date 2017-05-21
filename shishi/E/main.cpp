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
    // 其余的也就这么改就行了
    priority_queue<Node> Q1; // 结构体默认排序,权大先的出队
    priority_queue<Node ,vector<Node> ,greater<Node> > Q2; // 再定义出队顺序，权小的先出队

    for (int i=1;i<=10;i++)
    Q2.push((Node){i});
    while (!Q2.empty())
    {
        int x = Q2.top().x; Q2.pop(); // Q.size() 队列长度
        cout <<x<<' ';
    }
    return 0;
}
