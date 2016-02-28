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
      double temp;
      
      double S = 0;
      double t = 0;
      
      double arr[][] = new double[N][2];
      for(int i = 0; i < N; i++) {
          temp = sc.nextDouble();
          arr[i][0] = temp;
          S += arr[i][0];
          
          temp = sc.nextDouble();
          arr[i][1] = temp;
          t += arr[i][0] / arr[i][1];
      }
      
      System.out.println(S/t);


      
        
      
    }
}
