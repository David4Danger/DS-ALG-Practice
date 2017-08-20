#include <iostream>
#include "hashTableCH.h"
using namespace std;

hashMap::hashMap () {
  table = new linkedListKVP *[max_table_entries];
  
  // Explicitly set each linked list to NULL
  for (int i = 0; i < max_table_entries; ++i) {
    table[i] = NULL;
  }
}

hashMap::~hashMap () {
  for (int i = 0; i < max_table_entries; ++i) {
    if (table[i] != NULL) {
      delete table[i];
    }
  }
  delete[] table;
}

void hashMap::insert (int key, int val) {
  int hashval = key % max_table_entries;

  if (table[hashval] == NULL) {
    table[hashval] = new linkedListKVP();
  }
  //Add KVP to ll at hash index, or update value.
  table[hashval]->insertKVP(key, val);
}

int hashMap::deleteVal (int key) {
  int hashval = key % max_table_entries;
  return table[hashval]->deleteKVP(key);
}

int hashMap::search (int key) {
  int hashval = key % max_table_entries;
  return table[hashval]->searchKVP(key);
}

int main () {
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
