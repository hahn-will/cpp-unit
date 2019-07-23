#ifndef TREE_HPP__
#define TREE_HPP__

#include <string>
#include <vector>
#include <functional>

using namespace std;

class Tree {
  public:
    Tree(const string, bool = false, Tree * = nullptr);
    ~Tree();
    bool IsRoot() const;
    const string GetValue();
    Tree *AddSibling(Tree *);
    Tree *AddParent(Tree *);
    Tree *AddChild(Tree *);
    void DFSTraversal(function<void(string, int)>) const;
  private:
    void DFSHelper(function<void(string, int)>, int) const;
    bool is_holder_parent;
    string stored_value;
    vector<Tree *> children;
    Tree *parent;
};

#endif
