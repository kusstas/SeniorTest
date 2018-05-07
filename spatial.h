#ifndef SPATIAL_H
#define SPATIAL_H

namespace AyxCppTest
{
	struct Point
	{
		double m_x;
		double m_y;
		Point(double x, double y);
		Point(const Point &pt);
		~Point();

		static bool DbgHasLeaks();
	};

	bool operator == (Point const& p1, Point const& p2);
	bool operator != (Point const& p1, Point const& p2);

	class Area
	{
	public:
	virtual ~Area() { }
		// returns true if point is inside
		// false if outside or on the line
		virtual bool Contains(const Point &pt) = 0;
	};

	class Circle : public Area
	{
		Point m_pt;
		double m_radius;
	public:
		Circle(Point const& pt, double radius);
		bool Contains(const Point &pt) override;
	};

	class Rectangle : public Area
	{
		Point m_TopLeft;
		Point m_BottomRight;
	public:
		Rectangle(Point const& topLeft, Point const& bottomRight);
		bool Contains(const Point &pt) override;
		double Size();
	};
}

#endif