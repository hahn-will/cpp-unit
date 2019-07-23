#include "Tree.hpp"

Tree::Tree(const string value,
           bool is_holder_parent,
           Tree *parent) : is_holder_parent(is_holder_parent),
                                    stored_value(value),
                                    parent(parent) {
}

Tree::~Tree() {
  for (Tree *&t : children) {
    delete (t);
  }
}

bool Tree::IsRoot() const {
  return parent == nullptr;
}

const string Tree::GetValue() {
  return stored_value;
}

Tree *Tree::AddSibling(Tree *sibling) {
  if (!parent) {
    parent = new Tree("", true);
    parent->AddChild(this);
  }

  parent->AddChild(sibling);
  return parent;
}

Tree *Tree::AddParent(Tree *parent) {
  if (parent)
    throw new std::runtime_error("The parent already exists");

  this->parent = parent;
  return this->parent;
}

Tree *Tree::AddChild(Tree *child) {
  children.push_back(child);
  child->parent = this;
  return this;
}

void Tree::DFSTraversal(function<void(string, int)> executed_function) const {
  DFSHelper(executed_function, IsRoot() &&is_holder_parent ? -1 : 0);
}

void Tree::DFSHelper(function<void(string, int)> exec, int depth) const {
  if (is_holder_parent)
    return;

  exec(stored_value, depth);

  for (Tree *const &t : children) { 
    t->DFSHelper(exec, depth + 1);
  }
}
