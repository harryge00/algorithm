
import java.util.Scanner;
public class Main
{
	public static void main(String args[])
	{
		Scanner reader=new Scanner(System.in);
        int lines = reader.nextInt();
        for(int i = 0; i < lines; i++) {
            int [] scores = new int[4];
            for(int j = 0; j < 4; j++) {
                scores[j] = reader.nextInt();
            }
            System.out.println(printRes(scores));
            
        }
    }
    public static String printRes(int[] scores) {
        int total = 0;
        for(int j = 0; j < 4; j++) {
                int score = scores[j];
                if(j<2 && score < 60 || j>=2 && score < 90)
                {
                    return "Fail";
                }
                //System.out.println(total);
                total += score;
            }
            if(total <310)
                return "Fail";
            else {
                if(total>=350)
                    return "Gongfei";
                else
                    return "Zifei";
            }

    }
}
	
