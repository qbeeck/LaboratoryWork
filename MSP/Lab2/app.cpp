#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

void addAdjacencyList(vector <vector <int>> &adjList, int &rows) {
  cout << "Number of peaks? : ";
  cin >> rows;
  
  int peaksInRow = 0;
  int tempNum = 0;
  vector <int> row;

  for (int i = 0; i < rows; i++) {
    cout << "Numbers in a line? : ";
    cin >> peaksInRow;
    for (int j = 0; j < peaksInRow; j++) {
      cin >> tempNum;
      row.push_back(tempNum);
    }
    adjList.push_back(row);
    row.clear();
  }
}

int checkNumber(vector <int> partOfList, const int step) {
  if (partOfList.size() == 0) {
    return 0;
  } else {
    for (int i = 0; i < partOfList.size(); i++) {
      if (partOfList[i] == step + 1) {
        return 1;
      }
    }
    return 0;
  }
}

void adjacencyList_adjacencyMatrix(vector <vector <int>> &adjList, int** &array, int &rows) {
  array = new int*[rows]; 

  for (int i = 0; i < rows; i++) { 
    array[i] = new int[rows];
  }
  
  for (int i = 0; i < rows; i++) {
    vector <int> smallPart = adjList[i];
    for (int j = 0; j < rows; j++) {
      int temp = checkNumber(smallPart, j);
      array[i][j] = temp;
    }
  }
}

void BFS(int ** &array, queue<int> localQueue, int rows) {
  cout << "\n---------- BFS ----------" << endl;
  int temp[rows];
  for (int i = 0; i < rows; i++) {
    temp[i] = 0;
  }              

  localQueue.push(0); 
  while (!localQueue.empty()) {                               
    int node = localQueue.front(); 
    localQueue.pop();
    temp[node] = 2;
    for (int j = 0; j < rows; j++) { 
      if (array[node][j] == 1 && temp[j] == 0) {                     
        localQueue.push(j); 
        temp[j] = 1;        
      }
    }
    cout << node + 1 << endl; 
  }
  cout << "-------------------------" << endl;
}

void DFS(int ** &array, stack <int> localStack, int rows) {
  cout << "\n---------- DFS ----------" << endl;
  int temp[rows];
  for (int i = 0; i < 7; i++) {
    temp[i] = 0;
  }

  localStack.push(0); 
  while (!localStack.empty()) {                         
    int node = localStack.top(); 
    localStack.pop();
    if (temp[node] == 2) {
      continue;
    }
    temp[node] = 2; 
    for (int j = rows - 1; j >= 0; j--) { 
      if (array[node][j] == 1 && temp[j] != 2) {
        localStack.push(j);
        temp[j] = 1;
      }
    }
    cout << node + 1 << endl;
  }
  cout << "-------------------------" << endl;
}

int main() {
  int ** adjacencyMatrix = 0;
  int rows = 0;
  vector <vector <int>> adjacencyList;
  queue <int> bfsQueue;
  stack <int> dfsStack;

  addAdjacencyList(adjacencyList, rows);
  adjacencyList_adjacencyMatrix(adjacencyList, adjacencyMatrix, rows);
  BFS(adjacencyMatrix, bfsQueue, rows);
  DFS(adjacencyMatrix, dfsStack, rows);
}