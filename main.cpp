#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <list>
using namespace std;

int main(int argc, char *argv[]) 
{
		srand(time(NULL));
		list<string> tokens;
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

// PART 2 print to list.txt 
		ofstream listfile (filename + "_list.txt");
		for (auto it = tokens.begin(); it != tokens.end(); ++it) {
			listfile << *it << endl;
		}

// PART 3, 5, and maybe 6 map of strings to vector


 	/*	map<string, vector<string>> wordmap;
 		string state = "";
 		for (auto it = tokens.begin(); it != tokens.end(); it++) {
 			wordmap[state].push_back(*it);
 			state = *it;
		}

		
//Part 4 print something cool
		
		//state = "";
		// 
		// for(int i = 0; i < 100; i++){
		// 	int ind = rand() % wordmap[state].size();
		// 	cout << wordmap[state][ind] << " ";
		// 	state = wordmap[state][ind];
		// }
		// cout << endl;

		
	// 	}
*/
// Part 6
const int M = 2;
	map<list<string>, vector<string>> wordmap;
  list<string> mlist;
	list<string> startList;
  for (int i = 0; i < M; i++) {
    mlist.push_back("");
		startList.push_back("");
  }
  int stop = rand() % (tokens.size() - M - 1);                   
  for (auto it = tokens.begin(); it != tokens.end(); it++) {
    wordmap[mlist].push_back(*it);
    mlist.push_back(*it);
    mlist.pop_front();
		if (stop == wordmap.size()) {
		startList.push_back(*it);
    startList.pop_front();
		}
  }

	 ofstream mapfile(filename + "_map.txt");
		
	 for(auto it = mlist.begin(); it !=  mlist.end(); ++it) {
   	mapfile << it->first << ": ";
	 	 			for(auto possible:it->second) {
	 	 			mapfile << possible << " ";
	 	 			}
	 	 			mapfile << endl;
	 }
	
  for (int i = 0; i < 200; i++) {
    int ind = rand() % wordmap[startList].size();
    cout << wordmap[startList][ind]<<" ";
    startList.push_back(wordmap[startList][ind]);
    startList.pop_front();
	
  }

return 0;
}