#include <fstream>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <sys/stat.h>
using namespace std;

int main()
{
    cout << "This program reads text from file input.txt, redacts SSN's via regex, and saves to output.txt" << endl;

    /*The process for iterating through files in a given folder is apparently different between Windows and Linux
    So for now this program only redacts the specified file. In this case; the included input.txt


    I believe this code block will enable directory creation for the output results in Windows
    mkdir("/newFolder", NULL);
    cout << "Enter the filename/path: " << endl;
    cin >> filePath;

    ifstream inputFileStream(filePath);
    ofstream outputFileStream("/newFolder/output.txt");

    */

    ifstream inputFileStream("input.txt");
    ofstream outputFileStream("output.txt");

    regex regSNN("([0-9]{3}-[0-9]{2}-[0-9]{4})");  //Regular expression for SSN
    string replacementString("XXX-XX-XXXX");

    if (!inputFileStream){
        cerr << "Could not open input file " << endl;
        return 1;
    }
    if (!outputFileStream){
        cerr << "Could not open output file " << endl;
        return 1;
    }

    string str;
    while (getline(inputFileStream, str))
    {
        str = regex_replace(str, regSNN, replacementString);
        outputFileStream << str << '\n';
    }
}