/********************************************************************************
** Form generated from reading UI file 'highpassfilterdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHPASSFILTERDLG_H
#define UI_HIGHPASSFILTERDLG_H

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

class Ui_HighPassFilterDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *HighPassFilterDlg)
    {
        if (HighPassFilterDlg->objectName().isEmpty())
            HighPassFilterDlg->setObjectName(QStringLiteral("HighPassFilterDlg"));
        HighPassFilterDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(HighPassFilterDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(HighPassFilterDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(HighPassFilterDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(HighPassFilterDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(HighPassFilterDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), HighPassFilterDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HighPassFilterDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(HighPassFilterDlg);
    } // setupUi

    void retranslateUi(QDialog *HighPassFilterDlg)
    {
        HighPassFilterDlg->setWindowTitle(QApplication::translate("HighPassFilterDlg", "Dialog", 0));
        label->setText(QApplication::translate("HighPassFilterDlg", "  HighPassFilterThreshold : ", 0));
    } // retranslateUi

};

namespace Ui {
    class HighPassFilterDlg: public Ui_HighPassFilterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHPASSFILTERDLG_H
