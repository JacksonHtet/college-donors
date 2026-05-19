/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include "Menu.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Definition of function displayMenu
void displayMenu()
{
    cout << "\n============= DONATION MENU =============\n\n";
    cout << "\t1. Add college\n";
    cout << "\t2. Add donation\n";
    cout << "\t3. Print colleges\n";
    cout << "\t4. Print donations by college\n";
    cout << "\t5. Print donations by donor\n";
    cout << "\t6. Print totals by college\n";
    cout << "\t7. Print totals by donor\n";
    cout << "\t8. Print statistics\n";
    cout << "\t9. Print highest donor\n";
    cout << "\t10. Print highest-funded college\n";
    cout << "\t0. Exit\n";
}

// Definition of function processUserChoices
void processUserChoices(DonationManager& manager)
{
    int choice;
    string collegeCode, collegeName, donorName;
    double amount;
    int donorID;

    do
    {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter college code: ";
            cin >> collegeCode;
            cout << "Enter college name: ";
            cin.ignore();
            getline(cin, collegeName);
            manager.addCollege(collegeCode, collegeName);
            cout << "\n\t>>> College added.\n\n";
            system("pause");
        }
        else if (choice == 2)
        {
            cout << "\nEnter new donor name: ";
            cin.ignore();
            getline(cin, donorName);
            donorID = manager.addDonor(donorName);
            cout << "\n\t>>> New donor ID: " << donorID << endl;
            cout << "\nEnter college code: ";
            cin >> collegeCode;
            cout << "Enter donation amount: ";
            cin >> amount;
            manager.addDonation(donorID, collegeCode, amount);  // Use ID version
            cout << "\n\t>>> Donation added.\n\n";
            system("pause");
        }
        else if (choice == 3)
        {
            cout << "\n";
            manager.printColleges();
            system("pause");
        }
        else if (choice == 4)
        {
            cout << "\n";
            manager.printDonationsByCollege();
            system("pause");
        }
        else if (choice == 5)
        {
            cout << "\n";
            manager.printDonationsByDonor();
            system("pause");
        }
        else if (choice == 6)
        {
            cout << "\n";
            manager.printTotalsByCollege();
            system("pause");
        }
        else if (choice == 7)
        {
            cout << "\n";
            manager.printTotalsByDonor();
            system("pause");
        }
        else if (choice == 8)
        {
            cout << "\n";
            manager.printStatistics();
            system("pause");
        }
        else if (choice == 9)
        {
            cout << "\n";
            manager.printHighestDonor();
            system("pause");
        }
        else if (choice == 10)
        {
            cout << "\n";
            manager.printCollegeWithHighestTotal();
            system("pause");
        }
        else if (choice == 0)
        {
            cout << "\n\t>>>Logging out...\n\n";
			system("pause");
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
            system("pause");
        }

    } while (choice != 0);
}