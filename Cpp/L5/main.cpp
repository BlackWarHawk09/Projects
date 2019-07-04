#include <iostream>
#include<math.h>

using namespace std;

class Shape
{
    public:
        virtual bool isInside(double x, double y) const = 0;
};

class Square : public Shape
{
    public:
        Square(double x1, double y1, double x2, double y2) : lbx(x1), lby(y1), rtx(x2), rty(y2) { }

    virtual bool isInside(double x, double y) const override
    {
        if (x >= lbx && y >= lby && x <= rtx && y <= rty)
        {
            return 1;
        }
        else {
            return 0;
        }
    }

private:
    double lbx, lby;
    double rtx, rty;
};

class Circle : public Shape
{
    public:
        Circle(double x, double y, double r = 1) : _r(r), cx(x), cy(y) { }

    virtual bool isInside(double x, double y) const override
    {
        if (pow((cx - x), 2) + pow((cy - y), 2) <= pow(_r, 2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

private:
    double _r;
    double cx;
    double cy;
};

int main()
{
    const int N = 50;
    Shape *ar[N];
    for (int i = 0; i < N; i++)
    {
        if (i % 2)
        {
            ar[i] = new Circle(i * 2, i, 40);
            // x, y, radius
        }
        else {
            ar[i] = new Square(i, i, (i + 1) * (i + 2), i + 10);
            // x, y of left bottom point, then x, y of right top point
        }
    }
    long long int ans = 0;

    for (int i = 0; i < N; i++)
    {
        ans = ans * 2 + (int)ar[i]->isInside(i * 2 - 1, i * 2 - 1);
        // count boundary points as inside points
    }
    if (ans != 562766701483008)
    {
        cout << "testing fail" << endl;
    }
    else
    {
        cout << "all test passed" << endl;
    }
    for (int i = 0; i < N; i++)
    {
        delete ar[i];
    }
    cin.get();
    return 0;
}