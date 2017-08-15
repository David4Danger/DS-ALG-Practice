#include "trie.h"
using namespace std;

Trie::~Trie() {
  for (int i=0; i < children.size(); ++i) {
    delete children[i];
  }
}

void Trie::build_trie(string words[], int length) {
  for (int i = 0; i < length; ++i) {
    insert(words[i]);
  }
}

void Trie::insert(string word) {
  map<char, node*> *cur_tree = &head.children;
  map<char, node*>::iterator it;

  for (int i = 0; i < word.length(); ++i) {
    char curCh = word[i];
    it = cur_tree->find(curCh);

    if (it != cur_tree->end()) {
      //Desired char already exists
      cur_tree = &it->second->children;
      continue;
    } else {
      //Substr DNE yet, add the char and continue with word
      node *newnode = new node();
      newnode->c = curCh;
      (*cur_tree)[curCh] = newnode;
      cur_tree = &newnode->children;
      
      //For easy cleanup later
      children.push_back(newnode);
    }
  }
}

bool Trie::search(string word) {
  map<char, node*> cur_tree = head.children;
  map<char, node*>::iterator it;

  for (int i = 0; i < word.length(); ++i) {
    char curCh = word[i];
    it = cur_tree.find(curCh);

    if (it == cur_tree.end()) {
      return false;
    } else {
      //Char exists, continue
      cur_tree = it->second->children;
    }
  }
  return true;
}

void Trie::print_tree(map<char, node*> tree) {
  if (tree.empty()) {
    return;
  }

  map<char, node*>::iterator it;
  for (it = tree.begin(); it != tree.end(); ++it) {
    cout << it->first << endl;
    print_tree(it->second->children);
  }
}

void Trie::print() {
  map<char, node*> cur_tree = head.children;
  print_tree(cur_tree);
}

int main() {
  Trie testTrie;
  string words[] = {"to", "tea", "ted", "inn", "ten", "teach", "int"};
  
  testTrie.build_trie(words, 7);
  testTrie.print();
  cout << "'tea' in trie: " << testTrie.search("tea") << endl;
  cout << "'ted' in trie: " << testTrie.search("ted") << endl;
  cout << "'teach' in trie: " << testTrie.search("teach") << endl;
  cout << "'teacher' in trie: " << testTrie.search("teacher") << endl;
  cout << "'team' in trie: " << testTrie.search("team") << endl;
  cout << "'int' in trie: " << testTrie.search("int") << endl;

  cout << "Inserting 'teacher' into the trie" << endl;
  testTrie.insert("teacher");
  testTrie.print();
  cout << "'tea' in trie: " << testTrie.search("tea") << endl;
  cout << "'ted' in trie: " << testTrie.search("ted") << endl;
  cout << "'teach' in trie: " << testTrie.search("teach") << endl;
  cout << "'teacher' in trie: " << testTrie.search("teacher") << endl;
  cout << "'team' in trie: " << testTrie.search("team") << endl;
  cout << "'int' in trie: " << testTrie.search("int") << endl;

  return 0;
}
