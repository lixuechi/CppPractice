#include <iostream>
#include <fstream> // file handling
using namespace std;

int main() {
	ofstream destination("dest-file.txt");
	int x = 5;
	destination << x; // writes x to dest-file.txt

	ifstream source("dest-file.txt");
	int y;
	source >> y; // reads one int from source-file.txt
	source.close(); // close file as long as we're done using it

	source.open("dest-file.txt");

	cout << y << endl;

	/* fstream can read and write */
	fstream file3;
	file3.open("file.ext", ios::in|ios::out);
	// do read or write something here...
	file3.close();

	/* The modes of open(, arg) 
	   ios::in        read
	   ios::out       write
	   ios::app       write from the end of file
	   ios::binary    binary mode
	   ios::nocreate  if the file doesn't exist when being opened, do not create one
	   ios::noreplace if the file doesn't exist when being opened, create one
	   ios::trunc     open a file and clear everything
	   ios::ate       open a file and move the position to the end of file
	*/
	

	/* ios::beg - the beginning of the file
	   ios::end - the end of the file
	   ios::cur - the current position of the file */
	ifstream file0;
	file0.seekg(0, ios::end);
	int fl_sz = file0.tellg();
	file0.seekg(0, ios::beg);

	/* good() - opened OK
	   bad() - failed to open
	   eof() - end of file */
	char ch;
	ifstream file("lalaland.cpp", ios::in|ios::out);
	if(file.good()) {
		cout << "The file has been opened without problems" << endl;
	} else {
		cout << "An error has happened on opening the file" << endl;
	}
	while(!file.eof()) {
		file >> ch;
		cout << ch;
	}

	return 0;
} // close() called on destination by its destructor
