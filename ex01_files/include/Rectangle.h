// Declaration of class Time.
// Member functions are defined in time1.cpp

// prevent multiple inclusions of header file
#pragma once
#include "macros.h"
#include "Vertex.h"
#include "Board.h"

// Time definition
class Rectangle {

public:
	Rectangle() = default;
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);   // constructor 1
	Rectangle(const Vertex* verticles); //constructor 2
	Rectangle(double x0, double y0, double x1, double y1); // contructor 3
	Rectangle(const Vertex& start, double width, double height);
	void setDefault();
	bool CheckValid(const Vertex BL, const Vertex TR);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getheight() const;
	~Rectangle() = default;
private:
	Vertex m_bottomLeftRect;
	Vertex m_topRightRect;
}; // end class Rectangle