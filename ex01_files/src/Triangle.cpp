//-------------include section----------------
#include "Triangle.h"
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
Triangle::Triangle(const Vertex vertices[3])
{
	if (!(checkValid(vertices[0], vertices[1], vertices[2])))
	{
		setDefault();
	}
	else
	{
		m_left = vertices[0];
		m_right = vertices[1];
		m_top = vertices[2];
	}
}


Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
{
	Vertex v2;
	v2.m_col = v0.m_col + ((v1.m_col - v0.m_col) / 2);
	v2.m_row = v0.m_row + height;
	if (!(checkValid(v0, v1, v2)))
	{
		setDefault();
	}
	else
	{
		m_left = v0;
		m_right = v1;
		m_top = v2;
	}
}

Vertex Triangle::getVertex(int index) const
{
	switch (index)
	{
	case 0:
		return m_left;
	case 1:
		return m_right;
	case 2:
		return m_top;
	}
}

double Triangle::getLength() const
{
	return m_right.m_col - m_left.m_col;
}

double Triangle::getheight() const
{
	return abs(m_top.m_row - m_left.m_row);
}

bool Triangle::checkValid(Vertex v1, Vertex v2, Vertex v3) const
{
	if (!(v1.isValid()) || !(v2.isValid()) || !(v3.isValid()) 
		|| !(abs(v2.m_row - v1.m_row) < Epsilon) || !(v2.isToTheRightOf(v1)))
	{
		return false;
	}
	return true;
}

void Triangle::setDefault()
{
	m_left.m_col = 20;
	m_left.m_row = 20;
	m_right.m_col = 30;
	m_right.m_row = 20;
	m_right.m_col = 25;
	m_right.m_col = 20 + sqrt(75);
}

void Triangle::setDefaultUpper()
{
	m_left.m_col = 25;
	m_left.m_row = 20 + sqrt(75);
	m_right.m_col = 20;
	m_right.m_row = 20+2*sqrt(75);
	m_right.m_col = 30;
	m_right.m_col = 20 + 2*sqrt(75);
}