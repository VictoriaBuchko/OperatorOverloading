#include <iostream>
using namespace std;

#define TASK 2// поменяйте значение TASK что бы разблоуировать задание 

#if TASK == 1
class Fraction
{
	int Numerator;   // числитель
	int Denominator; // знаменатель
public:

	Fraction() {
		Numerator = 0;
		Denominator = 1;
	}

	Fraction(int numerator, int denominator) {
		Numerator = numerator;
		Denominator = denominator;
	}

	void SetNumeratorFirst() {
		do
		{
			cout << "Enter the numerator for the first fraction: \n";
			cin >> Numerator;

		} while (Numerator == 0);

	}
	void SetDenominatorFirst() {

		do
		{
			cout << "Enter the denominator for the first fraction: \n";
			cin >> Denominator;

		} while (Denominator == 0);
	}
	void SetNumeratorSecond() {

		do
		{
			cout << "Enter the numerator for the second fraction: \n";
			cin >> Numerator;

		} while (Numerator == 0);
	}

	void SetDenominatorSecond() {
		do
		{
			cout << "Enter the denominator for the second fraction: \n";
			cin >> Denominator;

		} while (Denominator == 0);
	}

	int GetNumerator() const {
		return Numerator;
	}

	int GetDenominator() const {
		return Denominator;
	}

	Fraction operator + (const Fraction& fraction2) const {
		Fraction sum;

		sum.Numerator = (Numerator) * (fraction2.Denominator) + (fraction2.Numerator) * (Denominator);
		sum.Denominator = Denominator * fraction2.Denominator;

		return sum;
	}

	Fraction operator - (const Fraction& fraction2) const {
		Fraction difference;

		difference.Numerator = Numerator * (fraction2.Denominator) - (fraction2.Numerator) * Denominator;
		difference.Denominator = Denominator * fraction2.Denominator;

		return difference;
	}

	Fraction operator *(const Fraction& fraction2) const {
		Fraction product;

		product.Numerator = Numerator * fraction2.Numerator;
		product.Denominator = Denominator * fraction2.Denominator;

		return product;
	}

	Fraction operator /(const Fraction& fraction2) const {
		Fraction fraction;

		fraction.Numerator = Numerator * fraction2.Denominator;
		fraction.Denominator = Denominator * fraction2.Numerator;

		return fraction;
	}
};

void printResult(const Fraction& result) {

	if ((result.GetNumerator() == result.GetDenominator()) || result.GetNumerator() == 0)
		cout << result.GetNumerator() / result.GetDenominator();
	else
		cout << result.GetNumerator() << "/" << result.GetDenominator();
}

int main()
{
	Fraction fraction1;
	Fraction fraction2;

	fraction1.SetNumeratorFirst();
	fraction1.SetDenominatorFirst();
	fraction2.SetNumeratorSecond();
	fraction2.SetDenominatorSecond();
	cout << endl;


	cout << "+, -, *, /, using operator overloading" << endl;
	Fraction sum = fraction1 + fraction2;
	Fraction difference = fraction1 - fraction2;
	Fraction product = fraction1 * fraction2;
	Fraction fraction = fraction1 / fraction2;


	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " + " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(sum);
	cout << endl;

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " - " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(difference);
	cout << endl;

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " * " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(product);
	cout << endl;

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " / " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(fraction);
	cout << endl;

	return 0;
}

#elif TASK == 2

class Date
{
	int day;
	int month;
	int year;

public:
	Date(): Date(0,0,0){}

	Date(int Day, int Month, int Year) : day(Day), month(Month), year(Year) {}

	void SetDate()
	{
		do
		{
			cout << "Enter date (day month year): ";
			cin >> day >> month >> year;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				break;
			}
		} while (true);
	}

	int GetDay() const
	{
		return day;
	}

	int GetMonth() const
	{
		return month;
	}
	int GetYear() const
	{
		return year;
	}

	//Высчитываем количество дней
	int TotalDays() const
	{
		int totalDays = day;

		for (int i = 1; i < month; i++)
		{
			totalDays += DaysInMonth(i, year);
		}
		return totalDays + DaysInYear(year);
	}
	//Высчитываем количество дней в определенном месяце
	int DaysInMonth(int monthI, int yearI) const
	{
		switch (monthI)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return (yearI % 4 == 0 && (yearI % 100 != 0 || yearI % 400 == 0)) ? 29 : 28;
		default:
			return 31;
		}
	}

	//Определяем высокосный ли год и считаем количество дней 
	int DaysInYear(int yearI) const
	{
		int days = 0;
		for (int i = 1; i < yearI; i++)
		{
			days += (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) ? 366 : 365;
		}
		return days;
	}


	Date operator - (const Date& date2) const
	{
		Date differenceDate;
		int totalDays1 = TotalDays();
		int totalDays2 = date2.TotalDays();
		differenceDate.day = -(totalDays1 - totalDays2);
		return differenceDate;
	}


	Date operator+(int days) const
	{
		Date newDate = *this; //копию текущей даты

		newDate.day += days;

		//переход на новый месяц
		while (newDate.day > DaysInMonth(newDate.month, newDate.year))
		{
			newDate.day -= DaysInMonth(newDate.month, newDate.year);
			newDate.month++;

			//переход на новый год 
			if (newDate.month > 12)
			{
				newDate.month = 1;
				newDate.year++;
			}
		}

		return newDate;
	}
};


int main()
{
	Date date1;
	Date date2;

	date1.SetDate();

	do
	{
		date2.SetDate();

		if (date1.TotalDays() > date2.TotalDays())
		{
			cout << "Please enter a date later than the first one. Try again\n";
		}
		else
		{
			break;
		}

	} while (true);

	Date differenceDate = date1 - date2;
	cout << "Difference between " << date1.GetDay() << "/" << date1.GetMonth() << "/" << date1.GetYear()
		<< " and " << date2.GetDay() << "/" << date2.GetMonth() << "/" << date2.GetYear() << " = " << differenceDate.GetDay() << "\n\n";


	int daysAdd;
	cout << "Enter the number of days to add to the date: ";
	cin >> daysAdd;
	cout << endl;

	Date newDate = date1 + daysAdd;
	cout << date1.GetDay() << "/" << date1.GetMonth() << "/" << date1.GetYear() << " + " << daysAdd;
	cout << "\nNew date: " << newDate.GetDay() << "/" << newDate.GetMonth() << "/" << newDate.GetYear() << endl;

	return 0;
}

#endif