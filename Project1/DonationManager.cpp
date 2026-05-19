/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#include <iostream>
#include "DonationManager.h"

using namespace std;


// Add donor
int DonationManager::addDonor(const string& donorName)
{
    Donor newDonor(donorName, nextDonorID);
    donors.insert(newDonor);
    return nextDonorID++;
}

// Add college 
void DonationManager::addCollege(const string& collegeCode, const string& collegeName)
{
    colleges.addCollege(collegeCode, collegeName);
}

// Add donation
void DonationManager::addDonation(const string& donorName, const string& collegeCode, double amount)
{
    for (const Donor& donor : donors)
    {
        if (donor.getDonorName() == donorName)
        {
            Donation newDonation(donorName, collegeCode, amount);
            donations.addDonation(newDonation);
            return;
        }
    }

    Donor newDonor(donorName, nextDonorID);
    donors.insert(newDonor);
    nextDonorID++;

    Donation newDonation(donorName, collegeCode, amount);
    donations.addDonation(newDonation);
}


// Overloaded add donation
void DonationManager::addDonation(const int donorID, const string& collegeCode, double amount)
{

    for (const Donor& donor : donors)
    {
        if (donor.getDonorID() == donorID)
        {
            Donation newDonation(donor.getDonorName(), collegeCode, amount);
            donations.addDonation(newDonation);
            break;
        }
    }
}

// Print colleges
void DonationManager::printColleges() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& entry : collegeMap)
    {
        cout << "\t"<< entry.first << " - " << entry.second << "\n";
    }
    cout << "\n";
}

// Print donations by college
void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& entry : collegeMap)
    {
        const string& code = entry.first;
        const string& name = entry.second;

        bool hasDonation = false;
        DonationNode* current = donations.getFirst();

        while (current != nullptr)
        {
            if (current->data.getCollegeCode() == code)
            {
                hasDonation = true;
                break;
            }
            current = current->next;
        }

        if (hasDonation)
        {
            cout << "\t" << code << " - " << name << "\n";
            current = donations.getFirst();
            while (current != nullptr)
            {
                if (current->data.getCollegeCode() == code)
                {
                    cout << "\t    " << current->data.getDonorName()
                        << " | Amount: $" << current->data.getAmount() << "\n";
                }
                current = current->next;
            }
        }
        else
        {
            cout << "\t" << code << " - " << name << "\n\t    (no donation)\n" ;
        }
    }
    cout << "\n";
}

// Print donations by donor
void DonationManager::printDonationsByDonor() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const Donor& donor : donors)
    {
        DonationNode* current = donations.getFirst();
        while (current != nullptr)
        {
            if (current->data.getDonorName() == donor.getDonorName())
            {
                string collegeName = collegeMap.at(current->data.getCollegeCode());
                string collegeCode = current->data.getCollegeCode();

                cout << "\tID " << donor.getDonorID() << " - " << donor.getDonorName() << "\n";
                cout << "\t\t" << collegeName << " (" << collegeCode << ")" << "\n";
                cout << "\t\tAmount: $" << current->data.getAmount() << "\n";
                break;
            }
            current = current->next;
        }
    }
    cout << "\n";
}

// Totals by college
void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        cout << "\t" << entry.first << " - " << entry.second << "\n";
        cout << "\t    Total donation amount: $" << total << "\n";
    }
    cout << "\n";
}

// Totals by donor
void DonationManager::printTotalsByDonor() const
{
    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        cout << "\t(ID " << donor.getDonorID() << ") " << donor.getDonorName()
            << " | $" << total << "\n";
    }
    cout << "\n";
}

// Statistics
void DonationManager::printStatistics() const
{
    cout << "\tNumber of donors: " << donors.size() << "\n";
    cout << "\tNumber of colleges: " << colleges.getColleges().size()<< "\n";
    cout << "\tNumber of donations: " << donations.getNumOfDonations() << "\n\n";
}

// Highest donor
void DonationManager::printHighestDonor() const
{
    double highestAmount = 0.0;

    // Find the highest amount first
    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > highestAmount)
        {
            highestAmount = total;
        }
    }

    // Find all donors with the highest amount
    cout << "\tHighest donor(s):" << "\n";
    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total == highestAmount)
        {
            cout <<"\t    " << donor.getDonorName() << "\n";
        }
    }
    cout << "\t    Highest amount donated: $" << highestAmount << "\n\n";
}

// College with highest total
void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    double highestTotal = 0.0;

    // Find the highest total first
    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        if (total > highestTotal)
        {
            highestTotal = total;
        }
    }

    // Find all colleges with the highest total
    cout << "\tCollege(s) with highest total donation:" << "\n";
    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        if (total == highestTotal)
        {
            cout << "\t    "<<entry.second << " (" << entry.first << ")" << "\n";
        }
    }
    cout << "\t    Highest total received: $" << highestTotal << "\n\n";
}

// Get donor total
double DonationManager::getDonorTotal(const string& donorName) const
{
    double total = 0.0;
    DonationNode* current = donations.getFirst();
    while (current != nullptr)
    {
        if (current->data.getDonorName() == donorName)
            total += current->data.getAmount();
        current = current->next;
    }
    return total;
}

// Get college total
double DonationManager::getCollegeTotal(const string& collegeCode) const
{
    double total = 0.0;
    DonationNode* current = donations.getFirst();
    while (current != nullptr)
    {
        if (current->data.getCollegeCode() == collegeCode)
            total += current->data.getAmount();
        current = current->next;
    }
    return total;
}