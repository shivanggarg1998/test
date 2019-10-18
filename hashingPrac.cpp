#include <iostream>
#include <unordered_map>
using namespace std;
// NOTE: Run it on hackerblocks IDE.
int main() {
	unordered_map<string, int> h;
	//This is the first way of insertion.
	//Structure is make a pair with it's signature as <string, int>.
	h.insert(make_pair("Apple", 20));


	//2nd way of insertion into a hashmap.
	pair<string, int> p;
	p.first = "guava";
	p.second = 25;
	h.insert(p);

	//3rd way and the most simple of all-> array[i'th element] = value of that element.
	h["banana"]=50;

	//Searching in a hashmap: Use count function. 
	if(h.count("banana")==0){
		cout<<"Not found in the hashmap";
	}
	else cout<<h["banana"]<<endl;

	//Removing an element from a hashmap
	h.erase("banana");

	//Finding in the list
	auto ptr = h.find("banana");
	if(ptr==h.end()){
		cout<<"banana not found in the map.";
	}
	else{
		cout<<ptr->first<<" and "<<ptr->second<<endl;
	}
	//Printing the hashmap.
	for(auto p:h){
		cout<<p.first<<" and "<<p.second<<endl;
	}

	//Clearing the hashmap.
	h.clear();

}