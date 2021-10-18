//-------------include section----------------
#include "Rectangle.h"
#include "Board.h"

#include <iostream>
#include <algorithm>
#include <cmath>

#include "macros.h"
#include "Utilities.h"

//-------------using section-------------------
using std::cout;
using std::cin;

//-------------------------------------------------------------
// Time constructor initializes each data members.
// Ensures all Rectangles objects start in a consistent state.
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (!CheckValid(bottomLeft, topRight))
		setDefault();
	else
	{
		m_bottomLeftRect = bottomLeft;
		m_topRightRect = topRight;
	}
} // end Rectangle constructor 1

//-------------------------------------------------------------
Rectangle::Rectangle(const Vertex* verticles)
{
	if (!CheckValid(verticles[0], verticles[1]))
		setDefault();
	else
	{
		m_bottomLeftRect = verticles[0];
		m_topRightRect = verticles[1];
	}
}

//-------------------------------------------------------------
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	Vertex vertex0(x0,y0), vertex1(x1,y1);

	if (!CheckValid(vertex0, vertex1))
		setDefault();
	else
	{
		m_bottomLeftRect = vertex0;
		m_topRightRect = vertex1;
	}
}

//-------------------------------------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height)
{
	if (!start.isValid() || width < 0 || height < 0)
		setDefault();
	else
	{
		m_bottomLeftRect = start;
		m_topRightRect.m_col = start.m_col + width;
		m_topRightRect.m_row = start.m_row + height;
	}
}
//-------------------------------------------------------------
bool Rectangle::CheckValid(const Vertex bl,const Vertex tr)
{
	if (!bl.isValid() || !tr.isValid() ||
		!tr.isToTheRightOf(bl) || !tr.isHigherThan(bl))
		return false;
	return true;
}
//-------------------------------------------------------------
void Rectangle::setDefault()
{
	m_bottomLeftRect.m_col = 20;
	m_bottomLeftRect.m_row = 10;
	m_topRightRect.m_col = 30;
	m_topRightRect.m_row = 20;
}

//-------------------------------------------------------------
Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeftRect;
}

//-------------------------------------------------------------
Vertex Rectangle::getTopRight() const
{
	return m_topRightRect;
}

//-------------------------------------------------------------
double Rectangle::getWidth() const 
{
	return m_topRightRect.m_col - m_bottomLeftRect.m_col;
}

//-------------------------------------------------------------
double Rectangle::getheight() const
{
	return m_topRightRect.m_row - m_bottomLeftRect.m_row;
}