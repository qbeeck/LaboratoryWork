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

void Menu(int &choice) {
  int tempUserChoice = 0;
  while (true) {
    cout << "\n\tUser Menu:" << endl;
    cout << "1. Add memory for N number of movies " << endl; /* + */
    cout << "2. Enter from Keyboard"<< endl; /* + */
    cout << "3. Search movie"<< endl; /* + */
    cout << "4. Sort by year"<< endl; /* + */
    cout << "5. Edit movie description"<< endl; /* + */
    cout << "6. Add movie to the end of the list"<< endl; /* + */
    cout << "7. Delete movie"<< endl; /* + */
    cout << "8. Add movie to N position"<< endl; /* + */
    cout << "9. Write list to txt"<< endl;
    cout << "10. Read list from txt"<< endl;
    cout << "11. Display the list"<< endl; /* + */
    cout << "12. Free up memory"<< endl; /* + */
    cout << "13. Close program\n"<< endl; /* + */

    cout << "Your variant: ";
    cin >> tempUserChoice;
    
    if (tempUserChoice > 0 && tempUserChoice < 14) {
      break;
    }
  };
  choice = tempUserChoice;
}

void callFunction(Movie * &Obj, int &ammount, int &desiredAmmount, const int choice) {
  switch (choice) {
    case 1: 
      addMemory(Obj, ammount, desiredAmmount);
      break;
    case 2: 
      enterElements(Obj, ammount, desiredAmmount);
      break;
    case 3: 
      searchMovie(Obj, ammount);
      break;
    case 4: 
      sortByYear(Obj, ammount);
      break;
    case 5: 
      editDescription(Obj, ammount);
      break;
    case 6: 
      addMovieToTheEnd(Obj, ammount);
      break;
    case 7: 
      deleteMovie(Obj, ammount);
      break;
    case 8: 
      addMovieToNpos(Obj, ammount);
      break;
    case 9: 
      addListInTxt(Obj, ammount);
      break;
    case 10: 
      readListFromTxt(Obj, ammount);
      break;
    case 11: 
      displayList(Obj, ammount);
      break;
    case 12: 
      deleteMemory(Obj, ammount);
      break;
  }
}

void addMemory(Movie * &Obj, int &ammount, int &desiredAmmount) {
  int desiredNumber = 0;
  cout << "Desired number of films : ";
  cin >> desiredNumber;

  desiredAmmount = desiredNumber;
  Obj = new Movie[desiredNumber];
}

void enterElements(Movie * &Obj, int &ammount, int &desiredAmmount) {
  int YesOrNot = 1;
  for (int i = 0; i < desiredAmmount; i++) {
    cout << "Movie Title: ";
    cin >> Obj[i].title;
    cout << "Movie Country: ";
    cin >> Obj[i].country;
    cout << "Movie Director: ";
    cin >> Obj[i].director;
    cout << "Movie Genre: ";
    cin >> Obj[i].genre;
    cout << "Movie Year: ";
    cin >> Obj[i].year;
    ammount++;

    if ((i + 1) == desiredAmmount) {
      YesOrNot = 0; 
    } else {
      cout << "Add one more Movie? (anything - yes, 0 - no) : ";
      cin >> YesOrNot;
    }

    if (YesOrNot == 0) {
      break;
    }
  }
}

void searchMovie(Movie * &Obj, const int ammount) {
  string userVariant;
  int filmFound = 0;

  cout << "Enter film title : ";
  cin >> userVariant;

  for (int i = 0; i < ammount; i++) {
    if (userVariant.compare(Obj[i].title) == 0) {
      filmFound = 1;
      cout << "\n\tYeah. There is such a movie :" << endl;
      cout << "Title: " << Obj[i].title << endl;
      cout << "Director: " << Obj[i].director << endl;
      cout << "Country: " << Obj[i].country << endl;
      cout << "Genre: " << Obj[i].genre << endl;
      cout << "Year: " << Obj[i].year << endl;
    }
  }
  
  if (filmFound == 0) {
    cout << "\nNot found movie with this title" << endl;
  }

}

void sortByYear(Movie * Obj, const int ammount) {
  Movie tempStructure;

  for (int i = ammount - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (Obj[j].year > Obj[j + 1].year) {
        tempStructure = Obj[j];
        Obj[j] = Obj[j + 1];
        Obj[j + 1] = tempStructure;
      }
    }
  }

  cout << "\nMovies sorted (oldest to new)" << endl;
}

void addMovieToTheEnd(Movie * &Obj, int &ammount) {
  cout << "\n\tEnter new Movie description : " << endl;

  Movie * tempObj = new Movie[ammount + 1];
  for (int i = 0; i < ammount; i++) {
    tempObj[i] = Obj[i];
  }

  cout << "Movie Title: ";
  cin >> tempObj[ammount].title;
  cout << "Movie Country: ";
  cin >> tempObj[ammount].country;
  cout << "Movie Director: ";
  cin >> tempObj[ammount].director;
  cout << "Movie Genre: ";
  cin >> tempObj[ammount].genre;
  cout << "Movie Year: ";
  cin >> tempObj[ammount].year;

  if (ammount == 0) {
    Obj = tempObj;
  } else {
    delete [] Obj;
    Obj = tempObj;
  }

  ammount++;
}

void editDescription(Movie * &Obj, const int ammount) {
  int userVariant = 0;
  while (true) {
    cout << "Which element do you want to edit? : ";
    cin >> userVariant;

    if (userVariant <= 0 || userVariant > ammount) {
      cout << "\nNo such element exists, again" << endl;
    } else {
      break;
    }
  }
  
  cout << "\nTitle: ";
  cin >> Obj[userVariant].title;
  cout << "Director: "; 
  cin >> Obj[userVariant].director;
  cout << "Country: "; 
  cin >> Obj[userVariant].country;
  cout << "Genre: "; 
  cin >> Obj[userVariant].genre;
  cout << "Year: "; 
  cin >>Obj[userVariant].year;
}

void displayList(Movie * &Obj, int &ammount) {
  if (Obj != 0) {
    for (int i = 0; i < ammount; i++) {
      cout << "\nTitle: " << Obj[i].title << endl;
      cout << "Director: " << Obj[i].director << endl;
      cout << "Country: " << Obj[i].country << endl;
      cout << "Genre: " << Obj[i].genre << endl;
      cout << "Year: " << Obj[i].year << endl;
    }
  }
}

void deleteMovie(Movie * &Obj, int &ammount) {
  int userVariant = 0;
  while (true) {
    cout << "Which element do you want to remove? : ";
    cin >> userVariant;

    if (userVariant <= 0 || userVariant > ammount) {
      cout << "\nNo such element exists, again" << endl;
    } else {
      break;
    }
  }
  
  Movie * tempObj = new Movie[ammount - 1];
  ammount--;

  for (int i = userVariant - 1; i < ammount; i++) {
    Obj[i] = Obj[i + 1];
  }

  for (int j = 0; j < ammount; j++) {
    tempObj[j] = Obj[j];
  }

  delete [] Obj;
  Obj = tempObj;

  cout << "\nReady" << endl;
}

void addListInTxt(Movie * &Obj, int &ammount) {
  ofstream fout("labrab6.txt");
  for (int i = 0; i < ammount; i++) {
    fout << Obj[i].title << endl;
    fout << Obj[i].director << endl;
    fout << Obj[i].country << endl;
    fout << Obj[i].genre << endl;
    fout << Obj[i].year << endl;
  }
  fout.close();
  cout << "\nReady" << endl;
}

void readListFromTxt(Movie * &Obj, int &ammount) {
  ifstream fin("labrab6.txt");
  string forCounter;
  int ammountStr = 0;  /* кол-во строк в файле */
  int i = 0;

  while (getline(fin, forCounter)) {
    ammountStr++;  
  }
  fin.close();

  Obj = new Movie[ammountStr / 5];

  ifstream q("labrab6.txt");
  while (true) {
    getline(q, Obj[i].title);
    getline(q, Obj[i].country);
    getline(q, Obj[i].director);
    getline(q, Obj[i].genre);
    getline(q, Obj[i].year);
    i++;
    if (i == ammountStr / 5) {
      break;
    }
  }

  ammount = ammountStr / 5;
  cout << "\nReady" << endl;
}

void addMovieToNpos(Movie * &Obj, int &ammount) {
  int userVariant = 0;
  while (true) {
    cout << "In which position do you want to add movie? : ";
    cin >> userVariant;

    if (userVariant <= 0 || userVariant > ammount) {
      cout << "\nNo such element exists, again" << endl;
    } else {
      break;
    }
  }

  Movie * tempObj = new Movie[ammount + 1];
  for (int i = 0; i < userVariant - 1; i++) {
    tempObj[i] = Obj[i];
  }

  cout << "\n\tEnter movie description" << endl;
  cout << "Movie Title: ";
  cin >> tempObj[userVariant - 1].title;
  cout << "Movie Country: ";
  cin >> tempObj[userVariant - 1].country;
  cout << "Movie Director: ";
  cin >> tempObj[userVariant - 1].director;
  cout << "Movie Genre: ";
  cin >> tempObj[userVariant - 1].genre;
  cout << "Movie Year: ";
  cin >> tempObj[userVariant - 1].year;

  for (int i = userVariant; i < ammount + 1; i++) {
    tempObj[i] = Obj[i - 1];
  }

  ammount++;

  delete [] Obj;
  Obj = tempObj;
}

void deleteMemory(Movie *& Obj, int &ammount) {
  ammount = 0;
  delete [] Obj;

  cout << "\nReady" << endl;
}
