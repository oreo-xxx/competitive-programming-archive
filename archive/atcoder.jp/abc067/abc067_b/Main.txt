import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Integer[] a = new Integer[n];
        for(int i = 0; i < n; ++i){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a, Collections.reverseOrder());
        Integer sum = 0;
        for(int i = 0; i < k; ++i){
            sum += a[i];
        }
        System.out.println(sum);
    }
}
