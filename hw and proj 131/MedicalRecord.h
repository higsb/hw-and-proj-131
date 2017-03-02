#pragma once
#include <string>
#include <stdexcept>
#include <vector>
#include <map>

#include "Baby.h"

using namespace std;

class MedicalRecord {
private:
    // update the data structure with information contained in Baby object
    vector<Baby>v;
    
    void addEntry(Baby b) {
        v.push_back(b);             //stores values at the end
    }
    
public:
    
	// default constructor
	MedicalRecord() {
        vector<Baby>v;	}
    
	// destructor
	~MedicalRecord() {
        v.clear();
	}

	// Load information from a text file with the given filename.
	void buildMedicalRecordfromDatafile(string filename) {
		ifstream myfile(filename);

		if (!myfile.is_open()) {
			cout << "Successfully opened file " << filename << endl;
			string name;
			int weight;
			while (myfile >> name >> weight) {
				// cout << name << " " << weight << endl;
				Baby b(name, weight);
				addEntry(b);                //adding it into the vector
			}
			myfile.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the most frequently appearing name in the text file
	string mostPopularName() {
        map<string, int> cnt;                   //for each string assigns int value
        int i;
        for ( i = 0 ; i < v.size() ; i ++ ) {
            string BabyName = v[i].getName();   //gets name at index and assigns to BabyName
            cnt[BabyName] ++;                   //cnt number of times BabyName is occuring <name, int>
        }
        
        int cnt_value = 0;      //
        string ans;
        
        for ( i = 0 ; i < v.size() ; i ++ ) {
            string BabyName = v[i].getName();       //get indexed name
            
            if ( cnt_value < cnt[BabyName] )    {   //cnt value has max and compares w/current name/value
                cnt_value = cnt[BabyName];          //highest cnt[BabyName] > than all other values cnt
                ans = BabyName;                     //assigns hightest BabyName to ans
            }
        }
        
        return ans;
           
	}

	// return the number of baby records loaded from the text file
	int numberOfBirths() {
        int len = v.size();
        return len;
	}

	// return the number of babies who had birth weight < 2500 grams
	int numberOfBabiesWithLowBirthWeight() {
        int i, count = 0;
        for (int i=0;i < v.size() ; i++)  {
            if (v[i].getWeight() < 2500)
                count++;
                }
        
    
		return count;
	}

	// return the number of babies who have the name contained in string s
	int numberOfBabiesWithName(string s) {
        int i, count = 0;
        for (int i=0;i < v.size() ; i++)
            if (v[i].getName() == s){
            count++;
            }
        return count;  //
	}


};
