#pragma once
/* Jesse Martin
*  CS210 Programming Languages
*  Project One: Chada Tech Clock
*/

#include <iostream> // To access standard stream objects such as cout,cin
#include <ctime> // Time library used for fetching and manipulating date and time
#include <iomanip> // Library of parametric manipulators such as setw and setfill
#include <Windows.h> // Used to include functions in the windows API such as Sleep()
#include <string> 

using namespace std;
// Base class
class Time {
public: // Access specifier
	// member variables inherited by derived classes
	int hours12;
	int minutes12;
	int seconds12;
	int hours24;
	int minutes24;
	int seconds24;
};

// Derived class for 24 hour time 
class format24 : public Time {
public: // Access specifier 

	format24() {
		time_t now = time(0); // Current time
		tm* local = localtime(&now); // To local time
		hours24 = local->tm_hour;
		minutes24 = local->tm_min;
		seconds24 = local->tm_sec;


	}
	/* Required functionality for adding hours, minutes, and seconds respectively
	*  For 24-hour format
	*/
	void addHours(int h) {
		hours24 += h;
		if (hours24 >= 24) {
			hours24 -= 24;
		}
	}
	void addMinutes(int m) {
		minutes24 += m;
		if (minutes24 >= 60) {
			int h = minutes24 / 60;
			minutes24 -= 60 * h;
			addHours(h);
		}
	}
	void addSeconds(int s) {
		seconds24 += s;
		if (seconds24 >= 60) {
			int m = seconds24 / 60;
			seconds24 -= 60 * m;
			addMinutes(m);
		}
	}
};
// Derived class for 12 our time
class format12 : public Time {
public:
	string amPM;
	format12() {
		time_t now = time(0); // Likewise as with the previous class
		tm* ltm = localtime(&now); // Likewise as with the previous class, as well
		hours12 = ltm->tm_hour;
		minutes12 = ltm->tm_min;
		seconds12 = ltm->tm_sec;
		// Simple conditional to evaluate whether the time is AM or PM
		if (hours12 >= 12) {
			amPM = "P M";
			hours12 -= 12;
		}
		else {
			amPM = "A M";
		}
	}
	/* Required functionality as with the format24 derived class, but
	*  for 12-hour time format.
	*/
	void addHours(int h) {
		hours12 += h;
		if (hours12 > 12) {
			hours12 -= 12;

		}
		else if (hours12 >= 12) {
			if (amPM == " A M") {
				amPM = "P M";
			}
			else if (amPM == "P M") {
				amPM = "A M";
			}
		}
	}
	void addMinutes(int m) {
		minutes12 += m;
		if (minutes12 >= 60) {
			int h = minutes12 / 60;
			minutes12 -= 60 * h;
			addHours(h);
		}
	}
	void addSeconds(int s) {
		seconds12 += s;
		if (seconds12 >= 60) {
			int m = seconds12 / 60;
			seconds12 -= 60 * m;
			addMinutes(m);
		}
	}

};

