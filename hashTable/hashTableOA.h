/* hashTableOA uses open addressing to handle collisions. This means
   entries are allowed to go into multiple locations, and each hash
   entry contains 1 item at most.

   Note that when working with open addressing, we must distinguish
   between EMPTY and DELETED locations in the table.

   - Deleted spots have a key value of -1, not NULL
   - Insertion can use deleted spots
   - Search skips deleted spots
*/

const int max_table_entries = 64;

class tableEntry {
private:
  int key;
  int val;

public:
  tableEntry(int newKey, int newVal);
  int getKey();
  int getVal();
  void deleted();//Method to call on an entry to mark it as deleted
};

class hashMap {
private:
  tableEntry **table;

public:
  hashMap();
  ~hashMap();
  void insert(int key, int val);//Add a KVP
  int deleteVal(int key);//Find and delete the KVP, mark key as deleted (-1)
  int search (int key);//Find KVP, return value
};
