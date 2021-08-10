import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

 public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        String [] pair_left = new String[t];
        String [] pair_right = new String[t];
        
        for (int i = 0; i < t; i++) {
            pair_left[i] = s.next();
            pair_right[i] = s.next();
        }
        HashSet<String> h1 = new HashSet<>();
        HashSet<String> h2 = new HashSet<>();
        int t1 = 0;
        for(int i = 0 ;i<t;i++){
            h1.add(pair_left[i]);
            h2.add(pair_right[i]);
            t1 = h1.size()<=h2.size()?h2.size():h1.size();
            System.out.println(t1);
        }
   }
}
