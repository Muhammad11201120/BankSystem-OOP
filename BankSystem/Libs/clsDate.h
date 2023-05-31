#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"
using namespace std;
class clsDate
{

	enum enDays
	{
		Sunday ,
		Monday ,
		Tuesday ,
		Wednesday ,
		Thursday ,
		Friday ,
		Saturday
	};
	int _day;
	int _month;
	int _year;

public:
	clsDate()
	{

		time_t t = time( 0 );
		tm* now = localtime( &t );
		this->_year = now->tm_year + 1900;
		this->_month = now->tm_mon + 1;
		this->_day = now->tm_mday;
	}
	clsDate( string Date )
	{

		vector<string> vDate;
		vDate = clsString::seperateString( Date , "/" );
		this->_day = stoi( vDate[ 0 ] );
		this->_month = stoi( vDate[ 1 ] );
		this->_year = stoi( vDate[ 2 ] );
	}
	clsDate( int day , int month , int year )
	{
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}

	void setDay( int day )
	{
		this->_day = day;
	}
	int getDay()
	{
		return this->_day;
	}
	void setMonth( int month )
	{
		this->_month = month;
	}
	int getMonth()
	{
		return this->_month;
	}
	void setYear( int year )
	{
		this->_year = year;
	}
	int getYear()
	{
		return this->_year;
	}
	void print()
	{
		cout << this->_day << "/" << this->_month << "/" << this->_year << endl;
	}
	/*Date Methods*/
	enum enDateCompare
	{
		Before = -1 ,
		Equal = 0 ,
		After = 1
	};
	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time( 0 );
		tm* now = localtime( &t );

		short Day , Month , Year , Hour , Minute , Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return ( to_string( Day ) + "/" + to_string( Month ) + "/"
			+ to_string( Year ) + " - "
			+ to_string( Hour ) + ":" + to_string( Minute )
			+ ":" + to_string( Second ) );

	}
	static void swapDates( clsDate& DateOne , clsDate& DateTwo )
	{
		clsDate Temp;

		Temp = DateOne;
		DateOne = DateTwo;
		DateTwo = Temp;
	}
	void swapDates( clsDate DateTwo )
	{
		swapDates( *this , DateTwo );
	}
	static bool isAleapYear( int year )
	{
		return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
	}
	bool isAleapYear()
	{
		return isAleapYear( this->_year );
	}
	static short numberOfDaysInMonth( short year , short month )
	{
		if ( month < 1 || month > 12 )
			return 0;
		short arr[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return ( month == 2 ) ? ( isAleapYear( year ) ? 29 : 28 ) : arr[ month - 1 ];
	}
	short numberOfDaysInMonth()
	{
		return numberOfDaysInMonth( this->_year , this->_month );
	}
	static short daysFromBeginingOfTheYear( short year , short month , short day )
	{
		short days = 0;
		for ( short i = 1; i <= month - 1; i++ )
		{
			days += numberOfDaysInMonth( year , i );
		}

		return days += day;
	}
	short daysFromBeginingOfTheYear()
	{
		return daysFromBeginingOfTheYear( this->_year , this->_month , this->_day );
	}
	static clsDate getDateOfDays( short year , short daysNumberInYear )
	{
		clsDate Date;
		short remainingDays = daysNumberInYear; // to increment days from.
		short monthDays = 0;

		Date._month = 1;
		Date._year = year;

		while ( true )
		{
			monthDays = numberOfDaysInMonth( year , Date._month );
			if ( remainingDays > monthDays )
			{
				remainingDays -= monthDays;
				Date._month++;
			}
			else
			{
				Date._day = remainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate getDateOfDays( short daysNumberInYear )
	{
		return getDateOfDays( this->_year , daysNumberInYear );
	}
	static clsDate addingDaysToDate( clsDate Date , int addingDays )
	{
		int monthDays = 0;
		while ( addingDays > 0 )
		{
			monthDays = numberOfDaysInMonth( Date._year , Date._month );
			Date._day++;
			if ( Date._day == monthDays )
			{
				Date._day = 1;
				Date._month++;
			}
			if ( Date._month == 12 )
			{
				Date._month = 1;
				Date._year++;
			}
			addingDays--;
		}
		return Date;
	}
	clsDate addingDaysToDate( int addingDays )
	{
		return addingDaysToDate( *this , addingDays );
	}
	static bool AreTwoDatesEqual( clsDate& DateOne , clsDate& DateTwo )
	{
		return ( DateOne._year == DateTwo._year ) && ( DateOne._month == DateTwo._month ) && ( DateOne._day == DateTwo._day );
	}
	bool AreTwoDatesEqual( clsDate DateTwo )
	{
		return AreTwoDatesEqual( *this , DateTwo );
	}
	static bool IsFirstDateBeforeSecondDate( clsDate DateOne , clsDate DateTwo )
	{
		return ( DateOne._year < DateTwo._year ) ? true : ( ( DateOne._year == DateTwo._year ) ? ( DateOne._month < DateTwo._month ? true : ( DateOne._month == DateTwo._month ? DateOne._day < DateTwo._day : false ) ) : false );
	}
	bool IsFirstDateBeforeSecondDate( clsDate DateTwo )
	{
		return IsFirstDateBeforeSecondDate( *this , DateTwo );
	}
	static bool IsFirstDatefterSecondDate( clsDate DateOne , clsDate DateTwo )
	{
		return ( !IsFirstDateBeforeSecondDate( DateOne , DateTwo ) && !AreTwoDatesEqual( DateOne , DateTwo ) );
	}
	bool IsFirstDatefterSecondDate( clsDate DateTwo )
	{
		return IsFirstDatefterSecondDate( *this , DateTwo );
	}
	static bool checkIfTheLastDayInTheMonth( clsDate& Date )
	{
		return ( Date._day == numberOfDaysInMonth( Date._year , Date._month ) );
	}
	bool checkIfTheLastDayInTheMonth()
	{
		return checkIfTheLastDayInTheMonth( *this );
	}
	static bool checkIfTheLastMonthInTheYear( clsDate& Date )
	{
		return ( Date._month == 12 );
	}
	bool checkIfTheLastMonthInTheYear()
	{
		return checkIfTheLastMonthInTheYear( *this );
	}
	static enDays calculateDayOfYear( int year , short month , short day )
	{
		int a = ( 14 - month ) / 12;
		int y = year - a;
		int m = month + ( 12 * a ) - 2;
		int d = ( day + y + ( y / 4 ) - ( y / 100 ) + ( y / 400 ) + ( ( 31 * m ) / 12 ) ) % 7;
		return ( enDays ) d;
	}
	enDays calculateDayOfYear()
	{
		return calculateDayOfYear( this->_year , this->_month , this->_day );
	}
	static string getDay( enDays day )
	{
		switch ( day )
		{
		case enDays::Sunday:
			return "Sunday";
		case enDays::Monday:
			return "Monday";
		case enDays::Tuesday:
			return "Tuesday";
		case enDays::Wednesday:
			return "Wednesday";
		case enDays::Thursday:
			return "Thursday";
		case enDays::Friday:
			return "Friday";
		case enDays::Saturday:
			return "Saturday";
		}
	}
	static string monthName( short month )
	{
		string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		return months[ month - 1 ];
	}

	static void printMonthCalender( int year , short month )
	{
		int numberOfDays;
		int current = calculateDayOfYear( year , month , 1 );
		numberOfDays = numberOfDaysInMonth( year , month );
		cout << "--------------------" << monthName( month ).c_str() << "----------------------" << endl;
		cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
		int i;
		for ( i = 0; i < current; i++ )
		{
			printf( "   " );
		}
		for ( int j = 1; j <= numberOfDays; j++ )
		{
			printf( "%5d" , j );
			if ( ++i == 7 )
			{
				i = 0;
				cout << endl;
			}
		}
		cout << "\n----------------------------------------------" << endl;
	}
	void printMonthCalender()
	{
		printMonthCalender( this->_year , this->_month );
	}
	static void printYearCalender( int year , short month )
	{
		for ( short i = 1; i <= 12; i++ )
		{
			printMonthCalender( year , i );
		}
	}
	void printYearCalender()
	{
		printYearCalender( this->_year , this->_month );
	}

	static clsDate increaseDateByOneDay( clsDate& Date )
	{
		if ( checkIfTheLastDayInTheMonth( Date ) )
		{
			if ( checkIfTheLastMonthInTheYear( Date ) )
			{
				Date._day = 1;
				Date._month = 1;
				Date._year++;
			}
			else
			{
				Date._day = 1;
				Date._month++;
			}
		}
		else
			Date._day++;

		return Date;
	}
	void increaseDateByOneDay()
	{
		increaseDateByOneDay( *this );
	}
	static bool isWeekEnd( clsDate Date )
	{
		if ( getDay( calculateDayOfYear( Date._year , Date._month , Date._day ) ) == "Friday" || getDay( calculateDayOfYear( Date._year , Date._month , Date._day ) ) == "Saturday" )
		{
			return true;
		}
		return false;
	}
	bool isWeekEnd()
	{
		return isWeekEnd( *this );
	}
	static clsDate calculateVacationDates( clsDate DateOne , short vacationDays )
	{
		short weekEndsCounter = 0;
		for ( short i = 0; i < vacationDays; i++ )
		{
			if ( isWeekEnd( DateOne ) )
			{
				weekEndsCounter++;
			}
			DateOne = increaseDateByOneDay( DateOne );
		}
		for ( short i = 0; i < weekEndsCounter; i++ )
		{
			DateOne = increaseDateByOneDay( DateOne );
		}
		// incase the return day is in weekend day
		while ( isWeekEnd( DateOne ) )
		{
			DateOne = increaseDateByOneDay( DateOne );
		}

		return DateOne;
	}
	clsDate calculateVacationDates( short vacationDays )
	{
		return calculateVacationDates( *this , vacationDays );
	}
	static clsDate stringDateToDate( string Date )
	{

		clsDate speratedDate;
		vector<string> vDate;

		vDate = clsString::seperateString( Date , "/" );
		speratedDate._day = stoi( vDate[ 0 ] );
		speratedDate._month = stoi( vDate[ 1 ] );
		speratedDate._year = stoi( vDate[ 2 ] );

		return speratedDate;
	}
	static string dateToString( clsDate Date )
	{
		return to_string( Date._day ) + "/" + to_string( Date._month ) + "/" + to_string( Date._year );
	}
	string dateToString()
	{
		return dateToString( *this );
	}
	static bool isValidDate( clsDate Date )
	{
		short ValidDate = numberOfDaysInMonth( Date._year , Date._month );
		return ( Date._day < ValidDate || Date._day > 1 ) && ( Date._month < 12 || Date._month > 1 );
	}
	bool isValidDate()
	{
		return isValidDate( *this );
	}
	static short differentBetweenTwoDates( clsDate DateOne , clsDate DateTwo , bool InclusingEndDay = false )
	{
		short days = 0;
		if ( !IsFirstDateBeforeSecondDate( DateOne , DateTwo ) )
		{
			return 0;
		}
		while ( IsFirstDateBeforeSecondDate( DateOne , DateTwo ) )
		{
			days++;
			DateOne = increaseDateByOneDay( DateOne );
		}

		return InclusingEndDay ? ++days : days;
	}
	short differentBetweenTwoDates( clsDate DateTwo , bool InclusingEndDay = false )
	{
		return differentBetweenTwoDates( *this , DateTwo , InclusingEndDay );
	}
	static void curretnDate( clsDate Date )
	{
		cout << "Today is => " << getDay( calculateDayOfYear( Date._year , Date._month , Date._day ) );
		cout << " - " << Date._day << "/" << Date._month << "/" << Date._year << endl;
	}
	void curretnDate()
	{
		return curretnDate( *this );
	}
	// IsEndOfWeek.
	static bool isEndOfWeek( clsDate Date )
	{
		if ( getDay( calculateDayOfYear( Date._year , Date._month , Date._day ) ) == "Friday" )
		{
			return true;
		}
		return false;
	}
	bool isEndOfWeek()
	{
		return isEndOfWeek( *this );
	}
	// IsBusinessDay.
	static bool isBusinessDay( clsDate Date )
	{
		if ( !isWeekEnd( Date ) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isBusinessDay()
	{
		return isBusinessDay( *this );
	}
	////DaysUntilTheEndOfWeek.
	static short daysUntilTheEndOfWeek( clsDate Date )
	{
		short counter = 0;
		while ( !isEndOfWeek( Date ) )
		{
			counter++;
			Date._day++;
		}
		return counter;
	}
	short daysUntilTheEndOfWeek()
	{
		return daysUntilTheEndOfWeek( *this );
	}
	////DaysUntiTheEndOfMonth.
	static short daysUntilTheEndOfMonth( clsDate Date )
	{
		short counter = 0;
		while ( Date._day != numberOfDaysInMonth( Date._year , Date._month ) )
		{
			Date._day++;
			counter++;
		}
		return counter;
	}
	short daysUntilTheEndOfMonth()
	{
		return daysUntilTheEndOfMonth( *this );
	}
	////DaysUntilTheEndOfYear
	static short daysUntilTheEndOfYear( clsDate Date )
	{
		clsDate endOfYearDate;
		endOfYearDate._day = 31;
		endOfYearDate._month = 12;
		endOfYearDate._year = Date._year;

		return differentBetweenTwoDates( Date , endOfYearDate , true );
	}
	short daysUntilTheEndOfYear()
	{
		return daysUntilTheEndOfYear( *this );
	}
	static clsDate increaseDateByXDays( clsDate& Date , short numberOfDaysToAdd )
	{
		for ( short i = 0; i < numberOfDaysToAdd; i++ )
		{
			Date = increaseDateByOneDay( Date );
		}
		return Date;
	}
	void increaseDateByXDays( short numberOfDaysToAdd )
	{
		increaseDateByXDays( *this , numberOfDaysToAdd );
	}
	static clsDate increaseDateByOneWeek( clsDate& Date )
	{
		for ( short i = 0; i < 7; i++ )
		{
			Date = increaseDateByOneDay( Date );
		}
		return Date;
	}
	void increaseDateByOneWeek()
	{
		increaseDateByOneWeek( *this );
	}
	static clsDate increaseDateByXWeeks( clsDate& Date , short numberOfWeeksToAdd )
	{
		for ( short i = 0; i < numberOfWeeksToAdd; i++ )
		{
			Date = increaseDateByOneWeek( Date );
		}
		return Date;
	}
	void increaseDateByXWeeks( short numberOfWeeksToAdd )
	{
		increaseDateByXWeeks( *this , numberOfWeeksToAdd );
	}
	static clsDate increaseDateByOneMonth( clsDate& Date )
	{
		short numberOfDaysToAdd = numberOfDaysInMonth( Date._year , Date._month );
		if ( Date._month == 12 )
		{
			Date._month = 1;
			Date._year++;
		}
		else
		{
			Date._month++;
		}
		short numberOfDaysInCurrentMonth = numberOfDaysInMonth( Date._month , Date._year );
		if ( Date._day > numberOfDaysInCurrentMonth )
		{
			Date._day = numberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void increaseDateByOneMonth()
	{
		increaseDateByOneMonth( *this );
	}
	static clsDate increaseDateByXmonths( clsDate& Date , short numberOfMonthsToAdd )
	{
		for ( short i = 0; i < numberOfMonthsToAdd; i++ )
		{
			Date = increaseDateByOneMonth( Date );
		}
		return Date;
	}
	void increaseDateByXmonths( short numberOfMonthsToAdd )
	{
		increaseDateByXmonths( *this , numberOfMonthsToAdd );
	}
	static clsDate increaseDateByOneYear( clsDate& Date )
	{
		Date._year++;
		return Date;
	}
	void increaseDateByOneYear()
	{
		increaseDateByOneYear( *this );
	}
	static clsDate increaseDateByXYears( clsDate& Date , short numberOfYearsToAdd )
	{
		for ( short i = 0; i < numberOfYearsToAdd; i++ )
		{
			Date = increaseDateByOneYear( Date );
		}
		return Date;
	}
	void increaseDateByXYears( short numberOfYearsToAdd )
	{
		increaseDateByXYears( *this , numberOfYearsToAdd );
	}
	static clsDate increaseDateByXYearsFaster( clsDate& Date , short numberOfYeasrToAdd )
	{
		Date._year += numberOfYeasrToAdd;
		return Date;
	}
	void increaseDateByXYearsFaster( short numberOfYeasrToAdd )
	{
		increaseDateByXYearsFaster( *this , numberOfYeasrToAdd );
	}
	static clsDate increaseDateByOneDecade( clsDate& Date )
	{
		for ( short i = 0; i < 10; i++ )
		{
			Date = increaseDateByOneYear( Date );
		}
		return Date;
	}
	void increaseDateByOneDecade()
	{
		increaseDateByOneDecade( *this );
	}
	static clsDate increaseDateByXDecades( clsDate& Date , short numberOfDecadesToAdd )
	{
		for ( short i = 0; i < numberOfDecadesToAdd; i++ )
		{
			Date = increaseDateByOneDecade( Date );
		}
		return Date;
	}
	void increaseDateByXDecades( short numberOfDecadesToAdd )
	{
		increaseDateByXDecades( *this , numberOfDecadesToAdd );
	}
	static clsDate increaseDateByXDecadesFaster( clsDate& Date , short numberOfYeasrToAdd )
	{
		Date._year += numberOfYeasrToAdd * 10;
		return Date;
	}
	void increaseDateByXDecadesFaster( short numberOfYeasrToAdd )
	{
		increaseDateByXDecadesFaster( *this , numberOfYeasrToAdd );
	}
	static clsDate increaseDateByOneCentury( clsDate& Date )
	{
		for ( short i = 0; i < 10; i++ )
		{
			Date = increaseDateByOneDecade( Date );
		}
		return Date;
	}
	void increaseDateByOneCentury()
	{
		increaseDateByOneCentury( *this );
	}
	static clsDate increaseDatByOneMillennium( clsDate& Date )
	{
		for ( short i = 0; i < 10; i++ )
		{
			Date = increaseDateByOneCentury( Date );
		}
		return Date;
	}
	void increaseDatByOneMillennium()
	{
		increaseDatByOneMillennium( *this );
	}
	static bool checkIfTheFirstDayInTheMonth( clsDate& Date )
	{
		return ( Date._day == 1 );
	}
	bool checkIfTheFirstDayInTheMonth()
	{
		return checkIfTheFirstDayInTheMonth( *this );
	}
	static bool checkIfTheFirstMonthInTheYear( clsDate& Date )
	{
		return ( Date._month == 1 );
	}
	bool checkIfTheFirstMonthInTheYear()
	{
		return checkIfTheFirstMonthInTheYear( *this );
	}
	static clsDate decreaseDateByOneDay( clsDate& Date )
	{
		if ( checkIfTheFirstDayInTheMonth( Date ) )
		{
			if ( checkIfTheFirstMonthInTheYear( Date ) )
			{
				Date._day = numberOfDaysInMonth( Date._year , Date._month );
				Date._month = 12;
				Date._year--;
			}
			else
			{
				Date._month--;
				Date._day = numberOfDaysInMonth( Date._year , Date._month );
			}
		}
		else
		{
			Date._day--;
		}
		return Date;
	}
	void decreaseDateByOneDay()
	{
		decreaseDateByOneDay( *this );
	}
	static clsDate decreaseDateByXDays( clsDate& Date , short daysToSub )
	{
		for ( short i = 0; i < daysToSub; i++ )
		{
			Date = decreaseDateByOneDay( Date );
		}
		return Date;
	}
	void decreaseDateByXDays( short daysToSub )
	{
		decreaseDateByXDays( *this , daysToSub );
	}
	static clsDate decreaseDateByOneWeek( clsDate& Date )
	{
		for ( short i = 0; i < 7; i++ )
		{
			Date = decreaseDateByOneDay( Date );
		}
		return Date;
	}
	void decreaseDateByOneWeek()
	{
		decreaseDateByOneWeek( *this );
	}
	static clsDate decreaseDateByXWeeks( clsDate& Date , short weeksToSub )
	{
		for ( short i = 0; i < weeksToSub; i++ )
		{
			Date = decreaseDateByOneWeek( Date );
		}
		return Date;
	}
	void decreaseDateByXWeeks( short weeksToSub )
	{
		decreaseDateByXWeeks( *this , weeksToSub );
	}
	static clsDate decreaseDateByOneMonth( clsDate& Date )
	{
		if ( Date._month == 1 )
		{
			Date._month = 12;
			Date._year--;
		}
		else
		{
			Date._month--;
		}
		short numberOfDaysInCurrentMonth = numberOfDaysInMonth( Date._year , Date._month );
		if ( Date._day > numberOfDaysInCurrentMonth )
		{
			Date._day = numberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void decreaseDateByOneMonth()
	{
		decreaseDateByOneMonth( *this );
	}
	static clsDate decreaseDateByXMonths( clsDate& Date , short monthsToAdd )
	{
		for ( short i = 0; i < monthsToAdd; i++ )
		{
			Date = decreaseDateByOneMonth( Date );
		}
		return Date;
	}
	void decreaseDateByXMonths( short monthsToAdd )
	{
		decreaseDateByXMonths( *this , monthsToAdd );
	}
	static clsDate decreaseDateByOneYear( clsDate& Date )
	{
		Date._year--;
		return Date;
	}
	void decreaseDateByOneYear()
	{
		decreaseDateByOneYear( *this );
	}
	static clsDate decreaseDateByXYears( clsDate& Date , short yearsToSubb )
	{
		for ( short i = 0; i < yearsToSubb; i++ )
		{
			Date = decreaseDateByOneYear( Date );
		}
		return Date;
	}
	void decreaseDateByXYears( short yearsToSubb )
	{
		decreaseDateByXYears( *this , yearsToSubb );
	}
	static clsDate decreaseDateByXyearsFaster( clsDate& Date , short yearsToSub )
	{
		Date._year -= yearsToSub;
		return Date;
	}
	void decreaseDateByXyearsFaster( short yearsToSub )
	{
		decreaseDateByXyearsFaster( *this , yearsToSub );
	}
	static clsDate decreaseDateByOneDecade( clsDate& Date )
	{
		Date = decreaseDateByXyearsFaster( Date , 10 );
		return Date;
	}
	void decreaseDateByOneDecade()
	{
		decreaseDateByOneDecade( *this );
	}
	static clsDate decreaseDateByXDecades( clsDate& Date , short decadesToSub )
	{
		for ( short i = 0; i < decadesToSub; i++ )
		{
			Date = decreaseDateByOneDecade( Date );
		}
		return Date;
	}
	void decreaseDateByXDecades( short decadesToSub )
	{
		decreaseDateByXDecades( *this , decadesToSub );
	}
	static clsDate decreaseDateByXdecadesFaster( clsDate& Date , short decadesToSub )
	{
		Date._year -= decadesToSub * 10;
		return Date;
	}
	void decreaseDateByXdecadesFaster( short decadesToSub )
	{
		decreaseDateByXdecadesFaster( *this , decadesToSub );
	}
	static clsDate decreaseDateByOneCentury( clsDate& Date )
	{
		for ( short i = 0; i < 10; i++ )
		{
			Date = decreaseDateByOneDecade( Date );
		}
		return Date;
	}
	void decreaseDateByOneCentury()
	{
		decreaseDateByOneCentury( *this );
	}
	static clsDate decreaseDatByOneMillennium( clsDate& Date )
	{
		for ( short i = 0; i < 10; i++ )
		{
			Date = decreaseDateByOneCentury( Date );
		}
		return Date;
	}
	void decreaseDatByOneMillennium()
	{
		decreaseDatByOneMillennium( *this );
	}
};
