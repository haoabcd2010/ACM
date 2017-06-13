#include<iostream>
using namespace std;

class container
{
protected:
    double  radius;
public:
    container(double  r);
    virtual double surface_area()=0;
};


container::container(double r)
{
	radius=r;
};

class cube:public container
{
public:
    cube(double r):container(r){}
    double surface_area()
    {
        cout<<"正方体的表面积为："<<6*radius*radius<<endl;
        return 0;
    }
};

int main()
{
    cube p(8);
    p.surface_area();
    return 0;
}
