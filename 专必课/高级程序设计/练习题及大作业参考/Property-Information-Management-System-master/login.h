#pragma once

#include <QDialog>
#include "ui_login.h"

class login : public QDialog
{
	Q_OBJECT

public:
	login(QWidget *parent = Q_NULLPTR);
	~login();
private slots:
	void on_clicked();
	void userType();
    bool UserLogin();
signals:
    void sendUserID(QString ID);
private:
	Ui::login ui;
	bool usertype;
    QString account[7][2] = {{"H1","123"},{"H2","234"},{"H3","345"},{"H4","456"},{"H5","567"},{"H6","678"},{"H7","789"}};
};
