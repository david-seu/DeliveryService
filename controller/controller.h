//
// Created by seu21 on 28.06.2023.
//

#pragma once

#include <valarray>
#include "entities.h"
#include "observer/observer.h"

class Controller: public Subject{
private:
    string courierFile;
    string packageFile;
    vector<Courier> couriers;
    vector<Package> packages;
    vector<string> street;
    void readCourier();
    void readPackage();
    void writePackage();
public:
    Controller(const string &courierFile, const string &packageFile);
    vector<Package> getPackages();
    vector<Courier> getCourier();
    Courier getCourier(const string& name);

    void deliverPackage(const string& recipient, const string& street, int number);

    void addPackage(const string& recipient, const string& street, int number, int x, int y);

    static bool isPointInsideCircle(int cx, int cy, int r, int x1, int y1) {
        int distance = std::sqrt(std::pow(x1 - cx, 2) + std::pow(y1 - cy, 2));
        return distance <= r;
    }

    vector<string> getStreets();

    virtual ~Controller();
};


