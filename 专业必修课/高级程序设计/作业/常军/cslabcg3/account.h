//account.h
#ifndef  __ACCOUNT_H__
#define  __ACCOUNT_H__

class SavingsAccount {        //储蓄账户类
private:
	int id;                  //账号
	double balance;          //余额
	double rate;
	int lastDate;            //上次变更余额的时间
	double accumulation;     //余额按日累加之和
	static double total;     //所有账户的总金额 
	//记录一笔账，date为日期，amount为金额
	void record(int date, double amount);
	//获得到指定日期为止的存款金额按日累积值
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	}
public:
	//构造函数
	SavingsAccount(int date, int id, double rate);
	int getId() const { return id; }
	double getBalance() const { return balance; }
	double getRate() const { return rate; }
	static double getTotal() { return total; }
	void deposit(int date, double amount);    //存入现金
	void withdraw(int date, double amount);  //取出现金
	//结算利息
	void settle(int date);
	void show() const;
};
#endif//__ACCOUNT_H__
