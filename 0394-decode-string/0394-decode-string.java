
class Solution {
    public String decodeString(String s) {
        Stack<String> stack = new Stack<>();  // Stack to store string components
        StringBuilder currentString = new StringBuilder();
        int k = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');  // Build the full number for repetition
            } else if (ch == '[') {
                // Push current string and k onto stack
                stack.push(currentString.toString());  
                stack.push(String.valueOf(k));
                currentString = new StringBuilder(); // Reset for new substring
                k = 0;  // Reset repeat count
            } else if (ch == ']') {
                int repeatCount = Integer.parseInt(stack.pop());  // Get stored repeat count
                String previousString = stack.pop();  // Get previous string from stack
                String repeatedString = currentString.toString().repeat(repeatCount);
                currentString = new StringBuilder(previousString + repeatedString);  // Append expanded substring
            } else {
                currentString.append(ch);  // Build substring
            }
        }
        return currentString.toString();
    }
}
