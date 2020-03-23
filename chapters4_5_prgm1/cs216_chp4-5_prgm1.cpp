/*
Programmer Name: Kyle Absten
Date: 03/01/2020
Description:  This is the First program for the Chapter 4-5 Assignments for cs216.

This program asks the user 4 questions about their plans to book hotel rooms.  Based on their replies, it calculates
how much of a discount they are entitled to, and all the total amounts for their invoice.  It then prints this to the console.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int DISCOUNT_10ROOMS = 10, // An int to store the discount if 10 rooms are booked.
DISCOUNT_20ROOMS = 20,  // An int to store the discount if 20 rooms are booked.
DISCOUNT_30ROOMS = 30,  // An int to store the discount if 30 rooms are booked.
DISCOUNT_3DAYS = 5;  //An int to store the discount if rooms are booked for 3 or more days.

int numberOfRooms,  // An int to store the number of rooms the user wants to book.
daysBooked,  // An int to store the number of days the user wants to book the rooms for.
discountPerRoom;  //An int to store the total discount per room, as a percentage.

double pricePerRoom,  // A double to store the price of one room for one night, input by the user.
salesTax, // A double to store the sales tax input by the user.
oneRoomTotal, // A double to store the total cost per room.
subtotal,  // A double to store the total cost before tax.
salesTaxTotal, // A double to store the total sales tax paid.
total;  // A double to store the total billed amount, including salse tax.

string roomString, // A string to store either room or rooms depending on how many rooms are booked.
daysString; // A string to store either day or days depending on the number of days booked.


int main() {

	// Ask the user to input the relevant data, and store it in the appropriate variables.
	cout << "What is the cost for a single room for one night? ";
	cin >> pricePerRoom;
	// Validate the user's price per room
	while (pricePerRoom <= 0) {
		cout << "Sorry, that is not a valid price.  Please enter a number greater that $0.00: ";
		cin >> pricePerRoom;
	};
	cout << "\nAnd what is the sales tax(as a percent)? ";
	cin >> salesTax;
	// Validate the user's input for salse tax.
	while (salesTax < 0) {
		cout << "Sorry, salse tax can not be a negative number.  Please try again: ";
		cin >> salesTax;
	};
	cout << "\nHow many rooms do you want to book? ";
	cin >> numberOfRooms;
	// Validate the user's input for rooms booked
	while (numberOfRooms <= 0) {
		cout << "Sorry, must book atleast 1 room.  Please try again: ";
		cin >> numberOfRooms;
	}
	cout << "\nAnd how many days will you be renting the rooms? ";
	cin >> daysBooked;
	// Validate the user's input for number of days booked.
	while (daysBooked <= 0) {
		cout << "Sorry, you must reserve rooms for a minimum of 1 day.  Please try again: ";
		cin >> daysBooked;
	};
	// Figure out the discount given for number of rooms booked.

	if (numberOfRooms >= 30) {
		discountPerRoom = DISCOUNT_30ROOMS;
	}
	else if (numberOfRooms >= 20) {
		discountPerRoom = DISCOUNT_20ROOMS;
	}
	else if (numberOfRooms >= 10) {
		discountPerRoom = DISCOUNT_10ROOMS;
	}
	else {
		discountPerRoom = 0;
	}
	// Apply an extra discount if rooms are booked for three or more days.
	if (daysBooked >= 3) {
		discountPerRoom += DISCOUNT_3DAYS;
	};

	// Calculate the needed values
	oneRoomTotal = (pricePerRoom * daysBooked) * (1 - (discountPerRoom / 100.00));
	subtotal = (numberOfRooms * pricePerRoom * daysBooked) * (1 - (discountPerRoom / 100.00));
	salesTaxTotal = subtotal * (salesTax / 100);
	total = subtotal + salesTaxTotal;

	// Set the roomString and daysString depending on number of rooms and days booked.
	numberOfRooms > 1 ? roomString = "rooms" : roomString = "room";
	daysBooked > 1 ? daysString = "days" : daysString = "day";

	// Set the double display percision
	cout << fixed << setprecision(2);
	// Display the information
	cout << "\nYou booked " << numberOfRooms << " " << roomString << " for " << daysBooked
		<< " " << daysString << " at a price of $" << pricePerRoom << " per room per night.\n";
	cout << "You received a total discount of " << discountPerRoom << "\% per room.\n";
	cout << "Cost per room: " << oneRoomTotal << endl;
	cout << "Your subtotal is: $" << subtotal << endl;
	cout << "The sales tax will be: $" << salesTaxTotal << endl;
	cout << "Your total bill will be: $" << total << endl;

	return 0;
}