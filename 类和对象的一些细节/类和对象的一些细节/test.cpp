#define _CRT_SECURE_NO_WARNINGS


#include"test.h"



//class date
//{
//public:
//	date(int year, int month, int day)
//	{
//		//����Ա������ֵ
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
//		//��ʼ����Ա����
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
//		_a = 0;//error C2789: ��date::_a��: �����ʼ�������޶����͵Ķ���
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
//	//error C2280: ��date::date(void)��: ����������ɾ���ĺ���
//	//message : ���������ڴ˴����ɡ�date::date��
//	//message : ��date::date(void)��: ���� ���ݳ�Ա��date::_T�����߱���Ӧ�� Ĭ�Ϲ��캯�� �����ؽ������ȷ���������ʽɾ������
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
//		,_year(1)//error C2437: ��_year��: �ѳ�ʼ��
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
//	{}//û����ʽд��ʼ���б�
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
//	//1.���ι��캯����û��ʹ��explicit���Σ���������ת������
//	//date(int year)
//	//explicit���ι��캯������ֹ����ת������explicitȥ��֮�󣬴������ͨ������
//	explicit date(int year)
//		:_year(year)
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	//error C2679 : ��Ԫ�� = �� : û���ҵ����ܡ�int�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
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
//	//2.��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���������ת������
//	//date(int year,int month = 1,int day = 1)
//	//ʹ��explicit�ؼ������ι��캯������ֹ����ת���������޷�ͨ��
//	explicit date(int year,int month = 1,int day = 1)
//		:_year(year),_month(month),_day(day)
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	//error C2679 : ��Ԫ�� = �� : û���ҵ����ܡ�int�����͵��Ҳ������������(��û�пɽ��ܵ�ת��)
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
//	d << cout;//�ɶ��Ժ��ڣ�
//	//�������÷��ǳ��֣��ǳ����ϳ��治����
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
//		//ֱ�ӷ���Time������˽�г�Ա
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
//	//������ô���������Ϊ�������޷�ʶ��������һ�������������Ƕ�����
//
//	//���ǿ�����������������������������ص��ǲ���ȡ����
//	//����������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
//	A();
//	cout << "i'm flag.Destructor was called before the end of program." << endl;
//
//	//�������������³����ܺ��ã�����Ҳ�У���ϸ����֮�������
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
	// ��ֵ����
	A aa1;
	f1(aa1);
	cout << endl;

	// ��ֵ����
	f2();
	cout << endl;

	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
	f1(1);
	cout << endl;

	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
	f1(A(2));
	cout << endl;

	// һ�����ʽ�У�������������+��������->�Ż�һ����������
	A aa2 = f2();
	cout << endl;

	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
	aa1 = f2();
	cout << endl;

	return 0;
}
