import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        for(long h = 1; h < 3501; ++h){
            for(long n = 1; n < 3501; ++n){
                long u = N * h * n;
                long d = 4 * h * n - N * n - N * h;
                if(d <= 0) continue;
                if(u < d) continue;
                if(u%d!=0) continue;
                long w = u/d;
                if(4 * h * n * w == N * n * w + N * h * w + N * h * n){
                    System.out.println(h + " " + n + " " + w);
                    return;
                }
            }
        }
        System.out.println("NO!");
    }
}
