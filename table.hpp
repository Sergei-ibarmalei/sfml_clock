#ifndef TABLE_HPP
#define TABLE_HPP

#include "consts.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

namespace table
{
    class Table
    {
        Vector2f* table_min;
        Vector2f* table_sec;
        void make_table_min();
        void make_table_sec();

        public:

        Table();
        ~Table();
        const Vector2f* table_m() const;
        const Vector2f* table_s() const;
    };
}

#endif