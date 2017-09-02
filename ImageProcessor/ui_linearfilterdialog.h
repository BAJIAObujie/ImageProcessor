/********************************************************************************
** Form generated from reading UI file 'linearfilterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARFILTERDIALOG_H
#define UI_LINEARFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LinearFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LinearFilterDialog)
    {
        if (LinearFilterDialog->objectName().isEmpty())
            LinearFilterDialog->setObjectName(QStringLiteral("LinearFilterDialog"));
        LinearFilterDialog->resize(510, 472);
        verticalLayout = new QVBoxLayout(LinearFilterDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LinearFilterDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(LinearFilterDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton = new QRadioButton(LinearFilterDialog);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout->addWidget(radioButton);

        buttonBox = new QDialogButtonBox(LinearFilterDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LinearFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LinearFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LinearFilterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LinearFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *LinearFilterDialog)
    {
        LinearFilterDialog->setWindowTitle(QApplication::translate("LinearFilterDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LinearFilterDialog", "Kernel:", Q_NULLPTR));
        radioButton->setText(QApplication::translate("LinearFilterDialog", "\347\201\260\345\272\246\345\244\204\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LinearFilterDialog: public Ui_LinearFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARFILTERDIALOG_H
