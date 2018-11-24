#pragma once
#include "vector_2d.h"
#include "matrix.h"

class utilities
{
	utilities() = default;
public:
	static vector_2d get_center_2d_vector_matrix(matrix<float>& matrix);
};

