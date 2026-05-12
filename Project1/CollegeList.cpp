/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "CollegeList.h"

#include <iostream>

using namespace std;

void CollegeList::addCollege(const string& code, const string& name) 
{
    colleges[code] = name;  
}

string CollegeList::getCollegeName(const string& code) const 
{
    return colleges.at(code);
}

void CollegeList::printColleges() const
{
    for (const auto& entry : colleges)
    {
        cout << entry.first << " - " << entry.second << endl;
    }
}

const map<string, string>& CollegeList::getColleges() const 
{
    return colleges;
}