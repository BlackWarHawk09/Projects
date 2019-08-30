#pragma once

class Cells
{
private:
    int st, health;
public:

    Cells();
    int get_st();
    void set_st(const int &a);
    int get_health();
    void set_health(const int &a);

    void water();
    void void_cell();

    void rabbit();
    void tr_rabbit();

    void wolf(const int &a);

    void she_wolf(const int &a);
    void tr_she_wolf();


};