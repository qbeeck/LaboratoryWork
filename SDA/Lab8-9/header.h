#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Movie {
  string Title;
  string Country;
  string Director;
  string Genre;
  string Year;

  Movie *next;
};

class List {
  private:
    Movie *first;
    Movie *last;
    int length;
  public:
    List() : first(NULL), last(NULL), length(0) {};

    void addElement(string fileName);
    void show();
    void search(string title);
    void editMovieDescription(string fileName, const int position);
    void exchangeTwoElements(const int firstPos, const int secondPos);
    void deleteMemory();
    void addMovieToNPosition(string fileName, const int position);
    int lengthList();
    void writeToTheFile(string filename);
    void readFromFile(string filename);
    Movie* firstPos();
    void mergeTwoLists(List listName);
    void twoLists(List listname);
    Movie * middle();
    void changeLength();
};