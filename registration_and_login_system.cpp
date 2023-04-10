#include <iostream>
#include <fstream> // for file handling
#include <string>
using namespace std;

void login();
void registration();
void forgot();
int main(){

int n;
cout<<"\t\t\t_________________________________________________\n\n\n";
cout<<"\t\t\t           Welcome to login page                 \n\n\n";
cout<<"\t\t\t___________________   Menu   _____________________ \n\n";
cout<<"                                                       \n\n";
cout<<"\t Press 1 to LOGIN     "<<endl;
cout<<"\t Press 2 to Register     "<<endl;
cout<<"\t Press 3 if password is forgot    "<<endl;
cout<<"\t Press 4 to exit     "<<endl;
cout<<"                                                      \n";
cout<<"\n\t\t Please enter your choice : ";
cin>> n;
cout << endl;
switch(n){

    case 1:
    login();
    break;

    case 2:
    registration();
    break;

    case 3:
    forgot();
    break;

    case 4:
    cout << "Thank u "<< endl;
    break;
    default:
    cout<<"\t\t\t Please select correct option " <<endl;
    }
    return 0;
}

    void login(){
        int count ;
        string userId, password, id, pass;
        cout << "Please enter username and password :"<<endl;
        cout <<"\t\t USERNAME ";
        cin >> userId ;
         cout <<"\t\t PASSWORD ";
        cin >> password;
        
        // class object_of_class("filename") ;
           ifstream input("records.txt"); // it(ifstream) checks in file whether login & password exist
             
           while (input>>id>>pass)
           {
            if(id==userId && pass==password){
                count = 1;
            }
           }
           input.close();

           if(count == 1){
            cout << userId << "\n login successfully !\n";
           }
         else{
            cout << "\n login error occur \n Please check username and password\n";
           }
   }
  void registration(){
    string ruserid,rpassword; //rid,rpass;
    
    cout <<"\t\t Enter the username: ";
    cin >> ruserid;

    cout <<"\t\t Enter the password: ";
    cin >> rpassword;
    
    ofstream f1("records.txt",ios::app);
    f1 <<ruserid <<" "<< rpassword << endl;
    cout << "\n\t\t Registration is successfull ! \n";
  }
  void forgot(){
    int option;
    cout << "\t\t\t you forgot the password ? No worries \n";
    cout << "press 1 to search your id by username "<< endl;
    cout << "press 2 to go back to main  menu" <<endl;
    cout <<"\t\t Enter your choice :";
    cin >> option;

    switch(option){
       case 1: {
        int count = 0;
        string suserid,sid,spass;
        cout << "Enter the username which you remembered :";
        cin >> suserid ;

      ifstream f2("records.txt");
      while(f2>>sid>>spass){
        if(sid==suserid)
        {
            count = 1;
        }
      }
        f2.close();
       if(count == 1){
        cout << "\n\n your account is found! \n";
        cout << "\n\n your password is: "<<spass;
       }
       else{
        cout << "\n\t sorry! your account is not found \n";
       }
       break;
       }
       case 2:{
        default: 
        cout << "\t\t\t wrong choice ! Please try again "<< endl;
        forgot();
       }
    }
  }


 