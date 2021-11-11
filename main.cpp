#include <iostream>
#include "sfml_class.hpp"
#include "narrow.hpp"
#include "rectangle.hpp"
#include "sfml_engine.hpp"
#include "ciferblat.hpp"
#include "thetime.hpp"
using namespace thetime;
using namespace narrow;
using namespace sfml_;
using namespace clock_;
using namespace sf;
using namespace cifer;


static Event e;
static Color white_color {0xFF, 0xFF, 0xFF, 0xFF};
static Vector2i mytime_first;
static Vector2i mytime_second;

int main()
{
        Table t;
        Narrow narrows(&t);
        Ciferblat c(&t);
        ContextSettings settings;
        settings.antialiasingLevel = 8;
        RenderWindow window(VideoMode(S_W, S_H), "Clock_3", Style::Default, settings);
        SF engine;
        Time_ the_time;
        mytime_first.x = the_time.get_h();
        mytime_first.y = the_time.get_m();
        narrows.take_time(mytime_first);
        while(window.isOpen())
        {
                while(window.pollEvent(e))
                {
                        if(e.type == Event::Closed) window.close();
                }
                engine.clear(window, white_color);
                engine.draw_ciferblat(window, c.get_cif_shadow(), CIFERBLAT_COUNTS);
                engine.draw_ciferblat(window, c.get_cif(), CIFERBLAT_COUNTS);
                engine.draw_ciferblat(window, narrows.get_big_shadow(), NARROW_BIG_COUNTS);
                engine.draw_ciferblat(window, narrows.get_big(), NARROW_BIG_COUNTS);
                engine.draw_ciferblat(window, narrows.get_little_shadow(), NARROW_LITTLE_COUNTS);
                engine.draw_ciferblat(window, narrows.get_little(), NARROW_LITTLE_COUNTS);
                engine.display(window);
                Time_ the_time_second;
                mytime_second.x = the_time_second.get_h();
                mytime_second.y = the_time_second.get_m();
                if(mytime_second.y != mytime_first.y)
                {
                        mytime_first.x = mytime_second.x;
                        mytime_first.y = mytime_second.y;
                        narrows.take_time(mytime_first);
                }
    }
    return 0;
}
