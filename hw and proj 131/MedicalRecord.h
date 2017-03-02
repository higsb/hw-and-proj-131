#pragma once
#include <string>
#include <stdexcept>

#include "Baby.h"

using namespace std;

class MedicalRecord {
private:
    // update the data structure with information contained in Baby object
    void addEntry(Baby b) {
        // not sure how to construct
    }
    
    // Add private member variables for your data structure along with any
    // other variables required to implement the public member functions
    int *babies;
    int babyarr;
    
    
public:
    int count;
    
	// default constructor
	MedicalRecord(int bbsize) {
        babyarr = bbsize;               //
        babies = new int[babyarr];      //dynamically allocate memory for babies
	}
    /*MedicalRecord(int bby[], int bbyarr)   {
        babyarr = bbyarr;
        babies = new int[babyarr];
        for(int i = 0; i < babyarr; i++)
            babies[i] = bby[i];
    }*/
	// destructor
	~MedicalRecord() {
        delete[] babies;
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
        return mpname;   //sort alphabetically
                                //count repeating names and compare and keep most common name
                                //output name
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths(int babyw) {
		return babies[babyw];
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight(int w) {
        
        while(w < 2500)
            count++;
    
		return count;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
        for (int i=0; ; i++)
            count++;
        return;  //
	}


};
