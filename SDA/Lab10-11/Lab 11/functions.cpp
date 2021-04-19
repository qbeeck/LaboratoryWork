using namespace std;

void Push_nd(double date) {
  nd* temp = new nd;
  temp->date = date;
  temp->next = Head;
  Head = temp;
  return;
}

void Print_nd() {
  nd* q = Head;
  while (q) {
    cout << "\nRezult: " << q->date;
    q = q->next;
  }

  return;
}

int Priority(char c) {
  switch (c) {
    case '%':return 5;
    case '^':return 4;
    case '+':case '-':return 2;
    case '*':case '/':return 3;
  }

  return 1000;
}

double Pop() {
  if (Head == 0) return 0;
  double i = Head->date;
  Head = Head->next;

  return i;
}

node * MakeTree(string * Term, size_t first, size_t last) {
  int nest = 0;
  node * Tree = new node;
  if (first == last) {
    Tree->key = Term[first];
    Tree->left = Tree->right = 0;
    return Tree;
  }

  int minprt = 100;
  size_t k;

  for (size_t i = first; i <= last; i++) {
    size_t size_perem = Term[i].size();
    int prt;
    if (size_perem > 1) {
      prt = 100;
      if (prt <= minprt) {
        minprt = prt;
        k = i;
      }
    } else {
        char c = Term[i][0];
        if (c == '(') {
          nest++; continue; 
        }
        if (c == ')') {
          nest--; continue; 
        }
        if (nest > 0) {
          continue; 
        }

        prt = Priority(c);

        if (prt <= minprt) {
          minprt = prt;
          k = i; 
        }
      }
    }

    if (minprt == 100 && Term[first][0] == '(' && Term[last][0] == ')') {
      return MakeTree(Term, first + 1, last - 1);
    }

    Tree->key = Term[k];
    Tree->left = MakeTree(Term, first, k - 1);
    Tree->right = MakeTree(Term, k + 1, last);
    return Tree;
}

void LPK(node* Tree) {
  if (!Tree) return;

  LPK(Tree->left);
  LPK(Tree->right);
  cout << Tree->key << "|";
  if (Tree->key.size() > 1 || isdigit(Tree->key[0])) {
    char* date;
    date = new char[Tree->key.size()];
    for (int i = 0; i < Tree->key.size(); i++) {
      date[i] = Tree->key[i];
    }
    Push_nd(atof(date));
    delete date;
  }

  if (Tree->key == "+") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(x1 + x2);
  }
  if (Tree->key == "-") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(x2 - x1);
  }
  if (Tree->key == "/") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(x2 / x1);
  }
  if (Tree->key == "*") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(x1 * x2);
  }
  if (Tree->key == "^") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(pow(x2, x1));
  }
  if (Tree->key == "%") {
    double x1 = Pop();
    double x2 = Pop();
    Push_nd(fmod(x2, x1));
  }
  return;
}
 
bool isOperandSym(int ch) {
  return isalnum(ch) || ch == '_' || ch == '.' || ch == ',';
}
 
size_t SizeTree(const string& s, size_t n) {
  size_t p = 0;
  bool inTerm = false;
  for (int i = 0; i < n; i++) {
    if (isOperandSym(s[i])) {
      if (!inTerm) {
        inTerm = true;
        ++p;
      }
    } else {
        if (inTerm) inTerm = false;
        if (!isspace(s[i])) ++p;
      }
    }
    return p;
}

string Input_perem(const string &s) {
  cout << "Znacenie peremennoi:" << s << endl;
  string name_perem;
  cin >> name_perem;
  return name_perem;
}

void MakeTerm(string* Term, size_t n, const string& s, int* k) {
  for (int i = 0; i < n; i++) {
    if (isOperandSym(s[i])) {
      char name[100] = "";
      int z = 0;
      while (isOperandSym(s[i]) && i < n) {
        name[z] = s[i];
        z++;
        i++;
      }

      string name1 = name;
      size_t size_name = name1.size();
      int date_or_name = 1;
      if (size_name == 1) {
        if (isdigit(name[0])) {
          Term[(*k)] = name;
          (*k)++;
        } else {
          string name_perem = Input_perem(name1);
          Term[(*k)] = name_perem;
          (*k)++;
        }
      } else {
        date_or_name = 0;
        for (int i = 0; i < size_name; i++) {
          if (isdigit(name[i]) || name[i] == ',' || name[i] == '.') {
            date_or_name++;
          }
        }
        
        if (date_or_name != size_name) {
          string name_perem = Input_perem(name1);
          Term[(*k)] = name_perem;
          (*k)++;
        } else {
          Term[(*k)] = name;
          (*k)++;
        }
      }
    }
        
    if (s[i] == '(' || s[i] == ')') {
      Term[(*k)] = s[i];
      (*k)++;
    }

    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%') {
      Term[(*k)] = s[i];
      (*k)++;
    }
  }

  return;
}

void output(node * root) {
  if (root == nullptr) return;

  cout << "\n--------------- " << root << " ---------------" << endl;
  cout << "Key: " << root->key << endl;
  cout << "Left root: " << root->left << endl;
  cout << "Right root: " << root->right << endl;
  cout << "----------------------------------------" << endl;

  output(root->left);
  output(root->right);
}

int maxDepth(node * root) {
  if (root == nullptr) {
    return 0;
  } else {
    int leftNodes = maxDepth(root->left);
    int rightNodes = maxDepth(root->right);

    return (max(leftNodes, rightNodes) + 1);
  }
}

int countNodes(node * root) {