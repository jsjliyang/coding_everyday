//运算符重载

#include <iostream>
#include <iomanip> //题目中求小数点2位，要用到格式控制符；否则可以用printf。
using namespace std;

class MyComplex
{
private:
  double x,y;
public:
  /* Implementation of MyComplex */
  MyComplex(){}
  MyComplex(double a,double b);
  MyComplex operator+(MyComplex &z2);
  MyComplex operator-(MyComplex &z2);
  MyComplex operator*(MyComplex &z2);
  MyComplex operator/(MyComplex &z2);
  MyComplex operator+=(MyComplex &z2);
  MyComplex operator-=(MyComplex &z2);
  MyComplex operator*=(MyComplex &z2);
  MyComplex operator/=(MyComplex &z2);
};
  MyComplex:: MyComplex(double a,double b)
  {
      this->x = a;
      this->y = b;
  }
  MyComplex MyComplex:: operator+(MyComplex &z2)
  {
      MyComplex z3;
      z3.x = this->x + z2.x;
      z3.y = this->y + z2.y;
      cout<<z3.x<<" "<<z3.y<<endl;
      return z3;
  }
  MyComplex MyComplex:: operator-(MyComplex &z2)
  {
      MyComplex z3;
      z3.x = this->x - z2.x;
      z3.y = this->y - z2.y;
      cout<<z3.x<<" "<<z3.y<<endl;
      return z3;
  }
  MyComplex MyComplex:: operator*(MyComplex &z2)
  {
      MyComplex z3;
      z3.x = this->x * z2.x - this->y * z2.y;
      z3.y = this->x * z2.y + this->y * z2.x;
      cout<<z3.x<<" "<<z3.y<<endl;
      return z3;
  }
  MyComplex MyComplex:: operator/(MyComplex &z2)//复数除法：(a+bi)/(c+di)=(a+bi)(c-di)/(c+di)(c-id)=(ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i
  {
      MyComplex z3;
      z3.x = (this->x * z2.x + this->y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
      z3.y = (this->y * z2.x - this->x * z2.y) / (z2.x * z2.x + z2.y * z2.y);
      cout<<z3.x<<" "<<z3.y<<endl;
      return z3;
  }
  MyComplex MyComplex:: operator+=(MyComplex &z2)
  {
      this->x += z2.x;
      this->y += z2.y;
      cout<<this->x<<" "<<this->y<<endl;
      return *this;
  }
  MyComplex MyComplex:: operator-=(MyComplex &z2)
  {
      this->x -= z2.x;
      this->y -= z2.y;
      cout<<this->x<<" "<<this->y<<endl;
      return *this;
  }
  MyComplex MyComplex:: operator*=(MyComplex &z2)
  {
      double p = this->x;
      this->x = this->x * z2.x - this->y * z2.y;
      this->y = p * z2.y + this->y * z2.x;
      cout<<this->x<<" "<<this->y<<endl;
      return *this;
  }
  MyComplex MyComplex:: operator/=(MyComplex &z2)
  {
      double p = this->x;
      this->x = (this->x * z2.x + this->y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
      this->y = (this->y * z2.x - p * z2.y) / (z2.x * z2.x + z2.y * z2.y);
      cout<<this->x<<" "<<this->y<<endl;
      return *this;
  }


int main()
{
  double x,y;
  cin>>x>>y;
  MyComplex z1(x,y);

  cin>>x>>y;
  MyComplex z2(x,y);

  MyComplex z3;

  cout<<setiosflags(ios::fixed);//用小数点形式来显示数据，头文件是iomanip
  cout<<setprecision(2);//设置2位小数,头文件是iomanip

  z3 = z1 + z2;
  z3 = z1 - z2;
  z3 = z1 * z2;
  z3 = z1 / z2;
  z1 += z2;
  z1 -= z2;
  z1 *= z2;
  z1 /= z2;

  return 0;
}
