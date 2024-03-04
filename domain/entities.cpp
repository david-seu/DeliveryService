//
// Created by seu21 on 28.06.2023.
//

#include "entities.h"

Package::Package(const string &recipient, const string &street, int number, int x, int y, const string &status)
        : recipient(recipient), street(street), number(number), x(x), y(y), status(status) {}

const string &Package::getRecipient() const {
    return recipient;
}

void Package::setRecipient(const string &recipient) {
    Package::recipient = recipient;
}

const string &Package::getStreet() const {
    return street;
}

void Package::setStreet(const string &street) {
    Package::street = street;
}

int Package::getNumber() const {
    return number;
}

void Package::setNumber(int number) {
    Package::number = number;
}

int Package::getX() const {
    return x;
}

void Package::setX(int x) {
    Package::x = x;
}

int Package::getY() const {
    return y;
}

void Package::setY(int y) {
    Package::y = y;
}

const string &Package::getStatus() const {
    return status;
}

void Package::setStatus(const string &status) {
    Package::status = status;
}

Package::Package() {}

string Package::toString() {
    return recipient + "|" + street + "|" + to_string(number) + "|" + to_string(x) + "|" + to_string(y) + "|" + status;
}

string Package::toStringUndelivered() {
    return recipient + "|" + street + "|" + to_string(number) + "|" + to_string(x) + "|" + to_string(y);
}

Courier::Courier(const string &name, const vector<string> &streets, int radius, int centreX,int centreY) : name(name),
                                                                                              streets(streets),
                                                                                              radius(radius),
                                                                                              centreX(centreX), centreY(centreY) {}

Courier::Courier() {}

const string &Courier::getName() const {
    return name;
}

void Courier::setName(const string &name) {
    Courier::name = name;
}

const vector<string> &Courier::getStreets() const {
    return streets;
}

void Courier::setStreets(const vector<string> &streets) {
    Courier::streets = streets;
}

int Courier::getRadius() const {
    return radius;
}

void Courier::setRadius(int radius) {
    Courier::radius = radius;
}

pair<int,int> Courier::getCentre() const {
    return make_pair(centreX,centreY);
}

