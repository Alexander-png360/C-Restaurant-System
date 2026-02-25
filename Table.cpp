#include "Table.hpp"


Table::Table(int cap) : capacity(cap), seatedCustomer(nullptr) {
	
}

bool Table::isOccupied() const {
	return seatedCustomer != nullptr;
}

void Table::seatCustomer(std::shared_ptr<Customer> customer) {
	seatedCustomer = customer;
}

std::shared_ptr<Customer> Table::getCustomer() const{
	return seatedCustomer;
}

void Table::removeCustomer() {
	//add stuff here 
}

void Table::clearTable() {
	seatedCustomer = nullptr;
}