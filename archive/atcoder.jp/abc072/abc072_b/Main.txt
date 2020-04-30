import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        for(int i = 0; i < n; i+=2){
            System.out.print(s.charAt(i));
        }
        System.out.println();
    }
}
