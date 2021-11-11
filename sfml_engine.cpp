#include "sfml_engine.hpp"

using render = sf::RenderWindow;
using color_ = sf::Color;

void clear(render& window, const color_& color)
{
    window.clear(color);
}

void draw_block(render& window, const RectangleShape* shape)
{
    window.draw(*shape);
}