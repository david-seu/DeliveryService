#include <QPainter>
#include "mapview.h"
#include "ui_mapview.h"

MapView::MapView(Controller* controller, QWidget *parent) :
    controller(controller),
    QWidget(parent),
    ui(new Ui::MapView)
{
    ui->setupUi(this);
    drawStatistic();
}

MapView::~MapView()
{
    delete ui;
}

void MapView::paintEvent(QPaintEvent *event) {
    drawStatistic();
}

void MapView::update(){
    repaint();
}

void MapView::drawStatistic() {
    QPainter painter{ this };

    vector<Package> packages;

    for(auto& p: controller->getPackages()) {
        if (p.getStatus() == "Undelivered") {
                packages.push_back(p);
        }
    }


    for (auto package : packages)
    {
        painter.drawRect(package.getX()*10, package.getY()*10, 80, 30);
        painter.drawText(package.getX()*10, package.getY()*10, 80, 30, Qt::AlignCenter, QString::fromStdString(to_string(package.getX()) + " " + to_string(package.getY()) + " " + package.getRecipient()));
    }
}
