#include "polygon.h"

namespace AyxCppTest
{

    bool lineIntersection(Point line1Pt1, Point line1Pt2, Point line2Pt1, Point line2Pt2, Point &r_Out)
	{
		double s1_x = line1Pt2.m_x - line1Pt1.m_x;
		double s1_y = line1Pt2.m_y - line1Pt1.m_y;
		double s2_x = line2Pt2.m_x - line2Pt1.m_x;
		double s2_y = line2Pt2.m_y - line2Pt1.m_y;
		double s, t;
		s = (-s1_y * (line1Pt1.m_x - line2Pt1.m_x) + s1_x * (line1Pt1.m_y - line2Pt1.m_y)) / (-s2_x * s1_y + s1_x * s2_y);
		t = (s2_x * (line1Pt1.m_y - line2Pt1.m_y) - s2_y * (line1Pt1.m_x - line2Pt1.m_x)) / (-s2_x * s1_y + s1_x * s2_y);
		
        if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
		{
			// Collision detected
			r_Out.m_x = line1Pt1.m_x + (t * s1_x);
			r_Out.m_y = line1Pt1.m_y + (t * s1_y);
			return true;
		}

		return false; // No collision
	}

    Polygon::Polygon(std::initializer_list<Point> list) : points(list)
    {
    }

    bool Polygon::Contains(Point const& pt) 
    {
        bool intersect = true;

        std::vector<std::pair<Point, Point>> lines;
        for (auto it = points.begin(); it != points.end() - 1; ++it) {
            lines.emplace_back(*it, *(it + 1));
        }
        lines.emplace_back(lines.back(), lines.front());


        for (auto const& p : points) {
            for (auto const& l : lines)
        }

        return intersect;
    }

}