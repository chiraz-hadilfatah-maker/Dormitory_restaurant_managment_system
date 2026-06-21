#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../project/university.h"
#include <QMainWindow>
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
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    university *uni;
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QComboBox *yearCombo;
    QPushButton *clearBtn;
    QPushButton *addBtn;
    QTableWidget *studentsTable;
    QLabel *totalRoomsCount;
    QLabel *totalDormStudentsCount;

    QLineEdit *dormNameEdit;
    QLineEdit *dormCapacityEdit;
    QPushButton *dormClearBtn;
    QPushButton *dormAddBtn;
    QPushButton *dormRemoveBtn;
    QLineEdit *dormSearchEdit;
    QTableWidget *dormTable;


    QComboBox *dormCombo;
    QPushButton *editMenuBtn;
    QPushButton *viewStatsBtn;

    QLabel *totalCountLabel;
    QLabel *assignedCountLabel;
    QLabel *unassignedCountLabel;
    QLabel *totalRoomsCountLabel;
    QLabel *totalDormStudentsCountLabel;
    QLabel *totalDormCount;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent *event)override;
private:
    Ui::MainWindow *ui;
    void setupStudentsPage();
    void refreshStudentTable();
    void refreshDormitoryTable();
    void refreshRestaurantDisplay();
    void updateStudentStatistics();
    void updateDormitoryStatistics();
    void showErrorMessage(const QString &message);
    void showSuccessMessage(const QString &message);
private slots:

    void on_clearBtn_clicked();
    void on_addBtn_clicked();


    void on_dormClearBtn_clicked();
    void on_dormAddBtn_clicked();
    void on_dormRemoveBtn_clicked();
    void on_dormSearchEdit_textChanged(const QString &text);
    void on_dormTable_itemSelectionChanged();


    void on_editMenuBtn_clicked();
    void on_viewStatsBtn_clicked();
    void on_dormCombo_currentIndexChanged(const QString &dormName);


    void on_student_btn_clicked();
    void on_dorm_btn_clicked();
    void on_room_btn_clicked();
    void on_rest_btn_clicked();

};

#endif
