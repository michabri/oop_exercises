#pragma once
#include "macros.h"
#include "Vertex.h"
#include "Board.h"
#include "Triangle.h"

class Hourglass {

public:
	Hourglass() = default;
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);
	bool checkValid(const Triangle& upper, const Triangle& lower) const;
	void setDefault();
	~Hourglass() = default;
private:
	Triangle m_top;
	Triangle m_bottom;
};