import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        int[] a = new int[n];
        for(int i = 0; i < n; ++i){
            a[i] = sc.nextInt();
            sum += a[i];
        }
        int m = sc.nextInt();
        for(int i = 0; i < m; ++i){
            int p = sc.nextInt();
            int t = sc.nextInt();
            --p;
            int ans = sum - a[p] + t;
            System.out.println(ans);
        }
    }
}
