/*Построить три класса (базовый и 2 потомка), описывающих некоторых работников с
почасовой оплатой (один из потомков) и фиксированной оплатой (второй потомок).
Написать методы для расчета заработной платы.
Для "повременщиков" формула для расчета следующая: почасовая ставка * 8 * 22
Реализовать следующий функционал:
- добавление, редактирование, удаление работников
- вывод работников
- повышение зарплаты в процентах*/

#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:

	Worker()
	{
		name = "Unknown";
		age = 0;
		status = 0;
	}

	Worker(string name, int age,  int status)
	{
		this->name = name;
		this->age = age;
		this->status = status;
	}

	void setWorkerName(string n)
	{
		name = n;
	}

	string getWorkerName()
	{
		return name;
	}

	void setWorkerAge(int a)
	{
		if(a <= 18)
		{
			a = 18;
		}
		else if(a >= 60)
		{
			a = 60;
		}
		age = a;
	}

	int getWorkerAge()
	{
		return age;
	}

	void setWorkerStatus(int st)
	{
		status = st;
	}

	double getWorkerStatus()
	{
		return status;
	}

	void showWorkerInfo()
	{
		cout<<name<<" "<<age<<" "<<status<<endl;
	}

private:
	string name;
	int age;
	int status;
};

class HourlyWorker : public Worker
{
public:
	HourlyWorker(string name, int age, int status, double rate) :
	  Worker(name, age, status)
	  {
		  this->rate = rate;
	  }

	  void setRate(double rate)
	  {
		  this->rate = rate;
	  }

	  double getRate()
	  {
		  return rate;
	  }

	  double getSalary()
	  {
		  double salary = rate * 8 * 22;
		  return salary;
	  }

	  void showHourlyWorkerInfo()
	  {
		  showWorkerInfo();
		  cout<<"Почасовая ставка: "<<rate<<endl
			  <<"Зарплата: "<<getSalary()<<"\n\n";
	  }

private:
	double rate;
};

class FixedWorker : public Worker
{
public:
	FixedWorker(string name, int age, int status, double salary) :
	  Worker(name, age, status)
	  {
		  this->salary = salary;
	  }

	  void setSalary(double salary)
	  {
		  this->salary = salary;
	  }

	  double getSalary()
	  {
		  return salary;
	  }

	  void showFixedWorkerInfo()
	  {
		  showWorkerInfo();
		  cout<<"Зарплата: "<<salary<<"\n\n";
	  }

private:
	double salary;
};

void main()
{
	setlocale(0, "rus");	 

	HourlyWorker hw("John", 33, 1, 15);
	hw.showHourlyWorkerInfo();

	FixedWorker fw("Bruce", 27, 1, 2956.89);
	fw.showFixedWorkerInfo();
}