#include<iostream>
#include "bird.h"
using namespace std;

void birddoessomething(Bird*&bird)
{
    bird -> eat();
    bird-> fly();
    bird -> eat();
    bird->eat();

}

int main ()
{
    Bird *bird = new sparrow();
    sparrow *sp = new sparrow();
    sp->eat();
    birddoessomething(bird);

    return 0;
}