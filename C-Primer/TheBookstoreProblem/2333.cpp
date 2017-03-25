#include <iostream>
#include "Sales_item.h"
#include <vector>
#include <map>
using namespace std;

int main() {
	/* test input: 0-201-70353-X 4 24.99
	Sales_item book;
	// read ISBN, number of copies sold, and sales price
	cin >> book;
	// write ISBN, number of copies sold, total revenue and average price
	cout << book << endl;
	*/

	/* test input: 0-201-78345-X 3 20.00 
	               0-201-78345-X 2 25.00 
	Sales_item item1, item2;
	cin >> item1 >> item2; // read a pair of transactions
	// first check that item1 and item2 represent the same book
	if(item1.isbn == item2.isbn) {
		cout << item1 + item2 << endl; // print their sum
		return 0; // indicate success
	} else {
		cerr << "Data must refer to the same ISBN: " << endl;
		return -1; // indicate failure
	}
	*/

	/* Read several transactions and counts how many transactions occur for each ISBN */
	/*
	vector<Sales_item> items;
	Sales_item itemN;
	while(cin >> itemN) {
		items.push_back(itemN);
	}
	map<string, int> m;
	for(vector<Sales_item>::iterator it = items.begin(); it != items.end(); it++) {
		if(m.find(it->isbn) == m.end()) {
			m.insert(pair<string, int>(it->isbn, 1));
		} else {
			int num = m.find(it->isbn)->second + 1;
			m.find(it->isbn)->second = num;
		}
	}
	for(map<string, int>::iterator itM = m.begin(); itM != m.end(); itM++)
		cout << itM->first << " " << itM->second << endl;
	*/

	Sales_item total; // variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	if(cin >> total) {
		Sales_item trans; // variable to hold the running sum
		// read and process the remaining transactions
		while(cin >> trans) {
			// if we're still processing the same book
			if(total.isbn == trans.isbn) {
				total += trans; // update the running total
			} else {
				// print the results for the previous book
				cout << total << endl;
				total = trans; // total now refers to the next book
			}
		}
		cout << total << endl; // print the last transaction
	} else {
		// no print! warn the user
		cerr << "No data" << endl;
		return -1; // indicate failure
	}

	return 0;
}
