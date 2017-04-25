#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Employee{
    private:
        string name;
        int idNumber;
        string department;
        string position;

    public:
        Employee(string, int, string, string);
        //Employee(string, int);

        //Default Constructor
        Employee();

        //Accessor Functions
        string getName() const;
        int getID () const;
        string getDepartment () const;
        string getPosition () const;

        //Mutator Functions
        void setName (string);
        void setID (int);
        void setDepartment(string);
        void setPosition(string);
};

Employee::Employee(string name_1, int id_1, string dept_1, string pos_1) {
    name = name_1;
    idNumber = id_1;
    department = dept_1;
    position = pos_1;
}

//Default Constructor
Employee::Employee(){
    idNumber = 0;
}

//Accessor Functions
string Employee::getName() const {
    return name;
}

int Employee::getID() const {
    return idNumber;
}

string Employee::getDepartment() const {
    return department;
}

string Employee::getPosition() const {
    return position;
}

//Mutator Functions
void Employee::setName(string name_1) {
    name = name_1;
}

void Employee::setID(int id_1) {
    idNumber = id_1;
}

void Employee::setDepartment(string dept_1) {
    department = dept_1;
}

void Employee::setPosition(string pos_1) {
    position = pos_1;
}

int main(){
    /*string name_1, dept_1, pos_1;
    int id_1;*/

    Employee Susan/*, Mark, Joy*/;

    //Susan
    Susan.setName("Susan Mayers");
    Susan.setID(47899);
    Susan.setDepartment("Accounting");
    Susan.setPosition("Vice President");

    cout << Susan.getName() << endl;
    cout << Susan.getID() << endl;
    cout << Susan.getDepartment() << endl;
    cout << Susan.getPosition() << endl;



    return 0;
}
