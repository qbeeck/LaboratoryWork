#include "header.h"

void addNode(string fileName, Node ** root) {
  Node * newNode = new Node;
  ifstream file(fileName);

  getline(file, newNode->Title);
  getline(file, newNode->Director);
  getline(file, newNode->Genre);
  getline(file, newNode->Country);
  getline(file, newNode->Year);

  newNode->left = NULL;
  newNode->right = NULL;

  if ((*root) != NULL) {
    if ((*root)->Year > newNode->Year) {
      addNode(fileName, &(*root)->left);
    } else if ((*root)->Year < newNode->Year) {
      addNode(fileName, &(*root)->right);
    }
  } else {
    (*root) = newNode;
  }
}

void output(Node * root) {
  if (root == NULL) return;

  cout << "\n--------------- " << root << " ---------------" << endl;
  cout << "Title: " << root->Title << endl;
  cout << "Director: " << root->Director << endl;
  cout << "Genre: " << root->Genre << endl;
  cout << "Country: " << root->Country << endl;
  cout << "Year: " << root->Year << endl << endl;
  cout << "Left root: " << root->left << endl;
  cout << "Right root: " << root->right << endl;
  cout << "----------------------------------------" << endl;

  output(root->left);
  output(root->right);
}

void search(Node * root, string title) {
  if (root == NULL) return;

  if (title == root->Title) {
    cout << "\n--------------- " << root << " ---------------" << endl;
  cout << "Title: " << root->Title << endl;
  cout << "Director: " << root->Director << endl;
  cout << "Genre: " << root->Genre << endl;
  cout << "Country: " << root->Country << endl;
  cout << "Year: " << root->Year << endl << endl;
  cout << "Left root: " << root->left << endl;
  cout << "Right root: " << root->right << endl;
  cout << "----------------------------------------" << endl;
  }

  search(root->left, title);
  search(root->right, title);
}

void cleanMemory(Node ** root) {
  if ((*root)->left) {
  cleanMemory(&(*root)->left);
  }

  if ((*root)->right) {
  cleanMemory(&(*root)->right);
  }

  delete *root;
  *root = NULL;
}

int heightTree(Node * root) {
  int heightLeft = 0;
  int heightRight = 0;
  int height = 0;

  if (root != NULL) {
    heightLeft = heightTree(root->left);
    heightRight = heightTree(root->right);
    ((heightLeft > heightRight) ? height = heightLeft + 1 : height = heightRight + 1);
  }
  return height;
}

void showheight(Node * root) {
  int length = heightTree(root);
  cout << "\nHeight tree : " << length << endl;
}

int countNodes(Node * root) {
  int leftNodes, rightNodes;

  if (root->left == NULL && root->right == NULL) {
    return 1;
  }

  (root->left != NULL) ? leftNodes = countNodes(root->left) : leftNodes = 0;
  (root->right != NULL) ? rightNodes = countNodes(root->right) : rightNodes = 0;

  return leftNodes + rightNodes + 1;
}

void showCountNodes(Node * root) {
  int count = countNodes(root);
  cout << "\nNodes : " << count << endl;
}