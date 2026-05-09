/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    DonationList
*/

#ifndef DONATIONLIST_H
#define DONATIONLIST_H

#include "Donation.h"

struct DonationNode
{
    Donation donation;
    DonationNode* next;
};

class DonationList
{
public:
    DonationList()
        : first(nullptr), last(nullptr), numOfDonations(0) {}

    int addDonation(const Donation& donation);
    int getNumOfDonations() const;
    DonationNode* getFirst() const;
    DonationNode* getLast() const;
    ~DonationList();

private:
    DonationNode* first;
    DonationNode* last;
    int numOfDonations;
};

#endif
