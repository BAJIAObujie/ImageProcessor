/********************************************************************************
** Form generated from reading UI file 'gauss_parameter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSS_PARAMETER_H
#define UI_GAUSS_PARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Gauss_parameter
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Gauss_parameter)
    {
        if (Gauss_parameter->objectName().isEmpty())
            Gauss_parameter->setObjectName(QStringLiteral("Gauss_parameter"));
        Gauss_parameter->resize(417, 314);
        verticalLayout_2 = new QVBoxLayout(Gauss_parameter);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Gauss_parameter);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Gauss_parameter);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Gauss_parameter);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Gauss_parameter);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton = new QRadioButton(Gauss_parameter);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);

        buttonBox = new QDialogButtonBox(Gauss_parameter);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Gauss_parameter);
        QObject::connect(buttonBox, SIGNAL(accepted()), Gauss_parameter, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Gauss_parameter, SLOT(reject()));

        QMetaObject::connectSlotsByName(Gauss_parameter);
    } // setupUi

    void retranslateUi(QDialog *Gauss_parameter)
    {
        Gauss_parameter->setWindowTitle(QApplication::translate("Gauss_parameter", "Dialog", 0));
        label->setText(QApplication::translate("Gauss_parameter", "\350\276\223\345\205\245Size:", 0));
        label_2->setText(QApplication::translate("Gauss_parameter", "\350\276\223\345\205\245Sigma:", 0));
        radioButton->setText(QApplication::translate("Gauss_parameter", "\347\201\260\345\272\246\345\244\204\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class Gauss_parameter: public Ui_Gauss_parameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSS_PARAMETER_H
