#include <iostream>
#include <string>
using namespace std;

class Sample
{
    private:
    char name;
    string ball;

    string makeBall(int r, int g, int b) 
    {
        return "\033[38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + "m●\033[0m";
    }

    public:
    Sample(int r, int g, int b)
    {
        ball = makeBall(r, g, b);
    }

    string getSample()
    {
        return ball;
    }
};