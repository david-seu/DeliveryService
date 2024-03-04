#pragma once
#include <QWidget>
#include "controller.h"
#include "observer/observer.h"
namespace Ui {
class MapView;
}

class MapView : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit MapView(Controller* controller,QWidget *parent = nullptr);
    ~MapView();
    Controller* controller;

private:
    Ui::MapView *ui;
    void paintEvent(QPaintEvent* event) override;

    void update() override;

    void drawStatistic();
};
