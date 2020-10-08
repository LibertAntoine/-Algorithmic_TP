#include <QApplication>
#include <time.h>
#include <stdio.h>
#include <math.h>

using std::size_t;
using std::string;

int hash(string key)
{
  int i = 0;
  int hash_value = 0;
  while(key[i] != '\0')
  {
    hash_value += key[i]* pow(128, i);
    i++;
  }
  return hash_value;
}

struct Node
{
  Node(string key, int value)
  {
    this->key = key;
    this->value = value;
    this->key_hash = hash(key);
    this->left = this->right = nullptr;
  }

  void insertNode(Node* node)
  {
    if (this->key_hash == node->key_hash) {
      if (this->right) {
        this->right->insertNode(node);
      } else {
        this->right=node;
      }
    } else if (this->key_hash< node->key_hash) {
      if (this->left) {
        this->left->insertNode(node);
      } else {
        this->left= node;
      }
    }
  }

  void insertNode(string key, int value)
  {
    this->insertNode(new Node(key, value));
  }

  string key;
  int key_hash;

  int value;

  Node* left;
  Node* right;
};

struct Map
{
  Map() {
    this->root = nullptr;
  }

  void insert(string key, int value)
  {
    if (this->root==NULL) {
      this->root= new Node(key,value);
    } else {
      this->root->insertNode(key,value);
    }
  }

  int get(string key)
  {
    Node* current;
    current = this->root;
    while (current != NULL) {
      if (current->key_hash > hash(key)) {
        current = current->right;
      } else if (current->key_hash < hash(key)) {
        current = current-> left;
      } else {
        return current->value;
      }
    }
    return 0;
  }
  Node* root;
};


int main(int argc, char *argv[])
{
  Map map;
  map.insert("Laura", 9);
  map.insert("Pierre", 5);
  map.insert("Eva", 14);
  map.insert("Yoann", 10);
  map.insert("Emilie", 15);

  printf("map[\"Laura\"]=%d\n", map.get("Laura"));
  printf("map[\"Yoann\"]=%d\n", map.get("Yoann"));
  return 0;
}
