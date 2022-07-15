//William Lemay, 4/25/22. declares variables and function definitions. Contains carRecord array of class Car.
#include "Car.h"

class AutoDealer {
    Car carRecord[50];
    int countCar;
public:
    AutoDealer() {
        countCar = 0;
    }
    void readCarsFile();
    void inputCarInfo();
    void searchCar();
    void displayCars();
    void writeCarsFile();
    int carEntered = false;
};