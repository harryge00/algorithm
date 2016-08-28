import java.io.*;
import java.util.*;
public class tttt
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
	while(cin.hasNextInt()) {       
	        double num = (double) cin.nextInt();
		int times = cin.nextInt();
		double sum = (double) num;
		
		for(int i = 1; i < times; i++) {
			num = Math.sqrt(num);
			sum += num;
		}
		System.out.println(sum);
	}
	}
}
