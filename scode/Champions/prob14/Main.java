import java.util.*;
import java.io.*;

class Main {
    static int countSwap(String str)
    {
	    int n = str.length();
    	char[] s = str.toCharArray();
    	int count = 0;

	    for (int i = 0; i < n / 2; i++) {
	        int left = i;
    	    int right = n - left - 1;
	      
	        while (left < right) {
        		if (s[left] == s[right]) {
            		break;
		        }
		        else {
	    	        right--;
		        }
	        }

	        if (left == right) {
		        return -1;
	        }
	        else {
		        for (int j = right; j < n - left - 1; j++) {
    		        char t = s[j];
	    	        s[j] = s[j + 1];
		            s[j + 1] = t;
		            count++;
		        }
	        }
	    }
	    return count;
    }
    static void reverse(char a[])
    {
	    int n=a.length;
	    char[] b = new char[n];
	    int j = n;
	    for (int i = 0; i < n; i++) {
	        b[j - 1] = a[i];
	        j = j - 1;
	    }
    }

    public static void main(String[] args)
    {
	    String s = "aab";
    	int ans1 = countSwap(s);

	    char[] charArray = s.toCharArray();
	    reverse(charArray);
	    s = new String(charArray);

	    int ans2 = countSwap(s);

	    if (ans1 > ans2)
	        System.out.println(ans1);
	    else
	        System.out.println(ans2);
    }
}