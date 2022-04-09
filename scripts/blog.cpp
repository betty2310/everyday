#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using std::string;

string getCurrentDate() {
    string currentDate, day, month, year;
    std::time_t t = std::time(0);  // get time now
    std::tm* now = std::localtime(&t);
    if (now->tm_mday < 10) {
        day = std::to_string(now->tm_mday);
        day = "0" + day;
    } else {
        day = std::to_string(now->tm_mday);
    }
    if (now->tm_mon < 10) {
        month = std::to_string(now->tm_mon + 1);
        month = "0" + month;
    } else {
        month = std::to_string(now->tm_mon + 1);
    }
    year = std::to_string(now->tm_year + 1900);
    currentDate = month + "." + day + "." + year;
    return currentDate;
}

string getTagName() {
    std::cout << "-> Enter tag name: ";
    string tagName;
    std::getline(std::cin, tagName);
    return tagName;
}

string getFileName() {
    std::cout << "-> Enter new today post name: ";
    string name;
    std::getline(std::cin, name);
    return name;
}
int main() {
    string name = getFileName();
    string tag = getTagName();
    string date = getCurrentDate();

    string fileName = date + " - " + tag + "/" + name;
    string path = "$HOME/everyday/notes/" + fileName;
    std::ofstream outfile(fileName);
    outfile << "my text here!" << std::endl;
    outfile.close();
    std::ofstream file;
    file.open(path);
    file << "hello world\n";
    file.close();
    return 0;
}
