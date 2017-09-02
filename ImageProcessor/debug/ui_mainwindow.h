/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLinear->setText(QApplication::translate("MainWindow", "Linear", 0));
        actionGaussBlur->setText(QApplication::translate("MainWindow", "Gauss Blur", 0));
        actionBilateralFilter->setText(QApplication::translate("MainWindow", "Bilateral Filter", 0));
        actionGauss->setText(QApplication::translate("MainWindow", "Gauss", 0));
        actionMedian->setText(QApplication::translate("MainWindow", "Median/Dilation/Erosion", 0));
        actionBilateral->setText(QApplication::translate("MainWindow", "Bilateral", 0));
        actionDilation->setText(QApplication::translate("MainWindow", "Dilation", 0));
        actionErosion->setText(QApplication::translate("MainWindow", "Erosion", 0));
        actionAffine->setText(QApplication::translate("MainWindow", "Affine", 0));
        actionSpectrum->setText(QApplication::translate("MainWindow", "Spectrum", 0));
        actionRGBToGray->setText(QApplication::translate("MainWindow", "RGBToGray", 0));
        actionImageReversal->setText(QApplication::translate("MainWindow", "ImageReversal", 0));
        actionLogTransform->setText(QApplication::translate("MainWindow", "LogTransform", 0));
        actionGrayToHist->setText(QApplication::translate("MainWindow", "GrayToHist", 0));
        actionRGBToHist->setText(QApplication::translate("MainWindow", "RGBToHist", 0));
        actionRGBToHSI->setText(QApplication::translate("MainWindow", "RGBToHSI", 0));
        actionSaveImage->setText(QApplication::translate("MainWindow", "SaveImage", 0));
        actionLowPassFilter->setText(QApplication::translate("MainWindow", "LowPassFilter", 0));
        actionHighPassFilter->setText(QApplication::translate("MainWindow", "HighPassFilter", 0));
        btnOpen->setText(QApplication::translate("MainWindow", "open", 0));
        btnReset->setText(QApplication::translate("MainWindow", "reset", 0));
        btnPre->setText(QApplication::translate("MainWindow", "previous", 0));
        btnNext->setText(QApplication::translate("MainWindow", "next", 0));
        menuSpatial_Filter->setTitle(QApplication::translate("MainWindow", "Spatial Filter", 0));
        menuAffine_Transform->setTitle(QApplication::translate("MainWindow", "Affine Transform", 0));
        menuIntensity_Transform->setTitle(QApplication::translate("MainWindow", "Intensity Transform", 0));
        menuSpectrum_Transform->setTitle(QApplication::translate("MainWindow", "Spectrum Transform", 0));
        menuSaveImage->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
