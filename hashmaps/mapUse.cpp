#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;   //unordered_map<key,value>
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;    // if "abc" doesn't exist , [] will insert "abc" and assign it value 0'
	cout << ourmap.at("abc") << endl; // if "abc" doesn't exist ,at() will give error.
	
	//cout << ourmap.at("ghi") << endl;
	cout << "size : " << ourmap.size() << endl;  //size() -> gives the size of the map.
	cout << ourmap["ghi"] << endl;
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) //
    {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}
    else
        cout << "ghi is deleted" << endl;
    

}
