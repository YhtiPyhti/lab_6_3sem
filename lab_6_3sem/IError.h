#pragma once
#include <iostream>
/*создать абстрактный класс IError – класс, определяющий интерфейс для хранения, описания и вывода ошибок.Поле – текст ошибки / код ошибки.
Виртуальная функция print, которая по умолчанию печатает единственное поле.
2. Отнаследовать от IError как минимум два класса ошибок(не абстрактных).В обработках исключений вместо завершения программы возвращаться в 
START(для этого нужен event loop и(ли) state machine), если необходимо, и заносить информацию об ошибке в соответствующий типу ошибки класс.
3. Реализовать функцию print_error_list(std::vector err), которая будет выводить список всех ошибок, произошедших за время работы программы.
Использовать повышение приведения типа.*/

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

