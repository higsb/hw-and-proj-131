#pragma once
#include <string>

using namespace std;

// class that contains information related to a single birth or baby name
class Baby {
private:
	string name;
	int weight;
public:
	Baby() {  // default constructor
        name = "Unknown";
        weight = NULL;
	};

	Baby(string s, int w) { // constructor
        name = s;
        weight = w;
	}

	// a "getter" method
	int getWeight() {
        
		return weight;
	}

	// a "getter" method
	string getName() {
        
		return name; 
	}


};