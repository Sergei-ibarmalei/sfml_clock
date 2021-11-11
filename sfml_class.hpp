#ifndef SFML_CLASS_HPP
#define SFML_CLASS_HPP
#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

namespace sfml_
{
    using render = sf::RenderWindow;
    using color_ = sf::Color;
    using namespace clock_;

    class SF
    {
        public:
        void clear(render& window, const color_& color);
        void display(render& window);
        void draw_ciferblat(render& window, const Block* array, int length);
        
    };

}

#endif