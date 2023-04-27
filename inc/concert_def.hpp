/**
 * @file  concert_def.hpp
 * @brief Defines the Concert class.
 */

#ifndef CONCERT_DEF_HPP
#define CONCERT_DEF_HPP

#include <string>

/**
 * @brief The Concert class 
 */
 
class Concert {
    public:
		/**
		* @brief Constructor for Concert class.
		* @param name Name of the concert.
		* @param artist Name of the artist performing in the concert.
		* @param date Date of the concert.
		*/
		Concert(std::string name, std::string artist, std::string date);
		
		 /**
		  * @brief Get the name of the concert.
		  * @return Name of the concert.
		  */
		 std::string getName() const;

		 /**
		  * @brief Get the name of the artist performing in the concert.
		  * @return Name of the artist.
		  */
		 std::string getArtist() const;

		 /**
		  * @brief Get the date of the concert.
		  * @return Date of the concert.
		  */
		 std::string getDate() const;
	 
	 private:
		std::string name_; 		///< Name of the concert.
		std::string artist_; 	///< Name of the artist performing in the concert.
		std::string date_; 		///< Date of the concert.
};

#endif // CONCERT_DEF_HPP
 

