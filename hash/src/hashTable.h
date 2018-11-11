/*
 * hashTable.h
 *
 *  Created on: Nov 11, 2018
 *      Author: Thibault
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <cstdlib>
#include <string>

class Hash{
 const int tablesize;

 	 struct item{
	 	 std::string name;
	 	 std::string sport;
	 	 item* next;
 };

public:
	//in which linked list / bucket the string should be stored
	Hash(int s = 13);
	int hash(std::string key);

};














#endif /* HASHTABLE_H_ */
