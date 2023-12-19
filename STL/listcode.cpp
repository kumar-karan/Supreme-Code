#include<iostream>
#include<vector>
#include<list>
#include<deque>

using namespace std;

void explainList()

{
    list<int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}
    ls.emplace_front(6); // {6,5,2,4}

    for(auto i : ls )
    { 
        cout<< i<< " ";
    }
    cout << endl;

}


void explainDequeue()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    for(auto i : dq )
    { 
        cout<< i<< " ";
    }
    cout << endl;

}

int main()
{
    
    // explainList();
    explainDequeue();

    
    return 0;
}
