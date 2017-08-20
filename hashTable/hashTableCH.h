#include "linkedListKVP.h"

/* hashTableCH uses buckets to handle collisions. This means that multiple KVP
   pairs can be placed in the same location if they have the same hash value.
   This is accomplished by having an array of linked lists, where each linked
   list corresponds to a single bucket containing 0 or more KVP entries.
*/

const int max_table_entries = 64;

class hashMap {
private:
  linkedListKVP **table;

public:
  hashMap();
  ~hashMap();
  void insert(int key, int val);//Add a KVP
  int deleteVal(int key);//Find and delete the KVP
  int search (int key);//Find KVP, return value, don't delete
};
