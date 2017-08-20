struct KVPnode {
  int key;
  int value;
  KVPnode * next;

  KVPnode(int newkey, int newvalue) {
    key = newkey;
    value = newvalue;
    next = NULL;
  } 
};

class linkedListKVP {
private:
  KVPnode * head;
public:
  linkedListKVP() {
    head = NULL;
  }
  ~linkedListKVP();
  void insertKVP(int newkey, int newvalue);
  int searchKVP(int key);//lookup value associated with key, don't delete
  int deleteKVP(int key);
};
