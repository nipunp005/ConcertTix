/**
 * @file  booking.hpp
 * @brief Defines the Booking and OnlineBookingSystem class.
 */

#ifndef BOOKING_HPP
#define BOOKING_HPP


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

#include "theatre_def.hpp"
#include "seat_def.hpp"
#include "concert_def.hpp"

/**
 * @brief The Booking class represents a booking for a concert at a theater, with specific seats reserved.
 */
class Booking {

	public:
		
		/**
		 * @brief Construct a new Booking object.
		 * 
		 * @param concertName The name of the concert.
		 * @param theaterName The name of the theater.
		 * @param seatNames The names of the seats reserved for the booking.
		 */
		Booking(std::string concertName, std::string theaterName, std::vector<std::string> seatNames);
		
		/**
		 * @brief Get the name of the concert for the booking.
		 * 
		 * @return The name of the concert.
		 */
		std::string getConcertName() const;
		
		/**
		 * @brief Get the name of the theater for the booking.
		 * 
		 * @return The name of the theater.
		 */
		std::string getTheaterName() const;
		
		/**
		 * @brief Get the names of the seats reserved for the booking.
		 * 
		 * @return The names of the seats.
		 */
		std::vector<std::string> getSeatNames() const;
		
	private:
		
		///< Name of the concert.
		std::string concertName_;
		
		///< The name of the theater.
		std::string theaterName_;

		///< The names of the seats reserved for the booking.
		std::vector<std::string> seatNames_;
};

/**
 * @brief The OnlineBookingSystem class provides functionality to manage and book seats for concerts at different theaters.
*/
class OnlineBookingSystem {

    public:
    
	 /**
	  * @brief Default constructor.
	  */
	 OnlineBookingSystem();
	 
	 /**
	  * @brief Get all the concerts that have been added to the booking system.
	  * @return A vector of Concert objects.
	  */
	 std::vector<Concert> getAllConcerts() const;
	 
	 /**
	  * @brief Get all the theaters for a given concert.
	  * @param concertName The name of the concert for which to get the theaters.
	  * @return A vector of Theater objects.
	  */
	 std::vector<Theater> getTheatersForConcert(std::string concertName) const;
	 
	 /**
	  * @brief Get all the available seats for a given theater and concert.
	  * @param concertName The name of the concert for which to get the seats.
	  * @param theaterName The name of the theater for which to get the seats.
	  * @return A vector of Seat objects.
	  */
	 std::vector<Seat> getAvailableSeatsForTheater(std::string concertName, std::string theaterName) const;
	 
	 /**
	  * @brief Book seats for a given concert and theater.
	  * @param concertName The name of the concert for which to book the seats.
	  * @param theaterName The name of the theater for which to book the seats.
	  * @param seatNames The names of the seats to be booked.
	  * @return A boolean indicating whether the seats were booked successfully or not.
	  */
	 bool bookSeats(std::string concertName, std::string theaterName, std::vector<std::string> seatNames);
	 
	 /**
	  * @brief Get all the bookings made in the booking system.
	  * @return A vector of Booking objects.
	  */
	 std::vector<Booking> getAllBookings() const;
	 
	 /**
	  * @brief Add a new concert to the booking system.
	  * @param concert The Concert object to be added.
	  */
	 void addConcert(const Concert& concert);
	 
	 /**
	  * @brief Add a new theater for a given concert.
	  * @param concertName The name of the concert for which to add the theater.
	  * @param theater The Theater object to be added.
	  */
	 void addTheaterForConcert(const std::string& concertName, const Theater& theater);
	 
	 /**
	  * @brief Add new seats for a given theater and concert.
	  * @param concertName The name of the concert for which to add the seats.
	  * @param theaterName The name of the theater for which to add the seats.
	  * @param seats A vector of Seat objects to be added.
	  */
	 void addSeatsForTheater(std::string concertName, std::string theaterName, std::vector<Seat> seats);
 
 	private:
 	
	 	///< A vector of all the concerts in the booking system.
		std::vector<Concert> concerts_;
		
		///< A vector of pairs where the first element is the name of the concert and the second element is a vector of 
		///< all the theaters for that concert. 											
		std::vector<std::pair<std::string, std::vector<Theater>>> concertTheaters_;
		
		///< A vector of pairs where the first element is the name of the theater and the second element is a vector of 
		///< all the seats for that theater. */ 
		std::vector<std::pair<std::string, std::vector<Seat>>> theaterSeats_; 
		
		///< A vector of all the active bookings.
		std::vector<Booking> bookings_;
};


#endif // BOOKING_HPP
