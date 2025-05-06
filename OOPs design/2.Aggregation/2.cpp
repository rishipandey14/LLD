// considers a scenario , where a UNIVERSITY conatins multiple PROFESSOR objects, However a professor can exist independently of any univeristy.
// Aggregation with Interfaces (Abstract Classes)
// Using abstract classes, we can further enhance the flexibility of aggregation.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Teachable {
public:
    virtual void teach() = 0; // Pure virtual function
    virtual string getName() = 0;
};

class Professor : public Teachable {
private:
    string name;
    string subject;
public:
    Professor(string name, string subject) : name(name), subject(subject) {}
    void teach() override {
        cout << name << " is teaching " << subject << endl;
    }
    string getName() override { return name; }
};

class University {
private:
    string universityName;
    vector<Teachable*> professors;
public:
    University(string name) : universityName(name) {}
    
    void addProfessor(Teachable* professor) {
        professors.push_back(professor);
    }
    
    void showProfessors() {
        cout << "Professors at " << universityName << ":" << endl;
        for (auto professor : professors) {
            professor->teach();
        }
    }
};

int main() {
    Professor prof1("Dr. MMS Rauthan", "DSA");
    Professor prof2("Dr. Om Prakash", "DBMS");
    
    University university("HNBGU");
    university.addProfessor(&prof1);
    university.addProfessor(&prof2);
    
    university.showProfessors();
    
    return 0;
}