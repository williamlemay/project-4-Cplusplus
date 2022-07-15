//William Lemay, 4/25/22. includes implementation for functions declared in AutoDealer.h
#include "AutoDealer.h"

//reads text file and inputs that data into carRecord array.
void AutoDealer::readCarsFile() {
    string tempYear,tempPrice;
    ifstream readF;
    readF.open("CarInfo.txt");
    //if CarInfo.txt is unavailable, this message appears and program doesn't run
    if (!readF) {
        cout << "\nUnable to open file 'CarInfo.txt' for reading.";
        exit(0);
    }
    while (!readF.eof())
    {
        getline(readF, carRecord[countCar].makeAndModel, '|');

        //year and price both have to be converted to their matching type in order to use get line.
        //getline can only get strings, so the program uses stoi and stof respectively. (string to int, string to float)
        //the temporary string versions are held in "tempYear" and "tempPrice".
        getline(readF, tempYear, '|');
        carRecord[countCar].year = stoi(tempYear);

        getline(readF, carRecord[countCar].color, '|');
        getline(readF, carRecord[countCar].vehicleClass, '|');
        getline(readF, carRecord[countCar].fuelType, '|');

        getline(readF, tempPrice, '\n');
        carRecord[countCar].price = stof(tempPrice);

        countCar++;
    }
    readF.close();
}

//allows user to input car information and adds car to array
void AutoDealer::inputCarInfo() {
    carEntered = true;
    cout << "\nEnter Make and Model: ";
    getline(cin >> ws, carRecord[countCar].makeAndModel);
    cout << "\nEnter Year: ";
    cin >> carRecord[countCar].year;
    cout << "\nEnter Color: ";
    cin >> carRecord[countCar].color;
    cout << "\nEnter Class: ";
    cin >> carRecord[countCar].vehicleClass;
    cout << "\nEnter Fuel Type: ";
    cin >> carRecord[countCar].fuelType;
    cout << "\nEnter Price: ";
    cin >> carRecord[countCar].price;
    countCar++;
}

//searches all array entries and matches model, color, and class to display car information.
void AutoDealer::searchCar()
{
//strings store data for comparison
    string searchMake;
    string searchColor;
    string searchClass;
    int searchFound = -1;
    cout<<"\nEnter Make and Model: ";
    getline(cin>>ws,searchMake);
    cout<<"\nEnter Color: ";
    cin>>searchColor;
    cout<<"\nEnter Class: ";
    getline(cin>>ws,searchClass);

//control is used to control the amount of times loop runs and decides array element
    for(int control = 0; control < countCar; control++)
    {
        if( (carRecord[control].makeAndModel.compare(searchMake) == 0) &&
            (carRecord[control].color.compare(searchColor) == 0) && (carRecord[control].vehicleClass.compare(searchClass) == 0) )
        {
            searchFound = control;
            break;
        }
    }

    if(searchFound != -1){
        cout<<"\nAUTO DEALER CAR INVENTORY";
        cout<<"\n         MAKE AND MODEL         |  YEAR  |  COLOR  |  CLASS  |  FUEL TYPE  |   PRICE   |";
        cout<<"\n--------------------------------|--------|---------|---------|-------------|-----------|";
        cout<<"\n"<<setw(31)<<carRecord[searchFound].makeAndModel
            <<setw(9)<<carRecord[searchFound].year
            <<setw(9)<<carRecord[searchFound].color
            <<setw(11)<<carRecord[searchFound].vehicleClass
            <<setw(13)<<carRecord[searchFound].fuelType
            <<setprecision(2)<<fixed<<setw(6)<<"$"<<carRecord[searchFound].price;
    }
    else
        cout<<"\nNo vehicle found matching your information.";
}

//displays all cars currently on record
void AutoDealer::displayCars()
{
    cout<<"\nAUTO DEALER CAR INVENTORY";
    cout<<"\n         MAKE AND MODEL         |  YEAR  |  COLOR  |  CLASS  |  FUEL TYPE  |   PRICE   |";
    cout<<"\n--------------------------------|--------|---------|---------|-------------|-----------|";

    for(int control = 0; control < countCar; control++)
        cout<<"\n"<<setw(31)<<carRecord[control].makeAndModel
            <<setw(9)<<carRecord[control].year
            <<setw(9)<<carRecord[control].color
            <<setw(11)<<carRecord[control].vehicleClass
            <<setw(13)<<carRecord[control].fuelType
            <<setprecision(2)<<fixed<<setw(6)<<"$"<<carRecord[control].price;
}

//writes cars in array to "carinfo.txt" text file.
void AutoDealer::writeCarsFile()
{
    //if a car has not been entered, nothing is entered into the text file. carEntered is automatically true
    //if a car is entered.
    if (carEntered == true){
        ofstream writeF;
        writeF.open("CarInfo.txt");

        if(!writeF)
        {
            //if CarInfo.txt is unavailable, this message appears and program doesn't write.
            cout<<"\nUnable to open file 'CarInfo.txt' for writing.";
            exit(0);
        }
        for(int control = 0; control < countCar; control++)
        {
            writeF<<carRecord[control].makeAndModel<<"|"<<carRecord[control].year<<"|"<<carRecord[control].color<<"|"
                  <<carRecord[control].vehicleClass<<"|"<<carRecord[control].fuelType<<"|"<<carRecord[control].price<<"\n";
        }
        writeF.close();
    }
}