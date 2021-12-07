#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class EmployeeSystem
{
protected:
    string name;
    int Basic_Salary;
public:
    EmployeeSystem() {}
    EmployeeSystem(string name, int Basic_Salary)
    {
        this->name = name;
        this->Basic_Salary = Basic_Salary;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }

    int getBasic_Salary() {
        return Basic_Salary;
    }

    void setBasic_Salary(int Basic_Salary) {
        this->Basic_Salary = Basic_Salary;
    }

    virtual void input() = 0;
    virtual void display() = 0;
    virtual int tinhluong() = 0;

};
bool comp(EmployeeSystem* a, EmployeeSystem* b) {
    if (a->tinhluong() < b->tinhluong()) {
        return true;
    }
    return false;
}
class  Worker : public EmployeeSystem
{
private:
    int Level;
public:
    Worker() {}
    Worker(string name, int Basic_Salary, int Level) : EmployeeSystem(name, Basic_Salary)
    {
        this->Level = Level;
    }
    void input()
    {
        cin.ignore();
        getline(cin, name);
        cin >> Basic_Salary;
        cin >> Level;
    }
    void display()
    {
        cout << " - Name: " << name << endl;
        cout << " - Basic Salary: " << Basic_Salary << endl;
        cout << " - Salary: " << tinhluong() << endl;
        cout << " - Level: " << Level << endl;
        
    }
    int tinhluong() {
        return (Level * getBasic_Salary() * 20 / 100) + getBasic_Salary();
    }
};

class  Manager : public EmployeeSystem
{
private:
    int Experience;
public:
    Manager() {}
    Manager(string name, int Basic_Salary, int Experience) : EmployeeSystem(name, Basic_Salary) {

        this->Experience = Experience;
    }
    void input()
    {
        cin.ignore();
        getline(cin, name);
        cin >> Basic_Salary;
        cin >> Experience;
    }
    void display()
    {
        cout << " - Name: " << name << endl;
        cout << " - Basic Salary: " << Basic_Salary << endl;
        cout << " - Salary: " << tinhluong() << endl;
        cout << " - Experience: " << Experience << endl;
    }
    int tinhluong() {
        return (Experience * getBasic_Salary() * 15 / 100) + getBasic_Salary();
    }

};
class dataEmployee {
private:
    vector<EmployeeSystem*> list;
public:
    dataEmployee() {}
    void input() {
        int soluong = 1;
        int dem = 0;
        cin >> soluong;
        int val = 0;
        while (dem != soluong) {
            EmployeeSystem* temp;
            cin >> val;
            if (val == 1) {
                temp = new Worker();
                temp->input();
                list.push_back(temp);
            }
            else if (val == 2) {
                temp = new Manager();
                temp->input();
                list.push_back(temp);
            }
            else {
                break;
            }
            dem++;
        }
    }

    void display() {
        int j = 0;
        sort(list.begin(), list.end(), comp);
        for (int i =0; i < list.size(); i++) {
            cout << "Employee [" << i << "]:"<<endl;
            j++;
            list[i]->display();
        }
    }

};
int main()
{
    dataEmployee h;
    h.input();
    h.display();
    return 0;
}