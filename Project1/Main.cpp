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

	cout << "\n===== PHASE 3: Testing Donation =====\n\n";

	// Test parameterized constructor + all accessors.
	cout << "-- Testing parameterized constructor --" << endl;

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
    DonationList dl;

    // Test DonationList::getNumOfDonations on an empty list.
    cout << "-- Testing getNumOfDonations() on an empty list --" << endl;
    cout << "Expected: 0" << endl;
    cout << "Actual: " << dl.getNumOfDonations() << endl;

    // Test DonationList::getFirst and DonationList::getLast on an empty list.
    cout << "\n-- Testing getFirst() and getLast() on an empty list --" << endl;
    cout << "Expected first: nullptr" << endl;
    cout << "Actual first: " << dl.getFirst() << endl;
    cout << "Expected last: nullptr" << endl;
    cout << "Actual last: " << dl.getLast() << endl;
    

    // Create and add a few Donation objects to the list.
    cout << "\n-- Testing addDonation() --" << endl;
    Donation don2("Alice Smith", "OCC", 1000.00);
    Donation don3("Bob Jones", "GWC", 500.00);
    Donation don4("Charlie Brown", "CCC", 750.00);

    dl.addDonation(don2);
    dl.addDonation(don3);
    dl.addDonation(don4);
    cout << "Added 3 donations." << endl;

    // Test DonationList::getNumOfDonations after adding donations.
    cout << "\n-- Testing getNumOfDonations() after adding donations --" << endl;
    cout << "Expected: 3" << endl;
    cout << "Actual: " << dl.getNumOfDonations() << endl;

    // Test DonationList::getFirst.
    // Print the data stored in the first node.
    cout << "\n-- Testing getFirst() --" << endl;
    cout << "\nExpected donor name: Alice Smith" << endl;
    cout << "Actual donor name: " << dl.getFirst()->donation.getDonorName() << endl;
    cout << "\nExpected college code: OCC" << endl;
    cout << "Actual college code: " << dl.getFirst()->donation.getCollegeCode() << endl;
    cout << "\nExpected amount: 1000" << endl;
    cout << "Actual amount: " << dl.getFirst()->donation.getAmount() << endl;

    // Test DonationList::getLast.
    // Print the data stored in the last node.
    cout << "\n-- Testing getLast() --" << endl;
    cout << "\nExpected donor name: Charlie Brown" << endl;
    cout << "Actual donor name: " << dl.getLast()->donation.getDonorName() << endl;
    cout << "\nExpected college code: CCC" << endl;
    cout << "Actual college code: " << dl.getLast()->donation.getCollegeCode() << endl;
    cout << "\nExpected amount: 750" << endl;
    cout << "Actual amount: " << dl.getLast()->donation.getAmount() << endl;

    // Traverse the DonationList manually using getFirst and next.
    // Print all donations in the list.
    cout << "\n-- Traversing DonationList --" << endl;
    DonationNode* current = dl.getFirst();
    int count = 1;
    while (current != nullptr)
    {
        cout << "\nDonation " << count << ":" << endl;
        cout << "  Donor Name: " << current->donation.getDonorName() << endl;
        cout << "  College Code: " << current->donation.getCollegeCode() << endl;
        cout << "  Amount: " << current->donation.getAmount() << endl;
        current = current->next;
        count++;
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