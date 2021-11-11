#include "table.hpp"
#include <cmath>

using namespace table;

Table::Table()
{
    table_min = new Vector2f[CIFERBLAT_COUNTS];
    table_sec = new Vector2f[CIFERBLAT_COUNTS_SEC];
    make_table_min();
    make_table_sec();
}

Table::~Table()
{
    delete [] table_min;
    table_min = 0;
    delete [] table_sec;
    table_sec = 0;
}

void Table::make_table_sec()
{
    float alpha {270.0f};
    auto ptr = &table_sec[0];
    for(;;ptr++)
    {
        if(ptr == &table_sec[CIFERBLAT_COUNTS_SEC]) break;
        else
        {
            ptr->x = cos(alpha * RADIAN);
            ptr->y = sin(alpha * RADIAN);
            alpha += 1.0f/2.0f;
        }
    }
}





void Table::make_table_min()
{
    float alpha {270.0f};
    auto ptr = &table_min[0];
    for(;;ptr++)
    {
        if(ptr== &table_min[CIFERBLAT_COUNTS]) break;
        else
        {
            ptr->x = cos(alpha*RADIAN);
            ptr->y = sin(alpha*RADIAN);
            alpha += 6.0f;
        }

    }
}

const Vector2f* Table::table_m() const
{
    return table_min;
}

const Vector2f* Table::table_s() const
{
    return table_sec;
}