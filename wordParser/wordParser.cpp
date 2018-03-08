#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void parseFile(string filename, vector<string>&);
void printMenu(vector<string>&);
void printParsedWords(vector<string>&);

int main() {
   string filename;
   vector <string>parsedWords;
   
   do {
      cout << "Enter name of file that needs to be parsed(add .txt after the files name): ";
      cin >> filename;
      
      parseFile(filename, parsedWords);
   
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

void printMenu() {
   char userInput;
   cout << "Enter a number to execute a command." << endl;
   cout << "1 - Print all parsed words" << endl;
   cout << "2 - Sort parsed words in alphabetical order" << endl;
   cout << "3 - Sort parsed words from z-a" << endl;
   cout << "'q' / 'Q' - Exit out of program" << endl;
   
   if(userInput == '1') {
      
   }
   else if(userInput == '2') {
      
   }
   else if(userInput == '3') {
      
   }
   else if(userInput == '4') {
      
   }
   else {
      cout << "Invalid Input!" << endl;
   }
   
   return;
}

void printParsedWords(vector<string>& parsedWords) {
   for(int i = 0; i < parsedWords.size(); ++i) {
         cout << parsedWords.at(i) << endl;
   }
   
   return;
}