class Solution {
    public boolean isValid(String s) {
	        int len = s.length();
	        if ((len % 2 != 0) || (len == 0)) {
	        	return false;
	        }
	        else {
	        	char stack[] = new char[len];
	        	int i = -1;
	        	int j = 0;
	        	while(j < len) {
                    if ((i == -1) && ((s.charAt(j) == ')') || (s.charAt(j) == '}') || (s.charAt(j) == ']'))){
                        return false;
                    }
	        		if((s.charAt(j) == '(') || (s.charAt(j) == '{') || (s.charAt(j) == '[') ) {
                        i++;
	        			stack[i] = s.charAt(j);
	        			
	        		}
	        		else if ((s.charAt(j) == ')') && (stack[i] == '(')) {
	        			i = i-1;
	        		}
	        		else if ((s.charAt(j) == '}') && (stack[i] == '{')) {
	        			i = i-1;
	        		}
	        		else if ((s.charAt(j) == ']') && (stack[i] == '[')) {
	        			i = i-1;
	        		}
	        		else {
                        i++;
	        			stack[i] = s.charAt(j);
	        			
	        		}
	        		j++;
                   
	        	}
	        	if (i == -1) {
	        		return true;
	        	}
	        	else
	        		return false;
	        }
	    }
}