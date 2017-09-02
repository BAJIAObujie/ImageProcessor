/********************************************************************************
** Form generated from reading UI file 'logtransformdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGTRANSFORMDLG_H
#define UI_LOGTRANSFORMDLG_H

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

class Ui_LogTransformDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LogTransformDlg)
    {
        if (LogTransformDlg->objectName().isEmpty())
            LogTransformDlg->setObjectName(QStringLiteral("LogTransformDlg"));
        LogTransformDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(LogTransformDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LogTransformDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LogTransformDlg);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(LogTransformDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LogTransformDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogTransformDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogTransformDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogTransformDlg);
    } // setupUi

    void retranslateUi(QDialog *LogTransformDlg)
    {
        LogTransformDlg->setWindowTitle(QApplication::translate("LogTransformDlg", "Dialog", 0));
        label->setText(QApplication::translate("LogTransformDlg", "\350\257\267\350\276\223\345\205\245\345\257\271\346\225\260\345\217\202\346\225\260\346\225\260\345\200\274 \357\274\232 ", 0));
    } // retranslateUi

};

namespace Ui {
    class LogTransformDlg: public Ui_LogTransformDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGTRANSFORMDLG_H
