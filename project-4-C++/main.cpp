//William Lemay, 4/25/22. Main file for project4, implements all other files together to execute main function.
#include "AutoDealer.h"

int main()
{
    AutoDealer dealer;
    dealer.readCarsFile();

    int choice;
    do
    {
        cout<<"\n\n**************** MENU ****************";
        cout<<"\n\t1 - Input Car Information";
        cout<<"\n\t2 - Display Car Information";
        cout<<"\n\t3 - Search Car Information";
        cout<<"\n\t4 - Exit";
        cout<<"\nEnter a number 1-4: ";
        cin>>choice;
        switch(choice)
        {
            //allows user to input a car into array
            case 1:
                dealer.inputCarInfo();
                break;
            //displays cars in array
            case 2:
                dealer.displayCars();
                break;
            //search one car in array
            case 3:
                dealer.searchCar();
                break;
            //writes cars into text file, closes program
            case 4:
                dealer.writeCarsFile();
                cout<<"\nThank you for using this program.";
                exit(0);
                //if user tries to put number other than 1-4, displays this. if user inputs letter, program infinite loops.
            default:
                cout<<"\nInvalid Choice.";
        }
    }
    while(true);
}