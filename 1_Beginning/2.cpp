
#include <iostream>
using namespace std;

class Student{
	public:
		string name;
		string section;
		int roll_no;
		Student(string name, string section, int roll_no){
			this->name=name;
			this->section=section;
			this->roll_no=roll_no;
		}
		void print(){
			cout<<"Name: "<<name<<endl;
			cout<<"Section: "<<section<<endl;
			cout<<"Roll Number: "<<roll_no<<endl;
		}
};
int main(){
	Student *c= new Student("Satvik", "K23PE", 5);
	c->print();
	
}
