/********************************************************************************
** Form generated from reading UI file 'bilateralfilterdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILATERALFILTERDLG_H
#define UI_BILATERALFILTERDLG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bilateralFilterDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *bilateralFilterDlg)
    {
        if (bilateralFilterDlg->objectName().isEmpty())
            bilateralFilterDlg->setObjectName(QStringLiteral("bilateralFilterDlg"));
        bilateralFilterDlg->resize(579, 441);
        verticalLayout_2 = new QVBoxLayout(bilateralFilterDlg);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(bilateralFilterDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(bilateralFilterDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(bilateralFilterDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(bilateralFilterDlg);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(bilateralFilterDlg);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_3 = new QLineEdit(bilateralFilterDlg);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(bilateralFilterDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(bilateralFilterDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), bilateralFilterDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), bilateralFilterDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(bilateralFilterDlg);
    } // setupUi

    void retranslateUi(QDialog *bilateralFilterDlg)
    {
        bilateralFilterDlg->setWindowTitle(QApplication::translate("bilateralFilterDlg", "Dialog", 0));
        label->setText(QApplication::translate("bilateralFilterDlg", "\350\276\223\345\205\245Size:", 0));
        label_2->setText(QApplication::translate("bilateralFilterDlg", "\350\276\223\345\205\245SigmaSpace:", 0));
        label_3->setText(QApplication::translate("bilateralFilterDlg", "\350\276\223\345\205\245SigmaColor:", 0));
    } // retranslateUi

};

namespace Ui {
    class bilateralFilterDlg: public Ui_bilateralFilterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILATERALFILTERDLG_H
