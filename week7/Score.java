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
            this.sumStudent[i] = 0;
            for(int j=0; j<count; j++){
                this.jumsu[i][j] = 0;
            }
            this.averageStudent[i] = 0;
        }
        for(int i=0; i<3; i++){
            this.sumClass[i] = 0;
            this.averageClass[i] = 0;
        }
    }
    public void getScore(){
        for(int i=0; i<this.count; i++){
            this.sumStudent[i] = 0;
            for(int j=0; j<3; j++){
                this.jumsu[i][j] = sc.nextInt();
                this.sumStudent[i] += this.jumsu[i][j];
                this.sumClass[j] += this.jumsu[i][j];
            }
            this.averageStudent[i] = (double)this.sumStudent[i]/this.count;
        }
        for(int i=0; i<3; i++){
            this.averageClass[i] = (double)this.sumClass[i]/this.count;
        }
    }
    public void printScore(){
        for(int i=0; i<this.count; i++){
            System.out.printf("Student #%d: %d %.1f",i+1,this.sumStudent[i],this.averageStudent[i]);
            if(this.averageStudent[i]>=90){
                System.out.println(" - A");
            }else if(this.averageStudent[i]>=80){
                System.out.println(" - B");
            }else if(this.averageStudent[i]>=70){
                System.out.println(" - C");
            }else if(this.averageStudent[i]>=60){
                System.out.println(" - D");
            }else{
                System.out.println(" - F");
            }
        }
    }
    public void printScore(int num){
        System.out.println("Student #"+(num));
        System.out.println("Kor : "+this.jumsu[num-1][0]);
        System.out.println("Eng : "+this.jumsu[num-1][1]);
        System.out.println("Math : "+this.jumsu[num-1][2]);
        System.out.println("Sum : "+sumStudent[num-1]);
        System.out.println("Average : "+averageStudent[num-1]);
    }
    public void printScore(int num, String className){
        System.out.println(className);
        System.out.println("class sum : "+this.sumClass[num-1]);
        System.out.println("class average : "+this.averageClass[num-1]);
    }
}
