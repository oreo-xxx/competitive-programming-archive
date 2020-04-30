import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        Map<Long, Long> mp = new HashMap<>();
        for(int i = 0; i < n; ++i){
            a[i] = sc.nextLong();
            long v = mp.getOrDefault(a[i], 0L);
            mp.put(a[i], v+1);
        }
      
        long sum = 0;
        for(long v : mp.values()){
            sum += v * (v-1) / 2L;
        }

      for(int i = 0; i < n; ++i){
            long v = mp.get(a[i]);
            long ans = sum;
            ans -= v*(v-1)/2L;
            ans += (v-1)*(v-2)/2L;
            System.out.println(ans);
        }
    }
}
