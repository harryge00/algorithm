import java.util.*;
public class Zhajinhua {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int [] res = new int[10000];
        int count = 0;
        while(cin.hasNext()) {
            String a = cin.next();
            String b= cin.next();
            res[count++] = avb(a,b);
           
        }
        for(int i=0; i<count;i++)
         System.out.println(res[i]);
        
          
        
    }
    // int[] parser(String str) {
    //     int [] res;
    // }
    private static int avb(String a, String b) {
        if(a.length() < 3 || a.length() > 6 || b.length() < 3 || b.length() > 6) {
            return -2;
        }
        char[] chars1 = a.toCharArray();
        char[] chars2 = b.toCharArray();
        Card[] cards1 = new Card[3], cards2 = new Card[3];
        
        for(int i = 0, count = 0; i < chars1.length; i++) {
            char c = chars1[i];
            if(c>'0' && c<='9' || c=='J' || c=='Q' || c=='K' || c=='A') {
                if(count > 2) return -2;
                cards1[count++] = new Card(c);
                if(c == '1') {
                    if(i == (chars1.length -1) || chars1[++i] != '0') return -2;
                    
                }
            }
            else return -2;
        }
        
        
        
        for(int i = 0, count = 0; i < chars2.length; i++) {
            char c = chars2[i];
            if(c>'0' && c<='9' || c=='J' || c=='Q' || c=='K' || c=='A') {
                if(count > 2) return -2;
                cards2[count++] = new Card(c);
                if(c == '1') {
                    if(i == (chars2.length -1) || chars2[++i] != '0') return -2;
                    
                }
            }
            else return -2;
        }
        
        Arrays.sort(cards1);
        Arrays.sort(cards2);
       


        int[] records1 = new int[3], records2 = new int[3];
        int res1 = compare(cards1, records1), res2 = compare(cards2, records2);
        if(res1 > res2) return 1;
        else if(res1 < res2 ) return -1;

        if(res1 == 1) {
            if(records1[0] > records2[0]) return 1;
            else if(records1[0] < records2[0]) return -1;
        }
        for(int i = 0; i < 3; i++) {
            if(cards1[i].val > cards2[i].val)
            return 1;
            else if(cards1[i].val < cards2[i].val)
                return -1;
        }
        return 0;

    }
    static int compare(Card[] cards, int [] record) {
        //3 2 1 0
        int sameCards = 0, shunzi = 0;
        boolean firstSame = true;
        for(int i = 0; i < cards.length - 1; i++) {
            if(cards[i].val == cards[i+1].val) {
                       
                record[sameCards++] = cards[i].val;
                
            }
            else if(cards[i].val == cards[i+1].val+1) shunzi++;
        }
        if(sameCards == 2) {            
            
            return 3;
        }
        else if(shunzi == 2) {
            
            return 2;
        }
        else if(sameCards == 1) return 1;
        else return 0;
    }
    static class Card implements Comparable<Card> {
        int val;
        Card(char c) {
            if(c>='2' && c <='9') val = c - '0';
            else if(c == '1') val = 10;
            else if(c == 'J') val = 11;
            else if(c == 'Q') val = 12;
            else if(c == 'K') val = 13;
            else if(c == 'A') val = 14;
            else throw new IllegalArgumentException();
        }
        @Override
        public int compareTo(Card d) {
            if(d.val > val) return 1;
            else return -1;

        }
    }
}
