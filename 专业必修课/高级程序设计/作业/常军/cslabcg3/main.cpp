// main.cpp : 个人银行账户管理程序。此处提供main.cpp工程文件作为示范，和account.h声明文件作为约束和提示，请独自完成account.cpp函数实现文件的编写。
//

#include "account.h"
#include <iostream>
using namespace std;

int main()
{
    //const double bank_rate = 0.015;
    double bank_rate;
    int i_date;
    int use_date1, use_date2,use_id1,use_id2;
    int s_date1, s_date2, w_date1, w_date2;
    double SaveAmout1, SaveAmout2, DeceAmout1, DeceAmout2;

    //cout << "请输入年利率、利息结算日:" << endl;
    cin >> bank_rate >> i_date;
    //cout << "请输入第一个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额：" << endl;
    cin >> use_date1 >> use_id1 >> s_date1>>SaveAmout1 >> w_date1>>DeceAmout1;
    //cout << "请输入第二个账户的创建日期、账户号（id）、存款日期、存入的金额、取款日期、取出的金额：" << endl;
    cin >> use_date2>> use_id2 >> s_date2>>SaveAmout2 >> w_date2>> DeceAmout2;
       
    //建立几个账户
    SavingsAccount sa0(use_date1, use_id1, bank_rate);
    SavingsAccount sa1(use_date2, use_id2, bank_rate);
     
        
    //几笔账目   
     sa0.deposit(s_date1, SaveAmout1);
     sa1.deposit(s_date2, SaveAmout2);

       
    sa0.withdraw(w_date1, DeceAmout1);
    sa1.withdraw(w_date2, DeceAmout2);
   

    //开户后第i_date天到了银行的计息日，结算所有账户的年息
    sa0.settle(i_date);
    sa1.settle(i_date);
    
    //输出各个账户信息
    sa0.show(); cout << endl;
    sa1.show(); cout << endl;
   

    cout << "Total:" << SavingsAccount::getTotal() << endl;
    //cout << "Total:" << SavingsAccount::getTotal();
    return 0;
}
