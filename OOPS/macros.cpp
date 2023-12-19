#include<iostream>
using namespace std;

#define pi 3.14
#define MAXX(x,y) (x>y ? x:y )

float circlearea( float r)
{
    return pi * r * r ;
}
float perimeter( float r)
{
    return pi * r * 2 ;
}

void fun()
{
    int x = 6;
    int y = 17;
    int z = MAXX(6,17);
    cout << z << endl;
}



int main ()
{


    cout << circlearea(6.15)<< endl; 
    cout << perimeter(6.15)<< endl; 

    fun();
    return 0; 
}