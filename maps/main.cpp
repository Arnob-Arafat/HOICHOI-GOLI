#include <iostream>
using namespace std;

#include "maps.cpp"

int main(void)
{
    Maps m(10);

    m.insert('2', 2, 3);

    m.print();
}