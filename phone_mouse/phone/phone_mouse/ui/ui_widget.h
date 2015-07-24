/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "advance_button.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_x;
    QLabel *lbl_y;
    QLabel *lbl_z;
    QSpacerItem *horizontalSpacer_2;
    Advance_Button *power;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    Advance_Button *left;
    QSpacerItem *horizontalSpacer;
    Advance_Button *right;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button_Left;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Button_Right;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(384, 679);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbl_x = new QLabel(Widget);
        lbl_x->setObjectName(QStringLiteral("lbl_x"));
        lbl_x->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(lbl_x);

        lbl_y = new QLabel(Widget);
        lbl_y->setObjectName(QStringLiteral("lbl_y"));
        lbl_y->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(lbl_y);

        lbl_z = new QLabel(Widget);
        lbl_z->setObjectName(QStringLiteral("lbl_z"));
        lbl_z->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(lbl_z);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        power = new Advance_Button(Widget);
        power->setObjectName(QStringLiteral("power"));
        power->setIconSize(QSize(100, 100));
        power->setButtonPicture(QPixmap(QString::fromUtf8(":/images/power.png")));
        power->setPressPicture(QPixmap(QString::fromUtf8(":/images/power1.png")));
        power->setProperty("releasePicutre", QVariant(QPixmap(QString::fromUtf8(":/images/power.png"))));
        power->setProperty("isdrag", QVariant(false));

        horizontalLayout->addWidget(power);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 129, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        left = new Advance_Button(Widget);
        left->setObjectName(QStringLiteral("left"));
        left->setIconSize(QSize(120, 120));
        left->setButtonPicture(QPixmap(QString::fromUtf8(":/images/gougou_1.png")));
        left->setPressPicture(QPixmap(QString::fromUtf8(":/images/gougou_11.png")));
        left->setProperty("releasePicutre", QVariant(QPixmap(QString::fromUtf8(":/images/gougou_1.png"))));
        left->setProperty("isdrag", QVariant(false));

        horizontalLayout_2->addWidget(left);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        right = new Advance_Button(Widget);
        right->setObjectName(QStringLiteral("right"));
        right->setIconSize(QSize(120, 120));
        right->setButtonPicture(QPixmap(QString::fromUtf8(":/images/gougou_2.png")));
        right->setPressPicture(QPixmap(QString::fromUtf8(":/images/gougou_21.png")));
        right->setProperty("releasePicutre", QVariant(QPixmap(QString::fromUtf8(":/images/gougou_2.png"))));
        right->setProperty("isdrag", QVariant(false));

        horizontalLayout_2->addWidget(right);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 130, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Button_Left = new QPushButton(Widget);
        Button_Left->setObjectName(QStringLiteral("Button_Left"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button_Left->sizePolicy().hasHeightForWidth());
        Button_Left->setSizePolicy(sizePolicy);
        Button_Left->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 0, 200);"));

        horizontalLayout_3->addWidget(Button_Left);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        Button_Right = new QPushButton(Widget);
        Button_Right->setObjectName(QStringLiteral("Button_Right"));
        sizePolicy.setHeightForWidth(Button_Right->sizePolicy().hasHeightForWidth());
        Button_Right->setSizePolicy(sizePolicy);
        Button_Right->setStyleSheet(QStringLiteral("background-color: rgba(0, 255, 255, 200);"));

        horizontalLayout_3->addWidget(Button_Right);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        lbl_x->setText(QApplication::translate("Widget", "x:", 0));
        lbl_y->setText(QApplication::translate("Widget", "y:", 0));
        lbl_z->setText(QApplication::translate("Widget", "z:", 0));
        Button_Left->setText(QApplication::translate("Widget", "\345\215\225\345\207\273", 0));
        Button_Right->setText(QApplication::translate("Widget", "\345\217\263\345\207\273", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
