#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "consts.hpp"
using namespace sf;


namespace clock_
{
    class Block
    {
        Vector2f position;
        RectangleShape* block;
        block_kind kind;

        public:
        Block();
        ~Block();
        
        block_kind get_kind() const;
        const RectangleShape* get_block_for_draw() const {return block;}
        RectangleShape* get_block();

        
    };
} // namespace clock


#endif