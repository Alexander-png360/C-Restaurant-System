#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Table.hpp"
#include "Customer.hpp"
class Restaurant{

private:

	std::vector<std::unique_ptr<Table>> tables;
	std::vector<std::shared_ptr<Customer>> activeCustomers;
	std::vector<std::shared_ptr<Customer>> waitList;
	void notifyWaitList();

public:
	Restaurant();
	Restaurant(int initialTableCount);

	bool reserveTable(std::shared_ptr<Customer>& customer);
	
	void releaseTable(int tableNumber);
	void printWaitList();
	void addCustomer(const std::string& name);
	void removeCustomer(std::shared_ptr<Customer> customer);
};

