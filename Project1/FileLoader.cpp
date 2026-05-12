/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "FileLoader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void loadCollegesFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        // Your code here...
        string line;

        while (getline(inFile, line))
        {
 
            stringstream lineStream(line);
            string collegeCode;
            string collegeName;

            getline(lineStream, collegeCode, ',');
            getline(lineStream, collegeName, ',');

            manager.addCollege(collegeCode, collegeName);
        }

        inFile.close();
        cout << "=> College data loaded...\n";
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}

void loadDonationsFromFile(const string& fileName, 
    DonationManager& manager)
{
    ifstream inFile(fileName);

    if (inFile)
    {
        // Your code here...   
        string line;

        while (getline(inFile, line))
        {
            stringstream lineStream(line);
            string donorName;
            string collegeCode;
            string amountStr;

            getline(lineStream, donorName, ',');
            getline(lineStream, collegeCode, ',');
            getline(lineStream, amountStr, ',');

            double amount = stod(amountStr);
            manager.addDonation(donorName, collegeCode, amount);
        }
  
        inFile.close();
        cout << "=> Donation data loaded...\n";
    }
    else
    {
        cout << "=> Could not open " << fileName << "." << endl;
    }
}