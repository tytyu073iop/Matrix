#include "Matrix.h"

matrix::matrix() : matrix(0, 0) {};

matrix::matrix(int m, int n) : m(m), n(n) {
	init_empty();
}

void matrix::init_empty() {
	p = new double* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new double[m];
	}
}

void matrix::add_elements(const matrix& m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = m.p[i][j];
		}
	}
}

matrix::matrix(const matrix& m) : matrix(m.m, m.n) {
	add_elements(m);
}

void matrix::erase() {
	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
}

matrix::~matrix() {
	erase();
}

matrix& matrix::operator=(const matrix& right) {
	if (this != &right) {
		erase();
		m = right.m;
		n = right.n;
		init_empty();
		add_elements(right);
	}
}

matrix& matrix::operator+=(const matrix& right) {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] = right.p[i][j];
		}
	}
}

matrix matrix::operator+(const matrix& right) {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	matrix result(*this);
	result += right;
	return result;
}