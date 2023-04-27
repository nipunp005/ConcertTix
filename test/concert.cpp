/**
 * @file concert.cpp
 * @brief Implementation of the Concert class
 */

#include "concert_def.hpp"

/**
 * @brief Constructor for Concert class
 * @param name Name of the concert
 * @param artist Artist of the concert
 * @param date Date of the concert
 */
Concert::Concert(std::string name, std::string artist, std::string date)
    : name_(name), artist_(artist), date_(date) {

}

/**
 * @brief Getter method for concert name
 * @return Concert name as a string
 */
std::string Concert::getName() const {
    return name_;
}

/**
 * @brief Getter method for concert artist
 * @return Concert artist as a string
 */
std::string Concert::getArtist() const {
    return artist_;
}

/**
 * @brief Getter method for concert date
 * @return Concert date as a string
 */
std::string Concert::getDate() const {
    return date_;
}

