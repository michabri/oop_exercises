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
	:m_bottomLeftRect(bottomLeft.m_col, bottomLeft.m_row), 
	m_topRightRect(topRight.m_col, topRight.m_row)
{
	if (!CheckValid(bottomLeft, topRight))
		setDefault();
} 

//-------------------------------------------------------------
Rectangle::Rectangle(const Vertex vertices[2])
	:Rectangle(vertices[0], vertices[1])
{}

//-------------------------------------------------------------
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
	:Rectangle(Vertex(x0, y0),Vertex(x1, y1))
{}

//-------------------------------------------------------------
Rectangle::Rectangle(const Vertex& start, double width, double height)
	:Rectangle(start, Vertex(start.m_col+width, start.m_row+height))
{}
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