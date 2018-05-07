#ifndef POLYGON_H
#define POLYGON_H

#include <utility>
#include <vector>
#include <initializer_list>
#include "spatial.h"

namespace AyxCppTest
{
    class Polygon : public Area
    {
    public:
        Polygon(std::initializer_list<Point> list);
        bool Contains(Point const& pt) override;
    private:
        std::vector<Point> points;
    };
}

#endif