/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *spinlong;
    QDoubleSpinBox *spinlat;
    QTextEdit *textEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *query_start;
    QLineEdit *query_end;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *query_basepath;
    QPushButton *btn_query_show;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *btn_keys;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_clear;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chk_price;
    QCheckBox *chk_sorce;
    QCheckBox *chk_grade;
    QCheckBox *chk_detour;
    QCheckBox *chk_total;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *query_keys;
    QPushButton *btn_query;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 923);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 910, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doubleSpinBox = new QDoubleSpinBox(dockWidgetContents_4);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        verticalLayout->addWidget(doubleSpinBox);

        spinlong = new QDoubleSpinBox(dockWidgetContents_4);
        spinlong->setObjectName(QString::fromUtf8("spinlong"));
        spinlong->setDecimals(6);
        spinlong->setMinimum(-180.000000000000000);
        spinlong->setMaximum(180.000000000000000);
        spinlong->setSingleStep(0.002000000000000);
        spinlong->setValue(123.414884999999998);

        verticalLayout->addWidget(spinlong);

        spinlat = new QDoubleSpinBox(dockWidgetContents_4);
        spinlat->setObjectName(QString::fromUtf8("spinlat"));
        spinlat->setDecimals(6);
        spinlat->setMinimum(-90.000000000000000);
        spinlat->setMaximum(90.000000000000000);
        spinlat->setValue(41.931849000000000);

        verticalLayout->addWidget(spinlat);

        textEdit = new QTextEdit(dockWidgetContents_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        scrollArea = new QScrollArea(dockWidgetContents_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, -355, 342, 761));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        query_start = new QLineEdit(groupBox_3);
        query_start->setObjectName(QString::fromUtf8("query_start"));

        horizontalLayout->addWidget(query_start);

        query_end = new QLineEdit(groupBox_3);
        query_end->setObjectName(QString::fromUtf8("query_end"));

        horizontalLayout->addWidget(query_end);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        query_basepath = new QLineEdit(groupBox_5);
        query_basepath->setObjectName(QString::fromUtf8("query_basepath"));

        verticalLayout_5->addWidget(query_basepath);

        btn_query_show = new QPushButton(groupBox_5);
        btn_query_show->setObjectName(QString::fromUtf8("btn_query_show"));

        verticalLayout_5->addWidget(btn_query_show);


        verticalLayout_3->addWidget(groupBox_5);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 1);

        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 9, 0, 1, 1);

        btn_keys = new QPushButton(scrollAreaWidgetContents_2);
        btn_keys->setObjectName(QString::fromUtf8("btn_keys"));

        gridLayout->addWidget(btn_keys, 8, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_clear = new QPushButton(scrollAreaWidgetContents_2);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));

        horizontalLayout_2->addWidget(btn_clear);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        chk_price = new QCheckBox(groupBox);
        chk_price->setObjectName(QString::fromUtf8("chk_price"));

        verticalLayout_2->addWidget(chk_price);

        chk_sorce = new QCheckBox(groupBox);
        chk_sorce->setObjectName(QString::fromUtf8("chk_sorce"));

        verticalLayout_2->addWidget(chk_sorce);

        chk_grade = new QCheckBox(groupBox);
        chk_grade->setObjectName(QString::fromUtf8("chk_grade"));

        verticalLayout_2->addWidget(chk_grade);

        chk_detour = new QCheckBox(groupBox);
        chk_detour->setObjectName(QString::fromUtf8("chk_detour"));

        verticalLayout_2->addWidget(chk_detour);

        chk_total = new QCheckBox(groupBox);
        chk_total->setObjectName(QString::fromUtf8("chk_total"));

        verticalLayout_2->addWidget(chk_total);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        query_keys = new QLineEdit(groupBox_2);
        query_keys->setObjectName(QString::fromUtf8("query_keys"));

        verticalLayout_4->addWidget(query_keys);


        verticalLayout_2->addWidget(groupBox_2);

        btn_query = new QPushButton(groupBox);
        btn_query->setObjectName(QString::fromUtf8("btn_query"));

        verticalLayout_2->addWidget(btn_query);


        gridLayout->addWidget(groupBox, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);

        dockWidget_2->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\217\202\346\225\260", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\350\265\267\347\202\271\344\270\216\347\273\210\347\202\271", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\216\237\345\247\213\350\267\257\345\276\204", nullptr));
        btn_query_show->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\276\271\346\225\260\346\215\256\350\276\223\345\205\245", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\347\202\271\346\240\207\350\256\260", nullptr));
        btn_keys->setText(QApplication::translate("MainWindow", "\345\205\263\351\224\256\345\255\227\346\225\260\346\215\256\350\276\223\345\205\245", nullptr));
        btn_clear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\240\207\350\256\260", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\267\257\347\275\221", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\351\235\242\346\235\277", nullptr));
        chk_price->setText(QApplication::translate("MainWindow", "\345\271\263\345\235\207\344\273\267\346\240\274", nullptr));
        chk_sorce->setText(QApplication::translate("MainWindow", "\345\244\247\344\274\227\350\257\204\344\273\267", nullptr));
        chk_grade->setText(QApplication::translate("MainWindow", "\346\260\264\345\271\263\347\255\211\347\272\247", nullptr));
        chk_detour->setText(QApplication::translate("MainWindow", "\347\273\225\350\267\257\344\273\243\344\273\267", nullptr));
        chk_total->setText(QApplication::translate("MainWindow", "\350\267\235\347\246\273\344\273\243\344\273\267", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\205\263\351\224\256\345\255\227", nullptr));
        btn_query->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\202\271\346\225\260\346\215\256\350\276\223\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
