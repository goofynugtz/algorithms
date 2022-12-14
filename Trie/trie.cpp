#include <bits/stdc++.h>

struct Node {
  Node* links[26];
  bool flag = false;
  bool contains(char c){
    return (links[c - 'a'] != NULL);
  }

  void put(char c, Node* node){
    links[c - 'a'] = node;
  }

  Node* get(char c){
    return links[c-'a'];
  }

  void markEnd(){
    flag = true; 
  }
  
  bool isEnd(){
    return flag;
  }
};

class Trie {
  private:
  Node* root;

  public:
  /*
  1. insert
  2. search
  3. starts with 
  */
  Trie(){
    root = new Node();
  }

  void insert(std::string word){
    Node* node = root;
    for (int i = 0; i < word.length(); i++){
      if (!node->contains(word[i])){
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->markEnd();
  }

  bool search(std::string word){
    Node* node = root;
    for (int i = 0; i < word.length(); i++){
      if (!node->contains(word[i])) return false;
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  bool startsWith(std::string word){
    Node* node = root;
    for (int i = 0; i < word.length(); i++){
      if (!node->contains(word[i])) return false;
      node = node->get(word[i]);
    }
    return true;
  }
};
