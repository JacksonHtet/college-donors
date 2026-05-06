/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai
    
    Spring 2026
    CS A250 - C++ 2
    
    College Donor
*/

#ifndef DONOR_H
#define DONOR_H

#include <string> 

 class Donor 
 {
	public:
        Donor(std::string aDonorName, int aDonorID)
            :donorName(aDonorName), donorID(aDonorID) {}
        
        std::string getDonorName() const;
        int getDonorID() const;

        bool operator<(const Donor& otherDonor) const;
	
    private:
        std::string donorName;
        int donorID;
	
 };
#endif
