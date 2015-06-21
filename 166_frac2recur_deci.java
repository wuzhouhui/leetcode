import java.util.*;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0)
            return("");
        if (numerator == 0)
            return("0");

        StringBuffer result = new StringBuffer();
        if ((numerator < 0) ^ (denominator < 0))
            result.append("-");
        long num = numerator;
        long den = denominator;
        num = Math.abs(num);
        den = Math.abs(den);
        long remainder = (num % den) * 10;
        num /= den;
        result.append(num);
        if (remainder == 0)
            return(result.toString());

        result.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                int start = map.get(remainder);
                String p1 = result.substring(0, start);
                String p2 = result.substring(start, result.length());
                return(p1 + "(" + p2 + ")");
            }
            map.put(remainder, result.length());
            num = remainder / den;
            result.append(num);
            remainder = (remainder % den) * 10;
        }
        return(result.toString());
    }
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);
        System.out.println(new Solution().fractionToDecimal(x, y));
    }
}
