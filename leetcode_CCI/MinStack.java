class MinStack {
    private int[] stack = new int[20];
    private int size = 0;
    private int min = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
    private class tile {
        int val;
        tile next;
        tile() {
            next = null;
        }
        tile(int x, tile n) {
            val = x;
            next = n;
        }
    }
    private void resize(int newsize) {
        int [] newstack = new int[newsize];
        for(int i = 0; i < size; i++) {
            newstack[i] = stack[i];
        }
        stack = newstack;
    }
    public void push(int x) {
        if(size == stack.length) {
            resize((int) (1.5 * size));
        } 
        stack[size++] = x;
        if(x < min) {
            min = x;
        }
    }

    private int findMin(int [] arr, int len) {
        int minVal = Integer.MAX_VALUE;
        for(int i = 0; i < len; i++) {
            if(arr[i] < minVal) minVal = arr[i];
        }
        return minVal;
    }

    public void pop() {
        if(size > 0) {
            if(min == stack[size - 1] && size >= 2)  min = findMin(stack, size - 1);
            size--;
        } 
    }

    public int top() {
        return stack[size - 1];
    }

    public int getMin() {
        return min;
    }
}