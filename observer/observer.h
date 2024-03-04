//
// Created by seu21 on 28.06.2023.
//
#pragma once
#include <vector>
using namespace std;
class Observer{
public:
    virtual void update()=0;
};

class Subject{
private:
    vector<Observer*> obersvers;
public:
    void addObserver(Observer* o){
        obersvers.push_back(o);
    }

    void notify(){
        for(auto& o: obersvers)
        {
            o->update();
        }
    }
};