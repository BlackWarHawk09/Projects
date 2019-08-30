#include <iostream>
#include <cstdlib>
#include "Cells.h"
#include "Island.h"
using namespace std;

int main()
{
    int N, n, m, r, w, sw;
   // cout << "Enter the number of steps: ";
   // cin >> N;
    cout << "Enter the widht:";
    cin >> n;
    cout << "Enter the lenght:";
    cin >> m;
    cout << "Enter the number of rabbits: ";
    cin >> r;
    cout << "Enter the number of wolfs: ";
    cin >> w;
    cout << "Enter the number of she wolfs: ";
    cin >> sw;
    Island a;
    if (a.create_island(n, m, r, w, sw))
    {
        a.placing(r, w, sw);
        a.print();
    }
    return 0;
}