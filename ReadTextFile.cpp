// Example to read a simple text file.
// Date created: 2019-05-01
// Contributor(s): Mark Moretto

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <windows.h>
#include <cstdio>


int main() {
    // Set console codepage to utf-8
    // TODO: This doesn't work perfectly, so a better solution is needed.
    SetConsoleCP(CP_UTF8); 

    std::string filename = "test1.txt"; // Name of text document in local directory.
    std::string contents; // Variable to hold streaming output.
    std::ifstream inFile; // Set input file stream constructor.
    inFile.open(filename); // Initialize constructor with file name.
    if (!inFile.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl; // Handle IO exception.
    }
    else {
        std::string line; // Create local string variable for handling input text.
        while (std::getline(inFile, line)) {
            std::istringstream iss(line); // Create input stream class instance.
            contents += iss.str(); // Append each line to contents string.
            contents.push_back('\n'); // Add newline to end of each line.
            std::cout << iss.str() << std::endl; // Print results to console.
        }
    }
    std::cout << "Length of file contents: " << contents.length() << std::endl; // Print length of file contents
    inFile.close(); // Close file once complete.
    return 0;
}