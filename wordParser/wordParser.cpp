#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void parseFile(string filename, vector<string>&);
void printMenu(vector<string>&);
void printParsedWords(vector<string>&);
void a2zSort(vector<string>&);
void z2zSort(vector<string>&);

int main() {
   string filename;
   vector <string>parsedWords;
   
   do {
      cout << "Enter name of file that needs to be parsed(add .txt after the files name): ";
      cin >> filename;
      
      parseFile(filename, parsedWords);
      
      cout << endl;
   
      printMenu(parsedWords);
      
      break; //you'll never reach here unless the user inputs the quit command in the menu
   } while(true);
   
   return 0;
}

void parseFile(string filename, vector<string>& parsedWords) {
   ifstream readFile;
   string word;
   bool isFirstWord = true;
   
   cout << "Opening file " << filename << endl;
   
   readFile.open(filename.c_str());
   if (!readFile.is_open()) {
      cout << "Could not open file " << filename << endl;
      return; 
   }
   
   while(getline(readFile, word)) { //read one line and get the first word of that line
      parsedWords.push_back(word.substr(0, word.find(' ')));
   }
   
   return;
}

void printMenu(vector<string>& parsedWords) {
   while(1) {
      char userInput;
      
      cout << "Enter a number to execute a command." << endl;
      cout << "1 - Print all parsed words" << endl;
      cout << "2 - Sort parsed words in alphabetical order" << endl;
      cout << "3 - Sort parsed words from z-a" << endl;
      cout << "'q' / 'Q' - Exit out of program" << endl;
      
      cout << "Enter input: ";
      cin >> userInput;
      cout << endl;
      
      if(userInput == '1') {
         printParsedWords(parsedWords);
         cout << endl;
      }
      else if(userInput == '2') {
         a2zSort(parsedWords);
      }
      else if(userInput == '3') {
         z2zSort(parsedWords);
      }
      else if(userInput == 'q') {
         return;
      }
      else {
         cout << "Invalid Input!" << endl;
      }
   }
   return;
}

void printParsedWords(vector<string>& parsedWords) {
   for(int i = 0; i < parsedWords.size(); ++i) {
         cout << parsedWords.at(i) << endl;
   }
   
   return;
}

void a2zSort(vector<string>& parsedWords) {
   for (int i = 0; i < parsedWords.size() - 1; i++) {
      for (int j = 0; j < parsedWords.size() - i - 1; j++) {
         if (parsedWords.at(j) > parsedWords.at(j + 1)) {
           string temp = parsedWords.at(j);
           parsedWords.at(j) = parsedWords.at(j + 1);
           parsedWords.at(j + 1) = temp;
         }
      }
   }         
}

void z2zSort(vector<string>& parsedWords) {
   for (int i = 0; i < parsedWords.size() - 1; i++) {
      for (int j = 0; j < parsedWords.size() - i - 1; j++) {
         if (parsedWords.at(j) < parsedWords.at(j + 1)) {
           string temp = parsedWords.at(j);
           parsedWords.at(j) = parsedWords.at(j + 1);
           parsedWords.at(j + 1) = temp;
         }
      }
   }         
}