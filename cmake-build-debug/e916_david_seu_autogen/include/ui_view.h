/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetStreet;
    QLabel *labelZone;
    QComboBox *comboBoxPackage;
    QPushButton *pushButtonDeliver;
    QListWidget *listWidgetUndelivered;

    void setupUi(QWidget *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(1723, 505);
        horizontalLayout = new QHBoxLayout(View);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        listWidgetStreet = new QListWidget(View);
        listWidgetStreet->setObjectName("listWidgetStreet");

        verticalLayout->addWidget(listWidgetStreet);

        labelZone = new QLabel(View);
        labelZone->setObjectName("labelZone");

        verticalLayout->addWidget(labelZone);

        comboBoxPackage = new QComboBox(View);
        comboBoxPackage->setObjectName("comboBoxPackage");

        verticalLayout->addWidget(comboBoxPackage);

        pushButtonDeliver = new QPushButton(View);
        pushButtonDeliver->setObjectName("pushButtonDeliver");

        verticalLayout->addWidget(pushButtonDeliver);


        horizontalLayout->addLayout(verticalLayout);

        listWidgetUndelivered = new QListWidget(View);
        listWidgetUndelivered->setObjectName("listWidgetUndelivered");

        horizontalLayout->addWidget(listWidgetUndelivered);


        retranslateUi(View);
        QObject::connect(pushButtonDeliver, SIGNAL(clicked()), View, SLOT(deliverPackage()));
        QObject::connect(listWidgetStreet, SIGNAL(doubleClicked(QModelIndex)), View, SLOT(showPackages()));
        QObject::connect(comboBoxPackage, SIGNAL(currentTextChanged(QString)), View, SLOT(showPackages()));

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QWidget *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "Form", nullptr));
        labelZone->setText(QCoreApplication::translate("View", "Zone:", nullptr));
        pushButtonDeliver->setText(QCoreApplication::translate("View", "Deliver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
