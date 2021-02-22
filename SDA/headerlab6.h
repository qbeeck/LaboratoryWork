#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Movie {
  string title;
  string country;
  string director;
  string genre;
  string year;
};

void Menu(int &choice);
void callFunction(Movie * &Obj, int &ammount, int &desiredAmmount, const int choice);
void addMemory(Movie * &Obj, int &ammount, int &desiredAmmount);
void enterElements(Movie * &Obj, int &ammount, int &desiredAmmount);
void searchMovie(Movie * &Obj, const int ammount);
void sortByYear(Movie * Obj, const int ammount);
void editDescription(Movie * &Obj, const int ammount);
void addMovieToTheEnd(Movie * &Obj, int &ammount);
void deleteMovie(Movie * &Obj, int &ammount);
void addMovieToNpos(Movie * &Obj, int &ammount);
void addListInTxt(Movie * &Obj, int &ammount);
void readListFromTxt(Movie * &Obj, int &ammount);
void displayList(Movie * &Obj, int &ammount);
void deleteMemory(Movie * &Obj, int &ammount);

int main() {
  Movie * movieList = NULL;
  int ammountMovies = 0;
  int desiredAmmount = 0;
  int userChoice = 0;
  while (true) {
    Menu(userChoice);
    callFunction(movieList, ammountMovies, desiredAmmount, userChoice);

    if (userChoice == 13) {
      break;
    }
  }
}