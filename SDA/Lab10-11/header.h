#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node {
  string Title;
  string Director;
  string Genre;
  string Country;
  string Year;

  Node *left;
  Node *right;
};

void addNode(string fileName, Node ** root);
void output(Node * root);
void search(Node * root, string title);
void cleanMemory(Node ** root);
int heightTree(Node * root);
void showheight(Node * root);
int countNodes(Node * root);
void showCountNodes(Node * root);