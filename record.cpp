# include<iostream>
# include<string>
# include<vector>
using namespace std;

struct Record{
    string name;
    string email;
    string phone;
};

class Database{
    private:
    vector<Record>records;

    public:
    void addRecord(){
        Record newRecord;
        system("cls");
        cout<<"*******************"<<endl;
        cout<<"NEW RECORD"<<endl;
        cout<<"*******************"<<endl;
        cout<<"Enter Name"<< endl;
        cin>>newRecord.name;
        cout<<"Enter Email"<<endl;
        cin>> newRecord.email;
        cout<<"Enter Phone"<< endl;
        cin>> newRecord.phone;

        records.push_back(newRecord);
        cout<<"\nRECORD SUCCESSFULLY ADDED"<<endl;
    }

    void removeRecord(){
        string name;
        cout<<"\n Enter name of record to remove"<<endl;
        cin>>name;

        for(int i = 0; i<records.size();i++){
            if (records[i].name == name){
                records.erase(records.begin() + i);
                cout<<"\nRecord successfully removed"<<endl;
                return;
            }
        }
        cout<<"\nRecord not found"<< endl;
    }

    void displayRecord(){
        if(records.empty()){
            system("cls");
            cout<<"No records found"<< endl;
            return;
        }
        cout<<"\n*******************"<<endl;
        cout <<"    REORDS:"<<endl;
        cout<<"*******************"<<endl;
        for(int i=0;i<records.size();i++){
            cout<<"\nName:"<< records[i].name<<endl;
            cout<<"Email:"<< records[i].email<<endl;
            cout<<"Phone:"<< records[i].phone<<endl;
            cout<<"\n";
        }
    }
};

int main(){
    Database db;
    int choice;
    system("cls");
    do{
        cout<<"\n*******************"<<endl;
        cout<<"   DATABASE MENU"<< endl;
        cout<<"*******************"<<endl;
        cout<<"\n1. Add Record"<< endl;
        cout<<"2. Remove Record"<< endl;
        cout<<"3. Display Records"<< endl;
        cout<<"4. Exit"<< endl;
        cout<<"Enter Your Choice"<< endl;
        cin>> choice;

        switch(choice){
            case 1: db.addRecord();
            break;
            case 2: db.removeRecord();
            break;
            case 3: db.displayRecord();
            break;
            default:
                cout<<"\nInvalid choice try again"<<endl;
                main();
        }
    }while(choice !=4);
    return 0;
}