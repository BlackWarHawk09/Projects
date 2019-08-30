#include "Island.h"
using std::cout;
using std::endl;

Island::Island() : n(0), m(0), matrix(NULL) {};

bool Island::create_island(const int &zn, const int &zm, const int &z_rabbit, const int &z_wolf,
                           const int &z_she_wolf)
{
    n = zn;
    m = zm;
    if (n * m < (z_rabbit + z_wolf + z_she_wolf))
    {
        cout << "This island is too small for so many animals " << endl;
        return false;
    }
    else
    {
        matrix = new Cells[(n + 2) * (m + 2) - 1];
        for (int i = 0; i < (n + 2) * (m + 2); i++)
        {
            if ((i <= n + 1) or (i % (n + 2) == 0) or ((i - (n + 1)) % (n + 2) == 0) or (i >= (n + 2)*(m + 1)))
            {
                (matrix + i) -> water();
            }
        }
        return true;
    }
}

Island::~Island()
{
    delete [] matrix;
}

void Island::print()
{
    for (int i = 0; i < (n + 2)*(m + 2); i++)
    {
        if ((matrix + i) -> get_st() == -1) {cout << "[ ~ ]";}
        if ((matrix + i) -> get_st() == 0) {cout << "[   ]";}
        if ((matrix + i) -> get_st() == 1) {cout << "[ r ]";}
        if ((matrix + i) -> get_st() == 3) {cout << "[S" << (matrix + i) -> get_health() << "]";}
        if ((matrix + i) -> get_st() == 5) {cout << "[W" << (matrix + i) -> get_health() << "]";}
        if ((i - n - 1)%(n + 2) == 0) {cout << "\n";}
    }
}

void Island::placing(const int &z_rabbit, const int &z_wolf, const int &z_she_wolf)
{
    int r;
    for (int i = 0; i < z_rabbit;)
    {
        r = rand() % ((n + 2)*(m + 2));
        if ((matrix + r) -> get_st() == 0)
        {
            (matrix + r) -> rabbit();
            i++;
        }
    }

    for (int i = 0; i < z_wolf;)
    {
        r = rand() % ((n + 2)*(m + 2));
        if ((matrix + r) -> get_st() == 0)
        {
            (matrix + r) -> wolf(10);
            i++;
        }
    }

    for (int i = 0; i < z_she_wolf;)
    {
        r = rand() % ((n + 2)*(m + 2));
        if ((matrix + r) -> get_st() == 0)
        {
            (matrix + r) -> she_wolf(10);
            i++;
        }
    }
}