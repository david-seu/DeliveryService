#include <QMessageBox>
#include <sstream>
#include "companyview.h"
#include "ui_companyview.h"

CompanyView::CompanyView(Controller* controller,QWidget *parent) :
    QWidget(parent), controller(controller),
    ui(new Ui::CompanyView)
{
    ui->setupUi(this);
    populateList();
}

CompanyView::~CompanyView()
{
    delete ui;
}

void CompanyView::update() {
    populateList();
}

void CompanyView::populateList() {
    ui->listWidgetPackage->clear();

    for(auto& p: controller->getPackages())
    {
        auto* item = new QListWidgetItem;
        item->setText(QString::fromStdString(p.toString()));
        if(p.getStatus()=="Delivered"){
            item->setBackground(QBrush("green"));
        }
        ui->listWidgetPackage->addItem(item);
    }
}

void CompanyView::addPackage() {
    string recipient = ui->lineEditRecipient->text().toStdString();
    string location = ui->lineEditLocation->text().toStdString();
    string street = ui->lineEditStreet->text().toStdString();

    if(recipient.empty() || location.empty() || street.empty()){
        QMessageBox::warning(this,"Warning","Fill form");
    }
    else{
        int x,y;
        string token;
        vector<string> data;
        stringstream ss(location);
        while(getline(ss,token,' '))
        {
            data.push_back(token);
        }
        try{
            x = stoi(data[0]);
            y = stoi(data[1]);
        }
        catch(exception& e){
            QMessageBox::warning(this,"Warning","Invalid location");
            return;
        }
        string streetName;
        int n;
        data.clear();
        stringstream ss1(street);
        while(getline(ss1,token,' '))
        {
            data.push_back(token);
        }
        streetName = data[0];
        try{
            n = stoi(data[1]);
        }
        catch (exception& e) {
            QMessageBox::warning(this,"Warning","Invalid street");
            return;
        }
        controller->addPackage(recipient,streetName,n,x,y);
    }

}

