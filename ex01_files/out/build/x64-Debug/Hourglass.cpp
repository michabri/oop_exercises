//-------------include section----------------
#include "Hourglass.h"
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
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
{
	if (checkValid(upper, lower))
	{
		m_bottom = lower;
		m_top = upper;
	}
	else
		setDefault();
}

//-------------------------------------------------------------
Hourglass::Hourglass(const Triangle& lower)
{
	Vertex v[3];
	v[0] = lower.getVertex(2);
	v[1].m_col = lower.getVertex(0).m_col;
	v[1].m_row = lower.getVertex(0).m_row + sqrt(3)* lower.getLength();
	v[2].m_col = lower.getVertex(1).m_col;
	v[2].m_row = lower.getVertex(0).m_row + sqrt(3) * lower.getLength();
	Triangle upper(v);
	if (upper.checkValid(v[1], v[2], v[0]))
	{
		m_bottom = lower;
		m_top = upper;
	}
	else
		setDefault();

	
}
//---------------------------------------------------------------
bool Hourglass::checkValid(const Triangle& upper, const Triangle& lower) const
{
	if(upper.getLength() == lower.getLength() && 
	   upper.getVertex(0).m_col == lower.getVertex(2).m_col &&
		upper.getVertex(0).m_row == lower.getVertex(2).m_row)
		return true;
	return false;
}

//---------------------------------------------------------------
void Hourglass::setDefault()
{
	m_bottom.setDefault();
	m_top.setDefaultUpper();
}