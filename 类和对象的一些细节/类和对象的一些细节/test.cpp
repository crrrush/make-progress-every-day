#define _CRT_SECURE_NO_WARNINGS


#include"test.h"



//class date
//{
//public:
//	date(int year, int month, int day)
//	{
//		//给成员变量赋值
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class date
//{
//public:
//	date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		//初始化成员变量
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//class date
//{
//public:
//	date(int year, int month, int day)
//	{
//		_a = 0;//error C2789: “date::_a”: 必须初始化常量限定类型的对象
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	const int _a;
//};


//class Time
//{
//public:
//	Time(int t)
//		:_t(t)
//	{}
//
//private:
//	int _t;
//};
//
//class date
//{
//public:
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _T;
//};
//
//int main()
//{
//	date d;
//	//error C2280: “date::date(void)”: 尝试引用已删除的函数
//	//message : 编译器已在此处生成“date::date”
//	//message : “date::date(void)”: 由于 数据成员“date::_T”不具备相应的 默认构造函数 或重载解决不明确，因此已隐式删除函数
//	return 0;
//}


//class Time
//{
//public:
//	Time(int t)
//		:_t(t)
//	{}
//
//private:
//	int _t;
//};
//
//class date
//{
//public:
//	date()
//		:_T(0)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _T;
//};
//
//int main()
//{
//	date d;
//	return 0;
//}


//class date
//{
//public:
//	date()
//		:_year(0)
//		,_year(1)//error C2437: “_year”: 已初始化
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	return 0;
//}


//class Time
//{
//public:
//	Time(int t = 0)
//		:_t(t)
//	{
//		cout << "Time(int t = 0)" << endl;
//	}
//private:
//	int _t;
//};
//
//class date
//{
//public:
//	date()
//	{}//没有显式写初始化列表
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _T;
//};
//
//int main()
//{
//	date d;
//	return 0;
//}



//class date
//{
//public:
//	date()
//		:_year(),_month(),_day()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class test
//{
//public:
//	test()
//	{
//		cout << _a << "/" << _b << "/" << _c << endl;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//
//
//
//int main()
//{
//	date d;
//	test t;
//
//	int n;
//	n = 0;
//	cout << n << endl;
//
//	return 0;
//}


//class test
//{
//public:
//	test()
//	{
//	}
//private:
//	const int _a;
//	int& _b;
//	int _c;
//};
//
//int main()
//{
//	test t;
//
//
//	return 0;
//}


//class date
//{
//public:
//	date()
//		:_day(1),_month(_day),_year(1970)
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	date d;
//	return 0;
//}



//class date
//{
//public:
//	//1.单参构造函数，没有使用explicit修饰，具有类型转换作用
//	//date(int year)
//	//explicit修饰构造函数，禁止类型转换——explicit去掉之后，代码可以通过编译
//	explicit date(int year)
//		:_year(year)
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	//error C2679 : 二元“ = ” : 没有找到接受“int”类型的右操作数的运算符(或没有可接受的转换)
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	date d(2022);
//	d = 2023;
//	return 0;
//}


//class date
//{
//public:
//	//2.虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
//	//date(int year,int month = 1,int day = 1)
//	//使用explicit关键字修饰构造函数，禁止类型转换，代码无法通过
//	explicit date(int year,int month = 1,int day = 1)
//		:_year(year),_month(month),_day(day)
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	//error C2679 : 二元“ = ” : 没有找到接受“int”类型的右操作数的运算符(或没有可接受的转换)
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	date d = 2023;
//	return 0;
//}


//class date
//{
//public:
//	date(int year = 1970, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day)
//	{}
//
//	ostream& operator<<(ostream& out)
//	{
//		out << _year << "/" << _month << "/" << _day << endl;
//		return out;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	date d;
//	d << cout;//可读性何在？
//	//这样的用法非常怪，非常不合常规不是吗？
//	return 0;
//}


//class date
//{
//	friend ostream& operator<<(ostream& out, date& d);
//	friend istream& operator>>(istream& in, date& d);
//public:
//	date(int year = 1970, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out,date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day;
//	return out;
//}
//
//istream& operator>>(istream& in, date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	date d;
//	cin >> d;
//	cout << d << endl;
//
//	return 0;
//}

//class Time
//{
//	friend class date;
//public:
//
//private:
//	int _h;
//	int _m;
//	int _s;
//};
//
//class date
//{
//public:
//	date(int year = 1970, int month = 1, int day = 1)
//		:_year(year), _month(month), _day(day)
//	{
//		_t._h = _t._m = _t._s = 0;
//		//直接访问Time类对象的私有成员
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//class A
//{
//public:
//	A(int a1)
//		:_a1(a1)
//	{}
//
//	class B
//	{
//	public:
//		void func(const A& a)
//		{
//			cout << a._a1 << endl;
//			cout << _a2 << endl;
//		}
//	};
//
//private:
//	int _a1;
//	static int _a2;
//};
//
//int A::_a2 = 0;
//
//
//int main()
//{
//	A a(10);
//	A::B b;
//	b.func(a);
//
//	return 0;
//}



//class A
//{
//public:
//	A(int a1 = 0)
//		:_a1(a1)
//	{
//		cout << "A(int a1 = 0)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a1;
//};
//
//class solution
//{
//public:
//	void funtion(int a)
//	{
//		//...
//	}
//
//private:
//};
//
//int main()
//{
//	//A a1();
//	//不能这么定义对象，因为编译器无法识别下面是一个函数声明还是对象定义
//
//	//但是可以这样定义匿名对象，匿名对象的特点是不用取名字
//	//且声明周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	cout << "i'm flag.Destructor was called before the end of program." << endl;
//
//	//匿名对象在以下场景很好用，其他也有，详细看我之后的文章
//	solution().funtion(100);
//
//	return 0;
//}



class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// 传值传参
	A aa1;
	f1(aa1);
	cout << endl;

	// 传值返回
	f2();
	cout << endl;

	// 隐式类型，连续构造+拷贝构造->优化为直接构造
	f1(1);
	cout << endl;

	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
	f1(A(2));
	cout << endl;

	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	A aa2 = f2();
	cout << endl;

	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;

	return 0;
}
