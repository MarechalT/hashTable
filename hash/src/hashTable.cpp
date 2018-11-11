/*
 * hashTable.cpp
 *
 *  Created on: Nov 11, 2018
 *      Author: Thibault
 */

#include "hashTable.h"

Hash::Hash(int s):tablesize(s){}

int Hash::hash(std::string key) {
	int value = 0;
	for(unsigned int i=0;i<key.length();i++){
		value+=static_cast<int>(key[i]);
	}
	return (value % tablesize);
}
