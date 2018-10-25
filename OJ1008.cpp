#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int calendar[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
//日历，存放每月天数

class Date{
public:
	int year;
	int month;
	int day;

	Date() {}  // 构造函数
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	bool isLeap()  // 闰年判断
    {
        if((year % 4 == 0) && (year % 100 != 0 || year % 400 ==0))
            return true;
		else return false;
	}

	Date getNextday()  // 获得下一天,用来逐天判断
	{
		Date nextday(year, month, day);

		int leapResult;
		if(isLeap())
            leapResult = 1;
		else leapResult = 0;

		if(day < calendar[leapResult][month]) // 下一天在当月
            nextday.day++;
		else
		{
			if(month < 12) // 下一天在下一月
			{
				nextday.month++;
				nextday.day = 1;
			}
			else // 下一天在下一年
			{
				nextday.year++;
				nextday.month = 1;
				nextday.day = 1;
			}
		}
		return nextday;
	}

	bool isWeekend()  // 周末判断
	{
		int y = year, m = month ,d = day;
		if(m == 1 || m == 2) {
			y--;
			m += 12;
		}
		int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1; // 基姆拉尔森计算公式，可根据日期计算这一天是星期几,0-6分别对应周一到周日，因此要+1
		if(week > 5)
            return true;
		else return false;
	}

	bool isHoliday() // 节假日判断
	{
		if((month == 1 && day == 1) || (month == 5 && day >= 1 && day <= 3) || (month == 10 && day >= 1 && day <= 7 ))
            return true;
		else return false;
	}

    //交易日判断：若满足非周末、非节假日（元旦、五一、十一）两个条件，则为交易日
	bool isDealDay() {
		if(isWeekend())
            return false;
		else if(isHoliday())
		    return false;
		else return true;
	}



	int calDealDay()   // 计算一年的交易日,364 = 7 * 52：一年有52个整周，因此一年至少有104天，闰年判断12.30和12.31，平年判断12.31。
	{
		int dd = 104, totalDay;
		Date d1(year, 12, 30), d2(year, 12, 31);
		if(isLeap()) {
			if(d1.isWeekend()) dd++;
			if(d2.isWeekend()) dd++;
			totalDay = 366;
		}
		else{
			if(d2.isWeekend()) dd++;
			totalDay = 365;
		}
		// 一年的节假日
		if(!Date(year, 1, 1).isWeekend()) //元旦
            dd++;
		for(int i = 1; i < 4; i++) //五一
		{
			if(!Date(year, 5, i).isWeekend())
			  dd++;
		}
		dd += 5;  //十一假期7天，必包含2天周末和5天工作日
		return totalDay - dd;
	}
};


bool equals(Date d1, Date d2) // 两个日期是否相等
{
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}

int main() {
	int n;
	cin >> n;
    int r[1];

	string s1[n], s2[n]; //根据数据条数定义字符串数组大小
	int daynum[n];

	for(int i = 0; i < n; i++)
        {
		cin >> s1[i];
		cin >> s2[i];

		string sy1, sy2, sm1, sm2, sd1, sd2; // 分离输入数据中的年月日
		sy1 = s1[i].substr(0, 4);
		sm1 = s1[i].substr(5, 2);
		sd1 = s1[i].substr(8, 2);
		sy2 = s2[i].substr(0, 4);
		sm2 = s2[i].substr(5, 2);
		sd2 = s2[i].substr(8, 2);

		int y1, y2, m1, m2, d1, d2; //将分离出来的年月日转化为int类型，使用<stdlib.h>中的atoi函数
		y1 = atoi(sy1.c_str());  //c_str()将string对象转换为c中的字符串样式，atoi函数的参数中定义为char*类型，因此需要转换
		m1 = atoi(sm1.c_str());
		d1 = atoi(sd1.c_str());
		y2 = atoi(sy2.c_str());
		m2 = atoi(sm2.c_str());
		d2 = atoi(sd2.c_str());

		Date date1(y1, m1, d1), date2(y2, m2, d2), di;

		daynum[i] = 0; // 交易日

		if(y1 == y2) // 判断是否同年
        {
            date2 = date2.getNextday();   //同年，则逐天判断
			for(di = date1; !equals(di, date2); di = di.getNextday())
			{
				if(di.isDealDay())
				  daynum[i]++;
			}
		}
		else
		{
			for(di = date1; !equals(di, Date(y1 + 1, 1, 1)); di = di.getNextday())  // 不同年，计算date1到年底的交易日，加上日期之间整年的交易日，加上年初到对date2的交易日
			{
				if(di.isDealDay())
				  daynum[i]++;
			}
			for(int j = y1 + 1; j < y2; j++)
            {
				Date myear(j, 1, 1);
				daynum[i] +=  myear.calDealDay();
			}
			date2 = date2.getNextday();
			for(di = Date(y2, 1, 1); !equals(di, date2); di = di.getNextday())
            {
				if(di.isDealDay())
                    daynum[i]++;
			}
		}
	}

	for(int i = 0; i < n; i++)
    {
        cout<<daynum[i]<<endl;
    }
}
