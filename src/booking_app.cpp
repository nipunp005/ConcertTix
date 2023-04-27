#include "booking.hpp"

// ===========================================================================================================

int main() {

	// Create some sample concerts
	Concert concert1("Concert1", "Artist1", "2023-05-01");
	Concert concert2("Concert2", "Artist2", "2023-06-01");

	// Create some sample theaters
	Theater theater1("Theater1", 20);
	Theater theater2("Theater2", 20);
	Theater theater3("Theater3", 20);

	// Add the theaters to the concerts
	std::vector<Theater> theaters1 = {theater1, theater2};
	std::vector<Theater> theaters2 = {theater2, theater3};

	std::pair<std::string, std::vector<Theater>> concertTheaters1 = {"Concert1", theaters1};
	std::pair<std::string, std::vector<Theater>> concertTheaters2 = {"Concert2", theaters2};

	std::vector<std::pair<std::string, std::vector<Theater>>> concertTheaters = {concertTheaters1, concertTheaters2};

	// Create some sample seats
	std::vector<Seat> seats1;
	std::vector<Seat> seats2;

	for (int i = 1; i <= 20; ++i) {
	    std::string name = "A" + std::to_string(i);
	    Seat seat(name, true);
	    seats1.push_back(seat);
	}

	for (int i = 1; i <= 20; ++i) {
	    std::string name = "B" + std::to_string(i);
	    Seat seat(name, true);
	    seats2.push_back(seat);
	}

	std::pair<std::string, std::vector<Seat>> theaterSeats1 = {"Theater1", seats1};
	std::pair<std::string, std::vector<Seat>> theaterSeats2 = {"Theater2", seats1};
	std::pair<std::string, std::vector<Seat>> theaterSeats3 = {"Theater3", seats2};

	std::vector<std::pair<std::string, std::vector<Seat>>> theaterSeats = {theaterSeats1, theaterSeats2, theaterSeats3};

	// Create the online booking system object and add the concerts, theaters, and seats
	OnlineBookingSystem bookingSystem;

	bookingSystem.addConcert(concert1);
	bookingSystem.addConcert(concert2);

	bookingSystem.addTheaterForConcert("Concert1", theater1);
	bookingSystem.addTheaterForConcert("Concert1", theater2);
	bookingSystem.addTheaterForConcert("Concert2", theater2);
	bookingSystem.addTheaterForConcert("Concert2", theater3);

	bookingSystem.addSeatsForTheater("Concert1", "Theater1", seats1);
	bookingSystem.addSeatsForTheater("Concert1", "Theater2", seats1);
	bookingSystem.addSeatsForTheater("Concert2", "Theater2", seats1);
	bookingSystem.addSeatsForTheater("Concert2", "Theater3", seats2);

	// ======================================= Main loop Begins here ============================================== //

	while(1) {

		std::cout << "======== ConcerTix - Concert Booking System ============" << std::endl;
		std::cout << " a. View all playing concerts " << std::endl;
		std::cout << " b. Select Concert and Book seat " << std::endl;
		std::cout << " c. View all bookings " << std::endl;
		std::cout << " q. Quit " << std::endl;
		
		char choice = 0;
		std::cout << "Enter your choice : ";
		std::cin >> choice;
		choice = tolower(choice);
		
		std::vector<Concert> concerts;
		std::string selectedConcert;
		
		std::vector<Theater> theaters;
		std::string selectedTheater;
		
		std::vector<Seat> seats;
		std::vector<std::string> selectedSeats;
		std::string seatName;
		
		std::vector<Booking> bookings;
		
		switch(choice) {
		
		case 'a':
				// Action 1: View all playing concerts
				std::cout << "All concerts:\n";
				concerts = bookingSystem.getAllConcerts();
				for (const Concert& concert : concerts) {
					std::cout << concert.getName() << " by " << concert.getArtist() << " on " << concert.getDate() << std::endl;
				}
				break;
				
		case 'b': {
		
					// Action 2: Select a concert
					std::cout << "Enter the name of the concert you want to attend: ";
					std::cin.ignore();
					std::getline(std::cin, selectedConcert);
						
					// Action 3: See all theaters showing the concert
					
					theaters = bookingSystem.getTheatersForConcert(selectedConcert);
					std::cout << "Theaters showing " << selectedConcert << ":\n";
					for (const Theater& theater : theaters) {
						std::cout << theater.getName() << " (capacity: " << theater.getCapacity() << ")" << std::endl;
					}

					// Action 4: Select a theater
					std::cout << "Enter the name of the theater you want to attend: ";
					std::getline(std::cin, selectedTheater);

					// Action 5: See available seats for selected concert and theater
					seats = bookingSystem.getAvailableSeatsForTheater(selectedConcert, selectedTheater);
					std::cout << "Available seats for " << selectedConcert << " at " << selectedTheater << ":" << std::endl;
					for (const Seat& seat : seats) {
						std::cout << seat.getName() << " (" << (seat.isAvailable() ? "available" : "booked") << ")" << std::endl;
					}

					// Action 6: Book one or more seats
					std::cout << "Enter the seat names you want to book (separated by spaces): ";
					std::string seatNamesInput;
					std::getline(std::cin, seatNamesInput);
					std::stringstream ss(seatNamesInput);
			
					while (ss >> seatName) {
						
							transform(seatName.begin(), seatName.end(), seatName.begin(), ::toupper);
							selectedSeats.push_back(seatName);
					}
						
					bool success = bookingSystem.bookSeats(selectedConcert, selectedTheater, selectedSeats);
						
					if (success) {
						std::cout << "Booking successful!\n";
					} else {
						std::cout << "Booking failed: one or more seats are already booked." << std::endl;
					}
					
					break;
				}

		case 'c':
		
				// Action 7: View all bookings
				std::cout << "All bookings:\n";
				bookings = bookingSystem.getAllBookings();
				
				for (const Booking& booking : bookings) {
					std::cout << "Concert: " << booking.getConcertName() << std::endl;
					std::cout << "Theater: " << booking.getTheaterName() << std::endl;
					std::cout << "Seats: ";
					for (const std::string& seatName : booking.getSeatNames()) {
						std::cout << seatName << " ";
					}
					std::cout << "\n\n";
				}
				break;
				
		case 'q':
		
				// Action 8	: Quit
				return 0;
				break;	
				
		default:
				std::cout << "Invalid Choice: " << choice << std::endl; break;	
		}
	}
}

