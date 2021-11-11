#ifndef SFML_ENGINE_HPP
#define SFML_ENGINE_HPP

#include "rectangle.hpp"
#include<SFML/Graphics.hpp>

using render = sf::RenderWindow;
using color_ = sf::Color;


void clear(render& window, const color_& color);
void display(render& window);
void draw_block(render& window, const RectangleShape* shape);



#endif