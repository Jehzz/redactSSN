#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string filePath;
    string str;
    string outFilePath;
    regex regSNN("([0-9]{3}-[0-9]{2}-[0-9]{4})");
    string replacementString("XXX-XX-XXXX");



    /*The process for iterating through files in a given folder is apparently different between Windows and Linux
    So for now this program only writes the results to a different file in the same folder

    //Create new folder to hold results
    mkdir("../input", 777);

    //and possibly a cross platform solution using boost
	boost::filesystem::path dir(filePath);
    boost::filesystem::create_directory(dir)

    */

    cout << "This program redacts SSN's via regex, and saves to another file" << endl;
    cout << "Enter the filename: " << endl;
    cin >> filePath;
    cout << "Enter the name for the redacted output: " << endl;
    cin >> outFilePath;

    ifstream inputFileStream(filePath);
    ofstream outputFileStream(outFilePath);

    if (!inputFileStream){
        cerr << "Could not open input file " << endl;
        return 1;
    }
    if (!outputFileStream){
        cerr << "Could not open output file " << endl;
        return 1;
    }

    while (getline(inputFileStream, str))                //Read input line-by-line
    {
        str = regex_replace(str, regSNN, replacementString);    //regex_replace searches for and replaces each match
        outputFileStream << str << '\n';                        //Save the edited string to the output
    }

    //close
    inputFileStream.close();
    outputFileStream.close();
    return 0;
}