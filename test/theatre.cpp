/**
 * @file theatre_def.cpp
 * Implementation of the Theater class methods.
 */

#include "theatre_def.hpp"

/**
 * @brief Constructor for Theater class.
 * @param name The name of the theater.
 * @param capacity The seating capacity of the theater.
 */
Theater::Theater(std::string name, int capacity) : name_(name), capacity_(capacity) {

}

/**
 * @brief Getter method for theater name.
 * @return The name of the theater.
 */
std::string Theater::getName() const {
    
    return name_;
}

/**
 * @brief Getter method for theater seating capacity.
 * @return The seating capacity of the theater.
 */
    
int Theater::getCapacity() const {
    
    return capacity_;
}

/**
 * @brief Setter method for theater seating capacity.
 * @param capacity The new seating capacity of the theater. 
 */
void Theater::setCapacity(int capacity) {
    
    capacity_ = capacity;
}
