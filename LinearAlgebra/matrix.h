#pragma once
#include <vector>
#include <iostream>
#include "vector_2d.h"

template<typename T> class matrix
{
	std::vector<std::vector<T> > mat_;
	unsigned rows_;
	unsigned cols_;

public:
	matrix(unsigned rows, unsigned cols);
	matrix();
	matrix<T> operator+(const matrix<T>& rhs_matrix);
	matrix<T> operator-(const matrix<T>& rhs_matrix);
	matrix<T> operator*(const matrix<T>& rhs_matrix);

	matrix<T> operator+(const T& rhs);
	matrix<T> operator-(const T& rhs);
	matrix<T> operator*(const T& rhs);

	T& operator()(const unsigned& row, const unsigned& col);
	const T& operator()(const unsigned& row, const unsigned& col) const;

	unsigned get_rows() const;
	unsigned get_cols() const;

	void add_vector_list(const std::vector<vector_2d>& position_vectors);
	void debug_draw();
};

template <typename T>
matrix<T>::matrix(unsigned rows, unsigned cols)
{
	mat_.resize(rows);
	for(unsigned i = 0; i < mat_.size(); i++)
	{
		mat_[i].resize(cols);
	}
	rows_ = rows;
	cols_ = cols;
}

template <typename T>
matrix<T>::matrix()
{
	rows_ = 0;
	cols_ = 0;
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& rhs_matrix)
{
	matrix result(rows_, cols_);

	for (unsigned i = 0; i < rows_; i++) {
		for (unsigned j = 0; j < cols_; j++) {
			result(i, j) = this->mat_[i][j] + rhs_matrix(i, j);
		}
	}

	return result;
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T>& rhs_matrix)
{
	unsigned rows = rhs_matrix.get_rows();
	unsigned cols = rhs_matrix.get_cols();
	matrix result(rows, cols);

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			result(i, j) = this->mat_[i][j] - rhs_matrix(i, j);
		}
	}

	return result;
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T>& rhs_matrix)
{
	unsigned int rows = rhs_matrix.get_rows();
	unsigned cols = rhs_matrix.get_cols();
	matrix result(rows, cols);

	for (unsigned i = 0; i < rows; i++) {
		for (unsigned j = 0; j < cols; j++) {
			for (unsigned k = 0; k < rows; k++) {
				result(i, j) += this->mat_[i][k] * rhs_matrix(k, j);
			}
		}
	}

	return result;
}

template <typename T>
matrix<T> matrix<T>::operator+(const T& rhs)
{
	matrix result(rows_, cols_);

	for (unsigned i = 0; i < rows_; i++) {
		for (unsigned j = 0; j < cols_; j++) {
			result(i, j) = this->mat_[i][j] + rhs;
		}
	}

	return result;
}

template <typename T>
matrix<T> matrix<T>::operator-(const T& rhs)
{
	matrix result(rows_, cols_);

	for (unsigned i = 0; i < rows_; i++) {
		for (unsigned j = 0; j < cols_; j++) {
			result(i, j) = this->mat_[i][j] - rhs;
		}
	}

	return result;
}

template <typename T>
matrix<T> matrix<T>::operator*(const T& rhs)
{
	matrix result(rows_, cols_);

	for (unsigned i = 0; i < rows_; i++) {
		for (unsigned j = 0; j < cols_; j++) {
			result(i, j) = this->mat_[i][j] * rhs;
		}
	}

	return result;
}

template <typename T>
T& matrix<T>::operator()(const unsigned& row, const unsigned& col)
{
	return this->mat_[row][col];
}

template <typename T>
const T& matrix<T>::operator()(const unsigned& row, const unsigned& col) const
{
	return this->mat_[row][col];
}

template <typename T>
unsigned matrix<T>::get_rows() const
{
	return this->rows_;
}

template <typename T>
unsigned matrix<T>::get_cols() const
{
	return this->cols_;
}

template <typename T>
void matrix<T>::add_vector_list(const std::vector<vector_2d>& position_vectors)
{
	this->mat_.resize(2);
	this->rows_ = 2;
	this->cols_ = position_vectors.size();

	for (unsigned i = 0; i < 2; i++)
	{
		this->mat_[i].resize(position_vectors.size());
	}

	for(int i = 0; i < position_vectors.size(); i++)
	{
		this->mat_[0][i] = position_vectors[i].get_x();
		this->mat_[1][i] = position_vectors[i].get_y();
	}
}

template <typename T>
void matrix<T>::debug_draw()
{
	for (unsigned i = 0; i < rows_; i++) {
		for (unsigned j = 0; j < cols_; j++) {
			std::cout << this->mat_[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

