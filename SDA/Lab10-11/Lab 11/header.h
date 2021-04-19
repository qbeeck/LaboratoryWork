#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
struct node {
  std::string key;
  node* left;
  node* right;
};

struct nd {
  double date;
  nd* next;
};

nd* Head;

void Push_nd(double date);
void Print_nd();
int Priority(char c);
double Pop();
node * MakeTree(string * Term, size_t first, size_t last);
void LPK(node* Tree);
bool isOperandSym(int ch);
size_t SizeTree(const string& s, size_t n);
string Input_perem(const string &s);
void MakeTerm(string* Term, size_t n, const string& s, int* k);
void output(node * root);
int maxDepth(node * root);
int countNodes(node * root);