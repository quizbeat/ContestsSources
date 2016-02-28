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
      int T = sc.nextInt();
      int c;
      int j;
      String s;
      
      for(int i = 0; i < T; i++) {
          c = sc.nextInt();
          j = sc.nextInt();
          
          char arr[];
          sc.nextLine();
          s = sc.nextLine();
          arr = s.toCharArray();
          
          boolean frogCan = false;
          int count = 0;
          int cur = 0;
          while(true) {
            if(cur + j + 1 < c - 1) {
                if(arr[cur+j + 1] == '.') {
                    cur += j + 1;
                    count++;
                    frogCan = true;
                } else {
                    for(int jTemp = j - 1; jTemp >= 0; jTemp--) {
                        if(arr[cur + jTemp + 1] == '.') {
                            cur += jTemp + 1;
                            count++;
                            frogCan = true;
                            break;
                        }
                    }
                }
                if(!frogCan) {
                    break;
                }
                frogCan = false;
            } else {
                count++;
                frogCan = true;
                break;
            }
        }
        if(!frogCan) {
             System.out.println("-1");
        } else {
             System.out.println(count);
        }         
               
      }    
    }
}
