/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package opencup;

import java.util.Scanner;

/**
 *
 * @author Alexa
 */
public class OpenCup {

    public static long gcd (long a, long b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
    }
    
    public static long lcm (long a, long b) {
	return a / gcd (a, b) * b;
    }
    
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        for(int i = 0; i < n; i++) {
            a[i] = in.nextLong();
            b[i] = in.nextLong();            
        }
        long A = a[0], B = b[0];
        for(int i = 0; i < n - 1; i++) {
            b[i + 1] = gcd(b[i], b[i + 1]);
            a[i + 1] = lcm(a[i], a[i + 1]);
        }
        A = a[n - 1];
        B = b[n - 1];
        long t = gcd(A, B);
        A = A / t;
        B = B / t;
        System.out.println(A + " " + B);
    }
    
}
