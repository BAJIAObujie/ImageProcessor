/********************************************************************************
** Form generated from reading UI file 'medianfilterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIANFILTERDIALOG_H
#define UI_MEDIANFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MedianFilterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MedianFilterDialog)
    {
        if (MedianFilterDialog->objectName().isEmpty())
            MedianFilterDialog->setObjectName(QStringLiteral("MedianFilterDialog"));
        MedianFilterDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(MedianFilterDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(MedianFilterDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(MedianFilterDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(MedianFilterDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(MedianFilterDialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(MedianFilterDialog);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton = new QRadioButton(MedianFilterDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        buttonBox = new QDialogButtonBox(MedianFilterDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(2, 1);

        retranslateUi(MedianFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MedianFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MedianFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MedianFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *MedianFilterDialog)
    {
        MedianFilterDialog->setWindowTitle(QApplication::translate("MedianFilterDialog", "Dialog", 0));
        label->setText(QApplication::translate("MedianFilterDialog", "\350\276\223\345\205\245Size:", 0));
        checkBox->setText(QApplication::translate("MedianFilterDialog", "\344\270\255\345\200\274\346\273\244\346\263\242", 0));
        checkBox_2->setText(QApplication::translate("MedianFilterDialog", "Dilation\350\206\250\350\203\200", 0));
        checkBox_3->setText(QApplication::translate("MedianFilterDialog", "Erosion \350\205\220\350\232\200", 0));
        radioButton->setText(QApplication::translate("MedianFilterDialog", "\347\201\260\345\272\246\345\244\204\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class MedianFilterDialog: public Ui_MedianFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIANFILTERDIALOG_H
