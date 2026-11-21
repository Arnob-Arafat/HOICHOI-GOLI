#include <iostream>
#include <vector>
using namespace std;

class Maps
{
    public:
    vector<vector <char>> map;
    
    Maps(int len)
    {
        for (int i = 0; i < len; i++)
        {
            vector<char> row;
            for (int j = 0; j < len; j++)
            {
                row.push_back('.');
            }
            map.push_back(row);
        }
    }


    void print()
    {
        for (vector v : map) 
        {
            for (char c : v) 
            {
                cout << c << " ";
            }
            cout << "\n";
        }
    }
};