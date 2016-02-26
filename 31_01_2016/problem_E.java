/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package test;

import java.util.*;

/**
 *
 * @author Andrej Rick
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
      Scanner sc = new Scanner(System.in);
      int N = sc.nextInt();
      
      long a[] = new long[N];
      
      for(int i = 0; i < N; i++) {
          a[i] = sc.nextInt();
      }
      int count = 1;
      Arrays.sort(a);
      long sum = a[0];
      for(int i = 1; i < N; i++) {
          if(a[i] > sum) {
              count++;
              sum += a[i];
          }
      }
      System.out.println(count);
      
    }
}
