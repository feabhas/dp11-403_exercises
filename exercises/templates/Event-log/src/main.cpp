// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DateTime.h"
#include "EventLogParser.h"

#include <iostream>
#include <fstream>

using std::cout;

int main() {
  cout << "Design Patterns\n";

  cout << DateTime::now() << '\n';

  {
    std::string filename{"log.txt"}; // Can be opened by Notepad

    // Open a new output file stream object with name "myFile.txt"
    // Open the file for truncation.
    std::ofstream MyFile{filename, std::ios_base::trunc};

    // Stream to the file object
    MyFile << "Line 1\n";
    MyFile << "Line 2\n";
    MyFile << "Line 3\n";
  } // file closed

  // EventLogParser elp{};
  // elp.construct("log.txt");
}
