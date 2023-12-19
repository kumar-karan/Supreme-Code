#include<iostream>
using namespace std;

void printDigitsLoop(int n)
{
    while(n!= 0)
    {
        cout << n%10<< " ";
        n = n/10;
    }
    cout << endl;
}
void printDigits(int n)
{
    if(n == 0)
        return;
    printDigits(n/10);
    cout << n%10 << " ";

}

int main()
{
    int n;
    cin >> n;
    if(n == 0)
        cout<< 0<< endl;
    // else
    // printDigitsLoop(n);

    printDigits(n);
    return 0;
}