#ifndef TREE_HPP__
#define TREE_HPP__

#include <string>
#include <vector>
#include <functional>

using namespace std;

class Tree {
  public:
    Tree(const string, Tree * = nullptr);
    bool IsRoot();
    const string GetValue();
    Tree *AddSibling();
    void AddParent();
    void AddChild();
    void DFSTraversal(function<void(string)>);
  private:
    bool is_holder_parent;
    string stored_value;
    vector<Tree *> children;
    Tree *parent;
};

#endif
