#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pmis.h"
#include <string>

class PMIS : public QMainWindow
{
	Q_OBJECT

public:
	PMIS(QWidget *parent = Q_NULLPTR);
    bool flag = true;
private:
    Ui::PMISClass ui;
private slots:
    void EditCommunityInfo();
    void SaveCommunityInfo();
    void DoCharge();
    void CancelCharge();
    void ShowChargeInfo();
    void ShowHouseholdInfo();
    void EditHouseholdInfo();
    void SaveHouseholdInfo();
    void PrintHouseholdInfo();
    void ShowParkingInfo();
    void on_lineEditHouseholdID_editingFinished();
    void on_comboBox_currentIndexChanged(int index);
    void on_lineEditSearchCarID_editingFinished();
    void on_lineEditSearchID_editingFinished();
    void EditParkingInfo();
    void SaveParkingInfo();
    void ShowFeedbackInfo();
    void on_tableWidgetFeedbackInfo_cellClicked(int row, int column);
    void ChangeFeedbackInfo();
    void FeedbackInfoDone();
    void ShowFeedbackInfo2();
    void on_tableWidgetFeedbackInfo2_cellClicked(int row, int column);
    void ChangeFeedbackInfo2();
    void FeedbackInfoDone2();
    void SwitchRoomType();
    void DeleteHousehold();
    void slot_sortByColumn(int);
    void OutputAll();
};
