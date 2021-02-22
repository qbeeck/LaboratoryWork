#include "header.h"

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