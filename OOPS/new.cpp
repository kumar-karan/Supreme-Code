#include<iostream>
using namespace std;

class Animal
{
    public:
    int age;
    int weight;

    void speak()
    {
        cout<<"Speaking"<<endl;
    }
};

class Dog : public Animal
{
    public:
    void speak()
    {
        cout<<"Barking"<<endl;
    }

};


int main ()
{

    Animal a;
    a.speak();

    Dog d1;
    d1.speak();

     
}