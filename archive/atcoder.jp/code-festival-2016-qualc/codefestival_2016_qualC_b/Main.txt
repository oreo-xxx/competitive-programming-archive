import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int T = sc.nextInt();
        Integer[] a = new Integer[T];
        Integer sum = 0;
        for(int i = 0; i < T; ++i){
            a[i] = sc.nextInt();
            sum += a[i];
        }
        Arrays.sort(a, Collections.reverseOrder());
        sum -= a[0];
        int ans = Math.max(0, a[0] - sum-1);

        System.out.println(ans);
    }
}
