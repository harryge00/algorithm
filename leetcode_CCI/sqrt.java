public class sqrt {
    public int mySqrt(int x) {
        if(x < 1)   return 0;
        
        int root = getHalf(x);
        
        
        for( ;root < x; root++) {
            int square = root * root;
            System.out.println(root);
            if(square < 0) return root;
            else if(square == x) return root;
            else if(square > x) return root - 1;
        }
        return root;
    }
    
    private int getHalf(int x) {
        int Half = 1;
        while(Half <= x) {
            Half <<= 1;
            x >>= 1;
        }
        return (Half >> 1);
    }
    public static void main(String[] args) {
        sqrt s = new sqrt();
        System.out.println(s.mySqrt(5));
    }
}