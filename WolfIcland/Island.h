#include "Cells.h"
#include <iostream>
#include <cstdlib>

class Island
{
private:
    int n, m;
    Cells* matrix;
public:
    Island();
    ~Island();
    bool create_island(const int &zn, const int &zm, const int &z_rabbit, const int &z_wolf, const int &z_she_wolf);
    void island_life(const int &N);
    void placing(const int &z_rabbit, const int &z_wolf, const int &z_she_wolf);
    void moving(const int &coord);
    void double_rabbit(const int &coord);
    void double_wolf(const int &coord);
    void print();
};