#pragma once
#include <memory>
#include "Customer.hpp"

class Table{

private:

	int capacity;
	std::shared_ptr<Customer> seatedCustomer;

public:

	Table(int cap);

	std::shared_ptr<Customer> getCustomer() const;
	void seatCustomer(std::shared_ptr<Customer> customer);

	bool isOccupied() const;
	void removeCustomer();
	void clearTable();

};

