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

void Hash::resetItem(item& i) {
	i.name = "";
	i.sport = "";
	i.next = nullptr;
}

bool Hash::remove(std::string name) {
	int index = hash(name);
	bool foundName = false;

	//init iptr1 to point to the first element of the LinkedList/Bucket
	item* iptr1 = hashTable[index];

	//Split the algorithm in few steps of checking:

	if (!isBucketEmpty(index)) {
		//1 - 1st item matching and no more item
		if (iptr1->name == name && iptr1->next == nullptr) {
			resetItem(*iptr1);
			return true;
		}
		//3 - 1st item but more items
		else if (iptr1->name == name && iptr1->next != nullptr) {
			hashTable[index] = hashTable[index]->next;
			delete iptr1;
			return true;
		}
		//4 - Bucket contains items but 1st is not a match

		item* iptr2 = iptr1->next;
		while (iptr2 != nullptr && iptr2->name != name) {
			iptr1 = iptr2;
			iptr2 = iptr2->next;
		}

		if (iptr2 != nullptr) {
			item* iptr3 = iptr2;	//ptr to delete "n"
			iptr2 = iptr2->next;		// "n" = "n+1"
			iptr1->next = iptr2;	//"n-1 -> next " = "n"
			delete iptr3;			//delete previous "n"
			return true;
		}
	}
	return foundName;
}

