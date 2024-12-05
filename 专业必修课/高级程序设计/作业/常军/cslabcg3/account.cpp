#include "account.h"
#include <bits/stdc++.h>

SavingsAccount::SavingsAccount(int date, int id, double rate){
    this->id = id;
    this->balance = 0;
    this->rate = rate;
    this->lastDate = date;
    this->accumulation = 0;
    std::cout << date << " #" << id << " is created" << std::endl;
}

void SavingsAccount::record(int date, double amount) {
    accumulation += balance * (date - lastDate); // 累加余额变动
    lastDate = date; // 更新上次余额变动日期
    balance += amount; // 更新余额
    total += amount; // 更新总余额
}

void SavingsAccount::deposit(int date, double amount) {
    record(date, amount);
    std::cout << date << " #" << id << " " << amount << " " << balance << std::endl;
}

void SavingsAccount::withdraw(int date, double amount) {
    record(date, -amount);
    std::cout << date << " #" << id << " -" << amount << " " << balance << std::endl;
}

void SavingsAccount::settle(int date) {
    double interest = accumulate(date) * rate / 365; // 计算利息
    record(date, interest); // 将利息加入余额
    std::cout << date << " #" << id << " " << std::round(interest*100)/100 << " " << balance << std::endl;
}

void SavingsAccount::show() const {
    std::cout << "#" << id << " Balance:" << balance << std::endl;
}

double SavingsAccount::total = 0; // 初始化静态成员变量