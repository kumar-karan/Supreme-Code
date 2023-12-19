#include<iostream>
#include<vector>

using namespace std;

int main()
{
/*
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(80);
    v.push_back(90);
    v.push_back(100);
    v.push_back(110);
    v.push_back(120);
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


    // !Iterations 
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    vector<int> :: iterator it = v.begin(); // it points at memory of v.begin()

    it++;
    cout << *(it) << " " ;

    it = it+2;
    cout << *(it) << " " ;

    vector<int> :: iterator it = v.end(); // points to location right after the last value
    //vector <int> :: iterator it = v.rend(); // points to before the first location
    //vector<int> :: iterator it = v.rbegin(); // points to last value 

    cout << v[0] << " " << v.at(0)<<endl; // both gives the first value 
    cout << v.back()<< " "; // gives the last value
        cout << endl;


    for(vector <int> :: iterator it = v.begin(); it != v.end(); it++)
    {
        cout<< *(it) <<" ";

    }
        cout << endl;
    for( auto it = v.begin(); it != v.end(); it++)
    {
        cout<< *(it) <<" ";
    }
        cout << endl;

    for ( auto it: v)
    {
        cout << it << " ";
    }
        cout << endl;


    // ! ERASE 

    v.erase(v.begin()+1);

    for(auto i:v)
    {
        cout << i<< " ";
    }
    cout << endl;
    
    v.erase ( v.begin() + 2 , v.begin() +4); // erase start and end 
    // start is included and end is not included 

    for(auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
*/


    //! INSERT FUNCTION 

    vector<int> v(2,100); //{100,100}
    v.insert(v.begin(), 300); // { 300,100,100}
    v.insert(v.begin()+1, 2, 10); // {300,10,10,100,100}

    vector <int> copy(2,50);
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    for(auto i : v)
    { 
        cout << i<< ", ";
    };
    cout<<endl;

    v.pop_back(); // last one is removed

    vector<int>v1 = {10,20};
    vector<int>v2 = {30,40};
    //v1 -> {10,20}
    //v2 -> {30,40}
    v1.swap(v2); // 
    //v2 -> {10,20}
    //v1 -> {30,40}

    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    v.clear(); // erases the entire vector 

    cout << v.empty(); // tells if vector is empty or not 


    return 0;
}