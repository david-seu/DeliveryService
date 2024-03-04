//
// Created by seu21 on 28.06.2023.
//
#pragma once
#include <string>
#include <vector>
using namespace std;

class Courier{
private:
    string name;
    vector<string> streets;
    int radius;
    int centreX;
    int centreY;
public:
    Courier(const string &name, const vector<string> &streets, int radius, int centreX,int centreY);

    Courier();

    const string &getName() const;

    void setName(const string &name);

    const vector<string> &getStreets() const;

    void setStreets(const vector<string> &streets);

    int getRadius() const;

    void setRadius(int radius);

    pair<int,int> getCentre() const;

};


class Package{
private:
    string recipient;
    string street;
    int number;
    int x;
    int y;
    string status;
public:

    Package(const string &recipient, const string &street, int number, int x, int y, const string &status);

    const string &getRecipient() const;

    void setRecipient(const string &recipient);

    const string &getStreet() const;

    void setStreet(const string &street);

    int getNumber() const;

    void setNumber(int number);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    const string &getStatus() const;

    void setStatus(const string &status);

    Package();

    string toString();

    string toStringUndelivered();
};