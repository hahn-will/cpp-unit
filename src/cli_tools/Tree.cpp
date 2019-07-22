#include "Tree.hpp"

Tree::Tree(const string value, Tree *parent) : stored_value(value),
                                               parent(parent) {
}

bool Tree::IsRoot() {
  return children.size() != 0;
}

const string Tree::GetValue() {
  return stored_value;
}

Tree *Tree::AddSibling() {
  if (!parent) {
    parent = new Tree("");
    parent->AddChild(this);
  }

  return nullptr;
}

void Tree::AddParent() {

}

// Change AddChild signature, finish the addSibling/addparent

void Tree::AddChild() {

}

void Tree::DFSTraversal(function<void(string)> executed_function) {
  executed_function(stored_value);

  for (Tree *&t : children) {
    t->DFSTraversal(executed_function);
  }
}
