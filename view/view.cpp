#include "view.h"

#include <utility>
#include "ui_view.h"
#include <QMessageBox>
#include <sstream>

View::View(    Controller* controller, string name,
QWidget *parent) : controller(controller), name(std::move(name)),
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    populateCombo();
    populateUndelivered();
    populateStreet();
    Courier c = this->controller->getCourier(this->name);
    ui->labelZone->setText("Centre: " + QString::fromStdString(to_string(c.getCentre().first) + " " + to_string(c.getCentre().second) + "; Radius: " + to_string(c.getRadius())));
}

View::~View()
{
    delete ui;
}

void View::update() {
    showPackages();
}

void View::populateUndelivered() {
    ui->listWidgetUndelivered->blockSignals(true);
    ui->listWidgetUndelivered->clear();
    ui->listWidgetUndelivered->blockSignals(false);
    Courier c = controller->getCourier(name);
    for(auto& p: controller->getPackages())
    {
        if(p.getStatus() == "Undelivered"){
            string street = p.getStreet();
            if(any_of(c.getStreets().begin(),c.getStreets().end(),[street](const string& street1){
                return street == street1;}))
            {

                    auto* item = new QListWidgetItem;
                    item->setText(QString::fromStdString(p.toStringUndelivered()));
                    ui->listWidgetUndelivered->addItem(item);
            }
            else if(controller->isPointInsideCircle(c.getCentre().first,c.getCentre().second,c.getRadius(),p.getX(),p.getY()))
            {
                auto* item = new QListWidgetItem;
                item->setText(QString::fromStdString(p.toStringUndelivered()));
                ui->listWidgetUndelivered->addItem(item);
            }
        }
    }

}

void View::populateStreet() {
    ui->listWidgetStreet->blockSignals(true);
    ui->listWidgetStreet->clear();
    ui->listWidgetStreet->blockSignals(false);
    Courier c = controller->getCourier(name);
    for(auto& s: c.getStreets())
    {
            auto* item = new QListWidgetItem;
            item->setText(QString::fromStdString(s));
            ui->listWidgetStreet->addItem(item);
    }

}

void View::deliverPackage() {
    if(!ui->listWidgetUndelivered->currentItem()->isSelected())
        QMessageBox::warning(this,"Warning","Select a pacakge");
    else{
        string datatext = ui->listWidgetUndelivered->currentItem()->text().toStdString();
        string token;
        vector<string> data;
        stringstream ss(datatext);
        while(getline(ss,token,'|'))
        {
            data.push_back(token);
        }

        controller->deliverPackage(data[0],data[1],stoi(data[2]));
    }

}

void View::showPackages() {
    ui->listWidgetUndelivered->blockSignals(true);
    ui->listWidgetUndelivered->clear();
    ui->listWidgetUndelivered->blockSignals(false);
    string street = ui->comboBoxPackage->currentText().toStdString();
    if(street == "all")
        populateUndelivered();
    else{
        for (auto &p: controller->getPackages()) {
            string street1 = p.getStreet();
            if (street1 == street) {
                if (p.getStatus() == "Undelivered") {
                    auto* item = new QListWidgetItem;
                    item->setText(QString::fromStdString(p.toStringUndelivered()));
                    ui->listWidgetUndelivered->addItem(item);
                }
            }
        }
    }
}

void View::populateCombo() {
    Courier c = controller->getCourier(name);
    ui->comboBoxPackage->blockSignals(true);
    ui->comboBoxPackage->clear();
    ui->comboBoxPackage->blockSignals(false);
        ui->comboBoxPackage->addItem("all");
    for(auto& s: c.getStreets())
    {
        ui->comboBoxPackage->addItem(QString::fromStdString(s));
    }
}


