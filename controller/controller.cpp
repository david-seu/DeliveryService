//
// Created by seu21 on 28.06.2023.
//

#include "controller.h"
#include <fstream>
#include <sstream>

Controller::Controller(const string &courierFile, const string &packageFile) : courierFile(courierFile),
                                                                               packageFile(packageFile) {
    readCourier();
    readPackage();
}

void Controller::readCourier() {
    ifstream f(courierFile);
    if(f.is_open())
    {
        string line;
        while(getline(f,line))
        {
            string token;
            vector<string> data;
            vector<string> streets;
            stringstream ss(line);
            while(getline(ss,token,'|'))
            {
                data.push_back(token);
            }
            stringstream ss1(data[1]);
            while(getline(ss1,token,';'))
            {
                streets.push_back(token);
                if(!any_of(this->street.begin(),this->street.end(),[&token](const string& s){return s == token;}))
                    this->street.push_back(token);
            }
            Courier courier(data[0],streets,stoi(data[2]),stoi(data[3]),stoi(data[4]));
            couriers.push_back(courier);
        }

    }
    f.close();

}

void Controller::readPackage() {
    ifstream f(packageFile);
    if(f.is_open())
    {
        string line;
        while(getline(f,line))
        {
            string token;
            vector<string> data;
            stringstream ss(line);
            while(getline(ss,token,'|'))
            {
                data.push_back(token);
            }
            Package package(data[0],data[1],stoi(data[2]),stoi(data[3]),stoi(data[4]),data[5]);
            packages.push_back(package);
        }

    }
    f.close();
}

void Controller::writePackage() {
    ofstream f(packageFile);

    if(f.is_open())
    {
        for(auto& p: packages){
            f << p.toString() << '\n';
        }
    }

}

vector<Package> Controller::getPackages() {
    return packages;
}

Courier Controller::getCourier(const string& name) {
    for(auto& c: couriers)
    {
        if(c.getName() == name)
        {
            return c;
        }
    }

    return Courier();
}

void Controller::deliverPackage(const string& recipient, const string& street, int number) {
    for(auto& p: packages)
    {
        if(p.getRecipient() == recipient && p.getStreet() == street && p.getNumber() == number)
            p.setStatus("Delivered");
    }
    notify();
}

void Controller::addPackage(const string& recipient, const string& street, int number, int x, int y) {
    Package p(recipient,street,number,x,y,"Undelivered");
    packages.push_back(p);
    notify();
}

vector<Courier> Controller::getCourier() {
    return couriers;
}

Controller::~Controller() {
    writePackage();
}

vector<string> Controller::getStreets() {
    return street;
}
