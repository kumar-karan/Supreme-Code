#include <iostream>
#include <vector>
#include <list>


using namespace std;

void explainList()
    {
        list<int> ls;

        ls.push_back(2);    //{2}
        ls.emplace_back(4); //{2,4}

        ls.push_front(5);   //{5,2,4}
        ls.emplace_front(); // {2,4};
        for (auto it : ls)
        {
            cout << it << " " << endl;
        }
    }

int main()
{
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // v.push_back(50);
    // v.push_back(60);
    /*
        vector<int> v;

        v.push_back(1); // push 1 in vector
        v.emplace_back(2); // faster than push back
        // pushes 2 in vecotr

        vector<pair<int,int>>vec;

        vec.push_back({1,2});
        vec.emplace_back(1,2);

        vector<int> v(5,100);  // {100,100,100,100,100,100}
        vector<int> v(5);  // 5 random values

        vector<int> v1(5,20);  // 20 five times
        vector<int> v2(v1));  // copy of v1


        // ITERATOR
        vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        vector<int> :: iterator it = v.begin(); // it points at memory of v.begin()

        it++;
        cout << (it) << " " ;

        it = it+2;
        cout <<(it) << " " ;

        vector<int> :: iterator it = v.end(); // points to location right after the last value
        //vector <int> :: iterator it = v.rend(); // points to before the first location
        //vector<int> :: iterator it = v.rbegin(); // points to last value


        cout << v[0] << " " << v.at(0) << endl;
        cout << v.back() << " ";

        // old way of printing the vector
        for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        {
            cout << *(it) << " " << endl;
        }

        // short way of printing the vector
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *(it) << " " << endl;
        }

        for (auto it : v)
        {
            cout << it << " " << endl;
        }


        //{10,20,20,40}
        v.erase(v.begin() + 1);
        // deletes 20


        // vector before deletion
        //{10,20,30,40,50,60}
        for (auto it : v)
        {
            cout << it << " " << endl;
        }

        // vector after deletion
        //{10,20,50,60}
        cout << "vector after deletion" << endl;
        v.erase(v.begin() + 2, v.begin() + 4);

        for (auto it : v)
        {

            cout << it << " " << endl;
        }


        // Insert function
        vector<int> v(2, 100);          //{100,100}
        v.insert(v.begin(), 300);       //{300,100,100}
        v.insert(v.begin() + 1, 2, 10); //{300,10,10,100,100}

        vector<int> v2(2, 50);                     //{50,50}
        v.insert(v.begin(), v2.begin(), v2.end()); //{50,50,300,10,10,100,100}

        //{10,20}
        cout << v.size(); // 2

        //{10,20}
        v.pop_back(); //{10}

        // v1-> {10,20}
        // v2->{30,40}
        v.swap(v2);        // v1-.{30,40},v2->{10,20}
        v.clear();         // erases the entire vector
        cout << v.empty(); // is empty?

    */

explainList();


    return 0;
}