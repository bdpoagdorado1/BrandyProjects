/**
 * Month class that compares months objects 
 */
public class Month 
{
	private int monthNumber;
	Month()
	{
		monthNumber = 1;
	}
	Month(int num)
	{
		if (num >= 1 && num <= 12) monthNumber = num;
		else monthNumber = 1;
	}
	Month(String month)
	{
		if (month.toLowerCase() == "february") monthNumber = 2;
		else if (month.toLowerCase() == "march") monthNumber = 3;
		else if (month.toLowerCase() == "april") monthNumber = 4;
		else if (month.toLowerCase() == "may") monthNumber = 5;
		else if (month.toLowerCase() == "june") monthNumber = 6;
		else if (month.toLowerCase() == "july") monthNumber = 7;
		else if (month.toLowerCase() == "august") monthNumber = 8;
		else if (month.toLowerCase() == "september") monthNumber = 9;
		else if (month.toLowerCase() == "october") monthNumber = 10;
		else if (month.toLowerCase() == "november") monthNumber = 11;
		else if (month.toLowerCase()== "december") monthNumber = 12;
		else monthNumber = 1;
	}
	public void setMonthNumber(int num)
	{
		if (num < 1 && num > 12) num = 1;
		monthNumber = num;
	}
	
	public int getMonthNumber()
	{
		return monthNumber;
	}
	public String getMonthName()
	{
		if (monthNumber == 1) return "January";
		else if (monthNumber == 2) return "February";
		else if (monthNumber == 3) return "March";
		else if (monthNumber == 4) return "April";
		else if (monthNumber == 5) return "May";
		else if (monthNumber == 6) return "June";
		else if (monthNumber == 7) return "July";
		else if (monthNumber == 8) return "August";
		else if (monthNumber == 9) return "September";
		else if (monthNumber == 10) return "October";
		else if (monthNumber == 11) return "November";
		else return "December";

	}
	public String toString()
	{
		return getMonthName();
	}
	public boolean equals(Month mon)
	{
		if (mon.monthNumber == monthNumber) return true;
		return false;
	}
	public boolean greaterThan(Month mon)
	{
		if (mon.monthNumber < monthNumber) return true;
		return false;
	}
	public boolean lessThan(Month mon)
	{
		if (mon.monthNumber > monthNumber) return true;
		return false;
	}
}
