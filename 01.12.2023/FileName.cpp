#include <iostream>
#include "Matrix.h"

int main() {
	int m, n;
	std::cout << "Введите размер 1 матрицы\n";
	std::cin >> m >> n;
	std::cout << "Введите матрицу 1\n";
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
	std::cout << "Неизменяющее операции\n";
	std::cout << '\t' << "a + b" << (a + b) << '\n';
	std::cout << '\t' << "a - b" << (a - b) << '\n';
	std::cout << '\t' << "a * b";
	try {
		std::cout << (a * b);
	}
	catch (matrix::Errors::Matrixs_unmultiple) {
		std::cout << "АШИПКА!";
	}
	
	std::cout << '\n';
	std::cout << "Введите число с:";
	double c;
	std::cin >> c;
	std::cout << '\t' << "c * b" << (c * b) << '\n';
	std::cout << '\t' << "b * c" << (b * c) << '\n';
	std::cout << '\t' << "a / c" << (a / c) << '\n';
	//
	std::cout << "Сравнение\n";
	std::cout << '\t' << "a == b" << (a == b) << '\n';
	std::cout << '\t' << "a != b" << (a != b) << '\n';
	//
	std::cout << "Изменяющие операции\n";
	std::cout << '\t' << "a += b" << (a += b) << '\n';
	std::cout << '\t' << "a -= b" << (a -= b) << '\n';
	std::cout << '\t' << "a *= c" << (a *= c) << '\n';
	std::cout << '\t' << "a /= c" << (a /= c) << '\n';
}