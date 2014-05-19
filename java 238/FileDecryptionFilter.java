import java.io.*;

public class FileDecryptionFilter 
{
	public static void main(String[] args) throws IOException
	{
		//main recreates the FileEncryptioFilter file that was 
		//encrypted in challenge 7
		char[] letters = { 'a', 'x', 'b', 'x', 'c', 'x', 'd',
				'x', 'e', 'x', 'f', 'x', 'g', 'x', 'h', 'x',
				'i', 'x', 'j', 'x', 'k', 'x', 'l', 'x' };
		RandomAccessFile randomFile = 
			new RandomAccessFile("Letters.dat", "rw");
		for(int i = 0; i < letters.length; i++)
			randomFile.writeChar(letters[i]);
		randomFile.close();
		//create a cryp object that will take an encrypted file
		//and return its origional state;
		Crypto cryp = new Crypto();
		System.out.println("Encrypted file: ");
		cryp.print(letters.length, "Letters.dat");
		System.out.println("Origional file: ");
		cryp.print(letters.length / 2, 
				cryp.origional_file(letters.length, "Letters.dat"));
		
	}
}
