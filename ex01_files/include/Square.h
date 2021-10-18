#pragma once
#include "macros.h"
#include "Vertex.h"
#include "Board.h"

class Square {

public:
	Square() = default;
	Square(const Vertex& v0, const Vertex& v1);
	Square(const Vertex& start, double length);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getLength() const;
	bool checkValid(const Vertex& v0, const Vertex& v1);
	void setDefault();
	~Square() = default;
private:
	Vertex m_bottomLeft;
	Vertex m_topRight;
};