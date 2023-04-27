/**
 * @file  seat_def.hpp
 * @brief This file contains the definition of the Seat class.
 */    

#ifndef SEAT_DEF_HPP
#define SEAT_DEF_HPP

#include <iostream>

/**
*@brief This class represents a seat in a theater.
*/

class Seat {
    public:
		/**
		* @brief Constructor for the Seat class.
		* @param name A string representing the name of the seat.
		* @param isAvailable A boolean value indicating whether the seat is available or not.
		*/
		Seat(std::string name, bool isAvailable);
		
		 /**
	  	* @brief Getter function to get the name of the seat.
	  	* @return A string representing the name of the seat.
	  	*/
	 	std::string getName() const;
	 
		/**
		* @brief Getter function to check if the seat is available.
		* @return A boolean value indicating whether the seat is available or not.
		*/
		bool isAvailable() const;
		 
		/**
		* @brief Function to reserve the seat.
		*/
		void reserve();
	
  	private:
    	std::string name_; 		   ///< A string representing the name of the seat.
    	bool isAvailable_ = true; ///< A boolean value indicating whether the seat is available or not.
};

#endif // SEAT_DEF_HPP

