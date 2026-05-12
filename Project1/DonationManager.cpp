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
    Donor newDonor(donorName,nextDonorID);
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
    Donor newDonor(donorName, nextDonorID);
    donors.insert(newDonor);
    nextDonorID++;

    Donation newDonation(donorName, collegeCode, amount);
    donations.addDonation(newDonation);
}

// Print colleges
void DonationManager::printColleges() const
{
    colleges.printColleges();
}

// Print donations by college
void DonationManager::printDonationsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& entry : collegeMap)
    {
        const string& code = entry.first;
        const string& name = entry.second;
        cout << "College: " << code << " - " << name << endl;

        DonationNode* current = donations.getFirst();
        while (current != nullptr)
        {
            const Donation& donation = current->data;
            if (donation.getCollegeCode() == code)
            {
                cout << "  Donor: " << donation.getDonorName()
                    << ", Amount: $" << donation.getAmount() << endl;
            }
            current = current->next;
        }
    }
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
                cout << "Donor ID: " << donor.getDonorID()
                    << ", Name: " << donor.getDonorName()
                    << ", College Code: " << current->data.getCollegeCode()
                    << ", College Name: " << collegeName
                    << ", Amount: $" << current->data.getAmount() << endl;
                break; // each donor has only one donation
            }
            current = current->next;
        }
    }
}

// Totals by college
void DonationManager::printTotalsByCollege() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        cout << "College " << entry.first<< " total: $" << total << endl;
    }
}

// Totals by donor
void DonationManager::printTotalsByDonor() const
{
    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        cout << "Donor ID: " << donor.getDonorID()
            << ", Name: " << donor.getDonorName()
            << ", Total: $" << total << endl;
    }
}

// Statistics
void DonationManager::printStatistics() const
{
    cout << "Number of donors: " << donors.size() << endl;
    cout << "Number of colleges: " << colleges.getColleges().size() << endl;
    cout << "Number of donations: " << donations.getNumOfDonations() << endl;
}

// Highest donor
void DonationManager::printHighestDonor() const
{
    string highestDonorName;
    double highestAmount = 0.0;
    for (const Donor& donor : donors)
    {
        double total = getDonorTotal(donor.getDonorName());
        if (total > highestAmount)
        {
            highestAmount = total;
            highestDonorName = donor.getDonorName();
        }
    }
    cout << "Highest donor: " << highestDonorName
        << " with $" << highestAmount << endl;
}

// College with highest total
void DonationManager::printCollegeWithHighestTotal() const
{
    const map<string, string>& collegeMap = colleges.getColleges();
    string highestCollegeCode;
    double highestTotal = 0.0;
    for (const auto& entry : collegeMap)
    {
        double total = getCollegeTotal(entry.first);
        if (total > highestTotal)
        {
            highestTotal = total;
            highestCollegeCode = entry.first;
        }
    }
    cout << "College with highest total: " << highestCollegeCode
        << " (" << collegeMap.at(highestCollegeCode) << ")"
        << " with $" << highestTotal << endl;
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