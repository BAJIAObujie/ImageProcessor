/********************************************************************************
** Form generated from reading UI file 'lowpassfilterdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOWPASSFILTERDLG_H
#define UI_LOWPASSFILTERDLG_H

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

class Ui_LowPassFilterDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LowPassFilterDlg)
    {
        if (LowPassFilterDlg->objectName().isEmpty())
            LowPassFilterDlg->setObjectName(QStringLiteral("LowPassFilterDlg"));
        LowPassFilterDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(LowPassFilterDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LowPassFilterDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LowPassFilterDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(LowPassFilterDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LowPassFilterDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), LowPassFilterDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LowPassFilterDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(LowPassFilterDlg);
    } // setupUi

    void retranslateUi(QDialog *LowPassFilterDlg)
    {
        LowPassFilterDlg->setWindowTitle(QApplication::translate("LowPassFilterDlg", "Dialog", 0));
        label->setText(QApplication::translate("LowPassFilterDlg", "  LowPassFilterThreshold : ", 0));
    } // retranslateUi

};

namespace Ui {
    class LowPassFilterDlg: public Ui_LowPassFilterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOWPASSFILTERDLG_H
