#include "rectangle.hpp"

//using namespace sf;
using namespace clock_;

Block::Block()
{
    block = new RectangleShape;
}



Block::~Block()
{
    delete block;
    block = 0;
}


RectangleShape* Block::get_block()
{
    return block;
}