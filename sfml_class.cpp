#include "sfml_class.hpp"
using namespace sfml_;


void SF::clear(render& window, const color_& color)
{
    window.clear(color);
}

void SF::display(render& window)
{
    window.display();
}

void SF::draw_ciferblat(render& window,  const Block* array, int length)
{
    auto ptr = &array[0];
    for(;;ptr++)
    {
        if(ptr == &array[length]) break;
        else
        {
            window.draw(*ptr->get_block_for_draw());
        }
    }
}

