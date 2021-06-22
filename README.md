# Railway-Reservation-System

This is a rudimentary railway reservation / booking system (somewhat like IRCTC Train Ticket Booking, but extremely scaled down in features). The same is implemented via an Object Oriented C++ programme which is broken into numerous files.

The main folder is classified into 3 parts:

	1. Documents.zip

		a. TestPlan.txt: The testplan document stating scenarios for unit tests and the test application
		a. TestReport.txt: The test report document based on the testplan

	2. Source.zip
		a. Implementation

			I.	  Station.h and Station.cpp:
					Class Station is implemented.
			II.	  Date.h and Date.cpp:
					Class Date is implemented.
			III.  Passenger.h and Passenger.cpp:
					Class Passenger is implemented.
			IV.	  Railways.h and Railways.cpp:
					Singleton class Railways is implemented.
			V.	  BookingClass.h and BookingCLass.cpp:
					All Booking Classes are implemented in a hierarchy. Abstract Base class BookingClassis made for implementation.
			VI.	  BookingCategory.h and BookingCategory.cpp:
					All Booking Categories are implemented in a hierarchy. Abstract Base classes BookingCategory, Concession and Divyang are made for implementation.
			VII.  Booking.h and Booking.cpp:
					Class Booking is implemented in a hierarchy parallel to BookingCategory.
			VIII. Gender.h and Gender.cpp:
					Hierarchy for Gender is implemented here, with abstract base class Gender.
			IX.	  Error.h and Error.cpp
					Hierarchy for exceptions are implemented here based on std::exception.									

		b. TestApplication

			I. 	 UnitTest.cpp: The Unit Tests are done here
			II.  TestApplication.cpp: The Test Application

			**Outputs are redirected to output files via freopen**

	3. Outputs.zip

		a. TestApplication.txt: The output of the test application.
		b. UnitTest.txt: The output of Unit tests.

Compiler used: g++ (MinGW GCC-6.3.0)
Commands used to get Output txt files:
	1. UnitTest: g++ UnitTest.cpp Booking.cpp BookingCategory.cpp BookingClass.cpp Railways.cpp Passenger.cpp Gender.cpp Date.cpp Station.cpp Error.cpp
	2. TestApplication: g++ TestApplication.cpp Booking.cpp BookingCategory.cpp BookingClass.cpp Railways.cpp Passenger.cpp Gender.cpp Date.cpp Station.cpp Error.cpp

**Please read the .h files in Implementation section for further notes on member variables and functions as comments**

# Contributors

- Amartya Mandal
