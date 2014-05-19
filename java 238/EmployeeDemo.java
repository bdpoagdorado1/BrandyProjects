import java.util.Scanner; // needed for the scanner class
/**
 * This program creates 3 objects from the employee class
 * and stores the employee information in each instance
 * then displays the employee information
 */

public class EmployeeDemo
{
	public static void main(String[] args)
	{
		// create 3 employee's and store their information
		Employee num1 = new Employee("Susan Meyers", 47899,
				"Accouting", "Vice President");
		Employee num2 = new Employee("Mark Jones", 39119,
				"IT", "Programmer");
		Employee num3 = new Employee("Joy Rogers", 81774,
				"Manufacturing", "Engineer");
		
		// display information about the three employee's
		System.out.println("The first employee's name is "
				+ num1.getName() + "\nher employee number is " 
				+ num1.getIdNumber() + "\nshe works in the " +
				num1.getDepartment() + "\ndepartment and holds the "
				+ num1.getPosition() + " position.\n\n");
		
		System.out.println("The second employee's name is "
				+ num2.getName() + "\nhis employee number is " 
				+ num2.getIdNumber() + "\nhe works in the " +
				num2.getDepartment() + "\ndepartment and holds the "
				+ num2.getPosition() + " position.\n\n");
		
		System.out.println("The third employee's name is "
				+ num3.getName() + "\nher employee number is " 
				+ num3.getIdNumber() + "\nshe works in the " +
				num3.getDepartment() + "\ndepartment and holds the "
				+ num3.getPosition() + " position.\n\n");
	}
}
