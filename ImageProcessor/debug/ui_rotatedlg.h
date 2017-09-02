/********************************************************************************
** Form generated from reading UI file 'rotatedlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEDLG_H
#define UI_ROTATEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RotateDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_9;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RotateDlg)
    {
        if (RotateDlg->objectName().isEmpty())
            RotateDlg->setObjectName(QStringLiteral("RotateDlg"));
        RotateDlg->resize(416, 311);
        verticalLayout = new QVBoxLayout(RotateDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(RotateDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(false);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(RotateDlg);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(RotateDlg);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        lineEdit_5 = new QLineEdit(RotateDlg);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setReadOnly(false);

        gridLayout->addWidget(lineEdit_5, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(RotateDlg);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(true);
        lineEdit_3->setAcceptDrops(true);
        lineEdit_3->setReadOnly(true);

        gridLayout->addWidget(lineEdit_3, 0, 2, 1, 1);

        lineEdit_7 = new QLineEdit(RotateDlg);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setReadOnly(true);

        gridLayout->addWidget(lineEdit_7, 2, 0, 1, 1);

        lineEdit_8 = new QLineEdit(RotateDlg);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setReadOnly(true);

        gridLayout->addWidget(lineEdit_8, 2, 1, 1, 1);

        lineEdit_6 = new QLineEdit(RotateDlg);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setReadOnly(true);

        gridLayout->addWidget(lineEdit_6, 1, 2, 1, 1);

        lineEdit_9 = new QLineEdit(RotateDlg);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setReadOnly(true);

        gridLayout->addWidget(lineEdit_9, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(RotateDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RotateDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), RotateDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RotateDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(RotateDlg);
    } // setupUi

    void retranslateUi(QDialog *RotateDlg)
    {
        RotateDlg->setWindowTitle(QApplication::translate("RotateDlg", "Dialog", 0));
        lineEdit->setText(QApplication::translate("RotateDlg", "0.5", 0));
        lineEdit_4->setText(QApplication::translate("RotateDlg", "0.866", 0));
        lineEdit_2->setText(QApplication::translate("RotateDlg", "-0.866", 0));
        lineEdit_5->setText(QApplication::translate("RotateDlg", "0.5", 0));
        lineEdit_3->setText(QApplication::translate("RotateDlg", "0", 0));
        lineEdit_7->setText(QApplication::translate("RotateDlg", "0", 0));
        lineEdit_8->setText(QApplication::translate("RotateDlg", "0", 0));
        lineEdit_6->setText(QApplication::translate("RotateDlg", "0", 0));
        lineEdit_9->setText(QApplication::translate("RotateDlg", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class RotateDlg: public Ui_RotateDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEDLG_H
