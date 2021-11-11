#ifndef NARROW_HPP
#define NARROW_HPP

#include "rectangle.hpp"
#include "table.hpp"
#include "consts.hpp"

using namespace clock_;
using namespace table;

namespace narrow
{
    class Narrow
    {
        Block* big_narrow;
        Block* big_narrow_shadow;
        Block* little_narrow;
        Block* little_narrow_shadow;
        const Table* table;

        //Установка координат стрелок
        void set_narrow(const Vector2i& time);

        //Установка координат часовой стрелки
        void set_big(const Vector2i& time);

        //Установка координат секундной стрелки
        void set_little(const Vector2i& time);

        public:
        Narrow(const Table* t);
        ~Narrow();

        const Block* get_big() const;
        const Block* get_big_shadow() const;
        const Block* get_little() const;
        const Block* get_little_shadow() const;
        void take_time(const Vector2i& time);



        

    };
}

#endif