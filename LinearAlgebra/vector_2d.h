#pragma once
class vector_2d
{
	float x_;
	float y_;
public:
	vector_2d(float x, float y): x_(x), y_(y)
	{
	}

	float get_x() const;
	float get_y() const;
	void set_x(float x);
	void set_y(float y);
	void scale(float factor);
	void add(const vector_2d& other);
	void subtract(const vector_2d& other);
};

