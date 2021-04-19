#include "header.h";

int main() {
  size_t n;
  size_t size_term = 0;
  int k = 0;
  string s = "((1+((2+3)*(4+(5/6))))+((2*3)*(4-6)))";
  n = s.size();
  size_term = SizeTree(s, n);
  string* Term = new string[size_term];
  cout << "Term " << Term << endl;
  MakeTerm(Term, n, s, &k);
  node * Tree = MakeTree(Term, 0, size_term - 1);
  output(Tree);
  cout << "\nHeight tree: " << maxDepth(Tree) << endl;
  cout << "\nCount nodes : " << countNodes(Tree) << endl;
  LPK(Tree);
  Print_nd();
  return 0;
}