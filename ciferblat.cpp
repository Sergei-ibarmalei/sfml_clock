#include "ciferblat.hpp"

using namespace clock_;
using namespace cifer;

static const Color red_color(0xFF, 0x00, 0x00, 0xFF);
static const Color black_color(0x00, 0x00, 0x00, 0xFF);
void make_one(RectangleShape* b, float x, float y, block_kind kind, bool isShadow);

Ciferblat::Ciferblat(const Table* table_)
{
    table = table_;
    ciferblat = make_ciferblat(false);
    ciferblat_shadow = make_ciferblat(true);
}



Ciferblat::~Ciferblat()
{
    delete [] ciferblat;
    ciferblat = 0;
    delete [] ciferblat_shadow;
    ciferblat_shadow = 0;
    table = 0;
}

Block* Ciferblat::make_ciferblat(bool isShasow)
{
    Block* ciferblat_ = new Block[CIFERBLAT_COUNTS];
    int count {0};
    auto ptr_table = &table->table_m()[0];
    auto ptr_block = &ciferblat_[0];
    for(;;ptr_table++, ptr_block++, count ++)
    {
        if(ptr_block == &ciferblat_[CIFERBLAT_COUNTS]) break;
        float x = CENTERX + RADIUS * ptr_table -> x;
        float y = CENTERY + RADIUS * ptr_table -> y;
        if(count % 5 == 0)
        {
            ptr_block->get_block()->setSize(Vector2f(HOUR_SIDE, HOUR_SIDE));
            make_one(ptr_block->get_block(), x, y, block_kind::hour, isShasow);
        } 
        else
        {
            ptr_block->get_block()->setSize(Vector2f(MIN_SIDE, MIN_SIDE));
            make_one(ptr_block->get_block(), x, y, block_kind::minute, isShasow);
        }

    }
    return ciferblat_;
}



const Block* Ciferblat::get_cif() const
{
    return ciferblat;
}

const Block* Ciferblat::get_cif_shadow() const 
{
    return ciferblat_shadow;
}



void make_one(RectangleShape* b, float x,  float y, block_kind kind, bool isShasow)
{
    if(isShasow)
    {
        if(kind == block_kind::hour || kind == block_kind::minute)
        {
            x += SHADOW_SHIFT; 
            y += SHADOW_SHIFT; 
        }
        b->setFillColor(black_color);
    }
    else
    {
        b->setFillColor(red_color);
    }
    if(kind == block_kind::hour)
    {
        b->setPosition(Vector2f(x-HOUR_SIDE_HALF, y-HOUR_SIDE_HALF));
    }
    else if(kind == block_kind::minute)
    {
        b->setPosition(Vector2f(x-MIN_SIDE_HALF, y-MIN_SIDE_HALF));
    }
}

