#include<iostream>

using namespace std;

class abc 
{
    public:
    int x;
    int *y;

    abc (int _x, int _y): x(_x), y(new int(_y)) {}

    // default dumb copy constructor : SHALLOW COPY 
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

    // SMART DEEP COPY 
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(* obj.y);
    }

    void print() const{
        cout <<endl<< "X: "<< x<<endl<<"PTR Y : " <<y <<endl<<"Content of Y (*y): " <<*y <<endl;

    }

    ~abc()
    {
        delete y;
    }
};

int main()
{
    abc *a = new abc (1,2);

    abc b= *a;
    delete a;
    b.print();
}

int main2 ()
{
    abc a(1,2);
    a.print();

    abc b =a;
    b.print();

    *b.y = 20;
    b.print();
    a.print();

    return 0;
}