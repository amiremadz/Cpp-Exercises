#include <iostream>

using namespace std;


void mightGoWrong(){
	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	if(error1){
		throw 1;
	}

	if(error2){
		throw string("stringError");
	}

	if(error3){
		throw "Something wrong!";
	}

}

class canGoWrong {
public:
	canGoWrong() {
		char *arr = new char[9999999999999999];
		delete[] arr;
	}
	virtual ~canGoWrong() {};
};

class myException : public exception{
public:
	myException() {};
	virtual const char* what() const throw(){
		return "Something bad happened!";
	}
};


class Test{
public:
	void goesWrong(){
		throw myException();
	}
};


void goesWrong(){
	bool error1 = false;
	bool error2 = true;

	if(error1){
		throw bad_alloc();
	}

	if(error2){
		throw exception();
	}
}

int main(){

	try{
		mightGoWrong();
	}
	catch(int e){
		cout << "Error code: " << e << endl;
	}
	catch(string &e){
		cout << "Error string: " << e << endl;
	}
	catch(char const *e){
		cout << "Error message: " << e << endl;
	}

	try{
		canGoWrong wrong;
	}
	catch(std::bad_alloc &e){
		cout << "Error: " << e.what() << endl;
	}

	Test test;

	try{
		test.goesWrong();
	}
	catch(myException &e){
		cout << "Error: " << e.what() << endl;
	}


	try{
		goesWrong();
	}
	catch(bad_alloc &e){
		cout << "Catching bad_alloc " << e.what() << endl;
	}
	catch(exception &e){
		cout << "Catching exception " << e.what() << endl;
	}


	cout << "Still running" << endl;

	return 0;
}
