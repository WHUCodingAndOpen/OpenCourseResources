#include "user.h"
#include "ui_user.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <string>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QDesktopServices>
#include <QAction>
#include <QMenu>
using namespace QXlsx;
#include "login.h"
extern QString UserID;
User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    connect(ui->pushButtonRup,SIGNAL(clicked()),this,SLOT(UserRup()));
    connect(ui->pushButtonCup,SIGNAL(clicked()),this,SLOT(UserCup()));
    connect(ui->pushButtonRclear,SIGNAL(clicked()),this,SLOT(UserRclear()));
    connect(ui->pushButtonCclear,SIGNAL(clicked()),this,SLOT(UserCclear()));


    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int HouseholdNum = doc.read(3,3).toInt();
    doc.selectSheet("住户信息");
    i=2;
    for (;i<=HouseholdNum+2;i++)
    {
        if (doc.read(i,1) == UserID)
            break;
    }
    doc.selectSheet("车位信息");
    j = 2;
    for (;j<=HouseholdNum+2;j++)
    {
        if (doc.read(j,2) == UserID)
            break;
    }
    if (j==HouseholdNum+3)
        j = -1;
    //显示住户信息
    ShowUserInfo(i,j);
    //显示维修投诉信息
    ShowUserC();
    ShowUserR();
}

User::~User()
{
    delete ui;
}
//加载页面信息
void User::ShowUserInfo(int i,int j)
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    ui->lineEditUserID->setText(UserID);
    doc.selectSheet("住户信息");
    ui->lineEditUserName->setText(doc.read(i,2).toString());
    ui->lineEditUserHouse->setText(doc.read(i,3).toString());
    ui->lineEditUserRoomType->setText(doc.read(i,4).toString());
    ui->lineEditUserTel->setText(doc.read(i,6).toString());
    ui->lineEditUserMoney->setText(doc.read(i,7).toString());
    if (j == -1)
    {
        ui->lineEditUserParkingID->setText("您没有车位");
        ui->lineEditUserParkingCarID->setText("您没有车位");
        ui->lineEditUserParkingCarID->setFrame(false);
        ui->lineEditUserParkingCarID->setReadOnly(true);
    }
    else
    {
        doc.selectSheet("车位信息");
        ui->lineEditUserParkingID->setText(doc.read(i,1).toString());
        ui->lineEditUserParkingCarID->setText(doc.read(i,3).toString());
    }

}
//保存用户更改并刷新
void User::on_lineEditUserName_editingFinished()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("住户信息");
    doc.write(i,2,ui->lineEditUserName->text());
    doc.save();
    ShowUserInfo(i,j);
}
void User::on_lineEditUserTel_editingFinished()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("住户信息");
    doc.write(i,6,ui->lineEditUserTel->text());
    doc.save();
    ShowUserInfo(i,j);
}
void User::on_lineEditUserParkingCarID_editingFinished()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("车位信息");
    doc.write(i,3,ui->lineEditUserParkingCarID->text());
    doc.save();
    ShowUserInfo(i,j);
}
//显示报修投诉信息
void User::ShowUserR()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,5).toInt();
    doc.selectSheet("报修");
    int col = 3;
    ui->tableWidgetUserR->setColumnCount(col);
    ui->tableWidgetUserR->setRowCount(row);
    ui->tableWidgetUserR->horizontalHeader()->setDefaultSectionSize(140);
    ui->tableWidgetUserR->verticalHeader()->setVisible(false);
    ui->tableWidgetUserR->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headlabels;
    headlabels <<"时间"<<"状态"<<"简述";
    ui->tableWidgetUserR->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<row;i++)
    {
            for (int j=0;j<col;j++)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(doc.read(i+1,j+1).toString());
                newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
                ui->tableWidgetUserR->setItem(i,j,newItem);
            }
    }
    ui->tableWidgetUserR->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dateEditRDate->setDisplayFormat("yyyy.MM.dd");
    ui->dateEditRDate->setDate(QDateTime::currentDateTime().date());
    ui->dateEditRDate->setCalendarPopup(true);
}
void User::ShowUserC()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,6).toInt();
    doc.selectSheet("投诉");
    int col = 3;
    ui->tableWidgetUserC->setColumnCount(col);
    ui->tableWidgetUserC->setRowCount(row);
    ui->tableWidgetUserC->horizontalHeader()->setDefaultSectionSize(140);
    ui->tableWidgetUserC->verticalHeader()->setVisible(false);
    ui->tableWidgetUserC->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headlabels;
    headlabels <<"时间"<<"状态"<<"简述";
    ui->tableWidgetUserC->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<row;i++)
    {
            for (int j=0;j<col;j++)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(doc.read(i+1,j+1).toString());
                newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
                ui->tableWidgetUserC->setItem(i,j,newItem);
            }
    }
    ui->tableWidgetUserC->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dateEditCDate->setDisplayFormat("yyyy.MM.dd");
    ui->dateEditCDate->setDate(QDateTime::currentDateTime().date());
    ui->dateEditCDate->setCalendarPopup(true);
}
//报修投诉信息提交
void User::UserRup()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int Rnum = doc.read(2,5).toInt();
    doc.write(2,5,doc.read(2,5).toInt()+1);
    doc.write(3,5,doc.read(3,5).toInt()+1);
    doc.selectSheet("报修");
    doc.write(Rnum+1,1,ui->dateEditRDate->date());
    doc.write(Rnum+1,2,ui->lineEditR->text());
    doc.write(Rnum+1,3,"待处理");
    doc.write(Rnum+1,4,"R"+QString(Rnum));
    doc.write(Rnum+1,5,ui->textEditRDetail->toPlainText());
    doc.save();
}
void User::UserCup()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int Cnum = doc.read(2,6).toInt();
    doc.write(2,6,doc.read(2,6).toInt()+1);
    doc.write(3,6,doc.read(3,6).toInt()+1);
    doc.selectSheet("投诉");
    doc.write(Cnum+1,1,ui->dateEditCDate->date());
    doc.write(Cnum+1,2,ui->lineEditC->text());
    doc.write(Cnum+1,3,"待处理");
    doc.write(Cnum+1,4,"C"+QString(Cnum));
    doc.write(Cnum+1,5,ui->textEditCDetail->toPlainText());
    doc.save();
}
//清空提交信息
void User::UserRclear()
{
    ui->dateEditRDate->clear();
    ui->lineEditR->clear();
    ui->textEditRDetail->clear();
    ui->pushButtonRclear->setEnabled(false);
}
void User::UserCclear()
{
    ui->dateEditCDate->clear();
    ui->lineEditC->clear();
    ui->textEditCDetail->clear();
    ui->pushButtonCclear->setEnabled(false);
}
//激活清空按钮
void User::on_dateEditRDate_dateChanged(const QDate &date)
{
    ui->pushButtonRclear->setEnabled(true);
}
void User::on_textEditRDetail_textChanged()
{
    ui->pushButtonRclear->setEnabled(true);
}
void User::on_lineEditR_textChanged(const QString &arg1)
{
    ui->pushButtonRclear->setEnabled(true);
}

void User::on_dateEditCDate_dateChanged(const QDate &date)
{
    ui->pushButtonCclear->setEnabled(true);
}

void User::on_lineEditC_textChanged(const QString &arg1)
{
    ui->pushButtonCclear->setEnabled(true);
}

void User::on_textEditCDetail_textChanged()
{
    ui->pushButtonCclear->setEnabled(true);
}
