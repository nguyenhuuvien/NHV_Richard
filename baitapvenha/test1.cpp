#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Employee {
protected:
    string fullName;
    int basicSalary;
public:
    Employee(string fullName = "", int basicSalary = 0) {
        this->fullName = fullName;
        this->basicSalary = basicSalary;
    }
    string getFullName() {
        return fullName;
    }
    int getBasicSalary() {
        return basicSalary;
    }
    void input() {
        getline(cin, fullName);

        cin >> basicSalary;
    }
    void display() {

        cout << " - Name: " << getFullName() << endl;

        cout << " - Basic Salary: " << getBasicSalary() << endl;
    }
};

class Worker :public virtual Employee {
protected:
    int level;
public:
    Worker(string fullName = "", int basicSalary = 0, int level = 0) :Employee(fullName, basicSalary) {
        this->level = level;
    }
    void input() {
        cin.ignore();
        Employee::input();
        cin >> level;
    }
    int calculateSalary(int basicSalary) {
        return basicSalary + level * basicSalary * 20 / 100;
    }
    void display() {
        Employee::display();
        cout << " - Salary: " << calculateSalary(getBasicSalary()) << endl;
        cout << " - Level: " << level << endl;
    }
};

class Manager :public virtual Employee {
protected:
    int experience;
public:
    Manager(string fullName = "", int basicSalary = 0, int experience = 0) :Employee(fullName, basicSalary) {
        this->experience = experience;
    }
    void input() {
        cin.ignore();
        Employee::input();
        cin >> experience;
    }
    int calculateSalary(int basicSalary) {
        return basicSalary + experience * basicSalary * 15 / 100;
    }
    void display() {
        Employee::display();
        cout << " - Salary: " << calculateSalary(getBasicSalary()) << endl;
        cout << " - Experience: " << experience << endl;
    }
};

class EmployeeSystem :public Worker, public Manager {
private:
    vector<Worker>listWorker;
    vector<Manager>listManager;
    int numberOfImployee;
public:
    void input() {
        cin >> numberOfImployee;
        for (int i = 0; i < numberOfImployee; i++) {
            int choose;
            cin >> choose;
            if (choose == 1) {
                Worker::input();
                Worker w(fullName, basicSalary, level);
                listWorker.push_back(w);
            }
            else {
                Manager::input();
                Manager m(fullName, basicSalary, experience);
                listManager.push_back(m);
            }
        }
    }
    void sort() {
        for (int i = 0; i < listWorker.size() - 1; i++) {
            for (int j = 0; j < listWorker.size(); j++) {
                if (listWorker.at(i).getBasicSalary() > listWorker.at(j).getBasicSalary()) {
                    Worker temp = listWorker.at(i);
                    listWorker.at(i) = listWorker.at(j);
                    listWorker.at(j) = temp;
                }
            }
        }
        for (int i = 0; i < listManager.size() - 1; i++) {
            for (int j = 0; j < listManager.size(); j++) {
                if (listManager.at(i).getBasicSalary() > listManager.at(j).getBasicSalary()) {
                    Manager temp = listManager.at(i);
                    listManager.at(i) = listManager.at(j);
                    listManager.at(j) = temp;
                }
            }
        }
    }
    void display() {

        sort();
        for (int i = 0; i < listWorker.size(); i++) {
            cout << "Employee [" << i + 1 << "]:" << endl;
            listWorker.at(i).display();
        }


        for (int i = 0; i < listManager.size(); i++) {
            cout << "Employee [" << i + listWorker.size() + 1 << "]:" << endl;
            listManager.at(i).display();
        }
    }
    ~EmployeeSystem() {
        listManager.clear();
        listWorker.clear();
    }
};
int main()
{
    EmployeeSystem es;
    es.input();
    es.display();
    return 0;
}