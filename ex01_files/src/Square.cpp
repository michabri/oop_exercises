#include "Square.h"
#include "Board.h"

#include <iostream>
#include <algorithm>
#include <cmath>

#include "macros.h"
#include "Utilities.h"

//-------------using section-------------------
using std::cout;
using std::cin;

//-------------const section-------------------
const double Epsilon = 0.5;

//-------------------------------------------------------------
// Time constructor initializes each data members.
// Ensures all Rectangles objects start in a consistent state.
Square::Square(const Vertex& v0, const Vertex& v1)
{
	if (checkValid(v0, v1))
	{
		m_bottomLeft = v0;
		m_topRight = v1;
	}
	else
		setDefault();
}
//-------------------------------------------------------------
Square::Square(const Vertex& start, double length)
{
	Vertex v1;
	v1.m_col = start.m_col + length;
	v1.m_row = start.m_row + length;
	if (checkValid(start, v1))
	{
		m_bottomLeft = start;
		m_topRight = v1;
	}
	else
		setDefault();
}
//-------------------------------------------------------------
Vertex Square::getBottomLeft() const
{
	return m_bottomLeft;
}

//-------------------------------------------------------------
Vertex Square::getTopRight() const
{
	return m_topRight;
}

//-------------------------------------------------------------
double Square::getLength() const
{
	return m_topRight.m_col - m_bottomLeft.m_col;
}

//-------------------------------------------------------------
bool Square::checkValid(const Vertex& v0, const Vertex& v1)
{
	if (v0.isValid() && v1.isValid() && v1.isHigherThan(v0) && v1.isToTheRightOf(v0) &&
		((v1.m_col - v0.m_col) - (v1.m_row - v0.m_row) < Epsilon))
		return true;
	return false;
}
void Square::setDefault()
{
	m_bottomLeft.m_col = 20;
	m_bottomLeft.m_row = 10;
	m_topRight.m_col = 30;
	m_topRight.m_row = 20;
}