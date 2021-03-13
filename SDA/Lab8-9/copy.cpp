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
};

void List::addElement(string fileName) {
  ifstream fin(fileName);
  string forCounter;
  int ammountStr = 0;  

  while (getline(fin, forCounter)) {
    ammountStr++;  
  }
  fin.close();

  ifstream q(fileName);

  while (length < ammountStr / 5) {
    Movie * temp = new Movie;

    getline(q, temp->Title);
    getline(q, temp->Director);
    getline(q, temp->Country);
    getline(q, temp->Genre);
    getline(q, temp->Year);

    if (length == 0) {
      first = temp;
      last = temp;
      first->next = last;
      last->next = first;
    } else {
      last->next = temp;
      last = temp;
    }
    length++;
  }
}

void List::show() {
  int node = 0;
  
  if (length == 0) {
    cout << "\nEmpty list" << endl;
  } else {
    Movie * temp = first;

    while (node < length) {
      cout << "\n------- Show result " << node + 1 << "------" << endl;
      cout << "Title : " << temp->Title << endl;
      cout << "Country : " << temp->Country << endl;
      cout << "Director : " << temp->Director << endl;
      cout << "Genre : " << temp->Genre << endl;
      cout << "Year : " << temp->Year << endl;
      cout << "----------------------------" << endl;

      temp = temp->next;
      node++;
    }
  }
}

void List::search(string title) {
  Movie * temp = new Movie;
  int currentPosition = 1;
  int status = 0;

  temp = first;

  while (currentPosition <= length) {
    if (title == temp->Title) {
      cout << "\n------- Search result ------ " << endl;
      cout << "Title : " << temp->Title << endl;
      cout << "Country : " << temp->Country << endl;
      cout << "Director : " << temp->Director << endl;
      cout << "Genre : " << temp->Genre << endl;
      cout << "Year : " << temp->Year << endl;
      cout << "----------------------------" << endl;
      status = 1;
      break;
    } else {
      temp = temp->next;
      currentPosition++;
    }
  }

  if (status == 0) {
    cout << "No movie with this Title in List" << endl;
  }
}

void List::editMovieDescription(string fileName, const int position) {
  if (position > length || position < 1) {
    cout << "\nWrong position" << endl;
  } else {
    ifstream fin(fileName);
    Movie * temp = new Movie;

    while (true) {
      getline(fin, temp->Title);
      getline(fin, temp->Director);
      getline(fin, temp->Country);
      getline(fin, temp->Genre);
      getline(fin, temp->Year);

      break;
    }
    fin.close();

    int currentPosition = 1;

    Movie * counter = new Movie;

    counter = first;
    if (currentPosition != position) {
      counter = counter->next;
      currentPosition++;
    }

    counter->Title = temp->Title;
    counter->Country = temp->Country;
    counter->Director = temp->Director;
    counter->Year = temp->Year;
    counter->Genre = temp->Genre;
  }
}

void List::exchangeTwoElements(const int firstPos, const int secondPos) {
  if (firstPos > length || firstPos < 1) {
    cout << "\nWrong position №1" << endl;
  } else if (secondPos > length || secondPos < 1) {
    cout << "\nWrong position №2" << endl;
  } else if (firstPos == secondPos) {
    cout << "\nThe same positions" << endl;
  } else {
    Movie * firstEl = new Movie;
    Movie * secondEl = new Movie;
    int currentPosition = 1;

    firstEl = first;
    while (currentPosition != firstPos) {
      firstEl = firstEl->next;
      currentPosition++;
    }
    currentPosition = 1;

    secondEl = first;
    while (currentPosition != secondPos) {
      secondEl = secondEl->next;
      currentPosition++;
    }

    swap(firstEl->Country, secondEl->Country);
    swap(firstEl->Title, secondEl->Title);
    swap(firstEl->Genre, secondEl->Genre);
    swap(firstEl->Director, secondEl->Director);
    swap(firstEl->Year, secondEl->Year);
  }
}

void List::deleteMemory() {
  Movie* temp = new Movie;
  int i = 0;

  while (i < length) {
    temp = first->next;
    delete first;
    first = temp;
    i++;
  }
  length = 0;
}

void List::addMovieToNPosition(string fileName, const int position) {
  if (position > length || position < 1) {
    cout << "\nWrong position" << endl;
  } else {
    ifstream fin(fileName);
    Movie * value = new Movie;

     while (true) {
      getline(fin, value->Title);
      getline(fin, value->Director);
      getline(fin, value->Country);
      getline(fin, value->Genre);
      getline(fin, value->Year);

      break;
    }

    fin.close();

    Movie * temp = new Movie;
    Movie * prepos = new Movie;
    Movie * pos = new Movie;
    int currentPosition = 1;

    temp = first;
    while (true) {
      if (currentPosition != position - 1) {
        temp = temp->next;
        currentPosition++;
      } else {
        prepos = temp;
        currentPosition++;
        pos = temp->next;
        break;
      }
    }
    value->next = pos;
    prepos->next = value;
    length++;
  }
}

int List::lengthList() {
  Movie * temp = first;
  int currentPosition = 0;

  while (temp != last->next) {
    temp = temp->next;
    currentPosition++;
  }

  return currentPosition;
}

void List::writeToTheFile(string filename) {
  if (length == 0) {
    cout << "List is empty" << endl;
  } else {
    ofstream fout(filename, std::ios_base::out);
    Movie * temp = first;
    
    while (temp != last->next) {
      fout << temp->Title << endl;
      fout << temp->Director << endl;
      fout << temp->Country << endl;
      fout << temp->Genre << endl;
      fout << temp->Year << endl;
      temp = temp->next;
    }
    fout.close();
  }
}

void List::readFromFile(string filename) {
  ifstream fin(filename);
  string forCounter;
  int ammountStr = 0;  
  int i = 0;

  while (getline(fin, forCounter)) {
    ammountStr++;  
  }
  fin.close();

  ifstream q(filename);

  while (length < ammountStr / 5) {
    Movie * temp = new Movie;

    getline(q, temp->Title);
    getline(q, temp->Director);
    getline(q, temp->Country);
    getline(q, temp->Genre);
    getline(q, temp->Year);

    if (length == 0) {
    first = temp;
    last = temp;
    first->next = last;
    last->next = first;
  } else {
    last->next = temp;
    last = temp;
  }
  length++;
  }
}

Movie* List::firstPos() {
  return first;
}

void List::mergeTwoLists(List listName) {
  Movie * test = (listName.firstPos)();
  cout << "test " << test << endl;

  last->next = test;
  length += lengthList();
}


int main () {
  List firstList;
  List secondList;
  
// 7. Сортировка
// 11. разделение списка на два
}