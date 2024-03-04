#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "controller.h"
#include "observer/observer.h"
namespace Ui {
class View;
}

class View : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit View(Controller* controller, string name,
    QWidget *parent = nullptr);
    ~View();

private:
    Ui::View *ui;
    Controller* controller;
    string name;
    void update() override;
    void populateUndelivered();
    void populateStreet();
    void populateCombo();
public slots:
    void deliverPackage();
    void showPackages();
};

#endif // VIEW_H
