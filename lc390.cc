class Solution {
public:
    int lastRemaining(int n) {
        /*
        	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        	2 4 6 8 10 12 14 16 18
        	2 6 10 14 18
        	6 14 22
        	6 22 
        	22

        	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        	2 4 6 8 10 12 14 16 18
        	4 8 12 16
        	8 16
        	8

        	1 2 3 4 5 6 7 8 9
			2 4 6 8
			2 6
			6


        	1 2 3 4 5 6 7 8 9 10
			2 4 6 8 10
			4 8
			8

        	1 2 3 4 5 6
			2 4 6
			4

        	remove1st round:	1/2 2/2
        	remove2nd round:		1 + 1/2 2/2
        */
        int gap = 1, res = 1;
        bool roundSingle = true;
        while(n > 1) {
        	if(roundSingle) {
        		res += gap;
        		n >>= 1;
        	} else {
        		n = (n + 1) >> 1;
        	}
        	gap <<= 1;
        	roundSingle = !roundSingle;
        }

        return res;

    }
};

class Solution {
public:
    int lastRemaining(int n) {
        /*
        	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        	2 4 6 8 10 12 14 16 18
        	2 6 10 14 18
        	6 14 22
        	6 22 
        	22

        	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        	2 4 6 8 10 12 14 16 18
        	4 8 12 16
        	8 16
        	8

        	1 2 3 4 5 6 7 8 9
			2 4 6 8
			2 6
			6


        	1 2 3 4 5 6 7 8 9 10
			2 4 6 8 10
			4 8
			8

        	1 2 3 4 5 6
			2 4 6
			4

        	single rounds:	single number? Next 1st: always 2nd

        	double rounds:	single number? Next 1st: 2nd ： 1st	
        */
        int gap = 1, res = 1;
        bool roundSingle = true;
        while(n > 1) {
        	if(roundSingle || n & 1) {
        		res += gap;
        	} 
        	n >>= 1;
        	gap <<= 1;
        	roundSingle = !roundSingle;
        }

        return res;

    }
};



