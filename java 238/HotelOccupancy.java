/**
 * Calculate the hotel occupancy
 */
import java.util.Scanner;
public class HotelOccupancy 
{
	// Calculate the hotel occupancy
	public static void main(String[] args) 
	{
		Scanner keyboard = new Scanner(System.in);
		int floors = 0, rooms = 0, occupied;
		double occupancy = 0, numRooms = 0, numOccupied = 0;
		while (floors < 1)
		{
			System.out.println("How many floors does the hotel" +
					" have? (There must be at least 1 floor)" );
			floors = keyboard.nextInt();
		}
		for (int i = 0; i < floors; i++)
		{
			while (rooms < 10)
			{
				System.out.println("How many rooms does floor " +
						(i + 1) + " have? (There must be at least 10 rooms" +
						" perfloor)" );
				rooms = keyboard.nextInt();
				
			}
			numRooms += rooms;
			rooms = 0;
			System.out.println("How many rooms are being " +
					"occupied? ");
			occupied = keyboard.nextInt();
			numOccupied += occupied;
		}
		occupancy = numOccupied / numRooms;
		System.out.println("There are " + numRooms +
				" rooms in the hotel.\nCurrently " + numOccupied +
				" rooms are occupied and " + (numRooms - numOccupied)
				+ " are vacant.\nThe occupancy rate is " + occupancy
				+ ". ");
	}

}
