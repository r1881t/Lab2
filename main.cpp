#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char *argv[]) 
{
	vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
		string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token <<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

// PART 1 print to _set.txt
		ofstream setfile (filename + "_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
				// cout << ' ' << *it;
				setfile << endl << *it;
				
		}
    cout << endl;

// PART 2 print to _vector.txt 
		ofstream vectorfile (filename + "_vector.txt");
		for (int i = 0; i < tokens.size(); i++) {
			vectorfile << tokens.at(i) << endl;
		}

// PART 3 map of strings to strings

		map<string, string> wordmap;
		string last="";
		for (vector<string>::iterator it = tokens.begin(); it!=tokens.end(); it++) {
			wordmap[last]=*it;
			last = *it;
     	mapfile << wordmap[*it] << ", " << *it << endl; 
		}
		map<string, vector<string>> wordmap;
		string state = "";
		ofstream mapfile (filename + "_map.txt");

		for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
			wordmap[state].push_back(*it);
			state = *it;
		}
// Part 4 print something cool

string state = "";
for(int i = 0; i < 100; i++){
  cout << wordmap[state] << " ";
  state = wordmap[state];
}
cout << endl;

return 0;
}