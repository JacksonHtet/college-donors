/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    College Donations
*/

#ifndef DONATIONLIST_H
#define DONATIONLIST_H

#include "Donation.h"

struct DonationNode
{
    Donation data;
    DonationNode* next;

    DonationNode(const Donation& donation)
        : data(donation), next(nullptr) {
    }
};

class DonationList
{
public:
    // Constructor 
    DonationList() : first(nullptr), last(nullptr), numOfDonations(0) {}

    void addDonation(const Donation& donation);

    int getNumOfDonations() const;
    DonationNode* getFirst() const;
    DonationNode* getLast() const;

    // Destructor
    ~DonationList();

private:
    DonationNode* first;
    DonationNode* last;
    int numOfDonations;
};

#endif