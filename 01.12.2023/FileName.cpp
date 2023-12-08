#include <iostream>
#include "Matrix.h"

int main() {
	int m, n;
	std::cout << "Enter first matrix size\n";
	std::cin >> m >> n;
	std::cout << "Enter 1 matrix\n";
	matrix a(m, n);
	std::cin >> a;
	std::cout << "Enter 2 matrix size\n";
	std::cin >> m >> n;
	std::cout << "Enter 2 matrix\n";
	matrix b(m, n);
	std::cin >> b;
	//
	std::cout << "cout 1 matrix\n" << a;
	std::cout << "cout 2 matrix\n" << b;
	//
	std::cout << "Operations\n";
	std::cout << '\t' << "a + b\n";
        try {
		std::cout << (a + b);
	}
	catch (matrix::Errors) {
		std::cout << "Error!";
	} 
        std::cout << '\n';
	std::cout << '\t' << "a - b\n";
        try {
		std::cout << (a - b);
	}
	catch (matrix::Errors) {
		std::cout << "Error!";
	}
        std::cout << '\n';
        std::cout << '\t' << "a * b\n";
	try {
		std::cout << (a * b);
	}
	catch (matrix::Errors) {
		std::cout << "Error!";
	}
	std::cout << '\n';
	std::cout << "Enter number c:";
	double c;
	std::cin >> c;
	std::cout << '\t' << "c * b\n" << (c * b) << '\n';
	std::cout << '\t' << "b * c\n" << (b * c) << '\n';
	std::cout << '\t' << "a / c\n" << (a / c) << '\n';
	//
	std::cout << "Comparing\n";
	std::cout << '\t' << "a == b: " << (a == b) << '\n';
	std::cout << '\t' << "a != b: " << (a != b) << '\n';
	//
	std::cout << "increments\n";
	std::cout << '\t' << "a += b\n";
        try {
		std::cout << (a += b);
	}
	catch (matrix::Errors) {
		std::cout << "Error!";
	}
        std::cout << '\n';
	std::cout << '\t' << "a -= b\n";
        try {
		std::cout << (a -= b);
	}
	catch (matrix::Errors) {
		std::cout << "Error!";
	}
        std::cout << '\n';
	std::cout << '\t' << "a *= c\n" << (a *= c) << '\n';
	std::cout << '\t' << "a /= c\n" << (a /= c) << '\n';
}
