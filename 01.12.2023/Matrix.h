#pragma once

#include <iostream>

class matrix {
	int m, n;
	double** p;
	//kolhoz
	void erase();
	void init_empty();
	void add_elements(const matrix& m);
public:
	matrix();
	matrix(int m, int n);
	matrix(const matrix& m);
	~matrix();
	matrix& operator=(const matrix& right);
	matrix& operator+=(const matrix& right);
	matrix& operator-=(const matrix& right);
	matrix& operator*=(const double& right);
	matrix operator+(const matrix& right);
	matrix operator-(const matrix& right);
	matrix operator*(const matrix& right);
	matrix operator*(const double& right);
	friend matrix operator*(const double& left, const matrix& right);
	matrix& operator/=(const double& right);
	matrix operator/(const double& right);
	bool operator==(const matrix& right);
	friend std::istream& operator>>(std::istream& is, const matrix& right);
	friend std::ostream& operator<<(std::ostream& os, const matrix& right);
	//errors
	enum class Errors
	{
		Matrixs_size_unequal,
		Matrixs_unmultiple
	};
};