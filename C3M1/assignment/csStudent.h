#pragma once
#include <string>
using namespace std;

class csStudent
{
    public:
        csStudent(
            int _id,          // Student ID: Unique identifier for each student.
            string _name,     // Name of the student
            string _gender,   // Gender of the student.
            int _age,         // Age of the student.
            double _gpa,      // Grade Point Average of the student.
            string _major,    // Field of study within computer science.
            string _domain,   // Interested Domain: Area of interest within the field of computer science.
            string _projects, // Noteworthy projects completed by the student.
            string _futureCareer, // Intended career path or job aspiration.
            string _python,   // Proficiency level in Python programming.
            string _sql,      // Proficiency level in SQL querying.
            string _java      // Proficiency level in Java programming.
        );

        int id;
        string name;
        string gender;
        int age;
        double gpa;
        string major;
        string domain;
        string projects;
        string futureCareer;
        string python;
        string sql;
        string java;
};
