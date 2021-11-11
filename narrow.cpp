#include "narrow.hpp"

using namespace narrow;
using namespace clock_;
using namespace table;

static Color red_color   {0xFF, 0x00, 0x00, 0xFF};
static Color black_color {0x00, 0x00, 0x00, 0xFF};


Narrow::Narrow(const Table* t)
{
    table = t;
    big_narrow           = new Block[NARROW_BIG_COUNTS];
    big_narrow_shadow    = new Block[NARROW_BIG_COUNTS];
    little_narrow        = new Block[NARROW_LITTLE_COUNTS];
    little_narrow_shadow = new Block[NARROW_LITTLE_COUNTS];

}

Narrow::~Narrow()
{
    table = 0;
    delete [] big_narrow;
    big_narrow = 0;
    delete [] big_narrow_shadow;
    big_narrow_shadow = 0;
    delete [] little_narrow;
    little_narrow = 0;
    delete [] little_narrow_shadow;
    little_narrow_shadow = 0;
}

void Narrow::set_narrow(const Vector2i& time)
{
    set_big(time);
    set_little(time);
}
 
void Narrow::take_time(const Vector2i& time) 
{
    set_narrow(time);
}

void Narrow::set_big(const Vector2i& time)
{
    //Радиус стрелки
    float radius  {0.0f};
    auto ptr        = &big_narrow[0];
    auto ptr_shadow = &big_narrow_shadow[0];
    for(;;ptr++, ptr_shadow++)
    {
        if(ptr == &big_narrow[NARROW_BIG_COUNTS]) break;
        int table_angle_h = time.x * 60 + time.y;
        float x = CENTERX + radius * table->table_s()[table_angle_h].x;
        float y = CENTERY + radius * table->table_s()[table_angle_h].y;
        ptr->get_block()->setSize(Vector2f(NARROW_BIG_SIDE, NARROW_BIG_SIDE));
        ptr_shadow->get_block()->setSize(Vector2f(NARROW_BIG_SIDE, NARROW_BIG_SIDE));
        ptr->get_block()->setPosition(x - NARROW_BIG_SIDE_HALF, y - NARROW_BIG_SIDE_HALF);
        ptr_shadow->get_block()->setPosition(Vector2f(x + SHADOW_SHIFT - NARROW_BIG_SIDE_HALF,
                                                        y + SHADOW_SHIFT - NARROW_BIG_SIDE_HALF));
        ptr->get_block()->setFillColor(red_color);
        ptr_shadow->get_block()->setFillColor(black_color);
        radius += NARROW_SHIFT;
        
    }
}

void Narrow::set_little(const Vector2i& time)
{
    float radius {0.0f};
    auto ptr        = &little_narrow[0];
    auto ptr_shadow = &little_narrow_shadow[0];
    for(;;ptr++, ptr_shadow++)
    {
        if(ptr == &little_narrow[NARROW_LITTLE_COUNTS]) break;
        int table_angle_m = time.y ;
        float x = CENTERX + radius * table->table_m()[table_angle_m].x;
        float y = CENTERY + radius * table->table_m()[table_angle_m].y;
        ptr->get_block()->setSize(Vector2f(NARROW_LITTLE_SIDE, NARROW_LITTLE_SIDE));
        ptr_shadow->get_block()->setSize(Vector2f(NARROW_LITTLE_SIDE, NARROW_LITTLE_SIDE));
        ptr->get_block()->setPosition(x - NARROW_LITTLE_SIDE_HALF, y - NARROW_LITTLE_SIDE_HALF);
        ptr_shadow->get_block()->setPosition(Vector2f(x + SHADOW_SHIFT - NARROW_LITTLE_SIDE_HALF,
                                                    y + SHADOW_SHIFT - NARROW_LITTLE_SIDE_HALF));
        ptr->get_block()->setFillColor(red_color);
        ptr_shadow->get_block()->setFillColor(black_color);
        radius += NARROW_LITTLE_SHIFT;
    }
}



const Block* Narrow::get_big() const
{
    return big_narrow;
}

const Block* Narrow::get_big_shadow() const
{
    return big_narrow_shadow;
}

const Block* Narrow::get_little() const
{
    return little_narrow;
}

const Block* Narrow::get_little_shadow() const
{
    return little_narrow_shadow;
}