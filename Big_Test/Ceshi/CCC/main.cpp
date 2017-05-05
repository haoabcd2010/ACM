#include <iostream>
#include <string>
using namespace std;
class Goods{
public:
    Goods(string a,string b,double c,double d){
        No = a;
        Name = b;
        Price = c;
        Mquantity = d;
    }
    void account(){
        Msales = Price * Mquantity;
    }
    void display(){
        cout<<"No:"<<No<<endl;
        cout<<"Name:"<<Name<<endl;
        cout<<"Price:"<<Price<<endl;
        cout<<"Mquantity:"<<Mquantity<<endl;
        cout<<"Msales:"<<Msales<<endl;
    }
private:
    string No;
    string Name;
    double Price;
    double Mquantity;
    double Msales;
};
int main()
{
    Goods A("101","apple",5,50);
    A.display();
    return 0;
}

