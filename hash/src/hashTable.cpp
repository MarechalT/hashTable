/*
 * hashTable.cpp
 *
 *  Created on: Nov 11, 2018
 *      Author: Thibault
 */

#include "hashTable.h"

Hash::Hash(int s) :
		tablesize(s) {
	hashTable = new item*[tablesize];
	for (int i = 0; i < tablesize; ++i) {
		hashTable[i] = new item;
		hashTable[i]->name = "";
		hashTable[i]->sport = "";
		hashTable[i]->next = nullptr;
	}
}

Hash::~Hash() {
	delete[] hashTable;
}

int Hash::hash(std::string key) {
	int value = 0;
	for (unsigned int i = 0; i < key.length(); i++) {
		value += static_cast<int>(key[i]);
	}
	return (value % tablesize);
}

void Hash::insert(std::string name, std::string sport) {
	int bucket = hash(name);

	///check if it is first element
	if (isBucketEmpty(bucket)) {
		hashTable[bucket]->name = name;
		hashTable[bucket]->sport = sport;
	} else {
		/// create the new item
		item* n = new item;
		n->name = name;
		n->sport = sport;
		n->next = nullptr;
		/// Find the last element of the linked list / bucket and associate the new item to its next ptr;
		item* iptr = hashTable[bucket];
		while (iptr->next != nullptr) {
			iptr = iptr->next;
		}
		iptr->next = n;
	}
}

int Hash::countItemsInBucket(int index) {
	int count = 0;
	if (!isBucketEmpty(index)) {
		count++;
		item * iptr = hashTable[index];
		while (iptr->next != nullptr) {
			count++;
			iptr = iptr->next;
		}
	}
	return count;
}

void Hash::printTable() {

}

std::ostream& operator<<(std::ostream &out, const Hash &h) {
	for (int i = 0; i < h.tablesize; ++i) {
		out << "[" << i << "]: ";
		if (!(h.isBucketEmpty(i))) {
			Hash::item *iptr = h.hashTable[i];
			while (iptr != nullptr) {
				out << iptr->name << " " << iptr->sport << ", ";
				iptr = iptr->next;
			}
		}
		out << std::endl;
	}
	return out;
}

std::string Hash::findSport(std::string name) {
	int index = hash(name);
	bool foundName = false;
	std::string sport;

	item* iptr = hashTable[index];
	while (iptr != nullptr) {
		if (iptr->name == name) {
			foundName = true;
			sport = iptr->sport;
		}
		iptr = iptr->next;
	}
	if (foundName)
		return sport;
	else
		return (name + " is not in the hashTable");
}

bool Hash::isBucketEmpty(int index) const {
	return (hashTable[index]->name == "" && hashTable[index]->sport == "");
}
