import java.io.*;

public class Crypto 
{
	public void print(int size, String file) throws IOException
	{
		final int CHAR_SIZE = 2;
		long byteNum;
		char ch;
		RandomAccessFile randomFile = 
			new RandomAccessFile(file, "rw");
		for(int i = 0; i < size; i++)
		{
			byteNum = CHAR_SIZE * i;
			randomFile.seek(byteNum);
			ch = randomFile.readChar();
			System.out.println(ch);
		}
		randomFile.close();
	}
	public String crypto_file(int size, String file) throws IOException
	{
		final int CHAR_SIZE = 2;
		long byteNum;
		char ch;
		RandomAccessFile randomFile = 
			new RandomAccessFile(file, "rw");
		RandomAccessFile cryptorandomFile = 
			new RandomAccessFile("CryptoLetters.dat", "rw");
		for(int i = 0; i < size; i++)
		{
			byteNum = CHAR_SIZE * i;
			randomFile.seek(byteNum);
			ch = randomFile.readChar();
			cryptorandomFile.writeChar(ch);
			cryptorandomFile.writeChar('x');
		}
		cryptorandomFile.close();
		return "CryptoLetters.dat";
	}
}
