/*
    Htet, Phyo Zayar (Team Leader)
    Ligatsyah, Nathan
    Puthy, Piseth
    Pha, Sai

    Spring 2026
    CS A250 - C++ 2

    Testing
*/

#include <iostream>
#include "Donor.h"
#include "CollegeList.h"
#include "Donation.h"
#include "DonationList.h"
//#include "DonationManager.h"
//#include "FileLoader.h"

using namespace std;

int main()
{
    // IMPORTANT TESTING RULES:
    //
    // 1. DO NOT delete or change any of the provided test comments.
    // 2. Each test must PRODUCE OUTPUT--silent or skipped tests will lose points.
    // 3. If a test fails, fix YOUR implementation, not the test.
    // 4. You may add additional tests for clarity, but do not remove any required ones.

    cout << "===== PHASE 1: Testing Donor =====\n\n";

    // Test parameterized constructor + all accessors.
    // Your code here...
    cout << "-- Testing parameterized constructor --" << endl;

	Donor d1("Alice Smith", 1001);

    cout << "Input: (\"Alice Smimth\", 1001)" << endl;
    cout << "Expected name: Alice Smith" << endl;
    cout << "Actual name: " << d1.getDonorName() << endl;
    
    cout << "Expected ID: 1001" << endl;
    cout << "Actual ID: " << d1.getDonorID() << endl;

    // Test Donor::operator<.
    // Your code here...
    
    cout << "\n-- Testing operator< --" << endl;

    Donor d2("Bob Jones", 1003);
    cout << "Comparing donor ID 1001 with donor ID 1003" << endl;
    cout << "Expected: 1" << endl;
    cout << "Actual  : " << (d1 < d2) << endl;


    cout << "\n===== PHASE 2: Testing CollegeList =====\n\n";

    // Create CollegeList object.
    // Your code here...
    CollegeList cl;

    // Test CollegeList::addCollege.
    // Your code here...
    cl.addCollege("OCC", "Orange Coast College");
    cl.addCollege("GWC", "Golden West College");
    cl.addCollege("CCC", "Coastline Community College");

    cout << "-- Testing addCollege() --\n";
    cout << "Added 3 colleges.\n";

    // Test CollegeList::getCollegeName with an existing college code.
    // Your code here...
    cout << "\n-- Testing getCollegeName() --\n";
    cout << "Expected: Orange Coast College\n";
    cout << "Actual:   " << cl.getCollegeName("OCC") << "\n";

    // Test CollegeList::printColleges.
    // Your code here...
    cout << "\n-- Testing printColleges() --\n";
    cl.printColleges();

    // Test CollegeList::getColleges.
    // Your code here...
    cout << "\n-- Testing getColleges() --\n";
    cout << "Expected size: 3\n";
    cout << "Actual size:   " << cl.getColleges().size() << "\n";

    cout << "\n===== PHASE 3: Testing Donation =====\n";

    // Test parameterized constructor + all accessors.
    // Your code here...
    cout << "-- Testing parameterized constructor --\n" << endl;

    Donation don1("John Doe", "OCC", 500.00);

	cout << "Input: (\"John Doe\", \"OCC\", 500.00)\n" << endl;
	// test GetDonorName function
	cout << "Expected donor name: John Doe" << endl;
    cout << "Actual donor name: " << don1.getDonorName() << endl;
	// test GetCollegeCode function
    cout << "\nExpected college code: OCC" << endl;
    cout << "Actual college code: " << don1.getCollegeCode() << endl;
	// test GetAmount function
    cout << "\nExpected amount: 500" << endl;
    cout << "Actual amount: " << don1.getAmount() << endl;

    cout << "\n===== PHASE 4: Testing DonationList =====\n\n";

    // Create DonationList object.
    DonationList donList;

    // Test DonationList::getNumOfDonations on an empty list.
    cout << "-- Testing getNumOfDonations() on empty list --\n";
    cout << "Expected: 0\n";
    cout << "Actual:   " << donList.getNumOfDonations() << "\n";

    // Test DonationList::getFirst and DonationList::getLast on an empty list.
    cout << "\n-- Testing getFirst() and getLast() on empty list --\n";
    cout << "Expected: nullptr for both\n";
    cout << "getFirst(): " << (donList.getFirst() == nullptr ? "nullptr" : "not nullptr") << "\n";
    cout << "getLast():  " << (donList.getLast() == nullptr ? "nullptr" : "not nullptr") << "\n";

    // Create and add a few Donation objects to the list.
    cout << "\n-- Adding donations to list --\n";
    donList.addDonation(Donation("John Doe", "OCC", 500.00));
    donList.addDonation(Donation("Jane Smith", "GWC", 750.50));
    donList.addDonation(Donation("Bob Johnson", "CCC", 1000.00));
    cout << "Added 3 donations.\n";

    // Test DonationList::getNumOfDonations after adding donations.
    cout << "\n-- Testing getNumOfDonations() after adding donations --\n";
    cout << "Expected: 3\n";
    cout << "Actual:   " << donList.getNumOfDonations() << "\n";

    // Test DonationList::getFirst and print the data stored in the first node.
    cout << "\n-- Testing getFirst() --\n";
    cout << "Expected donor: John Doe\n";
    cout << "Actual donor:   " << donList.getFirst()->donation.getDonorName() << "\n";
    cout << "Expected college: OCC\n";
    cout << "Actual college:   " << donList.getFirst()->donation.getCollegeCode() << "\n";

    // Test DonationList::getLast and print the data stored in the last node.
    cout << "\n-- Testing getLast() --\n";
    cout << "Expected donor: Bob Johnson\n";
    cout << "Actual donor:   " << donList.getLast()->donation.getDonorName() << "\n";
    cout << "Expected college: CCC\n";
    cout << "Actual college:   " << donList.getLast()->donation.getCollegeCode() << "\n";

    // Traverse the DonationList manually using getFirst and next.
    cout << "\n-- Traversing all donations --\n";
    for (auto node = donList.getFirst(); node != nullptr; node = node->next) {
        cout << node->donation.getDonorName() << " | " << node->donation.getCollegeCode()
             << " | $" << node->donation.getAmount() << "\n";
    }


    cout << "\n===== PHASE 5: Testing DonationManager with manual data =====\n\n";

    // Create DonationManager object.
    // Your code here...

    // Test DonationManager::addCollege by adding several colleges.
    // Your code here...

    // Test DonationManager::printColleges.
    // Your code here...

    // Test DonationManager::addDonor by adding several donors.
    // Print the ID returned for each donor.
    // Your code here...

    // Test DonationManager::addDonation by adding several donations.
    // Your code here...

    // Test DonationManager::printDonationsByCollege.
    // Your code here...

    // Test DonationManager::printDonationsByDonor.
    // Your code here...

    // Test DonationManager::printTotalsByCollege.
    // Your code here...

    // Test DonationManager::printTotalsByDonor.
    // Your code here...

    // Test DonationManager::printStatistics.
    // Your code here...

    // Test DonationManager::printHighestDonor.
    // Your code here...

    // Test DonationManager::printCollegeWithHighestTotal.
    // Your code here...


    cout << "\n===== PHASE 6: Testing FileLoader with colleges.csv and donations.csv =====\n\n";

    // Create DonationManager object.
    // Your code here...

    // Test loadCollegesFromFile.
    // Your code here...

    // After calling loadCollegesFromFile, test DonationManager::printColleges.
    // Your code here...

    // Test loadDonationsFromFile.
    // Your code here...

    // After calling loadDonationsFromFile, test all report functions:
    // printDonationsByCollege
    // printDonationsByDonor
    // printTotalsByCollege
    // printTotalsByDonor
    // printStatistics
    // printHighestDonor
    // printCollegeWithHighestTotal
    // Your code here...


    cout << "\n===== All tests completed. =====\n";

    cout << endl;
    system("Pause");
    return 0;
}