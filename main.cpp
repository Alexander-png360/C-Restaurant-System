#include <iostream>
#include "Restaurant.hpp"
#include "Customer.hpp"

int main() {
	
	Restaurant restaurant(2);

	std::vector<std::string> customerNames = { "Alice", "Bob", "Charlie", "Diana" };

	for (const auto& name : customerNames) {
		auto customer = std::make_shared<Customer>(name);

		if (restaurant.reserveTable(customer)){
			std::cout << "Reserving table for " << name << '\n';
		} else {
			std::cout << "Reserving table for " << name << ": Added to waitlist" << '\n';
		}
	}

	restaurant.releaseTable(0);
	restaurant.releaseTable(1);
}