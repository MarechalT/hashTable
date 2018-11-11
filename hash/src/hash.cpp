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

	Hash h(4);
	cout << h.hash("name5678901234") << endl;


	return 0;
}
