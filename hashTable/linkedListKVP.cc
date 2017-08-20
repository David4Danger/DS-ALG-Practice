#include <iostream>
#include "linkedListKVP.h"
using namespace std;

linkedListKVP::~linkedListKVP () {
  if (head == NULL) {
    return;
  }

  KVPnode * delnode = head;
  KVPnode * nextnode;
  while (delnode->next != NULL) {
    nextnode = delnode->next;
    delete delnode;
    delnode = nextnode;
  }
  delete delnode;
}

void linkedListKVP::insertKVP (int newkey, int newvalue) {
  KVPnode * newnode = new KVPnode(newkey, newvalue);
  if (head == NULL) {
    head = newnode;
  } else {
    newnode->next = head;
    head = newnode;
  }
}

int linkedListKVP::searchKVP (int key) {
  if (head == NULL) {
    return -1;
  }

  KVPnode * iternode = head;
  while (iternode != NULL) {
    if (iternode->key == key) {
      return iternode->value;
    }
    iternode = iternode->next;
  }
  return -1;
}

int linkedListKVP::deleteKVP (int key) {
  int delval;
  
  if (head == NULL) {
    return -1;
  }

  if (head->key == key) {
    delval = head->value;
    head = head->next;
    return delval;
  } else {
    KVPnode * iternode = head;
    while (iternode->next != NULL) {
      if (iternode->next->key == key) {
        delval = iternode->next->value;
        iternode->next = iternode->next->next;
        return delval;
      }
      iternode = iternode->next;
    }
  return -1;
  }
}

int main () {
  linkedListKVP llist;
  llist.insertKVP(5,99);
  cout << "Inserted key 5, value 99" << endl;
  llist.insertKVP(12,54);
  cout << "Inserted key 12, value 54" << endl;
  llist.insertKVP(123,19);
  cout << "Inserted key 123, value 19" << endl;
  llist.insertKVP(75, 201);
  cout << "Inserted key 75, value 201" << endl;
  cout << "Deleted key 5, value: " << llist.deleteKVP(5) << endl;
  cout << "Searched for key 5, got value: " << llist.searchKVP(5) << endl;
  cout << "Searched for key 123, got value: " << llist.searchKVP(123) << endl;
  cout << "Deleted key 123, value: " <<llist.deleteKVP(123) << endl;
  cout << "Attempted delete on non-existant key 99, got value: " << llist.deleteKVP(99) << endl;
  cout << "Deleted key 12, value: " << llist.deleteKVP(12) << endl;
  cout << "Deleted key 75, value: " << llist.deleteKVP(75) << endl;
  cout << "Attempted delete on empty llist, got value: " << llist.deleteKVP(12) << endl;
  return 0;
}
