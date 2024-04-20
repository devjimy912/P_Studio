package week7;

import java.util.Scanner;

public class Score {
    int count;
    int[][] jumsu;
    int[] sumStudent;
    double[] averageStudent;
    int[] sumClass;
    double[] averageClass;
    Scanner sc = new Scanner(System.in);

    public void Score(int count){
        this.count = count;
        for(int i=0; i<3; i++){
            sumStudent[i] = 0;
            for(int j=0; j<count; j++){
                jumsu[i][j] = 0;
            }
            averageStudent[i] = 0;
        }
        for(int i=0; i<3; i++){
            sumClass[i] = 0;
            averageClass[i] = 0;
        }
    }
    public void getScore(){
        for(int i=0; i<count; i++){
            sumStudent[i] = 0;
            for(int j=0; j<3; j++){
                jumsu[i][j] = sc.nextInt();
                sumStudent[i] += jumsu[i][j];
                sumClass[j] += jumsu[i][j];
            }
            averageStudent[i] = (double)sumStudent[i]/count;
        }
        for(int i=0; i<3; i++){
            averageClass[i] = (double)sumClass[i]/count;
        }
    }
    public void printScore(){
        for(int i=0; i<count; i++){
            System.out.printf("Student #%d: %d %.1f",i+1,sumStudent[i],averageStudent[i]);
            if(averageStudent[i]>=90){
                System.out.println(" - A");
            }else if(averageStudent[i]>=80){
                System.out.println(" - B");
            }else if(averageStudent[i]>=70){
                System.out.println(" - C");
            }else if(averageStudent[i]>=60){
                System.out.println(" - D");
            }else{
                System.out.println(" - F");
            }
        }
    }
    public void printScore(int num){
        System.out.println("Student #"+(num));
        System.out.println("Kor : "+jumsu[num-1][0]);
        System.out.println("Eng : "+jumsu[num-1][1]);
        System.out.println("Math : "+jumsu[num-1][2]);
        System.out.println("Sum : "+sumStudent[num-1]);
        System.out.println("Average : "+averageStudent[num-1]);
    }
    public void printScore(int num, String className){
        System.out.println(className);
        System.out.println("class sum : "+sumClass[num-1]);
        System.out.println("class average : "+averageClass[num-1]);
    }
}
