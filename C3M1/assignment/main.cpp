/*

This program reads the csv file "cs_student.csv",
which contains information about computer science students from a fictional university.

The CSV file contains 12 columns:
 1. (int) Student ID: Unique identifier for each student.
 2. (string) Name: Name of the student.
 3. (string) Gender: Gender of the student.
 4. (int) Age: Age of the student.
 5. (double) GPA: Grade Point Average of the student.
 6. (string) Major: Field of study within computer science.
 7. (string) Interested Domain: Area of interest within the field of computer science.
 8. (string) Projects: Noteworthy projects completed by the student.
 9. (string) Future Career: Intended career path or job aspiration.
10. (string) Python: Proficiency level in Python programming.
11. (string) SQL: Proficiency level in SQL querying.
12. (string) Java: Proficiency level in Java programming.

Author: Jay Liao (jay.chiehen@gmail.com)

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "csStudent.h"

using namespace std; // so that we don't need to keep writing std::

vector<string> tokenize(string csvLine, char separator) {

    // string vector tokens ## stores the tokens
    vector<string> tokens;

    // int start end ## used to delineate token positions
    signed int start, end;
    string token;

    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) {break;}
        if (end >= 0) { // a token is found
            token = csvLine.substr(start, end - start);
        }
        else {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    } while (end != string::npos);

    return tokens;
};

int main() {

    ifstream csvFile{"cs_students.csv"};
    string line;
    vector<string> tokens;

    if (csvFile.is_open()) {
        cout << "File is opened!\n" << endl;
        // int cnt_ln = 0;
        vector<csStudent> csStudents;
        getline(csvFile, line); // Read the csv header line but do nothing with it
        while (getline(csvFile, line)) {
            tokens = tokenize(line, ',');
            // cout << "Read line " << line << endl;
            // for (const string& token : tokens) {
            //     cout << token << endl;
            // }

            if (tokens.size() != 12) {
                cout << "\nError: a bad line!\n" << endl;
                continue;
            }
            try {
                int id = stod(tokens[0]);
                int age = stod(tokens[3]);
                double gpa = stod(tokens[4]);
                cout << "ID " << id << " | Age=" << age << ", GPA=" << gpa << endl;
                csStudent new_csStudent{
                    id, tokens[1], tokens[2], age, gpa,
                    tokens[5], tokens[6], tokens[7], tokens[8],
                    tokens[9], tokens[10], tokens[11]
                };
                csStudents.push_back(new_csStudent);
            } catch (exception& e) {
                cout << "Error in  " << tokens[3] << " | " << tokens[4] << endl;
                break;
            }
        }
        csvFile.close();

        // Computing and displaying basic statistics
        cout << "------- Statistics of PRICE ------" << endl;
    }
    else {
        cout << "File can not be opened!" << endl;
    }

    return 0;


};

