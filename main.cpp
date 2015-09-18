/*
    File Name: pgm1.cpp
    Author: Taylor Hoss
    Student ID: x432z869
    Assignment Number: 1
    Description: Will gain input on inventory items (description, quantity, price per item) and then calculate the total cost for that inventory item. After all inventory items are input the program will total all input inventory items.
    Last Changed: August 18, 2015
*/

#include <iostream>
#include <string>

//writing and reading files
#include <fstream>

//exit() and EXIT_FAILURE
#include <stdlib.h>

using namespace std;

//structure to hold the information for the inventory
struct inventory
{
    string description;
    int quantity;
    float pricePerItem;
    float totalPriceForItem;
};

int main(void)
{    
    //holds data for each item
    inventory inventoryList[50];
    //holds the current number of records obtained from the file.    
    int numRecords = 0;     
    //holds the users choice for the menu
    char choice;
    //holds the total price for entire input inventory
    float totalPriceForInventory = 0;
    
    //creating output stream
    ofstream out_file;

    //opening file and error checking
    out_file.open("inventory.txt");
    if(out_file.fail())
    {
   	 cout<<"Could not open file. Terminating program.\n";
   	 exit(EXIT_FAILURE);

    }else
    {

   	 //asking for input
   	 do
   	 {

   		 //prompts user for input or to quit
   		 do
   		 {
   			 cout<<endl<<"Do you have input? (Y or N): ";
   			 cin>>choice;
   		 }while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

   		 cout<<endl;

   		 //if user wishes to continue input...
   		 if(choice == 'Y' || choice == 'y')
   		 {
   			 //increment number of records
   			 numRecords ++;

   			 //refresh input bugger for getline
   			 cin.ignore();

   			 //get input
   			 cout<<"input description of item. ";
   			 getline(cin, inventoryList[numRecords].description);
   	 
   			 cout<<"input quantity of item. ";
   			 cin>>inventoryList[numRecords].quantity;

   			 cout<<"input price per item. ";
   			 cin>>inventoryList[numRecords].pricePerItem;
    
   			 //calculate total cost
   			 inventoryList[numRecords].totalPriceForItem = inventoryList[numRecords].quantity * inventoryList[numRecords].pricePerItem;
   		 
   			 //output users input to file
   			 out_file<<numRecords<<". Description: "<<inventoryList[numRecords].description<<"\n   Quantity: "<<inventoryList[numRecords].quantity<<"\n   Price Per Item: $"<<inventoryList[numRecords].pricePerItem<<"\n   Total Price For Quantity Of Items: $"<<inventoryList[numRecords].totalPriceForItem<<"\r\n";
   			 
   		 }
    
   	 }while(choice != 'N' && choice != 'n');
   	 //if user has no more input...

    }

    //closing file
    out_file.close();

    //calculate total
    for(int i = numRecords; i >= 0; i--)
    {
   	 totalPriceForInventory += inventoryList[i].totalPriceForItem;
    }    

    //show total and quit.    
    cout<<"Total cost for all input items in inventory is $"<<totalPriceForInventory<<"."<<endl;

    cout<<"Terminating program.";
    return 0;    
}

