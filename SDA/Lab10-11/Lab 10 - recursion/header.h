struct Node {
  std::string Title;
  std::string Director;
  std::string Genre;
  std::string Country;
  std::string Year;

  Node *left;
  Node *right;
};

void addElementToTree(Node ** root, std::string T, std::string D, std::string G, std::string C, std::string Y);
void addNode(Node ** root, Node * newNode);
void output(Node * root);
void search(Node * root, std::string year);
void cleanMemory(Node * root);
int maxDepth(Node * root);
int countNodes(Node * root);
