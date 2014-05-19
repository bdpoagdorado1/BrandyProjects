import java.io.*;

public class FileEncryptionFilter 
{
	public static void main(String[] args) throws IOException
	{
		//create a file and print it
		char[] letters = { 'a', 'b', 'c', 'd', 'e',
				'f', 'g', 'h', 'i', 'j', 'k', 'l' };
		RandomAccessFile randomFile = 
			new RandomAccessFile("Letters.dat", "rw");
		for(int i = 0; i < letters.length; i++)
			randomFile.writeChar(letters[i]);
		randomFile.close();
		Crypto cryp = new Crypto();
		
		System.out.println("Origional file: ");
		cryp.print(letters.length, "Letters.dat");
		
		//encrypt a file and print it
		System.out.println("Encrypted file: ");
		cryp.print(letters.length * 2, 
				cryp.crypto_file(letters.length, "Letters.dat"));
		
	}
}
