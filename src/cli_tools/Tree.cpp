#include "Tree.hpp"

Tree::Tree(const string value, Tree *parent) : stored_value(value),
                                               parent(parent) {
}

bool Tree::IsRoot() {
  return children.size() != 0;
}
