#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#pragma pack(push, 1) // No packing
struct Person {
	char name[50];
	int age;
	double height;
};
#pragma pack(pop)


int main(){

	fstream inputFile;
	string fileName = "stats.txt";

	inputFile.open(fileName, fstream::in);

	while(inputFile){
		string line;

		getline(inputFile, line, ':');

		int population;

		inputFile >> population;

		//inputFile.get(); // To remove extra white line
		inputFile >> ws;   // To remove extra white line

		if(!inputFile){
			break;
		}

		cout << line << " " << population  << endl;
	}

	cout << "Person struct size in bytes (62 expected): "<< sizeof(Person) << endl;

	Person someone = {"John", 23, 176.5};

	/// Write binary file

	string binFileName = "test.bin";
	fstream binFile;

	binFile.open(binFileName, fstream::out | ios::binary);

	if(binFile.is_open()){
		binFile.write(reinterpret_cast<char *>(&someone), sizeof(someone));
	}
	else{
		cout << "Cannot create file " << binFileName << endl;
	}

	binFile.close();

	/// Read binary file

	Person someOneElse = {};

	fstream readFile;
	readFile.open(binFileName, fstream::in | ios::binary);

	if(readFile.is_open()){
		readFile.read(reinterpret_cast<char *>(& someOneElse), sizeof(someOneElse));
	}
	else{
		cout << "No file " << binFileName << endl;
	}

	readFile.close();

	cout << "Name: " << someOneElse.name << " Age: " <<
			someOneElse.age << " Height: " << someOneElse.height << endl;


	return 0;
}
