/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLinear;
    QAction *actionGaussBlur;
    QAction *actionBilateralFilter;
    QAction *actionGauss;
    QAction *actionMedian;
    QAction *actionBilateral;
    QAction *actionDilation;
    QAction *actionErosion;
    QAction *actionAffine;
    QAction *actionSpectrum;
    QAction *actionRGBToGray;
    QAction *actionImageReversal;
    QAction *actionLogTransform;
    QAction *actionGrayToHist;
    QAction *actionRGBToHist;
    QAction *actionRGBToHSI;
    QAction *actionSaveImage;
    QAction *actionLowPassFilter;
    QAction *actionHighPassFilter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QPushButton *btnOpen;
    QPushButton *btnReset;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPre;
    QPushButton *btnNext;
    QMenuBar *menuBar;
    QMenu *menuSpatial_Filter;
    QMenu *menuAffine_Transform;
    QMenu *menuIntensity_Transform;
    QMenu *menuSpectrum_Transform;
    QMenu *menuSaveImage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(777, 486);
        actionLinear = new QAction(MainWindow);
        actionLinear->setObjectName(QStringLiteral("actionLinear"));
        actionGaussBlur = new QAction(MainWindow);
        actionGaussBlur->setObjectName(QStringLiteral("actionGaussBlur"));
        actionBilateralFilter = new QAction(MainWindow);
        actionBilateralFilter->setObjectName(QStringLiteral("actionBilateralFilter"));
        actionGauss = new QAction(MainWindow);
        actionGauss->setObjectName(QStringLiteral("actionGauss"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionBilateral = new QAction(MainWindow);
        actionBilateral->setObjectName(QStringLiteral("actionBilateral"));
        actionDilation = new QAction(MainWindow);
        actionDilation->setObjectName(QStringLiteral("actionDilation"));
        actionErosion = new QAction(MainWindow);
        actionErosion->setObjectName(QStringLiteral("actionErosion"));
        actionAffine = new QAction(MainWindow);
        actionAffine->setObjectName(QStringLiteral("actionAffine"));
        actionSpectrum = new QAction(MainWindow);
        actionSpectrum->setObjectName(QStringLiteral("actionSpectrum"));
        actionRGBToGray = new QAction(MainWindow);
        actionRGBToGray->setObjectName(QStringLiteral("actionRGBToGray"));
        actionImageReversal = new QAction(MainWindow);
        actionImageReversal->setObjectName(QStringLiteral("actionImageReversal"));
        actionLogTransform = new QAction(MainWindow);
        actionLogTransform->setObjectName(QStringLiteral("actionLogTransform"));
        actionGrayToHist = new QAction(MainWindow);
        actionGrayToHist->setObjectName(QStringLiteral("actionGrayToHist"));
        actionRGBToHist = new QAction(MainWindow);
        actionRGBToHist->setObjectName(QStringLiteral("actionRGBToHist"));
        actionRGBToHSI = new QAction(MainWindow);
        actionRGBToHSI->setObjectName(QStringLiteral("actionRGBToHSI"));
        actionSaveImage = new QAction(MainWindow);
        actionSaveImage->setObjectName(QStringLiteral("actionSaveImage"));
        actionLowPassFilter = new QAction(MainWindow);
        actionLowPassFilter->setObjectName(QStringLiteral("actionLowPassFilter"));
        actionHighPassFilter = new QAction(MainWindow);
        actionHighPassFilter->setObjectName(QStringLiteral("actionHighPassFilter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        btnOpen = new QPushButton(centralWidget);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));

        verticalLayout->addWidget(btnOpen);

        btnReset = new QPushButton(centralWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));

        verticalLayout->addWidget(btnReset);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPre = new QPushButton(centralWidget);
        btnPre->setObjectName(QStringLiteral("btnPre"));

        horizontalLayout->addWidget(btnPre);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));

        horizontalLayout->addWidget(btnNext);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 777, 26));
        menuSpatial_Filter = new QMenu(menuBar);
        menuSpatial_Filter->setObjectName(QStringLiteral("menuSpatial_Filter"));
        menuAffine_Transform = new QMenu(menuBar);
        menuAffine_Transform->setObjectName(QStringLiteral("menuAffine_Transform"));
        menuIntensity_Transform = new QMenu(menuBar);
        menuIntensity_Transform->setObjectName(QStringLiteral("menuIntensity_Transform"));
        menuSpectrum_Transform = new QMenu(menuBar);
        menuSpectrum_Transform->setObjectName(QStringLiteral("menuSpectrum_Transform"));
        menuSaveImage = new QMenu(menuBar);
        menuSaveImage->setObjectName(QStringLiteral("menuSaveImage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSaveImage->menuAction());
        menuBar->addAction(menuIntensity_Transform->menuAction());
        menuBar->addAction(menuSpatial_Filter->menuAction());
        menuBar->addAction(menuSpectrum_Transform->menuAction());
        menuBar->addAction(menuAffine_Transform->menuAction());
        menuSpatial_Filter->addAction(actionLinear);
        menuSpatial_Filter->addAction(actionGauss);
        menuSpatial_Filter->addAction(actionMedian);
        menuSpatial_Filter->addAction(actionBilateral);
        menuAffine_Transform->addAction(actionAffine);
        menuIntensity_Transform->addAction(actionRGBToGray);
        menuIntensity_Transform->addAction(actionImageReversal);
        menuIntensity_Transform->addAction(actionLogTransform);
        menuIntensity_Transform->addAction(actionGrayToHist);
        menuIntensity_Transform->addAction(actionRGBToHist);
        menuIntensity_Transform->addAction(actionRGBToHSI);
        menuSpectrum_Transform->addAction(actionSpectrum);
        menuSpectrum_Transform->addAction(actionLowPassFilter);
        menuSpectrum_Transform->addAction(actionHighPassFilter);
        menuSaveImage->addAction(actionSaveImage);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLinear->setText(QApplication::translate("MainWindow", "Linear", Q_NULLPTR));
        actionGaussBlur->setText(QApplication::translate("MainWindow", "Gauss Blur", Q_NULLPTR));
        actionBilateralFilter->setText(QApplication::translate("MainWindow", "Bilateral Filter", Q_NULLPTR));
        actionGauss->setText(QApplication::translate("MainWindow", "Gauss", Q_NULLPTR));
        actionMedian->setText(QApplication::translate("MainWindow", "Median/Dilation/Erosion", Q_NULLPTR));
        actionBilateral->setText(QApplication::translate("MainWindow", "Bilateral", Q_NULLPTR));
        actionDilation->setText(QApplication::translate("MainWindow", "Dilation", Q_NULLPTR));
        actionErosion->setText(QApplication::translate("MainWindow", "Erosion", Q_NULLPTR));
        actionAffine->setText(QApplication::translate("MainWindow", "Affine", Q_NULLPTR));
        actionSpectrum->setText(QApplication::translate("MainWindow", "Spectrum", Q_NULLPTR));
        actionRGBToGray->setText(QApplication::translate("MainWindow", "RGBToGray", Q_NULLPTR));
        actionImageReversal->setText(QApplication::translate("MainWindow", "ImageReversal", Q_NULLPTR));
        actionLogTransform->setText(QApplication::translate("MainWindow", "LogTransform", Q_NULLPTR));
        actionGrayToHist->setText(QApplication::translate("MainWindow", "GrayToHist", Q_NULLPTR));
        actionRGBToHist->setText(QApplication::translate("MainWindow", "RGBToHist", Q_NULLPTR));
        actionRGBToHSI->setText(QApplication::translate("MainWindow", "RGBToHSI", Q_NULLPTR));
        actionSaveImage->setText(QApplication::translate("MainWindow", "SaveImage", Q_NULLPTR));
        actionLowPassFilter->setText(QApplication::translate("MainWindow", "LowPassFilter", Q_NULLPTR));
        actionHighPassFilter->setText(QApplication::translate("MainWindow", "HighPassFilter", Q_NULLPTR));
        btnOpen->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        btnReset->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        btnPre->setText(QApplication::translate("MainWindow", "previous", Q_NULLPTR));
        btnNext->setText(QApplication::translate("MainWindow", "next", Q_NULLPTR));
        menuSpatial_Filter->setTitle(QApplication::translate("MainWindow", "Spatial Filter", Q_NULLPTR));
        menuAffine_Transform->setTitle(QApplication::translate("MainWindow", "Affine Transform", Q_NULLPTR));
        menuIntensity_Transform->setTitle(QApplication::translate("MainWindow", "Intensity Transform", Q_NULLPTR));
        menuSpectrum_Transform->setTitle(QApplication::translate("MainWindow", "Spectrum Transform", Q_NULLPTR));
        menuSaveImage->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
