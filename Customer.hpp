#pragma once
#include <string>
#include <iostream>

class Customer{

private:
	std::string name;
public:
	Customer(const std::string& n) : name(n) {}

	std::string getName() const { return name;  }

	void ordermeal() {
		std::cout << name << "is Ordering a meal. " << '\n';
	}
};

