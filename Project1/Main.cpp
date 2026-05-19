/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "DonationManager.h"
#include "FileLoader.h"
#include "Menu.h"

#include <iostream>

using namespace std;

int main()
{
    DonationManager manager;

    cout << fixed << showpoint;
    cout.precision(2);

    loadCollegesFromFile("colleges.csv", manager);
    loadDonationsFromFile("donations.csv", manager);

    processUserChoices(manager);

    cout << endl;
    system("pause");
    return 0;
}