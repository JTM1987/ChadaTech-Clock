#pragma warning(disable: 4996) // Used to disable error for variable "localtime"
#include "clock1224.h" // Including the header file for base and derived classes
//#include <string>
#include <sstream> // Included for parsing input

using namespace std;


// Function to display both clocks, formatted using setw,setfill, takes classes 12 and 24 as params
void displayClocks(format12 h1, format24 h2) {
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
	cout << "\t\t*\t12-Hour Clock\t*\t\t";
	cout << "*\t24-Hour Clock\t*\n";
	cout << "\t\t*\t" << setw(2) << setfill('0') << h1.hours12 << ":" << setw(2) << setfill('0') << h1.minutes12 << ":" << setw(2) << setfill('0') << h1.seconds12 << " " << h1.amPM << "\t*\t\t";
	cout << "*\t" << setw(2) << setfill('0') << h2.hours24 << ":" << setw(2) << setfill('0') << h2.minutes24 << ":" << setw(2) << setfill('0') << h2.seconds24 << "\t*\n";
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
	//Sleep(2500);
	//system("CLS");
}
// Function to validate input using stringstream
bool validateInput(int& maxChoice) {
	std::string line;
	std::getline(std::cin, line);
	std::istringstream iss(line);
	return (iss >> maxChoice && (iss >> std::ws).peek() == EOF);


}
// Displays the menu with required user selections.
void displayMenu() {
	cout << "\n\n\t\t\t\t   *************************\n";
	cout << "\t\t\t\t   * 1 - Add One Hour\t   *\n";
	cout << "\t\t\t\t   * 2 - Add One Minute\t   *\n";
	cout << "\t\t\t\t   * 3 - Add One Second\t   *\n";
	cout << "\t\t\t\t   * 4 - Exit Program\t   *\n";
	cout << "\t\t\t\t   *************************\n";
}
/* Main method with a loop to take user's choice as input, exit when choice is 4,
*  display clocks and show adjusted time based on the user's selection.
*  and clears screen
**/
int main(int maxChoice) {
	format12 h1;
	format24 h2;
	int choice = maxChoice;
	while (choice != 4) {
		displayClocks(h1, h2);
		displayMenu();
		validateInput(choice);
		switch (choice)
		{
		case 1: h1.addHours(1);
			h2.addHours(1);
			break;
		case 2: h1.addMinutes(1);
			h2.addMinutes(1);
			break;
		case 3: h1.addSeconds(1);
			h2.addSeconds(1);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Enter Correct Choice!!\n";
			Sleep(1000);
			system("cls");
			continue;
		}
		system("cls");

	}

}
