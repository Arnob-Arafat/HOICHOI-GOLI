#include <iostream>
#include <vector>
#include "samplechar.cpp"
using namespace std;

class Maps
{
    private:
    vector<vector <string>> map;

    public:
    Maps(int len)
    {
        map = vector<vector<string>>(len, vector<string>(len, "."));
    }


    void insert(char name, int x, int y)
    {
        Sample s(255, 60, 60);
        map[x][y] = s.getSample();
    }

    void remove(int x, int y)
    {
        map[x][y] = '.';
    }

    void print()
    {
        for (vector v : map) 
        {
            for (string c : v) 
            {
                cout << c << " ";
            }
            cout << "\n";
        }
    }
};