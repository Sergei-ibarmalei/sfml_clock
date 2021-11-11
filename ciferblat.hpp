#ifndef CIFERBLAT_HPP
#define CIFERBLAT_HPP

#include "rectangle.hpp"
#include "table.hpp"
#include "consts.hpp"

using namespace clock_;
using namespace table;


namespace cifer
{
    class Ciferblat
    {
        Block* ciferblat;
        Block* ciferblat_shadow;
        const Table* table;

        Block* make_ciferblat(bool isShadow);

        public:

        Ciferblat(const Table* table);
        ~Ciferblat();

        const Block* get_cif() const;
        const Block* get_cif_shadow() const;

    };


}

#endif