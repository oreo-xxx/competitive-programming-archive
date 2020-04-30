import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Long a = sc.nextLong();
        Long b = sc.nextLong();
        Long x = sc.nextLong();
        Long ans = b/x - a/x;
        if(a%x==0)++ans;
        System.out.println(ans);
    }
}
