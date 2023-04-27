/**
 * @file seat_def.cpp
 * Implementation of the Seat class.
 */

#include "seat_def.hpp"

/**
 * @brief Constructor for the Seat class.
 * @param name The name of the seat.
 * @param isAvailable A flag indicating whether the seat is available.
 */
Seat::Seat(std::string name, bool isAvailable)
: name_(name), isAvailable_(isAvailable) {

}

/**
 * @brief Returns the name of the seat.
 * @return The name of the seat.
 */
std::string Seat::getName() const {
	
	return name_;
}

/**
 * @brief Returns a flag indicating whether the seat is available.
 * @return True if the seat is available, false otherwise.
 */
bool Seat::isAvailable() const {
    
	return isAvailable_;
}

/**
 * @brief Reserves the seat.
 * This method updates the availability flag for the seat to false, indicating
 * that the seat is no longer available for booking.
 */
void Seat::reserve() {
    
	isAvailable_ = false;
}
    
    
