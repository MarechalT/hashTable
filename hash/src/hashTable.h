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

class Hash {

	struct item {
		std::string name;
		std::string sport;
		item* next;
	};
	const int tablesize;

	item** hashTable;	//buckets

public:
	//in which linked list / bucket the string should be stored
	Hash(int s = 13);
	~Hash();
	int hash(std::string key);
	void insert(std::string name, std::string sport);
	int countItemsInBucket(int index);
	bool isBucketEmpty(int index) const;
	std::string findSport(std::string name);
	friend std::ostream& operator<<(std::ostream &out, const Hash &h);
};

#endif /* HASHTABLE_H_ */
