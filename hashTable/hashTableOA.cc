#include <iostream>
#include "hashTableOA.h"
using namespace std;

tableEntry::tableEntry(int newKey, int newVal) {
  key = newKey;
  val = newVal;
}

int tableEntry::getKey() {
  return key;
}

int tableEntry::getVal() {
  return val;
}

void tableEntry::deleted() {
  key = -1;
}

hashMap::hashMap() {
  table = new tableEntry *[max_table_entries];
  
  // Explicitly set each entry to NULL
  for (int i = 0; i < max_table_entries; ++i) {
    table[i] = NULL;
  }
}

hashMap::~hashMap() {
  for (int i = 0; i < max_table_entries; ++i) {
    if (table[i] != NULL) {
      delete table[i];
    }
  }
  delete[] table;
}

void hashMap::insert (int key, int val) {
  int hashval = key % max_table_entries;
  while (table[hashval] != NULL && table[hashval]->getKey() != -1 && table[hashval]->getKey() != key) {
    // Spot is taken by another K-V pair, try the next possible location
    ++hashval;
  }

  if (table[hashval] != NULL) {
    // Updating an existing tableEntry with this key (could be a deleted entry -1)
    delete table[hashval];
  }
  table[hashval] = new tableEntry(key,val);
}

int hashMap::deleteVal (int key) {
  int hashval = key % max_table_entries;
  while (table[hashval] != NULL && table[hashval]->getKey() != key) {
    ++hashval;
  }

  if (table[hashval] == NULL) {
    // K-V pair DNE
    return -1;
  } else {
    int delval = table[hashval]->getVal();
    table[hashval]->deleted();
    return delval;
  }
}

int hashMap::search (int key) {
  int hashval = key % max_table_entries;
  while (table[hashval] != NULL && table[hashval]->getKey() != key) {
    ++hashval;
  }

  if (table[hashval] == NULL) {
    // K-V pair DNE
    return -1;
  } else {
    return table[hashval]->getVal();
  }
}

int main() {
  hashMap dict;
  cout << "Max entries in table is: " << max_table_entries << endl << endl;
  dict.insert(5,55);
  cout << "What value is associated with key 5: " << dict.search(5) << endl;
  dict.insert(42,1241);
  cout << "What value is associated with key 42: " << dict.search(42) << endl;
  dict.insert(69,69);
  cout << "What value is associated with key 69: " << dict.search(69) << endl;
  cout << "Deleting key 5" << endl;
  dict.deleteVal(5);
  cout << "Does key 5 still exist: " << dict.search(5) << endl;
  cout << "Can KV pair at table[6] be found still: " << dict.search(69) << endl;
  return 0;
}
