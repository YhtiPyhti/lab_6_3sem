#pragma once
#include <iostream>
/*������� ����������� ����� IError � �����, ������������ ��������� ��� ��������, �������� � ������ ������.���� � ����� ������ / ��� ������.
����������� ������� print, ������� �� ��������� �������� ������������ ����.
2. ������������� �� IError ��� ������� ��� ������ ������(�� �����������).� ���������� ���������� ������ ���������� ��������� ������������ � 
START(��� ����� ����� event loop �(��) state machine), ���� ����������, � �������� ���������� �� ������ � ��������������� ���� ������ �����.
3. ����������� ������� print_error_list(std::vector err), ������� ����� �������� ������ ���� ������, ������������ �� ����� ������ ���������.
������������ ��������� ���������� ����.*/

class IError
{
public:
	std::string description = "Error: ";
	virtual void print() {
		std::cout << description << std::endl;
	}
};

class IncorrectInput : IError {
public:
	IncorrectInput() {};
	void print() {
		std::cout << description << " Incorrect input " << std::endl;
	}
};

class IncorrectInputCritical : IError {
public:
	IncorrectInputCritical() {};
	void print() {
		std::cout << description << " You input TEXT!!! " << std::endl;
	}
};

class DivisionByZero : IError {
public:
	DivisionByZero() {};
	void print() {
		std::cout << description << " Integer division by zero " << std::endl;
	}
};

