#include "header.h"

int main() {
  Node * tree = NULL;

  addNode("filename.txt", &tree);
  output(tree);
  search(tree, "word");
  showheight(tree);
  showCountNodes(tree);
  cleanMemory(&tree);
}