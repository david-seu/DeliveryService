/********************************************************************************
** Form generated from reading UI file 'companyview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYVIEW_H
#define UI_COMPANYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyView
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidgetPackage;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditRecipient;
    QLabel *label_2;
    QLineEdit *lineEditStreet;
    QLabel *label_3;
    QLineEdit *lineEditLocation;
    QPushButton *pushButtonAdd;

    void setupUi(QWidget *CompanyView)
    {
        if (CompanyView->objectName().isEmpty())
            CompanyView->setObjectName("CompanyView");
        CompanyView->resize(535, 436);
        verticalLayout = new QVBoxLayout(CompanyView);
        verticalLayout->setObjectName("verticalLayout");
        listWidgetPackage = new QListWidget(CompanyView);
        listWidgetPackage->setObjectName("listWidgetPackage");

        verticalLayout->addWidget(listWidgetPackage);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(CompanyView);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEditRecipient = new QLineEdit(CompanyView);
        lineEditRecipient->setObjectName("lineEditRecipient");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditRecipient);

        label_2 = new QLabel(CompanyView);
        label_2->setObjectName("label_2");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        lineEditStreet = new QLineEdit(CompanyView);
        lineEditStreet->setObjectName("lineEditStreet");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditStreet);

        label_3 = new QLabel(CompanyView);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditLocation = new QLineEdit(CompanyView);
        lineEditLocation->setObjectName("lineEditLocation");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditLocation);


        verticalLayout->addLayout(formLayout);

        pushButtonAdd = new QPushButton(CompanyView);
        pushButtonAdd->setObjectName("pushButtonAdd");

        verticalLayout->addWidget(pushButtonAdd);


        retranslateUi(CompanyView);
        QObject::connect(pushButtonAdd, SIGNAL(clicked()), CompanyView, SLOT(addPackage()));

        QMetaObject::connectSlotsByName(CompanyView);
    } // setupUi

    void retranslateUi(QWidget *CompanyView)
    {
        CompanyView->setWindowTitle(QCoreApplication::translate("CompanyView", "Form", nullptr));
        label->setText(QCoreApplication::translate("CompanyView", "Recipient", nullptr));
        label_2->setText(QCoreApplication::translate("CompanyView", "Street", nullptr));
        label_3->setText(QCoreApplication::translate("CompanyView", "Location", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("CompanyView", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyView: public Ui_CompanyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYVIEW_H
