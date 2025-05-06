// considers a scenario , where a UNIVERSITY conatins multiple PROFESSOR objects, However a professor can exist independently of any univeristy.

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Professor {
  private :
    string name, subject;
  public : 
    Professor(string name, string subject) : name(name), subject(subject) {}
    void teach () {
      cout << name << " is teaching " << subject << endl;
    }
    string getName() { return name; }
};

class University {
  private:
    string universityName;
    vector<Professor* > professors;  // aggregation : University has a list of professors
  public:
    University(string name) : universityName(name) {}

    void addProfessor(Professor* professor) { professors.push_back(professor) ;}

    void showProfessors() {
      cout << "Professor at " << universityName << ":" << endl;
      for(auto professor : professors){
        cout << " - " << professor->getName() << endl;
      }
    }
};

int main(){
  Professor prof1("Dr. MMS Rauthan", "DSA");
  Professor prof2("Dr. Om Prakash", "DBMS");

  University university("HNBGU");
  university.addProfessor(&prof1);
  university.addProfessor(&prof2);

  university.showProfessors();
  prof1.teach();
  prof2.teach();

  return 0;
}