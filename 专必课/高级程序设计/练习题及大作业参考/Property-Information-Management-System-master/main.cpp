#include "pmis.h"
#include "login.h"
#include "user.h"
#include <QtWidgets/QApplication>
#include <QCoreApplication>
#include <QDebug>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;
QString UserID;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	login in;
    if (in.exec() == QDialog::Accepted)         //登录验证成功
	{
        //qDebug()<<UserID;
        if(UserID == "admin")                   //用户ID为管理员
        {
            PMIS p;
            p.setFixedSize(1024, 768);
            p.show();
            return a.exec();
        }
        else                                    //用户为普通住户
        {
            User u;
            u.setFixedSize(1024, 768);
            u.show();
            return a.exec();
        }
	}
}

