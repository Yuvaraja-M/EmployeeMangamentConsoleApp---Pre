#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
#include<fstream>
#include <iomanip>
using namespace std;
class Employee{
    private:
    string name;
    int age;
    string dob;
    int salary;
    string dept;
    int id;

    public:
    void menu();
    void show();
    void search();
    void update();
    void add();
    void del();
    void criteria();
    void avgdep();
    void avgcompany();
    void Enterkey();
};
void Employee::Enterkey(){
    cout << "\n\t\t\t\tPress Enter to exit window : ";
     system("pause");
    cin.get();
}
void Employee::add(){
    system("cls");
    fstream f;
    cout << "\n\n\t\t\t\tAdd Employee" << endl;
    cout << "\t\t\t\tEmployee Id :  " ;
    cin >> id;
    cout << "\t\t\t\tFirst Name :  " ;
    cin >> name;
    cout << "\t\t\t\tAge :  " ;
    cin >> age;
    cout << "\t\t\t\tDate of Birth :  " ;
    cin >> dob;
    cout << "\t\t\t\tSalary :  " ;
    cin >> salary;
    cout << "\t\t\t\tDepartment :  " ;
    cin >> dept;
    f.open("Employee.txt",ios::app|ios::out);
    f  << " "<< id << " " << name << " " << age  << " " << dob << " " << salary << " " << dept  << endl;
    f.close();
}
void Employee::show(){
    system("cls");
    int cnt = 1;
    fstream f;
    cout << "\n-----------------------------------------------------------------------------------------------" << endl;
    cout << "\n-----------------All Employees-----------------------------------------------------------------" << endl;
    f.open("Employee.txt", ios::in);
    if (!f) {
        cout << "\n\t\t\tNo Data Present :( ";;
        f.close(); 
        Enterkey();
    }
    else {
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||    EmpID    ||    NAME    ||     AGE    ||      DOB      ||    SALARY    ||    DEPARTMENT  ";
        cout << "\n -------------------------------------------------------------------------------------------------";

        while (f >> id >> name >> age >> dob >> salary >> dept) {
            cout << "\n";
            cout << setw(3) << cnt++ << ". ";
            cout << setw(13) << id;
            cout << setw(13) << name;
            cout << setw(12) << age;
            cout << setw(18) << dob;
            cout << setw(15) << salary;
            cout << setw(18) << dept;
        }
        Enterkey();
        f.close();
       
    }
}
void Employee::update(){
    system("cls");
    string n2;
    int flag = 0;
    int empid;
    fstream f,f1;
     cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
     cout << "------------------------------------- Update Employee's Record ------------------------------------------" << endl;
     f.open("Employee.txt",ios::in);
     if(!f){
        cout << "\n\t\t\tNo Data Present :( ";
        Enterkey();
        f.close();
     }
     else{
        cout << "Enter ID: ";
        cin >> empid;
        cout << "Enter name: ";
        cin >> n2;
        f1.open("temp.txt",ios::app|ios::out);
        while( f >> id >> name >> age >> dob >> salary >> dept){
            if(empid == id && name == n2){
                cout << "\n Enter Employee ID: ";
                cin >> id;
                cout << "\n Enter Name of Employee: ";
                cin >> name;

                cout << "\n Enter Age: ";
                cin >> age;
                cout << "\n Enter Date of birth: ";
                cin >> dob;
                cout << "\n Enter Employee Salary: ";
                cin >> salary;
                cout << "\n Enter Employee Department : ";
                cin >> dept;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                f1  << " "<< id << " " << name << " " << age  << " " << dob << " " << salary << " " << dept  << endl;
                flag++;
            }
            else{
                f1  << " "<< id << " " << name << " " << age  << " " << dob << " " << salary << " " << dept  << endl;

            }
        }
        if(flag == 0){
            cout << "\n\t\tEmployee Not present... Give Correct name and ID";

        }
        f1.close();
        f.close();
        remove("Employee.txt");
        rename("temp.txt","Employee.txt");
     }
     Enterkey();
}
void Employee::del() {
    system("cls");
    int empid;
    string n1;
    fstream f, f1;
    int flag = 0;

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete an Employee ------------------------------------------------" << endl;
    f.open("Employee.txt", ios::in);

    if (!f) {
        cout << "\n\t\tEmployee Not present... Give Correct name and ID";
        f.close();
    } else {
        cout << "Enter ID: ";
        cin >> empid;
        cout << "Enter name: ";
        cin >> n1;
        f1.open("temp.txt", ios::app | ios::out);

        while (f >> id >> name >> age >> dob >> salary >> dept) {
            if (empid != id || name != n1) {
                f1 << " " << id << " " << name << " " << age << " " << dob << " " << salary << " " << dept << endl;
            } else {
                flag++;
                cout << "\n\t\t\tSuccessfully Deleted Record";
                break;
            }
        }

        if (flag == 0) {
            cout << "\n\t\tEmployee Not present... Give Correct name and ID";
        }
        while (f >> id >> name >> age >> dob >> salary >> dept) {
            f1 << " " << id << " " << name << " " << age << " " << dob << " " << salary << " " << dept << endl;
        }

        f1.close();
        f.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        Enterkey();
    }
}

void Employee::criteria(){
    system("cls");
    fstream f;
    int ch;
    cout << "\n----------Filter Employee by Criteria----------" << endl;
    cout << "\tPress 1 for Filter By Department " << endl;
    cout << "\tPress 2 for Filter By Age" << endl;
    cout << "\tEnter your Choice : ";
    cin >> ch;
    if(ch == 1){
                string departmentToFilter;
        cout << "\tEnter Department to filter: ";
        cin >> departmentToFilter;

        f.open("Employee.txt", ios::in);
        if (!f) {
            cout << "\n\t\t\tNo Data Present :(";
            f.close();
            Enterkey();
        } else {
            cout << "\n -------------------------------------------------------------------------------------------------";
            cout << "\n||    EmpID    ||    NAME    ||     AGE    ||      DOB      ||    SALARY    ||    DEPARTMENT  ";
            cout << "\n -------------------------------------------------------------------------------------------------";

            int cnt = 1;
            while (f >> id >> name >> age >> dob >> salary >> dept) {
                if (dept == departmentToFilter) {
                    cout << "\n";
                    cout << setw(3) << cnt++ << ". ";
                    cout << setw(13) << id;
                    cout << setw(13) << name;
                    cout << setw(12) << age;
                    cout << setw(18) << dob;
                    cout << setw(15) << salary;
                    cout << setw(18) << dept;
                }
            }
            Enterkey();
            f.close();
        }
    }
    else if(ch == 2){
        int Age1;
        cout << "\tEnter the Age to filter: ";
        cin >> Age1;

        f.open("Employee.txt", ios::in);
        if (!f) {
            cout << "\n\t\t\tNo Data Present :(";
            f.close();
            Enterkey();
        } else {
            cout << "\n -------------------------------------------------------------------------------------------------";
            cout << "\n||    EmpID    ||    NAME    ||     AGE    ||      DOB      ||    SALARY    ||    DEPARTMENT  ";
            cout << "\n -------------------------------------------------------------------------------------------------";

            int cnt = 1;
            while (f >> id >> name >> age >> dob >> salary >> dept) {
                if (age == Age1) {
                    cout << "\n";
                    cout << setw(3) << cnt++ << ". ";
                    cout << setw(13) << id;
                    cout << setw(13) << name;
                    cout << setw(12) << age;
                    cout << setw(18) << dob;
                    cout << setw(15) << salary;
                    cout << setw(18) << dept;
                }
            }
            Enterkey();
            f.close();
    }
      
    }
}

void Employee::search(){
    system("cls");
    fstream f;
    string n1;
    int empid;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search for an Employee ------------------------------------------------" << endl;
        f.open("Employee.txt",ios::in);
        cout << "Enter ID: ";
        cin >> empid;
        if(!f){
            cout << "\n\t\t\tNo Data Present :( ";
            f.close();
        }
        else{
            while(f >> id >> name >> age >> dob >> salary >> dept){
                if(empid==id ){
                    cout << "\n----------Employee Info----------" << endl;
                    cout << " Id: " << id << endl;
                    cout << " Name: " << name << endl;
                    cout << " Age: " << age << endl;
                    cout << " Department: " << dept << endl; 
                }
                f >> id >> name >> age >> dob >> salary >> dept; 
            }
        }
        f.close();
        Enterkey();
}
void Employee::avgdep(){
    system("cls");
    fstream f;
    string dp1;
    cout << "\n\tEnter Department to calculate average salary: ";
    cin >> dp1;

    f.open("Employee.txt", ios::in);
    if (!f) {
        cout << "\n\t\t\tNo Data Present :(";
        f.close();
        Enterkey();
    } else {
        int tot = 0;
        int cnt = 0;

        while (f >> id >> name >> age >> dob >> salary >> dept) {
            if (dept == dp1) {
                tot += salary;
                cnt++;
            }
        }

        if (cnt > 0) {
            double averageSalary = (tot) / static_cast<double>(cnt);
            cout << "\n\tAverage Salary of Department " << dp1 << ": " << averageSalary << endl;
        } else {
            cout << "\n\t\tNo employees found in Department " << dp1;
        }

        Enterkey();
        f.close();
    }
}
void Employee::avgcompany(){
    system("cls");
    fstream f;
    f.open("Employee.txt", ios::in);
    if (!f) {
        cout << "\n\t\t\tNo Data Present :(";
        f.close();
        Enterkey();
    } else{
        int tot = 0;
        int cnt = 0;
        while (f >> id >> name >> age >> dob >> salary >> dept) {
                tot += salary;
                cnt++;
        }
        if (cnt > 0) {
            double averageSalary = static_cast<double>(tot) / (cnt);
            cout << "\n\te Average Salary of an Employee in the Company : " << averageSalary << endl;
        } else {
            cout << "\n\t\tNo employees record in the Company";
        }
        Enterkey();
        f.close();
    }
}
void Employee::menu(){
    while(true){
        int x;
        system("cls"); 
        cout<< "\n\n\t\t\t\tEmployee Management Application" << endl;
        cout << "\n\t\t\t\t---------------------------------------" << endl;
        cout << "\t\t\t\tType a below digit for operation:"<<endl;
        cout << "\n\n\t\t\t\t======================================" << endl;
        
        cout<<"\t\t\t\t1. Show all Employees" <<endl;
        cout<<"\t\t\t\t2. Filter Employees based on criteria" <<endl;
        cout<<"\t\t\t\t3. Search for an Employee" <<endl;
        cout<<"\t\t\t\t4. Update an Employee's Record" <<endl;
        cout<<"\t\t\t\t5. Delete an Employee" <<endl;
        cout<<"\t\t\t\t6. Add an Employee" <<endl;
        cout<<"\t\t\t\t7. Get Average Salary of a Department" <<endl;
        cout<<"\t\t\t\t8. Calculate the Average Salary of an Employee in the Company" <<endl;
        cout<<"\t\t\t\t9. Exit" <<endl;
        cout << "\n\n\t\t\t\t=======================================" << endl;
        cout << "\t\t\t\tEnter the choice : ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\t\t\t\tShow all the Employees"<<endl;
            show();
            break;
        case 2:
            cout << "\t\t\t\tFilter Employees based on criteria"<<endl;
            criteria();
            break;  
        case 3:
            cout << "\t\t\t\tSearch for an Employee"<<endl;
            search();
            break;
        case 4:
            cout << "\t\t\t\tUpdate An Employee"<<endl; 
            update(); 
            break;  
        case 5:
            cout << "\t\t\t\tDelete An Employee"<<endl;
            del();
            break;
        case 6:
            cout << "\t\t\t\tAdd an Employee"<<endl;
            add();
            break;
        case 7:
            cout <<  "\t\t\t\tAverage Salary of a Department"<<endl;
            avgdep();
            break;         
        case 8:
            cout <<  "\t\t\t\tAverage Salary of an Employee in the Company"<<endl;
            avgcompany();
            break;  
        case 9:
            exit(0);
        default:
    cout << "\t\t\t\tPlease Enter Valid Input!" << endl;
    cout << "\t\t\t\tPress Enter to continue...";
    cin.clear();           
    cin.ignore(INT_MAX, '\n');
    cin.get();     
        
        }
    }
}
int main()
{
    Employee ob;
    ob.menu();
    return 0;
}
