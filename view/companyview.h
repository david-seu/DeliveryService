#ifndef COMPANYVIEW_H
#define COMPANYVIEW_H

#include <QWidget>
#include "controller.h"
#include "observer/observer.h"
namespace Ui {
class CompanyView;
}

class CompanyView : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit CompanyView(Controller* controller,QWidget *parent = nullptr);
    ~CompanyView();

private:
    Ui::CompanyView *ui;
    Controller* controller;
    void update() override;
    void populateList();
public slots:
    void addPackage();
};

#endif // COMPANYVIEW_H
