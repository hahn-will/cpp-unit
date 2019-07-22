#ifndef TREE_HPP__
#define TREE_HPP__

#include <string>
#include <vector>

using namespace std;

class Tree {
  public:
    Tree(const string, Tree * = nullptr);
    bool IsRoot();
    const string GetValue();
    void AddSibling();
    void AddParent();
    void AddChild();
  private:
    bool is_holder_parent;
    string stored_value;
    vector<Tree *> children;
    Tree *parent;
};

#endif
