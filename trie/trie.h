#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct node {
  char c;
  map<char, node*> children;
};

class Trie {
private:  
  // Not necessary for trie implementation but makes deleting a lot easier.
  // Instead of running through the entire trie for each node, just keep a
  // vector of the same node* to delete.
  vector <node *> children;
  node head;
public:
  Trie() {
    head.c = 0;
  };

  ~Trie();
  void build_trie(string words[], int length);
  void insert(string word);
  bool search(string word);
  void print_tree(map<char, node*> tree);
  void print();
};
