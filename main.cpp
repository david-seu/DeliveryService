//
// Created by seu21 on 28.06.2023.
//
#include "controller.h"
#include "companyview.h"
#include "view.h"
#include "mapview.h"
#include <QApplication>
int main(int argc, char* argv[]){
    QApplication a(argc,argv);
    auto* controller = new Controller("data\\courier","data\\package");

    for(auto& c: controller->getCourier())
    {
        auto* view = new View(controller,c.getName());
        view->setWindowTitle(QString::fromStdString(c.getName()));
        view->show();
        controller->addObserver(view);
    }
    auto* view = new CompanyView(controller);
    view->setWindowTitle("Courier Company");
    view->show();
    controller->addObserver(view);
    auto* map = new MapView(controller);
    map->setWindowTitle("Map");
    map->show();
    controller->addObserver(map);
    auto r =  a.exec();
    delete controller;
    return r;
}