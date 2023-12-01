#include <iostream>
#include "Matrix.h"

int main() {
	int m, n;
	std::cout << "������� ������ 1 �������\n";
	std::cin >> m >> n;
	std::cout << "������� ������� 1\n";
	matrix a(m, n);
	std::cin >> a;
	std::cout << "������� ������ 2 �������\n";
	std::cin >> m >> n;
	std::cout << "������� 2 �������\n";
	matrix b(m, n);
	std::cin >> b;
	//
	std::cout << "����� 1 �������\n" << a;
	std::cout << "����� 2 �������\n" << b;
	//
	std::cout << "������������ ��������\n";
	std::cout << '\t' << "a + b" << (a + b) << '\n';
	std::cout << '\t' << "a - b" << (a - b) << '\n';
	std::cout << '\t' << "a * b";
	try {
		std::cout << (a * b);
	}
	catch (matrix::Errors::Matrixs_unmultiple) {
		std::cout << "������!";
	}
	
	std::cout << '\n';
	std::cout << "������� ����� �:";
	double c;
	std::cin >> c;
	std::cout << '\t' << "c * b" << (c * b) << '\n';
	std::cout << '\t' << "b * c" << (b * c) << '\n';
	std::cout << '\t' << "a / c" << (a / c) << '\n';
	//
	std::cout << "���������\n";
	std::cout << '\t' << "a == b" << (a == b) << '\n';
	std::cout << '\t' << "a != b" << (a != b) << '\n';
	//
	std::cout << "���������� ��������\n";
	std::cout << '\t' << "a += b" << (a += b) << '\n';
	std::cout << '\t' << "a -= b" << (a -= b) << '\n';
	std::cout << '\t' << "a *= c" << (a *= c) << '\n';
	std::cout << '\t' << "a /= c" << (a /= c) << '\n';
}