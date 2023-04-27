/**
 * @file  theatre_def.hpp
 * @brief Defines the Theatre class.
 */

#ifndef THEATRE_DEF_HPP
#define THEATRE_DEF_HPP

#include <string>

/**
 * @brief The Theatre class represents a theater with a name and a capacity.
 */
class Theater {
	public:
		/**
		 * @brief Constructs a new Theater object with the given name and capacity.
		 * @param name The name of the theater.
		 * @param capacity The capacity of the theater.
		 */
		Theater(std::string name, int capacity);

		/**
		 * @brief Gets the name of the theater.
		 * @return The name of the theater.
		 */
		std::string getName() const;

		/**
		 * @brief Gets the capacity of the theater.
		 * @return The capacity of the theater.
		 */
		int getCapacity() const;

		/**
		 * @brief Sets the capacity of the theater to the given value.
		 * @param capacity The new capacity of the theater.
		 */
		void setCapacity(int capacity);

	private:
		std::string name_;	///< The name of the theater. 
		int capacity_; 		///< The capacity of the theater. 
};

#endif // THEATRE_DEF_HPP

