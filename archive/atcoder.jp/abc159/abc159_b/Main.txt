import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static boolean check(String s){
        int n = s.length();
        for(int i = 0; i < n ; ++i){
            if(s.charAt(i) != s.charAt(n-1-i)){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        String a = s.substring(0, (n-1)/2);
        String b = s.substring((n+3)/2-1, n);
        String ans = "No";
        if(check(s) && check(a) && check(b)) ans = "Yes";
        System.out.println(ans);
    }
}