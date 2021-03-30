#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void addNode(Node ** root, Node * newNode) {
  if ((*root) != nullptr) {
    if ((*root)->Year > newNode->Year) {
      addNode(&(*root)->left, newNode);
    } else if ((*root)->Year < newNode->Year) {
      addNode(&(*root)->right, newNode);
    }
  } else {
    (*root) = newNode;
  }
}

void addElementToTree(Node ** root, string T, string D, string G, string C, string Y) {
  Node * newNode = new Node;

  newNode->Title = T;
  newNode->Director = D;
  newNode->Genre = G;
  newNode->Country = C;
  newNode->Year = Y;

  newNode->left = nullptr;
  newNode->right = nullptr;

  addNode(root, newNode);
}

void output(Node * root) {
  if (root == nullptr) return;

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

void search(Node * root, string year) {
  if (root == nullptr) return;

  if (year == root->Year) {
    cout << "\n--------------- " << root << " ---------------" << endl;
    cout << "Title: " << root->Title << endl;
    cout << "Director: " << root->Director << endl;
    cout << "Genre: " << root->Genre << endl;
    cout << "Country: " << root->Country << endl;
    cout << "Year: " << root->Year << endl << endl;
    cout << "Left root: " << root->left << endl;
    cout << "Right root: " << root->right << endl;
    cout << "----------------------------------------" << endl;
  } else if (root->Year > year) {
    search(root->left, year);
  } else {
    search(root->right, year);
  }
}

void cleanMemory(Node * root) {
  cout << root << endl;
  if (root != nullptr) {
    cleanMemory(root->left);
    cleanMemory(root->right);
  }

  delete root;
  root = nullptr;
}

int maxDepth(Node * root) {
  if (root == nullptr) {
    return 0;
  } else {
    int leftNodes = maxDepth(root->left);
    int rightNodes = maxDepth(root->right);

    return (max(leftNodes, rightNodes) + 1);
  }
}

int countNodes(Node * root) {
  int leftNodes, rightNodes;

  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }

  (root->left != nullptr) ? leftNodes = countNodes(root->left) : leftNodes = 0;
  (root->right != nullptr) ? rightNodes = countNodes(root->right) : rightNodes = 0;

  return leftNodes + rightNodes + 1;
}