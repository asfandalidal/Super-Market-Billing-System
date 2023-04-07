     /*cout << "-------------------------------------------------------" << endl;
    cout << "|                  Supermarket Billing System          |" << endl;
    cout << "|                                                     |" << endl;
    cout << "|                  Roll No: 22SW041                   |" << endl;
    cout << "|                                                    |" << endl;
    cout << "|                Subject: C++ Programming            |" << endl;
    cout << "-------------------------------------------------------" << endl;*/

#include <iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<chrono>
#include<thread>
using namespace std;
class shopping{
private:
    int pcode;
    float price;
    float discount;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void List();
    void receipt();
};
void shopping::menu() {
    string email="";
    string password="";
    char p;
    int attempt=0;
    int choice;

    while (true) {
        cout << "\t\t\t\t__________________________________\n";
        cout << "\t\t\t\t                               \n";
        cout << "\t\t\t\t Super Market Main Menu         \n";
        cout << "\t\t\t\t                                 \n";
        cout << "\t\t\t\t__________________________________\n";
        cout << "\t\t\t\t                                   \n";
        cout << "\t\t\t\t | 1) Administrator |\n";
        cout << "\t\t\t\t |                  |\n";
        cout << "\t\t\t\t | 2) Buyer         |\n";
        cout << "\t\t\t\t |                  |\n";
        cout << "\t\t\t\t | 3) Exit          |\n";
        cout << "\t\t\t\t |                  |\n";
        cout << "\n\t\t\t  Please select! \n";
        cin >> choice;
        if (cin.fail()) {
    cout << "Invalid input ! " << endl;
    system("CLS");
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
//Here, cin.fail() checks if the input is of the wrong type, and if so, it prints an error message and clears the error state of the stream using cin.clear(). The cin.ignore() statement discards any remaining input on the line, so that the next input statement can start with a fresh input buffer.

        if (choice == 1) {
            cout << "\n\t\t\t Please login\n";
            while (attempt <= 3) {
                cout << "\n\t\t\t Enter email: \n";
                cin >> email;
                cout << "\n\t\t\t Enter password: \n";
                for(int i = 1; i <= 2; i++) {
                    p = getch();
                    cout << "*";
                    password += p;
                }

                if(email == "asfandali" && password == "41") {
                    system("CLS");
                    administrator();
                    break;
                } else {
                    cout << "\n\t\t\t Invalid Credentials! Please try again.\n";
                    attempt++;
                    email = "";
                    password = "";
                }
            }//while loop
        } else if (choice == 2) {
        	system("CLS");
            buyer();
            break;
        } else if (choice == 3) {
            exit(0);
        } else {
            cout << "Please try again.\n";
        }
    }//while loop
}//menu function ends

void shopping::administrator()
{
    m:
    int choice;

 
    cout<<"\n\n\n\t\t\t Administrator Menu ";
    cout << "\n\t\t\t __________________________________ ";
cout << "\n\t\t\t|                                  |";
cout << "\n\t\t\t|_____1) Add Product         ____  |";
cout << "\n\t\t\t|__________________________________|";
cout << "\n\t\t\t|                                  |";
cout << "\n\t\t\t|_____2) Modify Product      ____  |";
cout << "\n\t\t\t|__________________________________|";
cout << "\n\t\t\t|                                  |";
cout << "\n\t\t\t|_____3) Delete Product      ____  |";
cout << "\n\t\t\t|__________________________________|";
cout << "\n\t\t\t|                                  |";
cout << "\n\t\t\t|_____4) Back to the Main Menu ____|";
cout << "\n\t\t\t|__________________________________|";
cout << "\n\t\t\t|                                  |";

    cout<<"\n\t\t\tPlease Enter your Choice "<<endl;
    cin>>choice;
    if (cin.fail()) {
    cout << " input error ! " << endl;
    system("CLS");
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
    switch(choice){
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid choice ! "<<endl;

}//admin switch
goto m;
}// admin fun end
void shopping::buyer()
{
	int choice;
    m:
    cout<<"\t\t\tBuyer\n";
    cout<<"\t\t\t_____________\n";
    cout<<"\t\t\t             \n";
    cout<<"\t\t\t 1)Buy Product\n";
    cout<<"\t\t\t             \n";
    cout<<"\t\t\t 2)Go back   \n";
    cout<<"Enter your choice  \n";
    cin>>choice;
    if (cin.fail()) {
    cout << "" << endl;
    system("CLS");
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
    switch(choice){
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout<<"Invalid Choice"<<endl;
       goto m;

    }
     //goto m;

}//buyer fun ended
void shopping::add()
{
    fstream data;
    int pcode, token = 0;
    string pname;
    float price, discount;

    cout << "\n\n\t\t\tAdd the product" << endl;
    cout << "\n\n\t\t\tEnter Product Code: ";
    cin >> pcode;
    if (cin.fail()) {
    cout << "Invalid Input ! " << endl;
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}

    data.open("database.txt", ios::in);
    if (data.is_open()) {
        int c;
        string n;
        float p, d;

        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                token = 1;
                break;
            }
        }
        data.close();
    }

    if (token == 1) {
        cout << "\n\t\t\tProduct code already exists. Please enter a different product code." << endl;
        return;
    }

    cin.ignore();
    cout << "\n\n\t\t\tName of the Product: ";
    getline(cin, pname);
    cout << "\n\n\t\t\tPrice of the Product: ";
    cin >> price;
    cout << "\n\n\t\t\tDiscount on the product: ";
    cin >> discount;

    data.open("database.txt", ios::app | ios::out);
    if (data.is_open()) {
        data << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
        cout << "\n\n\t\t Record inserted!" << endl;
    }
    else {
        cout << "\n\n\t\t Error opening file." << endl;
    }
}//add fun ended



void shopping ::edit()
{
	fstream data,data1;
int pkey;
int token=0;
int c;
float p;
float d;
string n;
cout<<"\n\t\t\t Modify the record";
cout<<"\n\t\t\t Product code :";
cin>>pkey;
if (cin.fail()) {
    cout << "Invalid Input ! " << endl;
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
data.open("database.txt",ios::in);
if(!data)
{
	cout<<"\n\n File does not exist ! ";
}
else
{
	data1.open("database1.txt",ios::app|ios::out);
	data>>pcode>>pname>>price>>discount;
	while(!data.eof())
	{
		if(pkey==pcode)
		{
			cout<<"\n\t\t Product new code : ";
			cin>>c;
			cout<<"\n\t\t Name of the product : ";
			cin>>n;
			cout<<"\n\t\t Price : ";
			cin>>p;
			cout<<"\n\t\t discount : ";
			cin>>d;
			data1<<c<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n";
			cout<<"\n\t\t\t Record edited";
			token++;
		}
		else
		{
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount;
		}
		 data>>pcode>>pname>>price>>discount;
	}
	data.close();
	data1.close();
	remove("database.txt");
	rename("database1.txt","database.txt");
	if(token==0)
	{
		cout<<"\n\n record not found sorry";
	}
}

}// edit fun ended
void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete the product : ";
	cout<<"\n\n\t Enter the product code : ";
	cin>>pkey;
	if (cin.fail()) {
    cout << "Invalid Input ! " << endl;
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
	data.open("database.txt",ios::in);
	if (!data){
		cout<<"File doesnt exist "<<endl;
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pcode==pkey){
				cout<<"\n\n\t Product deleted successfully ! ";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		if(token==0){
			cout<<"\n\n\t record is not found ";
		}
		else{
			remove("database.txt");
			rename("database1.txt","database.txt");
		}
	}
}
void shopping::List()
{
	string name;
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n_____________________________________\n";
	cout<<"proNo\t\t name\t\t price\n";
	cout<<"\n\n_____________________________________\n";
	data>>pcode>>pname>>price>>discount;
/*	while(getline(data,name)){
			cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;
	}
	data.close();*/
while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;
	}
	data.close();
}//list fun ended
void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float discount=0;
    float total=0;
    bool isEmpty = true; // added variable to check if the database is empty
    cout<<"\n\t\t\t\t\t\t\t\t Receipt\n ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t\t Empty database ! \n";
    }
    else
    {
        // Check if the database is empty
        data.seekg(0, ios::end);
        if (data.tellg() == 0) {
            cout << "\n\t\t\t No products found in the database. Please contact the administrator. \n";
            data.close();
            return;
        }
        data.seekg(0, ios::beg);
        // Proceed with the rest of the function if the database is not empty
        data.close();
        cout<<endl;
        cout<<"\nWELCOME TO SHOPPING MART ! \n";
        List();
        cout<<"\n";
        cout<<"\n_________________________________\n";
        cout<<"\n                                \n";
        cout<<"\n  Please place the order         \n";
        cout<<"\n                                  \n";
        cout<<"\n__________________________________ \n";
        do{
            m:
            cout<<"\n\nEnter product code\n";
            cin>>arrc[c];
            if (cin.fail()) {
    cout << "Invalid Input ! " << endl;
    cin.clear(); // clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input
} else {
    // process the valid input
}
            if(arrc[c]!=pcode){
            	cout<<"\t\t\t Product code is not found ! \n";
            	receipt();
			}
            cout<<"\n\nEnter the product quantity\n";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrq[c]){
                    cout<<"\n\n Duplicate product code.Please try again !\n";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product,If yes then press y otherwise press n:\n";
            cin>>choice;
        }
		
       while(choice=='y');
    if(choice=='n'){
   // cout<<"\t\tHappy Shopping !!! \n \t\t\tThank You ! \n";
    	//sleep(3);
    	//system("CLS");
    //	menu();
    	
	}
	else{
		system("CLS");
		cout<<"\t\t\t Invalid Input ! "<<endl;
		receipt();
	}
        // Perform time-consuming operation
        for (int i = 0; i < 10; i++) {
            // Display "Loading, please wait" message
            cout << "Loading, please wait...";

            // Display progress indicator
            for (int j = 0; j <= i; j++) {
                cout << ".";
            }

            // Wait for a moment to slow down the progress indicator
            this_thread::sleep_for(chrono::milliseconds(50));

            // Clear the console window
            system("cls");
        }
        // Display completion message
        cout << "Here is your receipt!\n";
        cout << "\n\n\t\t\t____________________Receipt______________________\n";
        cout << "\nProduct no \t\tProduct name \tProduct quantity \tAmount-Price\tAmount with discount\n";
        cout<<endl;

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t"<<amount<<"\t"<<"("<<discount<<")";
                    isEmpty = false; // set to false if there is at least one product in the receipt
                }
                data>>pcode>>pname>>price>>discount;
            }
            data.close();
            cout << "-------------------------------------------\n";
    cout << "Total amount: " << total << "\n";
    cout << "-------------------------------------------\n";
    cout<<"\t\t\t Happy Shopping !!! Thank you! \n";
    menu();
}
}
}//receipt fun ended
int main()
{
	system("color e0");//THis will  set color of console
	shopping s;
	// Perform time-consuming operation
    for (int i = 0; i < 10; i++)
    {
        // Display "Loading, please wait" message
        cout << "\t\t\t\tWelcome to the Super Mart !";

        // Display progress indicator
        for (int j = 0; j <= i; j++)
        {
            cout << ".";
        }

        // Wait for a moment to slow down the progress indicator
        this_thread::sleep_for(chrono::milliseconds(50));

        // Clear the console window
        system("cls");
    }
    
    cout << "\t\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t|                  Supermarket Billing System         |" << endl;
    cout << "\t\t\t|                                                     |" << endl;
    cout << "\t\t\t|                  Roll No: 22SW041                   |" << endl;
    cout << "\t\t\t|                                                     |" << endl;
    cout << "\t\t\t|                  Name:Asfand Ali                    |" << endl;
    cout << "\t\t\t-------------------------------------------------------" << endl;
   	s.menu();
	





    return 0;
}
