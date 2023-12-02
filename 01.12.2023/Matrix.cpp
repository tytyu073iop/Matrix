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
		for (int j = 0; j < this->m; j++)
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
        return *this;
}

matrix& matrix::operator+=(const matrix& right) {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] += right.p[i][j];
		}
	}
        return *this;
}

matrix matrix::operator+(const matrix& right) const {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	matrix result(*this);
	result += right;
	return result;
}

matrix& matrix::operator-=(const matrix& right) {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			p[i][j] -= right.p[i][j];
		}
	}
        return *this;
}

matrix matrix::operator-(const matrix& right) const {
	if (m != right.m || n != right.n) {
		throw Errors::Matrixs_size_unequal;
	}
	matrix result(*this);
	result -= right;
	return result;
}

matrix matrix::operator*(const matrix& right) const {
	if (m != right.n) {
		throw Errors::Matrixs_unmultiple;
	}
	matrix result(right.m, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int w = 0; w < m; w++)
			{
				sum += p[i][w] * right.p[w][j];
			}
			result.p[i][j] = sum;
		}
	}
	return result;
}

matrix& matrix::operator*=(const double& right) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			p[i][j] *= right;
		}
	}
        return *this;
}

matrix matrix::operator*(const double& right) const {
	matrix result(*this);
	result *= right;
	return result;
}

matrix operator*(const double& left, const matrix& right) {
	matrix result(right);
	result *= left;
	return result;
}

matrix& matrix::operator/=(const double& right) {
	*this *= (1 / right);
	return *this;
}

matrix matrix::operator/(const double& right) const {
	matrix result(*this);
	result /= right;
	return result;
}

bool matrix::operator==(const matrix& right) const {
	if (m != right.m || n != right.n) {
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (p[i][j] != right.p[i][j]) {
				return false;
			}
		}
	}
	return true;
}

std::istream& operator>>(std::istream& is, matrix& right) {
	for (int i = 0; i < right.n; i++)
	{
		for (int j = 0; j < right.m; j++)
		{
			is >> right.p[i][j];
		}
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const matrix& right) {
	for (int i = 0; i < right.n; i++)
	{
		for (int j = 0; j < right.m; j++)
		{
			os << right.p[i][j] << ' ';
		}
		os << '\n';
	}
	return os;
}
