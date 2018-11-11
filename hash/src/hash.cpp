//============================================================================
// Name        : hash.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hashTable.h"
#include <string>
#include <cstdlib>

using namespace std;

int main() {

	//Example of use

	Hash h(4);
	h.insert("Thibault", "Basketball");
	h.insert("Weronika", "Running");
	h.insert("Pascal", "Football");
	h.insert("Damien", "Basketball");
	h.insert("Caudelia", "Sieste");
	h.insert("Maciej", "Sauna");
	h.insert("Ewa", "Shooting");
	h.insert("Slawomir", "BodyBuilding");
	h.insert("Maximus","Bricolage");
	h.insert("William","Basketball");
	h.insert("Portos","Rugby");

	cout << h << endl;

	cout << "Weronika's sport is: " << h.findSport("Weronika") << endl;
	cout << "Jean-Louis's sport is: " <<h.findSport("Jean-Louis") << endl;

	return 0;
}
