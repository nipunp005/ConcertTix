# ConcertTix
This is a C++ based application for booking concert tickets. It allows users to browse upcoming concerts and events, select the seats they want to purchase, and complete the booking process.

## Requirements
- g++ compiler - ver 11.3.0
- GNU Make v4.3
- CppUTest v8.3
- gcov (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
- lcov: LCOV version 1.14
- x86_64-pc-linux
- Docker version 23.0.4, build f480fb1

## Directory structure

Following is the directory structure 
```
├── Dockerfile
├── inc
│   ├── booking.hpp
│   ├── concert_def.hpp
│   ├── seat_def.hpp
│   └── theatre_def.hpp
├── Makefile
├── README.md
├── src
│   ├── booking_app.cpp
│   ├── booking.cpp
│   ├── concert.cpp
│   ├── seat.cpp
│   └── theatre.cpp
└── test
    ├── concert.cpp
    ├── concert_test.cpp
    ├── seat.cpp
    ├── seat_test.cpp
    ├── test_main.cpp
    ├── theatre.cpp
    └── theatre_test.cpp

```
- booking_app.cpp - Main driver for running the application.
- test_main.cpp - Main app for running the unit tests.

### Steps 

- Clone the repository - https://github.com/nipunp005/ConcertTix.git
```
- make all - To build the application
- make clean - Clean the project

```

## Usage

- Find the binary in under the build folder. Launch the application 
```
./build/booking_app 

```
- To run the unit tests, launch the application :

``` 
./build/unit_test

```

## Generate Coverage report

- Once build is completed , go to root folder run script ***gen_cov_report.sh***
- Find coverage report in html format under : ***build/coverage*** folder. Open ***index.html*** to see coverage report.

### Docker

- To build : sudo docker build -t booking-app .
- To run   : sudo docker run -it booking-app 
- Alternatively you can download a pre-built docker image : 

```
docker pull nipunp005/concertix:latest
 
```
and run it using : 

```
docker run -it nipunp005/concertix

```

## Known Limitations 

- Unit test coverage currently limited to 3 classes only : Seat , Concert, Theatre. (100% coverage).
- Unit test implementation for Booking and OnlineBooking class are not implemented. (0% coverage).
- No save restore feature.
- Simultaneous multiple request handling is absent. 
- Embedded CLI interface support only as of now.  

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use and modify this code as you see fit.
