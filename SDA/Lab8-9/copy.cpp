#include <iostream>
#include <string>

using namespace std;

struct Movie {
  string Title;
  string Country;
  string Director;
  string Genre;
  int Year;

  Movie *next;
};

class List {
  private:
    Movie *first;
    Movie *last;
    int length;
  public:
    List() : first(NULL), last(NULL), length(0) {};

    void menu(int &position);
    void userChoice(const int position);

    void addFromKeyboard(Movie * value);
    bool check__addFromKeyboard(Movie * value);

    void deleteMovie(Movie * value, const int position);
    bool check__deleteMovie(int &position);

    void show();
    void exit();
};

void List::menu(int &position) {
  cout << "\n-------- User menu ---------" << endl;
  cout << "1. Enter from Keyboard" << endl; /* + */
  cout << "2. Search movie" << endl;
  cout << "3. Sort by year" << endl;
  cout << "4. Edit movie description" << endl;
  cout << "5. Add movie to the end of the list" << endl;
  cout << "6. Delete movie" << endl; /* + */
  cout << "7. Add movie to N position" << endl;
  cout << "8. Write list to txt" << endl;
  cout << "9. Read list from txt" << endl;
  cout << "10. Display the list" << endl; /* + */
  cout << "11. Close program" << endl; /* + */
  cout << "----------------------------\n";

  cout << "Your choice : ";
  cin >> position;
  cout << endl;
}

void List::userChoice(const int position) {
  switch (position) {
    case 1: {
      Movie * temp = new Movie;

      if (check__addFromKeyboard(temp)) {
        addFromKeyboard(temp);
      }
      break;
    }
    case 5: {
      Movie * temp = new Movie;

      if (check__addFromKeyboard(temp)) {
        addFromKeyboard(temp);
      }
      break;
    }
    case 6: {
      Movie * temp = new Movie;
      int position = 0;

      if (check__deleteMovie(position)) {
        deleteMovie(temp, position);
      }
      break;
    }
    case 7: 
      
      break;
    case 10: 
      show();
      break;
    case 11: 
      exit();
      break;
    default:
      cout << "There is no such variant" << endl;
      break;
  }
}

void List::addFromKeyboard(Movie * value) {
  if (length == 0) {
    first = value;
    last = value;
    first->next = last;
    last->next = first;
  } else {
    last->next = value;
    last = value;
  }
  length++;
}

bool List::check__addFromKeyboard(Movie * value) {
  cout << "Movie Title : ";
  cin >> value->Title;
  cout << "Movie Country : ";
  cin >> value->Country;
  cout << "Movie Director : ";
  cin >> value->Director;
  cout << "Movie Genre : ";
  cin >> value->Genre;
  cout << "Movie Year : ";
  cin >> value->Year;
  cout << endl;
}

void List::show() {
  int node = 0;
  
  if (length == 0) {
    cout << "\nEmpty list" << endl;
  } else {
    Movie * temp = first;

    while (node < length) {
      cout << "----------------------------" << endl;
      cout << "Title : " << temp->Title << endl;
      cout << "Country : " << temp->Country << endl;
      cout << "Director : " << temp->Director << endl;
      cout << "Genre : " << temp->Genre << endl;
      cout << "Year : " << temp->Year << endl;
      cout << "----------------------------" << endl;

      temp = temp->next;
      node++;
    }
    cout << endl;
  }
}

bool List::check__deleteMovie(int &position) {
  while (true) {
    cout << "Which element delete ? : ";
    cin >> position;

    if (position > length || position < 0) {
      cout << "Wrong element" << endl;
    } else {
      break;
    }
  }
}

void List::deleteMovie(Movie * value, const int position) {
  if (position == 1) {
    value = first;
    first = first->next;
    delete value;
    length--;
  } else {
    int currentPosition = 1;
    value = first;
    while (currentPosition != position - 1) {
      value = value->next;
      currentPosition++;
    }
    Movie* delElement = value->next;
    value->next = delElement->next;
    delete delElement;
    length--;
  }
}

void List::exit() {
  Movie* temp = new Movie;
  int i = 0;

  while (i < length) {
    temp = first->next;
    delete first;
    first = temp;
    i++;
  }

  first = NULL;
  last = NULL;
  length = 0;
}

int main () {
  List newList;
  int choice = 0;

  while (choice != 11) {
    newList.menu(choice);
    newList.userChoice(choice);
  }
}