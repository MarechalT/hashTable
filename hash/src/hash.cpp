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
	h.insert("Maximus", "Bricolage");
	h.insert("William", "Basketball");
	h.insert("Portos", "Rugby");

	cout << h << endl;
	std::string name;
	while (name != "exit") {
		cout << "Remove: ";
		cin >> name;
		if (name != "exit")
			cout << h.remove(name) << " for " << name << endl;
		cout << h << endl;
	}
	return 0;
}
