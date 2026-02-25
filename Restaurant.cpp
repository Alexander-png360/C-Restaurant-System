#include <iostream>
#include <string>
#include "Restaurant.hpp"
#include "Table.hpp"

Restaurant::Restaurant(int initialTableCount){
	for (int i = 0; i < initialTableCount; ++i) {
		tables.push_back(std::make_unique<Table>(4));
	}
}

void Restaurant::addCustomer(const std::string& name) {

	auto customer = std::make_shared<Customer>(name);
	
	if (reserveTable(customer)){
		std::cout << "Reserving table for " << name << " Success! " << '\n';
	} else{

		std::cout << "Reserving Table for " << name << " Added To Waitlist " << '\n';
	}

}

void Restaurant::removeCustomer(std::shared_ptr<Customer> customer) {

	activeCustomers.erase(
		std::remove(activeCustomers.begin(), activeCustomers.end(), customer),
		activeCustomers.end()
	);
	std::cout << "Customer removed " << customer->getName() << '\n';
}

bool Restaurant::reserveTable(std::shared_ptr<Customer>& customer) {

	for (std::unique_ptr<Table>& table : tables){
		if (!(*table).isOccupied()){
			table->seatCustomer(customer);
			activeCustomers.push_back(customer);
			return true;
		}
	}

	waitList.push_back(customer);
	return false;
}

void Restaurant::printWaitList() {
	
	std::cout << "The following people are waiting for a table: " << '\n';
	for (const auto& customer : waitList) {
	std::cout << customer->getName() << '\n';
	
	}
}

void Restaurant::releaseTable(int tableNumber) {
	
	if (tableNumber < 0 || tableNumber >= tables.size()){
		std::cout << "Invalid table number: " << tableNumber << '\n';
		return;
	}
	
	if (tables[tableNumber]->isOccupied()){
		auto customerOnTable = tables[tableNumber]->getCustomer();
		
		std::cout << "Releasing table " << tableNumber << " Occupied by "
			<< customerOnTable->getName() << '\n';

		tables[tableNumber]->removeCustomer();
		removeCustomer(customerOnTable);

	} else {
		std::cout << "Table " << tableNumber << " is already empty" << '\n';
	}

	notifyWaitList();
}

void Restaurant::notifyWaitList() {

	if (waitList.empty()){
		return;
	}

	auto nextCustomer = waitList.front();
	
	waitList.erase(waitList.begin());
	
	if (reserveTable(nextCustomer)){
		std::cout << "Reserving Table for " << nextCustomer->getName() << "Success! " << '\n';
	}
}
