#include "login.h"
#include<QString>
#include<QMessageBox>
#include<QButtonGroup>
#include<QDebug>
extern QString UserID;
login::login(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonLogin, SIGNAL(clicked()), this, SLOT(on_clicked()));		
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));			
	connect(ui.radioButtonManager, SIGNAL(toggled(bool)), this, SLOT(userType()));	
	connect(ui.radioButtonHousehold, SIGNAL(toggled(bool)), this, SLOT(userType()));
    ui.radioButtonManager->setChecked(false);
    ui.radioButtonHousehold->setChecked(false);
}

login::~login()
{

}
//点击登录验证
void login::on_clicked()
{
    QButtonGroup *bg = new QButtonGroup(this);
    bg->addButton(ui.radioButtonManager,0);
    bg->addButton(ui.radioButtonHousehold,1);
    switch(bg->checkedId())
    {
    case 0:
    {
        {
            if (ui.username->text() == tr("admin") && ui.password->text() == tr("admin"))
            {
                UserID = "admin";
                accept();
            }
            else
            {
                QMessageBox::warning(this, tr("Wrong!"), tr("please try again."), QMessageBox::Yes);
            }
        }
    }
        break;
    case 1:
    {
        if (UserLogin())
        {

            UserID = ui.username->text();
            accept();
        }
        else
        {
            QMessageBox::warning(this, tr("Wrong!"), tr("please try again."), QMessageBox::Yes);
        }
    }
        break;
    }

}
//判断用户类型 false 为住户，true 为管理员
void login::userType()
{
	if (ui.radioButtonHousehold->isChecked())
	{
		usertype = false;
    }
    if (ui.radioButtonManager->isChecked())
	{
		usertype = true;
    }
}
//验证住户登录信息
bool login::UserLogin()
{
    for (int i=0;i<7;i++)
        if (account[i][0] == ui.username->text() && account[i][1] == ui.password->text())
        {
            UserID = ui.username->text();
            return true;
        }
    return false;
}

