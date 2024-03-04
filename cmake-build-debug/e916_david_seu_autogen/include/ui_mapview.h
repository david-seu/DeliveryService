/********************************************************************************
** Form generated from reading UI file 'mapview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPVIEW_H
#define UI_MAPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapView
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *MapView)
    {
        if (MapView->objectName().isEmpty())
            MapView->setObjectName("MapView");
        MapView->resize(400, 300);
        horizontalLayout = new QHBoxLayout(MapView);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(MapView);

        QMetaObject::connectSlotsByName(MapView);
    } // setupUi

    void retranslateUi(QWidget *MapView)
    {
        MapView->setWindowTitle(QCoreApplication::translate("MapView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapView: public Ui_MapView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPVIEW_H
