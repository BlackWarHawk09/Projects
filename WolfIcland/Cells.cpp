#include "Cells.h"

Cells::Cells() : st(0), health(0) {};

int Cells::get_st()
{
    return st;
}

void Cells::set_st(const int &a)
{
    st = a;
}

int Cells::get_health()
{
    return health;
}

void Cells::set_health(const int &a)
{
    health = a;
}

void Cells::water()
{
    st = -1;
}

void Cells::void_cell()
{
    st = 0;
    health = 0;
}

void Cells::rabbit()
{
    st = 1;
    health = 0;
}

void Cells::tr_rabbit()
{
    st = 2;
    health = 0;
}

void Cells::she_wolf(const int &a)
{
    if (a != 0)
    {
        st = 3;
        health = a;
    }
    else
    {
        this->void_cell();
    }
}
void Cells::tr_she_wolf()
{
    st = 4;
    health = 0;
}

void Cells::wolf(const int &a)
{
    if (a != 0)
    {
        st = 5;
        health = a;
    }
    else
    {
        this->void_cell();
    }
}