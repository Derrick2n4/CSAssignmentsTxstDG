#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <istream>
#include <vector>
#include <ctime>

using namespace std;

struct Ship {
    string shipName;
    string designerName;
	string shipFile;

    float mass,thrust,acceleration,deltaV,maxAlt; //deltaV = Change in velocity

};

void designShip(Ship Ships);
void testShipDesign(Ship Ships);
void flightSimulator();
string readShipFiles(Ship Ships);
void testResults(Ship Ships);


int main() {
	struct Ship Ships;
    char choice;

    // Run loop until user choose to quit
    do {
        // Display the menu
        std::cout << "Menu:\n";
        std::cout << "D - Design a new ship\n";
        std::cout << "T - Test a new ship\n";
        std::cout << "S - Simulate a flight\n";
        std::cout << "Q - Quit the Program\n";

        // Ask user to select option from the menu
        std::cout << "Choose an option (D/T/S/Q): ";
        std::cin >> choice;

        // Do operation as per user's choice
        switch (toupper(choice)) {
            case 'D': designShip(Ships); break; // Design a Ship
            case 'T': testShipDesign(Ships); break; // Test Ship Design
            case 'S': flightSimulator(); break; // Simulate a flight
            case 'Q': std::cout << "\nThank you for using Craft Designer Plus\n"; exit(0);
            default: std::cout << "Invalid Choice!!!!\n";
        }

    } while (true);
}




void designShip(struct Ship &Ships){
	// Gather user input
	std::cout<<"Enter Ship Name:";
	getline(cin, Ships.shipName);

	std::cout<<"Enter Designer Name:";
	getline(cin, Ships.designerName);

	std::cout<<"Enter Ship's Mass:";
	std::cin>>Ships.mass;

	std::cout<<"Enter Engine Thrust:";
	std::cin>>Ships.thrust;

	Ships.acceleration = Ships.thrust/Ships.mass;
	Ships.deltaV = (100000/Ships.thrust) * 9.8 * log(2);
	Ships.maxAlt = 100 + (Ships.deltaV-200)/10;

	ofstream file;

	// Open text file in write mode
	file.open(Ships.shipName+".txt");

	// Write the obtained information to the text file
	file << "##########"+Ships.shipName+"##########" << endl << endl;
	file << "Designed By:\t\t" << Ships.designerName << endl;
	file << "Ship Mass:\t\t" << Ships.mass << "kg" << endl;
	file << "Acceleration:\t\t" << fixed << setprecision(1) << Ships.acceleration << "m/s2" << endl;
	file << "Delta V:\t\t" << fixed << setprecision(1) << Ships.deltaV<< "m/s" << endl;
	file << "Max Altitude:\t\t" << fixed << setprecision(1) << Ships.maxAlt << "km" << endl << endl;
	file << "File saved at:\t\t" << time(NULL);

	// Close the file.
	file.close();

	std::cout << "File written for " + Ships.shipName << endl << endl;
};

void testShipDesign(Ship Ships){
	/*Update for version 2.2: The Test a Ship Design function should be split into two functions.
• Use one function to read the ship file and store the values in a Ship variable (described in 5.2).
• Use a second function to run the tests and print the results.
• You can decide how the Ship is passed between the two functions. The first function could
return a Ship or be passed a Ship by reference. But all file operations should be done in one
function and all tests (described in another).*/

}


string readShipFiles(Ship Ships) {
	// opening ship.txt file in read mode

	fstream newFile;
	newFile.open(Ships.shipName+".txt:", ios::in);
	if (newFile.is_open()){
		while (getline(newFile, Ships.shipFile)){
			continue;
		}
		newFile.close();
	}
	if(!newFile.is_open())
	{
		std::cout<<"File does not Exist";
		return 0;
	}
	return Ships.shipFile;

};

void testResults(Ship Ships) {
	/* Now that I have the read ship file method I can use the variable that has the ship data stored in it
	 * to run tests
	 * */
	bool testFail = false;
	string line;
	




};