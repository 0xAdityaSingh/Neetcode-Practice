class Solution {
public:
    int reverse(int x) {
        // Handle INT_MIN immediately because abs(INT_MIN) overflows a standard int
        if (x == INT_MIN) return 0; 
        
        bool isNegative = false;
        if (x < 0) isNegative = true;
        
        string str = to_string(abs(x));
        ::reverse(str.begin(), str.end()); // Use :: to avoid naming conflict with the function itself
        
        // Use try-catch because stoi() will throw an exception if the reversed string overflows INT_MAX
        try {
            int newNum = stoi(str);
            if (isNegative) {
                newNum = newNum * (-1);
            }
            return newNum;
        } 
        catch (const out_of_range& e) {
            // LeetCode requires returning 0 if the reversed integer overflows
            return 0; 
        }
    }
};