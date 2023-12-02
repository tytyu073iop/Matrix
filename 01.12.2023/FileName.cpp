#include <iostream>
#include "Matrix.h"

int main() {
	int m, n;
	std::cout << "Введите размер 1 матрицы\n";
	std::cin >> m >> n;
	std::cout << "Введите 1 матрицу\n";
	matrix a(m, n);
	std::cin >> a;
	std::cout << "Введите размер 2 матрицы\n";
	std::cin >> m >> n;
	std::cout << "Введите 2 матрицу\n";
	matrix b(m, n);
	std::cin >> b;
	//
	std::cout << "Вывод 1 матрицы\n" << a;
	std::cout << "Вывод 2 матрицы\n" << b;
	//
	std::cout << "Операции с матрицами\n";
	std::cout << '\t' << "a + b\n";
        try {
		std::cout << (a + b);
	}
	catch (matrix::Errors) {
		std::cout << "Ошибка!";
	} 
        std::cout << '\n';
	std::cout << '\t' << "a - b\n";
        try {
		std::cout << (a - b);
	}
	catch (matrix::Errors) {
		std::cout << "Ошибка!";
	}
        std::cout << '\n';
        std::cout << '\t' << "a * b\n";
	try {
		std::cout << (a * b);
	}
	catch (matrix::Errors) {
		std::cout << "Ошибка!";
	}
	std::cout << '\n';
	std::cout << "Введите число c:";
	double c;
	std::cin >> c;
	std::cout << '\t' << "c * b\n" << (c * b) << '\n';
	std::cout << '\t' << "b * c\n" << (b * c) << '\n';
	std::cout << '\t' << "a / c\n" << (a / c) << '\n';
	//
	std::cout << "Сравнение\n";
	std::cout << '\t' << "a == b: " << (a == b) << '\n';
	std::cout << '\t' << "a != b: " << (a != b) << '\n';
	//
	std::cout << "Операции присваивания\n";
	std::cout << '\t' << "a += b\n";
        try {
		std::cout << (a += b);
	}
	catch (matrix::Errors) {
		std::cout << "Ошибка!";
	}
        std::cout << '\n';
	std::cout << '\t' << "a -= b\n";
        try {
		std::cout << (a -= b);
	}
	catch (matrix::Errors) {
		std::cout << "Ошибка!";
	}
        std::cout << '\n';
	std::cout << '\t' << "a *= c\n" << (a *= c) << '\n';
	std::cout << '\t' << "a /= c\n" << (a /= c) << '\n';
}
