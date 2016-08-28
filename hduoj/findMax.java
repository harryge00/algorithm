private static int findMax(int [] array) {
    int max = array[0];
    for (int i = 1; i < array.length; i++) {
        if (array[i] > max) {
          max = array[i];
        }
    }
    return max;
}
    private static int find3Max(int a, int b, int c) {
        if(a > b) {
            return a > c? a:c;
        }
        else {
            return b > c? b:c;
        }
    }
