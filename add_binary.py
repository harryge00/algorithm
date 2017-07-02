class Solution(object):
    def addBinary(self, a, b):
    	res=""
    	cout=0
    	cursum = ''
    	n = min(len(a), len(b))
    	for i in range(0, n):
    		if a[i] == '1':
    			if b[i] == '1':
    				if cout == 1:
    					cursum = '1'
    				else:
    					cursum = '0'
	    				cout = 1
	    		else:
	    			if cout == 1:
	    				cursum = '0'
	    			else:
	    				cursum = '1'
	    				cout = 0
	    	else:
	    		if b[i] == '1':
    				if cout == 1:
    					cursum = '0'
    				else:
    					cursum = '1'
	    				cout = 0
	    		else:
	    			if cout == 1:
	    				cursum = '1'
	    				cout = 0
	    			else:
	    				cursum = '0'
	    	res = cursum + res
	    if cout == 0:
	    	return res	 
	    m = max(len(a), len(b))

    def addBinary(self, a, b):
    	if len(a) == 0:
    		return b
    	if len(b) == 0:
    		return a
    	if len(a) == len(b):
    		if a[len(a) - 1] == '1' and b[len(b) - 1] == '1'
    		return '1' + addBinary(self, a[1: ])