package week7;

import java.util.Scanner;

public class BMICalculator {
    int height, weight;
    double bmi;
    int level;
    String name;

    public BMICalculator(){}

    public void getHW(){
        Scanner input = new Scanner(System.in);
        System.out.print("Name: ");
        name = input.nextLine();
        System.out.print("Height: ");
        height = input.nextInt();
        System.out.print("Weight: ");
        weight = input.nextInt();

        bmi = (double) weight / (height * height*0.0001);
        if(bmi < 18.5){
            level = 1;
        }else if(bmi < 25){
            level = 2;
        }else if(bmi < 30){
            level = 3;
        }else{
            level = 4;
        }
    }

    public void printBMI(){
        System.out.println("Name: " + name);
        System.out.println("Height: " + height);
        System.out.println("Weight: " + weight);
        System.out.println("BMI: " + bmi);
        if(level == 1){
            System.out.println("Underweight");
        }else if(level == 2){
            System.out.println("Heavy Weight");
        }else if(level == 3){
            System.out.println("Overweight");
        }else{
            System.out.println("Obesity");
        }
    }
}
