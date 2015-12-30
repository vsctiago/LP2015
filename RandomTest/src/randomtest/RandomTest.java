/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package randomtest;

import java.util.Random;

/**
 *
 * @author Utilizador
 */
public class RandomTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Random rng = new Random();
        int num, con0 = 0, con1 = 0, con2 = 0, con3 = 0;
        
        for(int i=0; i<1000000000; i++) {
            num = rng.nextInt(4);
            if(num == 0) {
                con0++;
            } else if(num == 1) {
                con1++;
            } else if(num == 2) {
                con2++;
            } else if(num == 3) {
                con3++;
            }
        }
        System.out.println("Num 0: " + con0);
        System.out.println("Num 1: " + con1);
        System.out.println("Num 2: " + con2);
        System.out.println("Num 3: " + con3);
    }
    
}
