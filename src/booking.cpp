/**
 * @file booking.cpp
 * @brief Implementation of the Booking class.
 */

#include "booking.hpp"

/**
 * @brief Constructs a new Booking object with the given parameters.
 * @param concertName The name of the concert for which the booking is being made.
 * @param theaterName The name of the theater in which the booking is being made.
 * @param seatNames The names of the seats being booked.
 */
Booking::Booking(std::string concertName, std::string theaterName, std::vector<std::string> seatNames)
    : concertName_(concertName), theaterName_(theaterName), seatNames_(seatNames) {
    
}

/**
 * @brief Returns the name of the concert for which the booking is made.
 * @return The name of the concert.
 */
std::string Booking::getConcertName() const {
    return concertName_;
}

/**
 * @brief Returns the name of the theater in which the booking is made.
 * @return The name of the theater.
 */
std::string Booking::getTheaterName() const {
    return theaterName_;
}

/**
 * @brief Returns the names of the seats that are booked.
 * @return The names of the seats.
 */
std::vector<std::string> Booking::getSeatNames() const {
    return seatNames_;
}


//============================================================================================================

// OnlineBookingSystem class

/**
 * @brief Constructor for the OnlineBookingSystem class.
 */
OnlineBookingSystem::OnlineBookingSystem() {
    // constructor implementation
}

/**
 * @brief Returns a vector of all the concerts in the booking system.
 * @return A vector of all the concerts in the booking system.
 */
std::vector<Concert> OnlineBookingSystem::getAllConcerts() const {
    return concerts_;
}

/**
 * @brief Returns a vector of theaters associated with a given concert.
 * @param concertName The name of the concert.
 * @return A vector of theaters associated with the given concert.
 */
std::vector<Theater> OnlineBookingSystem::getTheatersForConcert(std::string concertName) const {
    for (auto concertTheater : concertTheaters_)
    {
        if (concertTheater.first == concertName)
        {
            return concertTheater.second;
        }
    }
    return std::vector<Theater>();
}

/**
 * @brief Returns a vector of available seats for a given theater at a given concert.
 * @param concertName The name of the concert.
 * @param theaterName The name of the theater.
 * @return A vector of available seats for the given theater at the given concert.
 */
std::vector<Seat> OnlineBookingSystem::getAvailableSeatsForTheater(std::string concertName, std::string theaterName) const {
    for (auto theaterSeats : theaterSeats_)
    {
        if (theaterSeats.first == theaterName)
        {
            std::vector<Seat> availableSeats;
            for (auto seat : theaterSeats.second)
            {
                if (seat.isAvailable())
                {
                    availableSeats.push_back(seat);
                }
            }
            return availableSeats;
        }
    }
    return std::vector<Seat>();
}

/**
 * @brief Books seats for a given concert and theater
 * 
 * @param concertName The name of the concert to book seats for
 * @param theaterName The name of the theater to book seats for
 * @param seatNames A vector of seat names to book
 * @return true if the seats were successfully booked, false otherwise
 */
bool OnlineBookingSystem::bookSeats(std::string concertName, std::string theaterName, std::vector<std::string> seatNames) {
    // Find the corresponding theater and seats vectors for the selected concert
    auto theaterIt = std::find_if(concertTheaters_.begin(), concertTheaters_.end(),
                                  [&](const std::pair<std::string, std::vector<Theater>>& ct) {
                                      return ct.first == concertName;
                                  });
    if (theaterIt == concertTheaters_.end()) {
        std::cout << "Invalid concert name." << std::endl;
        return false;
    }
    auto seatsIt = std::find_if(theaterSeats_.begin(), theaterSeats_.end(),
                                [&](const std::pair<std::string, std::vector<Seat>>& ts) {
                                    return ts.first == theaterName;
                                });
    if (seatsIt == theaterSeats_.end()) {
        std::cout << "Invalid theater name." << std::endl;
        return false;
    }
    
    // Check if all the selected seats are available
    std::vector<std::string> unavailableSeats;
    for (const auto& seatName : seatNames) {
        auto seatIt = std::find_if(seatsIt->second.begin(), seatsIt->second.end(),
                                   [&](const Seat& s) {
                                       return s.getName() == seatName;
                                   });
        if (seatIt == seatsIt->second.end() || !seatIt->isAvailable()) {
            unavailableSeats.push_back(seatName);
        }
    }
    
    // If any of the selected seats are unavailable, inform the user and return false
    if (!unavailableSeats.empty()) {
        std::cout << "The following seats are not available:";
        for (const auto& seatName : unavailableSeats) {
            std::cout << " " << seatName;
        }
        std::cout << std::endl;
        return false;
    }
    
    // Reserve the selected seats and update the booking and theater capacity
    std::vector<Seat> bookedSeats;
    for (const auto& seatName : seatNames) {
        auto seatIt = std::find_if(seatsIt->second.begin(), seatsIt->second.end(),
                                   [&](const Seat& s) {
                                       return s.getName() == seatName;
                                   });
        seatIt->reserve();
        bookedSeats.push_back(*seatIt);
    }
    bookings_.emplace_back(concertName, theaterName, seatNames);
    for (auto& theater : theaterIt->second) {
        if (theater.getName() == theaterName) {
            theater.setCapacity(theater.getCapacity() - static_cast<int>(seatNames.size()));
            break;
        }
    }
    
    std::cout << "Successfully booked seats: ";
    for (const auto& seat : bookedSeats) {
        std::cout << seat.getName() << " ";
    }
    std::cout << std::endl;
    
    return true;
}

/**
 * @brief Returns all the bookings in the online booking system.
 * 
 * @return std::vector<Booking> A vector of all the bookings in the online booking system.
 */
std::vector<Booking> OnlineBookingSystem::getAllBookings() const
{
    return bookings_;
}

/**
 * @brief Adds a concert to the online booking system.
 * 
 * @param concert The concert to be added to the online booking system.
 */
void OnlineBookingSystem::addConcert(const Concert& concert) {
    concerts_.push_back(concert);
}

/**
 * @brief Adds a theater for a concert to the online booking system.
 * 
 * @param concertName The name of the concert for which the theater is being added.
 * @param theater The theater to be added to the online booking system for the specified concert.
 */
void OnlineBookingSystem::addTheaterForConcert(const std::string& concertName, const Theater& theater) {
    for (auto& concertTheater : concertTheaters_) {
        if (concertTheater.first == concertName) {
            concertTheater.second.push_back(theater);
            return;
        }
    }
    concertTheaters_.push_back({concertName, {theater}});
}

/**
 * @brief Adds seats to a theater for a concert in the online booking system.
 * 
 * @param concertName The name of the concert for which the theater and seats are being added.
 * @param theaterName The name of the theater for which the seats are being added.
 * @param seats The seats to be added to the online booking system for the specified concert and theater.
 */
void OnlineBookingSystem::addSeatsForTheater(std::string concertName, std::string theaterName, std::vector<Seat> seats) {
    // Find the index of the theater in the theaterSeats_ vector 
    for(auto& concertTheaterPair : concertTheaters_) {
        if(concertTheaterPair.first == concertName) {
            for(auto& theaterSeatsPair : theaterSeats_) {
                if(theaterSeatsPair.first == theaterName) {
                    theaterSeatsPair.second = std::move(seats);
                    return;
                }
            }
            theaterSeats_.push_back({theaterName, std::move(seats)});
            return;
        }
    }
    throw std::invalid_argument("The concert or theater does not exist.");
}
