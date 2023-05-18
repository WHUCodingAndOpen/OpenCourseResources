#include "pmis.h"
#include <QCoreApplication>
#include <QDebug>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <QString>
#include <QMessageBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QDesktopServices>
#include <QAction>
#include <QMenu>
using namespace QXlsx;
PMIS::PMIS(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
    connect(ui.buttonEditCommunityInfo, SIGNAL(clicked()), this, SLOT(EditCommunityInfo()));
    connect(ui.buttonSaveCommunityInfo, SIGNAL(clicked()), this, SLOT(SaveCommunityInfo()));
    connect(ui.buttonEditHouseholdInfo,SIGNAL(clicked()),this,SLOT(EditHouseholdInfo()));
    connect(ui.buttonSaveHouseholdInfo,SIGNAL(clicked()),this,SLOT(SaveHouseholdInfo()));
    connect(ui.buttonOutHouseholdInfo,SIGNAL(clicked()),this,SLOT(PrintHouseholdInfo()));
    connect(ui.buttonChargeDo, SIGNAL(clicked()), this, SLOT(DoCharge()));
    connect(ui.buttonChargeCancel, SIGNAL(clicked()), this, SLOT(CancelCharge()));
    connect(ui.buttonEditParkingInfo,SIGNAL(clicked()),this,SLOT(EditParkingInfo()));
    connect(ui.buttonSaveParkingInfo,SIGNAL(clicked()),this,SLOT(SaveParkingInfo()));
    connect(ui.pushButtonDoing,SIGNAL(clicked()),this,SLOT(ChangeFeedbackInfo()));
    connect(ui.pushButtonDone,SIGNAL(clicked()),this,SLOT(FeedbackInfoDone()));
    connect(ui.pushButtonDoing2,SIGNAL(clicked()),this,SLOT(ChangeFeedbackInfo2()));
    connect(ui.pushButtonDone2,SIGNAL(clicked()),this,SLOT(FeedbackInfoDone2()));
    connect(ui.pushButtonSwitchRoomType,SIGNAL(clicked()),this,SLOT(SwitchRoomType()));
    connect(ui.buttonDeleteHousehold,SIGNAL(clicked()),this,SLOT(DeleteHousehold()));
    connect(ui.tableWidgetHouseholdInfo->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(slot_sortByColumn(int)));
    connect(ui.buttonOutputAll,SIGNAL(clicked()),this,SLOT(OutputAll()));
    //读取excel文件
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    //总览->小区信息页面加载
    doc.selectSheet("小区信息");
    QVariant CommunityName = doc.read(2,1);
    QVariant CommunityLocation = doc.read(2,2);
    ui.lineEditCommunityName->setText(CommunityName.toString());
    ui.lineEditCommunityLocation->setText(CommunityLocation.toString());
    ui.lineEditHouseholdNum->setText(doc.read(3,3).toString()+"/"+doc.read(2,3).toString());
    ui.lineEditParkingNum->setText(doc.read(3,4).toString()+"/"+doc.read(2,4).toString());
    ui.lineEditHNum->setText(doc.read(3,3).toString()+"/"+doc.read(2,3).toString());
    ui.lineEditRNum->setText(doc.read(3,5).toString()+"/"+doc.read(2,5).toString());
    ui.lineEditCNum->setText(doc.read(3,6).toString()+"/"+doc.read(2,6).toString());
    //总览->物业收费页面加载
    doc.selectSheet("收费信息");
    QVariant ChargeNum = doc.read(1,2);
    ui.dateEditChargeTime->setDisplayFormat("yyyy.MM.dd");
    ui.dateEditChargeTime->setDate(QDateTime::currentDateTime().date());
    ui.dateEditChargeTime->setCalendarPopup(true);
    ShowChargeInfo();

    //房型信息
    ui.labelRoomTypeBImage->setVisible(false);
    ui.labelRoomTypeBDetail->setVisible(false);
    //住户信息加载
    ShowHouseholdInfo();
    //车位信息加载
    ShowParkingInfo();
    //投诉报修信息加载
    ShowFeedbackInfo();
    ShowFeedbackInfo2();
}
//按下修改按钮后允许修改小区信息
void PMIS::EditCommunityInfo()
{
    ui.lineEditCommunityName->setFrame(true);
    ui.lineEditCommunityLocation->setFrame(true);
    ui.lineEditCommunityName->setReadOnly(false);
    ui.lineEditCommunityLocation->setReadOnly(false);
}
//按下保存按钮后保存小区信息
void PMIS::SaveCommunityInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    doc.write(2,1,ui.lineEditCommunityName->text());
    doc.write(2,2,ui.lineEditCommunityLocation->text());
    doc.save();
    ui.lineEditCommunityName->setFrame(false);
    ui.lineEditCommunityLocation->setFrame(false);
    ui.lineEditCommunityName->setReadOnly(true);
    ui.lineEditCommunityLocation->setReadOnly(true);
}
//保存并执行收费
void PMIS::DoCharge()
{
    QMessageBox confirm;
    confirm.setWindowTitle(tr("请确认"));
    confirm.setText(tr("确认执行收费吗？"));
    confirm.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirm.setButtonText(QMessageBox::Yes,tr("确认"));
    confirm.setButtonText(QMessageBox::No,tr("取消"));
    confirm.setDefaultButton(QMessageBox::Yes);
    if (confirm.exec() == QMessageBox::Yes)
     {
        int roomTypeA = 0,roomTypeB = 0,Parking = 0;
        QXlsx::Document xlsx;
        Document doc("Data.xlsx");
        doc.selectSheet("收费信息");
        QVariant chargeNum = doc.read(1,2);
        doc.write(chargeNum.toInt()+3,1,ui.dateEditChargeTime->date());
        doc.write(chargeNum.toInt()+3,2,ui.lineEditChargeCost->text().toFloat());
        if (ui.checkBoxChargeRoomTypeA->checkState())
        {
            doc.write(chargeNum.toInt()+3,3,1);
            roomTypeA = 1;
        }
        else doc.write(chargeNum.toInt()+3,3,0);
        if (ui.checkBoxChargeRoomTypeB->checkState())
        {
            doc.write(chargeNum.toInt()+3,4,1);
            roomTypeB = 1;
        }
        else doc.write(chargeNum.toInt()+3,4,0);
        if (ui.checkBoxChargeParking->checkState())
        {
            doc.write(chargeNum.toInt()+3,5,1);
            Parking = 1;
        }
        else doc.write(chargeNum.toInt()+3,5,0);
        doc.write(chargeNum.toInt()+3,6,ui.textEditChargeRemark->toPlainText());
        doc.write(1,2,chargeNum.toInt()+1);
        //扣费
        doc.selectSheet("小区信息");
        int Householdnum = doc.read(2,3).toInt();
        float roomTypeAcost = doc.read(2,7).toFloat();
        float roomTypeBcost = doc.read(2,8).toFloat();
        doc.selectSheet("住户信息");
        for (int i = 1;i<=Householdnum+1;i++)
        {
            if (doc.read(i,4).toString() == "A")
                doc.write(i,7,doc.read(i,7).toFloat()-(ui.lineEditChargeCost->text().toFloat()*roomTypeAcost*roomTypeA));
            if (doc.read(i,4).toString() == "B")
                doc.write(i,7,doc.read(i,7).toFloat()-(ui.lineEditChargeCost->text().toFloat()*roomTypeBcost*roomTypeB));
            if (doc.read(i,5).toString() == "有")
                doc.write(i,7,doc.read(i,7).toFloat()-(ui.lineEditChargeCost->text().toFloat()*Parking));
        }
        doc.save();
        //to do :refresh the table
        CancelCharge();
    }

    //else if (reply == QMessageBox::No)  ;
    ShowChargeInfo();
    ShowHouseholdInfo();


}
//撤销收费信息填写
void PMIS::CancelCharge()
{
    ui.lineEditChargeCost->clear();
    ui.checkBoxChargeRoomTypeA->setChecked(false);
    ui.checkBoxChargeRoomTypeB->setChecked(false);
    ui.textEditChargeRemark->clear();
}
//显示收费信息内容
void PMIS::ShowChargeInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("收费信息");
    int col = 6;
    int row = doc.read(1,2).toInt();
    ui.tableWidgetCharge->setColumnCount(col);
    ui.tableWidgetCharge->setRowCount(row);
    ui.tableWidgetCharge->horizontalHeader()->setDefaultSectionSize(135);
    ui.tableWidgetCharge->verticalHeader()->setMinimumWidth(30);
    QStringList headlabels;
    headlabels <<"收费时间"<<"单价"<<"房型A"<<"房型B"<<"车位"<<"备注";
    ui.tableWidgetCharge->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<=row;i++)
    {
        for (int j=0;j<col;j++)
        {
            QTableWidgetItem *newItem;
            if (j>=2 && j<=4)
            {
                if (doc.read(i+3,j+1).toInt() == 1)
                {
                    newItem = new QTableWidgetItem(tr("√"));
                }
                else
                {
                    newItem = new QTableWidgetItem(tr(""));
                }
            }
            else
            {
                if (j != 1)
                    newItem = new QTableWidgetItem(doc.read(i+3,j+1).toString());
                else
                    newItem = new QTableWidgetItem(QString::number(doc.read(i+3,j+1).toDouble(),'f',2));
            }
            newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
            ui.tableWidgetCharge->setItem(i,j,newItem);
        }
    }
    ui.tableWidgetCharge->setSelectionBehavior(QAbstractItemView::SelectRows);
}
//显示住户信息
void PMIS::ShowHouseholdInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,3).toInt();
    doc.selectSheet("住户信息");
    int col = 7;
    ui.tableWidgetHouseholdInfo->setColumnCount(col);
    ui.tableWidgetHouseholdInfo->setRowCount(row);
    ui.tableWidgetHouseholdInfo->horizontalHeader()->setDefaultSectionSize(129);
    ui.tableWidgetHouseholdInfo->verticalHeader()->setVisible(false);
    ui.tableWidgetHouseholdInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headlabels;
    headlabels <<"编号"<<"姓名"<<"住址"<<"房型"<<"车位"<<"电话"<<"账户金额";
    ui.tableWidgetHouseholdInfo->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<=row;i++)
    {
        for (int j=0;j<col;j++)
        {
            QTableWidgetItem *newItem;
            if (j != col-1)
            {
                newItem = new QTableWidgetItem(doc.read(i+2,j+1).toString());
            }
            else
            {
                newItem = new QTableWidgetItem();
                newItem->setData(Qt::DisplayRole,doc.read(i+2,j+1).toFloat());
            }
            newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
            ui.tableWidgetHouseholdInfo->setItem(i,j,newItem);
        }
    }
    ui.tableWidgetHouseholdInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.tableWidgetHouseholdInfo->setContextMenuPolicy(Qt::CustomContextMenu);
}
//允许修改住户信息
void PMIS::EditHouseholdInfo()
{
    ui.tableWidgetHouseholdInfo->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.buttonSaveHouseholdInfo->setEnabled(true);
}
//保存住户信息并刷新显示
void PMIS::SaveHouseholdInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,3).toInt();
    doc.selectSheet("住户信息");
    int col = 7;
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<col;j++)
        {
            doc.write(i+2,j+1,ui.tableWidgetHouseholdInfo->item(i,j)->text());
        }
    }
    doc.save();
    ShowHouseholdInfo();
    ui.buttonSaveCommunityInfo->setEnabled(false);
}
//输出住户信息
void PMIS::PrintHouseholdInfo()
{
    SaveHouseholdInfo();
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,3).toInt();

    QXlsx::Document xlsxW;
    xlsxW.write(1,1,"编号");
    xlsxW.write(1,2,"姓名");
    xlsxW.write(1,3,"住址");
    xlsxW.write(1,4,"房型");
    xlsxW.write(1,5,"车位");
    xlsxW.write(1,6,"电话");
    xlsxW.write(1,7,"账户金额");
    int col = 7;
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<col;j++)
        {
            xlsxW.write(i+2,j+1,ui.tableWidgetHouseholdInfo->item(i,j)->text());
        }
    }
    xlsxW.saveAs("Output.xlsx");
    QFile file("Output.xlsx");
    if (file.exists())
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("Output.xlsx"));
    }
}
//住户信息排序
void PMIS::slot_sortByColumn(int index)
{
    if (index == 6 && flag)
    {
        ui.tableWidgetHouseholdInfo->sortItems(index,Qt::DescendingOrder);
        flag = !flag;
    }
    else if (index == 6 && !flag)
    {
        ui.tableWidgetHouseholdInfo->sortItems(index,Qt::AscendingOrder);
        flag = !flag;
    }
}
//查询住户
void PMIS::on_lineEditHouseholdID_editingFinished()
{
    QString data = ui.lineEditHouseholdID->text();
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int num = doc.read(2,3).toInt();

    for (int i=0;i<num;i++)
    {
        if (ui.tableWidgetHouseholdInfo->item(i,0)->text() == data || ui.tableWidgetHouseholdInfo->item(i,1)->text() == data)
            ui.tableWidgetHouseholdInfo->setCurrentCell(i,QItemSelectionModel::Select);
    }
}
//删除住户
void PMIS::DeleteHousehold()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("住户信息");
    int row = ui.tableWidgetHouseholdInfo->currentRow();
    doc.write(row+2,2,"无");
    doc.write(row+2,4,"无");
    doc.write(row+2,5,"无");
    doc.write(row+2,6,"无");
    doc.write(row+2,7,"无");
    doc.selectSheet("小区信息");
    doc.write(1,7,doc.read(1,7).toInt()-1);
    doc.save();
    ShowHouseholdInfo();
    ui.tableWidgetHouseholdInfo->selectRow(row);
    ui.tableWidgetHouseholdInfo->setFocus(Qt::MouseFocusReason);

}
//显示车位信息
void PMIS::ShowParkingInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,4).toInt();
    ui.lineEditPNum->setText(doc.read(2,4).toString());
    QString temp = QString::number(doc.read(2,4).toInt()-doc.read(3,4).toInt());
    ui.lineEditPNum3->setText(temp);
    ui.lineEditPNum2->setText(doc.read(3,4).toString());
    doc.selectSheet("车位信息");
    int col = 3;
    ui.tableWidgetParkingInfo->setColumnCount(col);
    ui.tableWidgetParkingInfo->setRowCount(row);
    ui.tableWidgetParkingInfo->horizontalHeader()->setDefaultSectionSize(160);
    ui.tableWidgetParkingInfo->verticalHeader()->setVisible(false);
    ui.tableWidgetParkingInfo->setSelectionBehavior(QAbstractItemView::SelectRows);

    doc.selectSheet("车位信息");
    QStringList headlabels;
    headlabels <<"车位编号"<<"住户编号"<<"住户车牌";
    ui.tableWidgetParkingInfo->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<=row;i++)
    {
        for (int j=0;j<col;j++)
        {
            QTableWidgetItem *newItem;
            newItem = new QTableWidgetItem(doc.read(i+2,j+1).toString());
            newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
            ui.tableWidgetParkingInfo->setItem(i,j,newItem);
        }
    }
    ui.tableWidgetParkingInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//选择车牌信息进行查询
void PMIS::on_comboBox_currentIndexChanged(int index)
{
    ui.tableWidgetParkingInfo->clearSelection();
    ui.comboBox_2->clear();
    QStringList JS;
    JS<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"J"<<"K"<<"L"<<"M"<<"N";
    QStringList ZJ;
    ZJ<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"J"<<"K"<<"L";
    QStringList SH;
    SH<<"A"<<"B"<<"C"<<"D";
    switch(index)
    {
    case 0:ui.comboBox_2->addItems(JS);break;
    case 1:ui.comboBox_2->addItems(ZJ);break;
    case 2:ui.comboBox_2->addItems(SH);break;
    }
}
void PMIS::on_lineEditSearchCarID_editingFinished()
{
    ui.tableWidgetParkingInfo->clearSelection();
    QString data = ui.comboBox->currentText() + ui.comboBox_2->currentText() + " " + ui.lineEditSearchCarID->text();
    //qDebug()<<data;
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int num = doc.read(3,4).toInt();

    for (int i=0;i<num;i++)
    {
        if (ui.tableWidgetParkingInfo->item(i,2)->text() == data )
        {
            ui.tableWidgetParkingInfo->setCurrentCell(i,QItemSelectionModel::Select);
        }
    }
}

void PMIS::on_lineEditSearchID_editingFinished()
{
    ui.tableWidgetParkingInfo->clearSelection();
    QString data = ui.lineEditSearchID->text();
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int num = doc.read(2,4).toInt();

    for (int i=0;i<num;i++)
    {
        if (ui.tableWidgetParkingInfo->item(i,0)->text() == data || ui.tableWidgetParkingInfo->item(i,1)->text() == data)
        {
            ui.tableWidgetParkingInfo->setCurrentCell(i,QItemSelectionModel::Select);
        }
    }
}
//允许修改车位信息
void PMIS::EditParkingInfo()
{
    ui.tableWidgetParkingInfo->setEditTriggers(QAbstractItemView::CurrentChanged);
    ui.buttonSaveParkingInfo->setEnabled(true);
    ui.buttonEditParkingInfo->setEnabled(false);
}
//保存车位信息并刷新显示
void PMIS::SaveParkingInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,4).toInt();
    doc.selectSheet("车位信息");
    int col = 3;
    for (int i = 0;i<row;i++)
    {
        for (int j = 0;j<col;j++)
        {
            doc.write(i+2,j+1,ui.tableWidgetParkingInfo->item(i,j)->text());
        }
    }
    int count = 0;
    //QString temp = doc.read(2,2).toString();

    for (int i=0;i<row;i++)
    {
        if (doc.read(i+2,2).toString() != "")
            count ++;
    }
    qDebug()<<"count"<<count;
    doc.selectSheet("小区信息");
    doc.write(3,4,count);
    doc.save();
    ShowParkingInfo();
    ui.tableWidgetParkingInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui.buttonSaveParkingInfo->setEnabled(false);
    ui.buttonEditParkingInfo->setEnabled(true);
}
//显示维修信息
void PMIS::ShowFeedbackInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,5).toInt();
    doc.selectSheet("报修");
    int col = 3;
    ui.tableWidgetFeedbackInfo->setColumnCount(col);
    ui.tableWidgetFeedbackInfo->setRowCount(row);
    ui.tableWidgetFeedbackInfo->horizontalHeader()->setDefaultSectionSize(120);
    ui.tableWidgetFeedbackInfo->verticalHeader()->setVisible(false);
    ui.tableWidgetFeedbackInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headlabels;
    headlabels <<"时间"<<"状态"<<"简述";
    ui.tableWidgetFeedbackInfo->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<row;i++)
    {
            for (int j=0;j<col;j++)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(doc.read(i+1,j+1).toString());
                newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
                ui.tableWidgetFeedbackInfo->setItem(i,j,newItem);
            }
    }
    ui.tableWidgetFeedbackInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//显示报修信息详情
void PMIS::on_tableWidgetFeedbackInfo_cellClicked(int row, int column)
{
    std::cout<<column;
    ui.pushButtonDone->setEnabled(false);
    ui.pushButtonDoing->setEnabled(false);
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("报修");
    ui.labelFeedbackType->setText("编号："+doc.read(row+1,4).toString());
    ui.textBrowserFeedbackDetail->setText(doc.read(row+1,5).toString());
    if (doc.read(row+1,3) == "处理中") ui.pushButtonDone->setEnabled(true);
    else if (doc.read(row+1,3) == "待处理") ui.pushButtonDoing->setEnabled(true);
}
//改变报修信息状态
void PMIS::ChangeFeedbackInfo()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("报修");
    int row = ui.tableWidgetFeedbackInfo->currentRow();
    doc.write(row+1,3,"处理中");
    doc.save();
    ShowFeedbackInfo();
    ui.tableWidgetFeedbackInfo->selectRow(row);
    ui.tableWidgetFeedbackInfo->setFocus(Qt::MouseFocusReason);
    ui.pushButtonDone->setEnabled(true);
    ui.pushButtonDoing->setEnabled(false);
}
//解决报修信息
void PMIS::FeedbackInfoDone()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("报修");
    int row = ui.tableWidgetFeedbackInfo->currentRow();
    doc.write(row+1,3,"已解决");
    doc.save();
    ShowFeedbackInfo();
    ui.tableWidgetFeedbackInfo->selectRow(row);
    ui.tableWidgetFeedbackInfo->setFocus(Qt::MouseFocusReason);
    ui.pushButtonDone->setEnabled(false);
    ui.pushButtonDoing->setEnabled(false);
    doc.selectSheet("小区信息");
    doc.write(3,5,doc.read(3,5).toInt()-1);
    doc.save();
}
//显示投诉信息
void PMIS::ShowFeedbackInfo2()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("小区信息");
    int row = doc.read(2,6).toInt();
    doc.selectSheet("投诉");
    int col = 3;
    ui.tableWidgetFeedbackInfo2->setColumnCount(col);
    ui.tableWidgetFeedbackInfo2->setRowCount(row);
    ui.tableWidgetFeedbackInfo2->horizontalHeader()->setDefaultSectionSize(120);
    ui.tableWidgetFeedbackInfo2->verticalHeader()->setVisible(false);
    ui.tableWidgetFeedbackInfo2->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList headlabels;
    headlabels <<"时间"<<"状态"<<"简述";
    ui.tableWidgetFeedbackInfo2->setHorizontalHeaderLabels(headlabels);
    for (int i=0;i<row;i++)
    {
            for (int j=0;j<col;j++)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(doc.read(i+1,j+1).toString());
                newItem->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
                ui.tableWidgetFeedbackInfo2->setItem(i,j,newItem);
            }
    }
    ui.tableWidgetFeedbackInfo2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//显示投诉信息详情
void PMIS::on_tableWidgetFeedbackInfo2_cellClicked(int row, int column)
{
    std::cout<<column;
    ui.pushButtonDone2->setEnabled(false);
    ui.pushButtonDoing2->setEnabled(false);
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("投诉");
    ui.labelFeedbackType->setText("编号："+doc.read(row+1,4).toString());
    ui.textBrowserFeedbackDetail2->setText(doc.read(row+1,5).toString());
    if (doc.read(row+1,3) == "处理中") ui.pushButtonDone2->setEnabled(true);
    else if (doc.read(row+1,3) == "待处理") ui.pushButtonDoing2->setEnabled(true);
}
//改变投诉信息状态
void PMIS::ChangeFeedbackInfo2()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("投诉");
    int row = ui.tableWidgetFeedbackInfo2->currentRow();
    doc.write(row+1,3,"处理中");
    doc.save();
    ShowFeedbackInfo2();
    ui.tableWidgetFeedbackInfo2->selectRow(row);
    ui.tableWidgetFeedbackInfo2->setFocus(Qt::MouseFocusReason);
    ui.pushButtonDone2->setEnabled(true);
    ui.pushButtonDoing2->setEnabled(false);
}
//解决投诉信息
void PMIS::FeedbackInfoDone2()
{
    QXlsx::Document xlsx;
    Document doc("Data.xlsx");
    doc.selectSheet("投诉");
    int row = ui.tableWidgetFeedbackInfo2->currentRow();
    doc.write(row+1,3,"已解决");
    doc.save();
    ShowFeedbackInfo2();
    ui.tableWidgetFeedbackInfo2->selectRow(row);
    ui.tableWidgetFeedbackInfo2->setFocus(Qt::MouseFocusReason);
    ui.pushButtonDone2->setEnabled(false);
    ui.pushButtonDoing2->setEnabled(false);
    doc.selectSheet("小区信息");
    doc.write(3,6,doc.read(3,6).toInt()-1);
    doc.save();
}
//切换房型显示
void PMIS::SwitchRoomType()
{
    ui.labelRoomTypeAImage->setVisible(!ui.labelRoomTypeAImage->isVisible());
    ui.labelRoomTypeBImage->setVisible(!ui.labelRoomTypeBImage->isVisible());
    ui.labelRoomTypeADetail->setVisible(!ui.labelRoomTypeADetail->isVisible());
    ui.labelRoomTypeBDetail->setVisible(!ui.labelRoomTypeBDetail->isVisible());
}
//打开数据文件
void PMIS::OutputAll()
{
    QFile file("Data.xlsx");
    if (file.exists())
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("Data.xlsx"));
    }
}

