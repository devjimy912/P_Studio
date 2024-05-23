#include <iostream>
#include <sstream>
#include <fstream>
#define MAX 50

using namespace std;
string kname[2] = {"A+~F", "P/F"}; // String for grading

class MyClass{
private:
	int code;		    // class code
	string name; 	// class name
	int unit;		    // credites
	int grading;	    // grading category (1:A+~F, 2:P/F)
public:
    MyClass(int ncode, string nname, int nunit, int ngrading){
        code = ncode; name = nname; unit = nunit; grading = ngrading;
    }
    ~MyClass();
    int getCode(){return code;}
    string getName(){return name;}
    int getUnit(){return unit;}
    int getGrading(){return grading;};
    void setCode(int newcode){code = newcode;}
    void setName(string newname){name = newname;}
    void setUnit(int newunit){unit = newunit;}
    void setGrading(int newgrading){grading = newgrading;}
    string toString(){
        stringstream sstm;
        sstm <<  "[" << code << "] " << name << " [credit " << unit << " - "+kname[grading-1] << "]";
        return sstm.str();
    }
    string toStringSave(){
        stringstream sstm;
        sstm << code << " " << name << " " << unit << " " << grading;
        return sstm.str();
    }
};

class MyClassManager{
private:
    MyClass* allclasses[MAX];
    MyClass* myclasses[10];
    int count;
    int mycount;
public:
    MyClassManager(){
        count=0; mycount=0;
    }
    ~MyClassManager(){}
    int getCount(){return count;}
    int getMyCount(){return mycount;}

    void loadData(string filename);
    void printAllClasses(); // Print all class list
    void findClasses(string name); // Search a class by name from the list
	int findClass(int code); // Search a class by code from the list
    void saveAllClasses(string filename); // Save all class list

    // Functions for modifying
    void addClass(); // Add a class into the list
    void editClass(); // Modify a class in the list

    // Functions for making
    void applyMyClass(); // Apply a class
    void printMyClasses(); // Print my classes
    void saveMyClasses(string filename); // Save my classes
};


int main() {
	int no;	// menu number 
    int quit = 0;
	string name;

	MyClassManager manager; // MyClassManager obj

	manager.loadData("classes.txt");

	while(!quit){
		cout << "Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n";
		cout << ">> Menu? > ";
		cin >> no;
        switch(no){
            case 1: 
			    cout << "> 1.Print All Classes\n";
	    		manager.printAllClasses();
                break;
            case 2:
			    cout << "> 2.Add a Class\n";
    			manager.addClass();
                break;
		    case 3:
    			cout << "> 3.Modify a Class\n";
	    		manager.editClass();
                break;
            case 4:
            	cout << "> 4.Search a Class\n";
			    cout << ">> Enter class name > ";
			    cin >> name;
    			manager.findClasses(name);
                break;
		    case 5:
    			cout << "> 5.Apply a class\n";
	    		manager.applyMyClass();
		    	cout << manager.getMyCount() << " classes has been applied.\n";
                break;
    		case 6:
    			cout << "> 6.My classes\n";
	    		manager.printMyClasses();
                break;
    		case 7:
    			cout << "> 7.Save\n";
	    		manager.saveMyClasses("myclasses.txt");
		    	cout << "\n> All my classes ware saved to my_classes.txt.\n";
			    manager.saveAllClasses("classes.txt");
			    cout << "\n> All of class list ware saved to classes.txt.\n";
                break;
            case 0:
                quit = 1;
                break;
		}
	}
	return 0;
}

void MyClassManager::loadData(string filename){
    string line, name;
    int code, unit, grading;
	ifstream file(filename);
	while(!file.eof()){
        if(file.eof()) break;
		file >> code >> name >> unit >> grading;
        allclasses[count] = new MyClass(code, name, unit, grading);
		count++;
	}
	file.close();
    cout << count << " classes are loaded.\n";
}

void MyClassManager::printAllClasses(){
	for (int i=0; i<count; i++){
		cout << allclasses[i]->toString() << endl;
	}
}

void MyClassManager::saveAllClasses(string filename){
	ofstream file(filename);
	for(int i=0; i<count; i++){
		file << allclasses[i]->toStringSave();
        if(i<count-1) file << endl;
	}
	file.close();	
}

void MyClassManager::findClasses(string name){
	int found = 0;
	cout << "Searching keyword: " << name << endl;
	for(int i=0; i<count; i++){
		if(allclasses[i]->getName().find(name) != string::npos){
		    cout << allclasses[i]->toString() << endl;
			found++;
		}
	}
	cout << count << " classes found.\n";
}

int MyClassManager::findClass(int code){
	//search class code in allClasses list
	//if find - return index(i)
	//else not found - return -1
	for(int i=0; i<count; i++){ // find index info
		if(code == allclasses[i]->getCode()){
			return i;
		}
	}
	return -1;
}

// You must complete these functions.
void MyClassManager::addClass(){
// Caution : Don't allow the duplicate class code.
// You must complete this function.
    string name;
    int code, unit, grading;
	bool check = true;

	while(check){
		cout << ">> code number > ";
		cin >> code;
		for(int i=0; i<count; i++){
			if(allclasses[i]->getCode() == code){
				check = true;
				break;
			}else{
				check = false;
			}
		}
	}

	cout << ">> class name > ";
	cin >> name;
	cout << ">> credits > ";
	cin >> unit;
	cout << ">> grading (1: A+~F, 2: P/F) > ";
	cin >> grading;

	// You must complete this section.
	allclasses[count] = new MyClass(code, name, unit, grading);
    
	count++;
}

void MyClassManager::editClass(){
	int code;
	cout << ">> Enter a code of class > ";
	cin >> code;
	//if not exist, quit.
	
	// You must complete this section.
	//1. 입력받은 코드가 기존의 배열에 있는 지 확인.
	//2. 있으면 접근. 없으면 없다는 메세지 띄우고 종료.

	int index = findClass(code);
	int unit, grading;
	string name;

	if(index != -1){ // found
		cout << ">> class name > ";
		cin >> name;
		cout << ">> credits > ";
		cin >> unit;
		cout << ">> grading (1: A+~F, 2: P/F) > ";
		cin >> grading;
		allclasses[index]->setName(name);
		allclasses[index]->setUnit(unit);
		allclasses[index]->setGrading(grading);
	}else{ // not found
		cout << "Can not find code " << code << endl;
	}
}



void MyClassManager::applyMyClass(){

// You must make all these functions.
// 원하는 과목 이름을 받고 find()함수로 찾는다. - 이름이 아니라 코드로 받는 거였네..
// 찾은 과목을 레퍼런스로 받아서 myclasses배열에 넣는다.
// 만약 못 찾으면 찾을 수 없습니다. 출력.

	int code;
	cout << ">> Enter a code of class > ";
	cin >> code;

	int index = findClass(code);

	if(index != -1){ // found
		MyClass& applyClass = *allclasses[index];
		cout << myclasses[index]->toString() << endl;
	}else{ // not found
		cout << "Can not find code " << code << endl;
	}

	myclasses[mycount] = *allclasses;
	mycount++;
}

void MyClassManager::printMyClasses(){

// You must make all these functions.
// copy printAllClasses
	int sumCredit = 0;
	for (int i=0; i<mycount; i++){
		cout << myclasses[i]->toString() << endl;
		sumCredit += myclasses[i]->getUnit();
	}
	cout << "All : " << sumCredit << " credits" << endl;

}

void MyClassManager::saveMyClasses(string filename){

// You must make all these functions.

	ofstream outFile;
	outFile.open("my_classes.txt");
	if (!outFile) {
        std::cerr << "Error: File could not be opened" << std::endl;
        return; // Exit with error code
    }
	int AB_Credit = 0;
	int PF_Credit = 0;
	for (int i=0; i<mycount; i++){
		outFile << myclasses[i]->toString() << endl;
		if(myclasses[i]->getGrading() == 0){
			AB_Credit += myclasses[i]->getUnit();
		}else if(myclasses[i]->getGrading() == 1){
			PF_Credit += myclasses[i]->getUnit();
		}
	}
	outFile << "All : " << mycount << " classes, "
			<< AB_Credit + PF_Credit << " credits "
			<< "(" << kname[0] << " "<< AB_Credit << " credits, "
			<< kname[0] << " "<< PF_Credit << " credits)" << endl;
	outFile.close();
}