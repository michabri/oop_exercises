// Declaration of class Time.
// Member functions are defined in time1.cpp

// prevent multiple inclusions of header file
#pragma once
#include "macros.h"
#include "Vertex.h"
#include "Board.h"

// Time definition
class Triangle {

public:
	Triangle() = default;
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);
	bool checkValid(Vertex v1, Vertex v2, Vertex v3) const;
	void setDefault();
	void setDefaultUpper();
	Vertex getVertex(int index) const;
	double getLength() const;
	double getheight() const;
	~Triangle() = default;

private:
	Vertex m_left;
	Vertex m_right;
	Vertex m_top;
};