#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QHeaderView>
#include<QMessageBox>
#include <QTableWidgetItem>
#include "../project/student.h"
#include "../project/university.h"
#include "../project/dormitory.h"
#include "../project/restaurant.h"
#include "../project/room.h"
#include "../project/menu.h"
#include "../project/room_empty.h"
#include "../project/room_full.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ uni=new university;

    ui->setupUi(this);
    ui->main_stack->setCurrentIndex(0);

    ui->student_page->setStyleSheet("background-color: #f5f5f5;");
    ui->dorm_page->setStyleSheet("background-color: #f5f5f5;");
    setMinimumSize(1000, 700);


    ui->top_bar->setGeometry(0, 0, width(), 80);
    ui->tab_bar->setGeometry(0, 80, width(), 50);


    ui->top_bar->setFixedHeight(80);
    ui->tab_bar->setFixedHeight(50);
    connect(ui->student_btn, &QPushButton::clicked, this, [this]() {
        ui->main_stack->setCurrentWidget(ui->student_page);
    });

    connect(ui->dorm_btn, &QPushButton::clicked, this, [this]() {
        ui->main_stack->setCurrentWidget(ui->dorm_page);
    });

    connect(ui->room_btn, &QPushButton::clicked, this, [this]() {
        ui->main_stack->setCurrentWidget(ui->room_page);
    });

    connect(ui->rest_btn, &QPushButton::clicked, this, [this]() {
        ui->main_stack->setCurrentWidget(ui->restaurant_page);
    });
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->student_page);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);

    QFrame *studentStatsFrame = new QFrame();
    studentStatsFrame->setFixedHeight(100);
    studentStatsFrame->setStyleSheet("background-color: transparent;");

    QHBoxLayout *studentStatsLayout = new QHBoxLayout(studentStatsFrame);
    studentStatsLayout->setSpacing(15);

    QFrame *totalFrame = new QFrame();
    totalFrame->setStyleSheet("background-color: #3498db; border-radius: 10px;");
    totalFrame->setMinimumWidth(200);

    QVBoxLayout *totalLayout = new QVBoxLayout(totalFrame);
    totalLayout->setAlignment(Qt::AlignCenter);

    totalCountLabel = new QLabel("0");
    totalCountLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    totalCountLabel->setAlignment(Qt::AlignCenter);

    QLabel *totalCountText = new QLabel("Total Students");
    totalCountText->setStyleSheet("color: white; font-size: 14px;");
    totalCountText->setAlignment(Qt::AlignCenter);

    totalLayout->addWidget(totalCountLabel);
    totalLayout->addWidget(totalCountText);

    QFrame *assignedFrame = new QFrame();
    assignedFrame->setStyleSheet("background-color: #2ecc71; border-radius: 10px;");
    assignedFrame->setMinimumWidth(200);

    QVBoxLayout *assignedLayout = new QVBoxLayout(assignedFrame);
    assignedLayout->setAlignment(Qt::AlignCenter);

    assignedCountLabel = new QLabel("0");
    assignedCountLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    assignedCountLabel->setAlignment(Qt::AlignCenter);

    QLabel *assignedCountText = new QLabel("Assigned to Room");
    assignedCountText->setStyleSheet("color: white; font-size: 14px;");
    assignedCountText->setAlignment(Qt::AlignCenter);

    assignedLayout->addWidget(assignedCountLabel);
    assignedLayout->addWidget(assignedCountText);

    QFrame *unassignedFrame = new QFrame();
    unassignedFrame->setStyleSheet("background-color: #e74c3c; border-radius: 10px;");
    unassignedFrame->setMinimumWidth(200);

    QVBoxLayout *unassignedLayout = new QVBoxLayout(unassignedFrame);
    unassignedLayout->setAlignment(Qt::AlignCenter);

    unassignedCountLabel = new QLabel("0");
    unassignedCountLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    unassignedCountLabel->setAlignment(Qt::AlignCenter);

    QLabel *unassignedCountText = new QLabel("Without Room");
    unassignedCountText->setStyleSheet("color: white; font-size: 14px;");
    unassignedCountText->setAlignment(Qt::AlignCenter);

    unassignedLayout->addWidget(unassignedCountLabel);
    unassignedLayout->addWidget(unassignedCountText);

    studentStatsLayout->addWidget(totalFrame);
    studentStatsLayout->addWidget(assignedFrame);
    studentStatsLayout->addWidget(unassignedFrame);
    studentStatsLayout->addStretch();

    mainLayout->addWidget(studentStatsFrame);

    QFrame *formFrame = new QFrame();
    formFrame->setStyleSheet(
        "background-color: #f9f9f9;"
        "border: 1px solid #ddd;"
        "border-radius: 5px;"
        );

    QGridLayout *formLayout = new QGridLayout(formFrame);
    formLayout->setSpacing(10);
    formLayout->setContentsMargins(15, 15, 15, 15);


    QLabel *formTitle = new QLabel("Add New Student");
    formTitle->setStyleSheet("color: black;");
    formTitle->setStyleSheet("font-size: 16px; font-weight: bold;");
    formLayout->addWidget(formTitle, 0, 0, 1, 2);


    QLabel *idLabel = new QLabel("Student ID:");
    idEdit = new QLineEdit();
    idLabel->setStyleSheet("color: black ;");
    idEdit->setPlaceholderText("e.g. 20231045");
    idEdit->setStyleSheet("color: black;" );
    idEdit->setMinimumHeight(30);
    formLayout->addWidget(idLabel, 1, 0);
    formLayout->addWidget(idEdit, 1, 1);


    QLabel *nameLabel = new QLabel("Full Name:");
    nameEdit = new QLineEdit();
    nameLabel->setStyleSheet("color: black;");
    nameEdit->setPlaceholderText("e.g. Chiraz Hadil FATAH");
    nameEdit->setMinimumHeight(30);
    nameEdit->setStyleSheet("color:black;");
    formLayout->addWidget(nameLabel, 2, 0);
    formLayout->addWidget(nameEdit, 2, 1);


    QLabel *yearLabel = new QLabel("Academic Year:");
    yearCombo = new QComboBox();
    yearLabel->setStyleSheet("color: black;");
    yearCombo->addItems({"Year 1", "Year 2", "Year 3","Year 4","Year 5"});
    yearCombo->setMinimumHeight(30);
    yearCombo->setStyleSheet("color: black;");
    formLayout->addWidget(yearLabel, 3, 0);
    formLayout->addWidget(yearCombo, 3, 1);


    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);

    clearBtn = new QPushButton("Clear");
    clearBtn->setStyleSheet(
        "background-color: #95a5a6;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 100px;"
        );

    addBtn = new QPushButton("Add Student");
    addBtn->setStyleSheet(
        "background-color: #3498db;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 120px;"
        "font-weight: bold;"
        );

    buttonLayout->addStretch();
    buttonLayout->addWidget(clearBtn);
    buttonLayout->addWidget(addBtn);

    formLayout->addLayout(buttonLayout, 4, 0, 1, 2);


    mainLayout->addWidget(formFrame);

    studentsTable = new QTableWidget();
    studentsTable->setMinimumHeight(250);
    studentsTable->setColumnCount(4);
    studentsTable->setHorizontalHeaderLabels({"ID", "Full Name", "Academic Year", "Room Number"});
    studentsTable->horizontalHeader()->setStretchLastSection(true);
    studentsTable->setStyleSheet(
        "QTableWidget { background-color: white; gridline-color: #ddd; }"
        "QTableWidget::item { padding: 8px; }"
        "QHeaderView::section { background-color: #f0f0f0; padding: 8px; font-weight: bold; }"
        );
    mainLayout->addWidget(studentsTable);

    QWidget *studentButtonPanel = new QWidget();
    studentButtonPanel->setMinimumHeight(50);

    QHBoxLayout *studentPanelLayout = new QHBoxLayout(studentButtonPanel);
    studentPanelLayout->setContentsMargins(0, 0, 0, 0);

    QLineEdit *searchEdit = new QLineEdit();
    searchEdit->setPlaceholderText("Search by name or ID...");
    searchEdit->setMinimumHeight(30);
    searchEdit->setMinimumWidth(250);
    searchEdit->setStyleSheet(
        "color: black;"
        "placeholder-text-color: #888888;"
        );

    QPushButton *assignBtn = new QPushButton("Assign to Room");
    assignBtn->setStyleSheet(
        "background-color: #2ecc71;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 130px;"
        );

    QPushButton *removeBtn = new QPushButton("Remove Selected");
    removeBtn->setStyleSheet(
        "background-color: #e74c3c;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 130px;"
        );

    studentPanelLayout->addWidget(searchEdit);
    studentPanelLayout->addStretch();
    studentPanelLayout->addWidget(assignBtn);
    studentPanelLayout->addWidget(removeBtn);

    mainLayout->addWidget(studentButtonPanel);

    QVBoxLayout *dormLayout = new QVBoxLayout(ui->dorm_page);
    dormLayout->setContentsMargins(10, 10, 10, 10);
    dormLayout->setSpacing(10);


    QFrame *dormStatsFrame = new QFrame();
    dormStatsFrame->setFixedHeight(100);
    dormStatsFrame->setStyleSheet("background-color: transparent;");

    QHBoxLayout *dormStatsLayout = new QHBoxLayout(dormStatsFrame);
    dormStatsLayout->setSpacing(15);


    QFrame *totalDormFrame = new QFrame();
    totalDormFrame->setStyleSheet(
        "background-color: #3498db;"
        "border-radius: 10px;"
        );
    totalDormFrame->setMinimumWidth(200);

    QVBoxLayout *totalDormLayout = new QVBoxLayout(totalDormFrame);
    totalDormLayout->setAlignment(Qt::AlignCenter);

    totalDormCount = new QLabel("0");
    totalDormCount->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    totalDormCount->setAlignment(Qt::AlignCenter);

    QLabel *totalDormText = new QLabel("Total Dormitories");
    totalDormText->setStyleSheet("color: white; font-size: 14px;");
    totalDormText->setAlignment(Qt::AlignCenter);

    totalDormLayout->addWidget(totalDormCount);
    totalDormLayout->addWidget(totalDormText);


    QFrame *totalRoomsFrame = new QFrame();
    totalRoomsFrame->setStyleSheet(
        "background-color: #2ecc71;"
        "border-radius: 10px;"
        );
    totalRoomsFrame->setMinimumWidth(200);

    QVBoxLayout *totalRoomsLayout = new QVBoxLayout(totalRoomsFrame);
    totalRoomsLayout->setAlignment(Qt::AlignCenter);

    totalRoomsCountLabel = new QLabel("0");
    totalRoomsCountLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    totalRoomsCountLabel->setAlignment(Qt::AlignCenter);

    QLabel *totalRoomsText = new QLabel("Total Rooms");
    totalRoomsText->setStyleSheet("color: white; font-size: 14px;");
    totalRoomsText->setAlignment(Qt::AlignCenter);

    totalRoomsLayout->addWidget(totalRoomsCountLabel);
    totalRoomsLayout->addWidget(totalRoomsText);


    QFrame *totalDormStudentsFrame = new QFrame();
    totalDormStudentsFrame->setStyleSheet(
        "background-color: #f39c12;"
        "border-radius: 10px;"
        );
    totalDormStudentsFrame->setMinimumWidth(200);

    QVBoxLayout *totalDormStudentsLayout = new QVBoxLayout(totalDormStudentsFrame);
    totalDormStudentsLayout->setAlignment(Qt::AlignCenter);

    totalDormStudentsCountLabel = new QLabel("0");
    totalDormStudentsCountLabel->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    totalDormStudentsCountLabel->setAlignment(Qt::AlignCenter);

    QLabel *totalDormStudentsText = new QLabel("Total Students");
    totalDormStudentsText->setStyleSheet("color: white; font-size: 14px;");
    totalDormStudentsText->setAlignment(Qt::AlignCenter);

    totalDormStudentsLayout->addWidget(totalDormStudentsCountLabel);
    totalDormStudentsLayout->addWidget(totalDormStudentsText);


    dormStatsLayout->addWidget(totalDormFrame);
    dormStatsLayout->addWidget(totalRoomsFrame);
    dormStatsLayout->addWidget(totalDormStudentsFrame);
    dormStatsLayout->addStretch();

    dormLayout->addWidget(dormStatsFrame);


    QFrame *dormFormFrame = new QFrame();
    dormFormFrame->setStyleSheet(
        "background-color: #f9f9f9;"
        "border: 1px solid #ddd;"
        "border-radius: 5px;"
        );

    QGridLayout *dormFormLayout = new QGridLayout(dormFormFrame);
    dormFormLayout->setSpacing(10);
    dormFormLayout->setContentsMargins(15, 15, 15, 15);


    QLabel *dormFormTitle = new QLabel("Add New Dormitory");
    dormFormTitle->setStyleSheet(
        "font-size: 16px;"
        "font-weight: bold;"
        "color: #2c3e50;"
        );
    dormFormLayout->addWidget(dormFormTitle, 0, 0, 1, 2);


    QLabel *dormNameLabel = new QLabel("Dormitory Name:");
    dormNameLabel->setStyleSheet("color: #34495e; font-weight: bold;");

    dormNameEdit = new QLineEdit();
    dormNameEdit->setPlaceholderText("e.g. Dorm C");
    dormNameEdit->setMinimumHeight(30);
    dormNameEdit->setStyleSheet(
        "color: black;"
        "placeholder-text-color: #888888;"
        );
    dormFormLayout->addWidget(dormNameLabel, 1, 0);
    dormFormLayout->addWidget(dormNameEdit, 1, 1);


    QLabel *dormCapacityLabel = new QLabel("Total Capacity (students):");
    dormCapacityLabel->setStyleSheet("color: #34495e; font-weight: bold;");

    dormCapacityEdit = new QLineEdit();
    dormCapacityEdit->setPlaceholderText("e.g. 120");
    dormCapacityEdit->setMinimumHeight(30);
    dormCapacityEdit->setStyleSheet(
        "color: black;"
        "placeholder-text-color: #888888;"
        );
    dormFormLayout->addWidget(dormCapacityLabel, 2, 0);
    dormFormLayout->addWidget(dormCapacityEdit, 2, 1);


    QHBoxLayout *dormButtonLayout = new QHBoxLayout();
    dormButtonLayout->setSpacing(10);

    dormClearBtn = new QPushButton("Clear");
    dormClearBtn->setStyleSheet(
        "background-color: #95a5a6;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 100px;"
        );

    dormAddBtn = new QPushButton("Add Dormitory");
    dormAddBtn->setStyleSheet(
        "background-color: #3498db;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 120px;"
        "font-weight: bold;"
        );

    dormButtonLayout->addStretch();
    dormButtonLayout->addWidget(dormClearBtn);
    dormButtonLayout->addWidget(dormAddBtn);

    dormFormLayout->addLayout(dormButtonLayout, 3, 0, 1, 2);

    dormLayout->addWidget(dormFormFrame);


    dormTable = new QTableWidget();
    dormTable->setMinimumHeight(250);
    dormTable->setColumnCount(6);
    dormTable->setStyleSheet(
        "QTableWidget {"
        "   background-color: white;"
        "   gridline-color: #ddd;"
        "   color: black;"
        "}"
        "QTableWidget::item {"
        "   padding: 8px;"
        "   color: black;"
        "}"
        "QHeaderView::section {"
        "   background-color: #f0f0f0;"
        "   padding: 8px;"
        "   font-weight: bold;"
        "   color: black;"
        "}"
        );
    dormTable->setHorizontalHeaderLabels({
        "Name",
        "Capacity",
        "Rooms",
        "Students",
        "Restaurant",
        "Actions"
    });
    dormTable->horizontalHeader()->setStretchLastSection(true);


    dormTable->insertRow(0);
    dormTable->setItem(0, 0, new QTableWidgetItem("Dorm A"));
    dormTable->setItem(0, 1, new QTableWidgetItem("60"));
    dormTable->setItem(0, 2, new QTableWidgetItem("20"));
    dormTable->setItem(0, 3, new QTableWidgetItem("24"));
    dormTable->setItem(0, 4, new QTableWidgetItem("Active"));

    QPushButton *actionBtn1 = new QPushButton("Manage");
    actionBtn1->setStyleSheet(
        "background-color: #3498db;"
        "color: white;"
        "border-radius: 3px;"
        "padding: 3px;"
        );
    dormTable->setCellWidget(0, 5, actionBtn1);

    dormTable->insertRow(1);
    dormTable->setItem(1, 0, new QTableWidgetItem("Dorm B"));
    dormTable->setItem(1, 1, new QTableWidgetItem("80"));
    dormTable->setItem(1, 2, new QTableWidgetItem("30"));
    dormTable->setItem(1, 3, new QTableWidgetItem("55"));
    dormTable->setItem(1, 4, new QTableWidgetItem("Active"));

    QPushButton *actionBtn2 = new QPushButton("Manage");
    actionBtn2->setStyleSheet(
        "background-color: #3498db;"
        "color: white;"
        "border-radius: 3px;"
        "padding: 3px;"
        );
    dormTable->setCellWidget(1, 5, actionBtn2);

    dormLayout->addWidget(dormTable);


    QWidget *dormButtonPanel = new QWidget();
    dormButtonPanel->setMinimumHeight(50);

    QHBoxLayout *dormPanelLayout = new QHBoxLayout(dormButtonPanel);
    dormPanelLayout->setContentsMargins(0, 0, 0, 0);

    dormSearchEdit = new QLineEdit();
    dormSearchEdit->setPlaceholderText("Search dormitory...");
    dormSearchEdit->setMinimumHeight(30);
    dormSearchEdit->setMinimumWidth(250);
    dormSearchEdit->setStyleSheet(
        "color: black;"
        "placeholder-text-color: #888888;"
        );

    dormRemoveBtn = new QPushButton("Remove Selected");
    dormRemoveBtn->setStyleSheet(
        "background-color: #e74c3c;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 130px;"
        );

    dormPanelLayout->addWidget(dormSearchEdit);
    dormPanelLayout->addStretch();
    dormPanelLayout->addWidget(dormRemoveBtn);

    dormLayout->addWidget(dormButtonPanel);

    ui->restaurant_page->setStyleSheet("background-color: #f5f5f5;");


    QVBoxLayout *restLayout = new QVBoxLayout(ui->restaurant_page);
    restLayout->setContentsMargins(20, 20, 20, 20);
    restLayout->setSpacing(15);


    QFrame *restStatsFrame = new QFrame();
    restStatsFrame->setFixedHeight(100);
    restStatsFrame->setStyleSheet("background-color: transparent;");

    QHBoxLayout *restStatsLayout = new QHBoxLayout(restStatsFrame);
    restStatsLayout->setSpacing(15);


    QFrame *breakfastFrame = new QFrame();
    breakfastFrame->setStyleSheet(
        "background-color: #f39c12;"
        "border-radius: 10px;"
        );
    breakfastFrame->setMinimumWidth(200);

    QVBoxLayout *breakfastLayout = new QVBoxLayout(breakfastFrame);
    breakfastLayout->setAlignment(Qt::AlignCenter);

    QLabel *breakfastCount = new QLabel("48");
    breakfastCount->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    breakfastCount->setAlignment(Qt::AlignCenter);

    QLabel *breakfastText = new QLabel("Breakfasts Served");
    breakfastText->setStyleSheet("color: white; font-size: 14px;");
    breakfastText->setAlignment(Qt::AlignCenter);

    breakfastLayout->addWidget(breakfastCount);
    breakfastLayout->addWidget(breakfastText);


    QFrame *lunchFrame = new QFrame();
    lunchFrame->setStyleSheet(
        "background-color: #3498db;"
        "border-radius: 10px;"
        );
    lunchFrame->setMinimumWidth(200);

    QVBoxLayout *lunchLayout = new QVBoxLayout(lunchFrame);
    lunchLayout->setAlignment(Qt::AlignCenter);

    QLabel *lunchCount = new QLabel("41");
    lunchCount->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    lunchCount->setAlignment(Qt::AlignCenter);

    QLabel *lunchText = new QLabel("Lunch Served");
    lunchText->setStyleSheet("color: white; font-size: 14px;");
    lunchText->setAlignment(Qt::AlignCenter);

    lunchLayout->addWidget(lunchCount);
    lunchLayout->addWidget(lunchText);


    QFrame *dinnerFrame = new QFrame();
    dinnerFrame->setStyleSheet(
        "background-color: #2ecc71;"
        "border-radius: 10px;"
        );
    dinnerFrame->setMinimumWidth(200);

    QVBoxLayout *dinnerLayout = new QVBoxLayout(dinnerFrame);
    dinnerLayout->setAlignment(Qt::AlignCenter);

    QLabel *dinnerCount = new QLabel("53");
    dinnerCount->setStyleSheet("color: white; font-size: 28px; font-weight: bold;");
    dinnerCount->setAlignment(Qt::AlignCenter);

    QLabel *dinnerText = new QLabel("Dinners Served");
    dinnerText->setStyleSheet("color: white; font-size: 14px;");
    dinnerText->setAlignment(Qt::AlignCenter);

    dinnerLayout->addWidget(dinnerCount);
    dinnerLayout->addWidget(dinnerText);

    restStatsLayout->addWidget(breakfastFrame);
    restStatsLayout->addWidget(lunchFrame);
    restStatsLayout->addWidget(dinnerFrame);
    restStatsLayout->addStretch();

    restLayout->addWidget(restStatsFrame);


    QFrame *actionFrame = new QFrame();
    actionFrame->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ddd;"
        "border-radius: 8px;"
        );
    actionFrame->setFixedHeight(60);

    QHBoxLayout *actionLayout = new QHBoxLayout(actionFrame);
    actionLayout->setContentsMargins(15, 10, 15, 10);
    actionLayout->setSpacing(15);

    QLabel *dormLabel = new QLabel("Dormitory:");
    dormLabel->setStyleSheet("font-weight: bold; color: #2c3e50;");

    dormCombo = new QComboBox();
    dormCombo->addItems({"Dorm A", "Dorm B", "Dorm C"});
    dormCombo->setMinimumWidth(150);
    dormCombo->setStyleSheet(
        "border: 1px solid #ccc;"
        "border-radius: 4px;"
        "padding: 5px;"
        );

    editMenuBtn = new QPushButton("Edit Today's Menu");
    editMenuBtn->setStyleSheet(
        "background-color: #3498db;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 150px;"
        "border-radius: 4px;"
        );

    viewStatsBtn = new QPushButton("View Meal Stats");
    viewStatsBtn->setStyleSheet(
        "background-color: #2ecc71;"
        "color: white;"
        "min-height: 30px;"
        "min-width: 150px;"
        "border-radius: 4px;"
        );

    actionLayout->addWidget(dormLabel);
    actionLayout->addWidget(dormCombo);
    actionLayout->addStretch();
    actionLayout->addWidget(editMenuBtn);
    actionLayout->addWidget(viewStatsBtn);

    restLayout->addWidget(actionFrame);


    QFrame *mealsFrame = new QFrame();
    mealsFrame->setStyleSheet("background-color: transparent;");

    QHBoxLayout *mealsLayout = new QHBoxLayout(mealsFrame);
    mealsLayout->setSpacing(20);


    QFrame *breakfastMealFrame = new QFrame();
    breakfastMealFrame->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ddd;"
        "border-radius: 8px;"
        );
    breakfastMealFrame->setMinimumHeight(300);

    QVBoxLayout *breakfastMealLayout = new QVBoxLayout(breakfastMealFrame);
    breakfastMealLayout->setContentsMargins(15, 15, 15, 15);
    breakfastMealLayout->setSpacing(10);

    QLabel *breakfastTitle = new QLabel("BREAKFAST");
    breakfastTitle->setStyleSheet(
        "font-size: 16px;"
        "font-weight: bold;"
        "color: #f39c12;"
        "border-bottom: 2px solid #f39c12;"
        "padding-bottom: 8px;"
        );
    breakfastMealLayout->addWidget(breakfastTitle);


    QStringList breakfastItems = {
        "• Bread + butter + jam",
        "• Milk or coffee",
        "• Boiled eggs",
        "• Fresh orange juice"
    };

    for (const QString &item : breakfastItems) {
        QLabel *itemLabel = new QLabel(item);
        itemLabel->setStyleSheet("color: #2c3e50; padding: 3px;");
        breakfastMealLayout->addWidget(itemLabel);
    }

    breakfastMealLayout->addStretch();


    QFrame *lunchMealFrame = new QFrame();
    lunchMealFrame->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ddd;"
        "border-radius: 8px;"
        );
    lunchMealFrame->setMinimumHeight(300);

    QVBoxLayout *lunchMealLayout = new QVBoxLayout(lunchMealFrame);
    lunchMealLayout->setContentsMargins(15, 15, 15, 15);
    lunchMealLayout->setSpacing(10);

    QLabel *lunchTitle = new QLabel("LUNCH");
    lunchTitle->setStyleSheet(
        "font-size: 16px;"
        "font-weight: bold;"
        "color: #3498db;"
        "border-bottom: 2px solid #3498db;"
        "padding-bottom: 8px;"
        );
    lunchMealLayout->addWidget(lunchTitle);


    QStringList lunchItems = {
        "• Lentil soup",
        "• Chicken with rice",
        "• Salad",
        "• Yogurt"
    };

    for (const QString &item : lunchItems) {
        QLabel *itemLabel = new QLabel(item);
        itemLabel->setStyleSheet("color: #2c3e50; padding: 3px;");
        lunchMealLayout->addWidget(itemLabel);
    }

    lunchMealLayout->addStretch();


    QFrame *dinnerMealFrame = new QFrame();
    dinnerMealFrame->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ddd;"
        "border-radius: 8px;"
        );
    dinnerMealFrame->setMinimumHeight(300);

    QVBoxLayout *dinnerMealLayout = new QVBoxLayout(dinnerMealFrame);
    dinnerMealLayout->setContentsMargins(15, 15, 15, 15);
    dinnerMealLayout->setSpacing(10);

    QLabel *dinnerTitle = new QLabel("DINNER");
    dinnerTitle->setStyleSheet(
        "font-size: 16px;"
        "font-weight: bold;"
        "color: #2ecc71;"
        "border-bottom: 2px solid #2ecc71;"
        "padding-bottom: 8px;"
        );
    dinnerMealLayout->addWidget(dinnerTitle);


    QStringList dinnerItems = {
        "• Vegetable harira",
        "• Grilled fish",
        "• Couscous",
        "• Fruit"
    };

    for (const QString &item : dinnerItems) {
        QLabel *itemLabel = new QLabel(item);
        itemLabel->setStyleSheet("color: #2c3e50; padding: 3px;");
        dinnerMealLayout->addWidget(itemLabel);
    }

    dinnerMealLayout->addStretch();


    mealsLayout->addWidget(breakfastMealFrame);
    mealsLayout->addWidget(lunchMealFrame);
    mealsLayout->addWidget(dinnerMealFrame);

    restLayout->addWidget(mealsFrame);


    //here we have the connection of the functions with the function of the real classes

    connect(ui->student_btn, &QPushButton::clicked, this, &MainWindow::on_student_btn_clicked);
    connect(ui->dorm_btn, &QPushButton::clicked, this, &MainWindow::on_dorm_btn_clicked);
    connect(ui->room_btn, &QPushButton::clicked, this, &MainWindow::on_room_btn_clicked);
    connect(ui->rest_btn, &QPushButton::clicked, this, &MainWindow::on_rest_btn_clicked);


    connect(clearBtn, &QPushButton::clicked, this, &MainWindow::on_clearBtn_clicked);
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::on_addBtn_clicked);

    connect(dormClearBtn, &QPushButton::clicked, this, &MainWindow::on_dormClearBtn_clicked);
    connect(dormAddBtn, &QPushButton::clicked, this, &MainWindow::on_dormAddBtn_clicked);
    connect(dormRemoveBtn, &QPushButton::clicked, this, &MainWindow::on_dormRemoveBtn_clicked);
    connect(dormSearchEdit, &QLineEdit::textChanged, this, &MainWindow::on_dormSearchEdit_textChanged);
    connect(dormTable, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_dormTable_itemSelectionChanged);

    connect(editMenuBtn, &QPushButton::clicked, this, &MainWindow::on_editMenuBtn_clicked);
    connect(viewStatsBtn, &QPushButton::clicked, this, &MainWindow::on_viewStatsBtn_clicked);
    connect(dormCombo, &QComboBox::currentIndexChanged, this, [this](int index) {
        QString dormName = dormCombo->itemText(index);
        refreshRestaurantDisplay();
    });

    //refreshStudentTable();
    //refreshDormitoryTable();
    //refreshRestaurantDisplay();
    //updateStudentStatistics();
    //updateDormitoryStatistics();




}
void MainWindow::resizeEvent(QResizeEvent *event)
{

    ui->top_bar->setGeometry(0, 0, width(), 80);
    ui->tab_bar->setGeometry(0, 80, width(), 50);
    ui->main_stack->setGeometry(0, 130, width(), height() - 130);
    QMainWindow::resizeEvent(event);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearBtn_clicked()
{

    idEdit->clear();
    nameEdit->clear();
    yearCombo->setCurrentIndex(0);
}

void MainWindow::on_addBtn_clicked()
{
    try {
        int id = idEdit->text().toInt();
        std::string name = nameEdit->text().toStdString();
        int year = yearCombo->currentIndex() + 1;

        if (id <= 0 || name.empty()) {
            QMessageBox::warning(this, "Error", "Please enter valid Student ID and Name");
            return;
        }

        student newStudent(id, name, year);
        uni->add_student(newStudent);

        QMessageBox::information(this, "Success", "Student added successfully!");
        on_clearBtn_clicked();
        refreshStudentTable();
        updateStudentStatistics();

    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_dormClearBtn_clicked()
{
    dormNameEdit->clear();
    dormCapacityEdit->clear();
}

void MainWindow::on_dormAddBtn_clicked()
{
    try {
        std::string name = dormNameEdit->text().toStdString();
        int capacity = dormCapacityEdit->text().toInt();

        if (name.empty() || capacity <= 0) {
            QMessageBox::warning(this, "Error", "Please enter valid Dormitory Name and Capacity");
            return;
        }

        restaurant rest;
        dormitory newDorm(rest, name, 10, capacity);
        uni->add_dormitory(newDorm);

        QMessageBox::information(this, "Success", "Dormitory added successfully!");
        on_dormClearBtn_clicked();
        refreshDormitoryTable();
        updateDormitoryStatistics();
        refreshRestaurantDisplay();

    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_dormRemoveBtn_clicked()
{
    try {
        int currentRow = dormTable->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "Error", "Please select a dormitory to remove");
            return;
        }

        QString name = dormTable->item(currentRow, 0)->text();
        uni->remove_dormitory(name.toStdString());

        QMessageBox::information(this, "Success", "Dormitory removed successfully!");
        refreshDormitoryTable();
        updateDormitoryStatistics();
        refreshRestaurantDisplay();

    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void MainWindow::on_dormSearchEdit_textChanged(const QString &text)
{
    QString searchText = text.toLower();
    for (int row = 0; row < dormTable->rowCount(); row++) {
        bool match = false;
        for (int col = 0; col < dormTable->columnCount(); col++) {
            QTableWidgetItem *item = dormTable->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                match = true;
                break;
            }
        }
        dormTable->setRowHidden(row, !match);
    }
}
void MainWindow::on_editMenuBtn_clicked()
{
    QMessageBox::information(this, "Edit Menu", "Menu editor would open here");
}

void MainWindow::on_viewStatsBtn_clicked()
{
    refreshRestaurantDisplay();
    QMessageBox::information(this, "Statistics", "Meal statistics updated");
}

void MainWindow::on_dormCombo_currentIndexChanged(const QString &dormName)
{
    Q_UNUSED(dormName);
    refreshRestaurantDisplay();
}
void MainWindow::on_student_btn_clicked()
{
    ui->main_stack->setCurrentWidget(ui->student_page);
    refreshStudentTable();
    updateStudentStatistics();
}

void MainWindow::on_dorm_btn_clicked()
{
    ui->main_stack->setCurrentWidget(ui->dorm_page);
    refreshDormitoryTable();
    updateDormitoryStatistics();
}

void MainWindow::on_room_btn_clicked()
{
    ui->main_stack->setCurrentWidget(ui->room_page);
}

void MainWindow::on_rest_btn_clicked()
{
    ui->main_stack->setCurrentWidget(ui->restaurant_page);
    refreshRestaurantDisplay();
}

void MainWindow::on_dormTable_itemSelectionChanged()
{
    bool hasSelection = dormTable->currentRow() >= 0;
    dormRemoveBtn->setEnabled(hasSelection);
}

void MainWindow::refreshStudentTable()
{
    if (!studentsTable || !uni) return;
    studentsTable->setRowCount(0);
    std::vector<student> allStudents = uni->getAllStudents();
    int row = 0;
    for (const auto& s : allStudents) {
        studentsTable->insertRow(row);
        studentsTable->setItem(row, 0, new QTableWidgetItem(QString::number(s.get_student_id())));
        studentsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(s.get_fullname())));
        studentsTable->setItem(row, 2, new QTableWidgetItem(QString("Year %1").arg(s.get_academic_year())));
        studentsTable->setItem(row, 3, new QTableWidgetItem(s.get_is_assigned() ? QString::number(s.get_assigned_room()) : "-"));
        row++;
    }
}

void MainWindow::refreshDormitoryTable()
{
    if (!dormTable || !uni) return;
    dormTable->setRowCount(0);
    std::vector<dormitory> allDorms = uni->getDormitories();
    int row = 0;
    for (const auto& d : allDorms) {
        dormTable->insertRow(row);
        dormTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(d.get_dorm_name())));
        dormTable->setItem(row, 1, new QTableWidgetItem(QString::number(d.get_available_room())));
        row++;
    }
}

void MainWindow::updateStudentStatistics()
{
    if (!uni) return;
    int total = uni->get_total_students();
    int assigned = 0;
    int unassigned = 0;

    std::vector<student> allStudents = uni->getAllStudents();
    for (const auto& s : allStudents) {
        if (s.get_is_assigned()) {
            assigned++;
        } else {
            unassigned++;
        }
    }
    if (totalCountLabel) totalCountLabel->setText(QString::number(total));
    if (assignedCountLabel) assignedCountLabel->setText(QString::number(assigned));
    if (unassignedCountLabel) unassignedCountLabel->setText(QString::number(unassigned));
}

void MainWindow::updateDormitoryStatistics()
{
    if (!uni) return;
    int total = uni->getDormitoryCount();
    int totalRooms = 0;
    int totalStudents = 0;

    std::vector<dormitory> allDorms = uni->getDormitories();
    for (const auto& d : allDorms) {
        totalRooms += d.get_available_room();
    }

    if (totalDormCount) totalDormCount->setText(QString::number(total));
    if (totalRoomsCountLabel) totalRoomsCountLabel->setText(QString::number(totalRooms));
    if (totalDormStudentsCountLabel) totalDormStudentsCountLabel->setText(QString::number(totalStudents));
}
void MainWindow::refreshRestaurantDisplay()
{
    if (!dormCombo || !uni) return;
    QString dormName = dormCombo->currentText();
    Q_UNUSED(dormName);
}