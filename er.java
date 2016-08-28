public class er{
    public static void main(String[] aa) {
        Object o = new Object(){
            public boolean equals(Object obj) {
                return true;
            }
        };
        class BDD {

        }
        BDD a = new BDD() {
            int ddd;
            public boolean test2(Object obj) {
                ddd=3;
                return true;
            }
        };
        System.out.println(o.equals(9));
        System.out.println(a.test2(9));
    }
}
