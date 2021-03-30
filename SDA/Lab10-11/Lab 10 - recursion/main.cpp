#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main() {
  Node * tree = NULL;

  addElementToTree(&tree, "Artiom", "Olari", "Krek", "Jopa", "2000");
  addElementToTree(&tree, "Anja", "asdas", "1231", "12", "2001");
  addElementToTree(&tree, "Sereja", "asd", "dasd", "dsfsd", "1999");
  addElementToTree(&tree, "Lesha", "asasdd", "ddsdasd", "assadas", "1998");
  output(tree);
  search(tree, "1998");
  cout << "\nHeight tree : " << maxDepth(tree) << endl;
  cout << "\nCount nodes : " << countNodes(tree) << endl;
  cleanMemory(tree);
}
