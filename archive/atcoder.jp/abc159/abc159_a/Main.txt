import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans = a * (a-1) + b * (b-1);
        ans /= 2;
        System.out.println(ans);
    }
}
