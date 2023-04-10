#include <iostream> 
#include <stdlib.h> 
#include <iomanip>
#include <fstream> // for file handling
#include <string> // for using string 
using namespace std; // for using standard names which is predefined in iostream header file
 
// function prototypes 
void printIntroMenu(); 
void printMainMenu(); 
void start(); 
void login(); 
void createAccount();
 
// global variable (use this variable to store the user’s menu selection) char menuInput; 
 
// the main function
int main() 
{ 
	 	// TO WRITE A WELCOME MESSAGE HERE 
         cout << "Hi! Welcome to Mr. Zamar's ATM Machine!" << endl;
         cout << "Please select an option from the menu below:" << endl;
        
            printIntroMenu();
	 	 	// call the function start 
	 	 	      start(); 
      
	 	 	return 0; 
} 

void printIntroMenu() 
{ 
	 	// WRITE CODE HERE 
    cout << "l -> Login \nc -> Create New Account \nq -> Quit" << endl;
    cout << "\n > " ;
} 
 
void printMainMenu() 
{ 
	 	// WRITE CODE HERE 
        cout << "\nd -> Deposit Money \nw -> Withdraw Money \nr -> Request Balance \nq -> Quit" << endl;
        cout << "\n > " ;

} 

void start() 
{ 
	 	// EXPLANATION OF CODE THAT GOES HERE IS BELOW 
        char n;

        do{
        cin >> n;
        switch(n){
            case 'l':
            login();
            break;

            case 'c':
            createAccount();
            break;

            case 'q':
            cout << "Thanks for stopping by!" << endl;
            exit(0);
        }
        }while(n!= 'q');
 }

void createAccount() 
{ 
	 	//PHASE 1
        string username,password;

        cout << "Please enter your username: ";
        cin >> username;

        cout << "Please enter your password: ";
        cin >> password;


        ofstream f1("records.txt",ios::app);
        f1 << username <<" "<< password << endl;

        cout << "\nThank You! Your account has been created! \n"<< endl;
        printIntroMenu();

} 
 

void login() 
{ 
	 	// PHASE 2 
        int flag ;
        string userId, passw, id, pass;
        cout << "Please enter your username: ";
        cin >> userId;

        cout << "Please enter your password: ";
        cin >> passw;

         ifstream input("records.txt"); // it(ifstream) checks in file whether login & password exist
             
           while (input>>id>>pass)
           {
            if(id==userId && pass==passw){
                flag = 1;
            }
           }
           input.close();

           if(flag == 1){

            cout << endl;
            cout << "Access Granted!\n"<<endl;
            printMainMenu();

           char m;
           int dep;
           
           do{
             
            cin >> m;

            switch(m){
            
            case 'd':
            
            cout << "\nAmount of deposit: " <<"$"<<"20"<<endl;
            printMainMenu(); 
            break;

            case 'w':
            cout << "\nAmount of withdrawal: " <<"$"<<"17.5"<<endl;
            printMainMenu();
            break;

            case 'r':
            cout << "\nYour balance is: "<<"$"<<"17.5"<<endl;
           printMainMenu();
           break;

            case 'q':
             cout << "\nThanks for stopping by!" << endl;
              exit(0);
        }
           } while(m != 'q');
     
           }
         else{
            cout << "\n ******** LOGIN FAILED! ******** \n"<<endl;
            printIntroMenu();

           }
   }
 
 
