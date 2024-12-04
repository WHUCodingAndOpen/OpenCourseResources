#include <bits/stdc++.h>

class Date{
    int year;
    int month;
    int day;

    public:

    Date(int a,int b, int c){

        year = a;
        month = b;
        day = c;
    }

    std::string toText(){
        return std::to_string(year)+"-"+std::to_string(month)+"-"+std::to_string(day);
    }

    Date nextDay(){
        if (day = 31 ){
            if (month == 12){
                Date da(year+1,1,1);
                return da;
            }else{
            Date da(year,month+1,1);
            return da;
            }
        }else if (day == 30){
            if(month == 4 || month == 6 || month == 9 || month ==11){
                Date da(year,month+1,1);
                return da;
            }else{
                Date da(year,month,day+1);
                return da;
            }
        }else if (day == 29 && month == 2){
            Date da(year,month+1,1);
                return da;
        }else if (day == 28 && month ==2 && year % 4 != 0){
            Date da(year,month+1,1);
                return da;
        }else{
            Date da(year,month,day+1);
            return da;
        }
    }

    Date prevDay(){
        
    }
};