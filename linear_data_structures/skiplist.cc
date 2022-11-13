#ifndef SKIPLIST_HPP_
#define SKIPLIST_HPP_

#include <iostream>
#include <random>
#include <vector>

constexpr int MAX_LEVEL{16};

class SkipList {
  struct Node {
    int key;
    std::vector<Node *> forward;  // forward pointers.
    explicit Node(const int key) : key{key}, forward(MAX_LEVEL, nullptr) {}
  };

 public:
  SkipList()
      : p{0.5},
        level{1},
        header{new Node(INT32_MIN)},
        nil{new Node(INT32_MAX)} {
    for (int i = 0; i < MAX_LEVEL; ++i) {
      header->forward[i] = nil;
    }
  }

  ~SkipList() {
    Node *x = header->forward[0];
    while (x != nil) {
      remove(x->key);
      x = header->forward[0];
    }
    delete nil;
    delete header;
  }

  bool search(const int key) {
    Node *x = header;

    // loop inv: x->key < key.
    for (int i = level - 1; i >= 0; --i) {
      while (x->forward[i]->key < key) {
        x = x->forward[i];
      }
    }
    // post cond: x->key < key <= x->forward[0]->key.

    x = x->forward[0];
    return x->key == key;
  }

  void insert(const int key) {
    std::vector<Node *> prev(MAX_LEVEL, nullptr);
    Node *x = header;
    for (int i = level - 1; i >= 0; --i) {
      while (x->forward[i]->key < key) {
        x = x->forward[i];
      }
      prev[i] = x;
    }
    x = x->forward[0];

    if (x->key == key) {
      return;
    }

    const int new_level = random_level();
    if (new_level > level) {
      for (int i = level; i < new_level; ++i) {
        prev[i] = header;
      }
      level = new_level;
    }

    x = new Node(key);
    for (int i = 0; i < level; ++i) {
      x->forward[i] = prev[i]->forward[i];
      prev[i]->forward[i] = x;
    }
  }

  void remove(const int key) {
    std::vector<Node *> prev(MAX_LEVEL, nullptr);
    Node *x = header;
    for (int i = level - 1; i >= 0; --i) {
      while (x->forward[i]->key < key) {
        x = x->forward[i];
      }
      prev[i] = x;
    }
    x = x->forward[0];

    if (x->key != key) {
      return;
    }

    for (int i = 0; i < level; ++i) {
      if (prev[i]->forward[i] != x) {
        break;
      }
      prev[i]->forward[i] = x->forward[i];
    }
    delete x;

    while (level > 1 && header->forward[level - 1] == nil) {
      --level;
    }
  }

  void print() {
    for (int i = level - 1; i >= 0; --i) {
      std::cout << "(LEVEL " << i << ") ";
      std::cout << "HEADER ";
      Node *x = header->forward[i];
      while (x != nil) {
        std::cout << x->key << ' ';
        x = x->forward[i];
      }
      std::cout << "NIL\n";
    }
    std::cout << '\n';
  }

 private:
  const double p;
  int level;
  Node *header = nullptr;
  Node *nil = nullptr;

  int random_level() {
    int lvl = 1;
    static auto dice = std::bind(std::uniform_real_distribution<double>(0., 1.),
                                 std::default_random_engine());
    while (dice() < p && lvl < MAX_LEVEL) {
      ++lvl;
    }
    return lvl;
  }
};

#endif  // SKIPLIST_HPP_