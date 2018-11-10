#include "vector_2d.h"

float vector_2d::get_x() const
{
	return x_;
}

float vector_2d::get_y() const
{
	return y_;
}

void vector_2d::set_x(float x)
{
	x_ = x;
}

void vector_2d::set_y(float y)
{
	y_ = y;
}

void vector_2d::scale(float factor)
{
	x_ *= factor;
	y_ *= factor;
}

void vector_2d::add(const vector_2d& other)
{
	x_ += other.x_;
	y_ += other.y_;
}

void vector_2d::subtract(const vector_2d& other)
{
	x_ -= other.x_;
	y_ -= other.y_;
}
