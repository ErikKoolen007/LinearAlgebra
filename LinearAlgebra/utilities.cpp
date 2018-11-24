#include "utilities.h"
#include <tuple>
#include <algorithm>

vector_2d utilities::get_center_2d_vector_matrix(matrix<float>& matrix)
{
	//https://stackoverflow.com/questions/2792443/finding-the-centroid-of-a-polygon

	vector_2d centroid = { 0, 0 };
	int vertexCount = matrix.get_cols();
	double signedArea = 0.0;
	double x0 = 0.0; // Current vertex X
	double y0 = 0.0; // Current vertex Y
	double x1 = 0.0; // Next vertex X
	double y1 = 0.0; // Next vertex Y
	double a = 0.0;  // Partial signed area

	// For all vertices except last
	int i = 0;
	for (i = 0; i < vertexCount - 1; ++i)
	{
		x0 = matrix(0, i);
		y0 = matrix(1, i);
		x1 = matrix(0, i + 1);
		y1 = matrix(1, i + 1);
		a = x0 * y1 - x1 * y0;
		signedArea += a;
		centroid.set_x(centroid.get_x() + (x0 + x1)*a);
		centroid.set_y(centroid.get_y() + (y0 + y1)*a);
	}

	// Do last vertex separately to avoid performing an expensive
	// modulus operation in each iteration.
	x0 = matrix(0, i);
	y0 = matrix(1, i);
	x1 = matrix(0, 0);
	y1 = matrix(1, 0);
	a = x0 * y1 - x1 * y0;
	signedArea += a;
	centroid.set_x(centroid.get_x() + (x0 + x1)*a);
	centroid.set_y(centroid.get_y() + (y0 + y1)*a);

	signedArea *= 0.5;
	centroid.set_x(centroid.get_x() / (6.0*signedArea));
	centroid.set_y(centroid.get_y() / (6.0*signedArea));

	return centroid;
}
