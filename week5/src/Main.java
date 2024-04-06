package week5.src;

import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in); // Scanner 객체 생성
    public static void main(String[] args) {
        Main Pstudio = new Main();
        Pstudio.J001();
        Pstudio.J011();
        Pstudio.J021();
        Pstudio.J002();
        Pstudio.J003();
        Pstudio.J012();
        Pstudio.J022();
        Pstudio.J013();
        Pstudio.J023();
        Pstudio.J029();
    }
    void J001(){
        int height = sc.nextInt();
        int weight = sc.nextInt();
        double bmi = weight / (height * height * 0.0001);
        System.out.printf("%.1f\n",bmi);
    }
    void J011(){
        int height = sc.nextInt();
        int weight = sc.nextInt();
        double bmi = weight / (height * height * 0.0001);
        if(bmi >= 25){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
    void J021(){
        int height, weight;
        double bmi;
        int count = 0;
        int num = sc.nextInt();
        for(int i=0; i<num; i++) {
            height = sc.nextInt();
            weight = sc.nextInt();
            bmi = weight / (height * height * 0.0001);
            if (bmi >= 25) {
                count = count + 1;
            }
        }
        System.out.println(count);
    }
    void J002(){
        double c_degree;
        double f_degree;
        c_degree = sc.nextInt();
        f_degree = c_degree * 1.8 + 32;
        System.out.println(f_degree);
    }
    void J003(){
        double m2_area;
        double pyung_area;
        m2_area = sc.nextDouble();
        pyung_area = m2_area / 3.305;
        System.out.printf("%.1f\n", pyung_area);
    }
    void J012(){
        double m2_area;
        double pyung_area;
        m2_area = sc.nextDouble();
        pyung_area = m2_area / 3.305;
        System.out.printf("%.1f\n", pyung_area);
        if(pyung_area < 15){
            System.out.println("small");
        }else if(pyung_area < 30){
            System.out.println("normal");
        }else if(pyung_area < 50){
            System.out.println("large");
        }else{
            System.out.println("huge");
        }
    }
    void J022(){
        double m2_area;
        double pyung_area;
        int count1, count2, count3, count4;
        count1=count2=count3=count4=0;
        for(int i=0; i<10; i++) {
            m2_area = sc.nextDouble();
            pyung_area = m2_area / 3.305;
            if (pyung_area < 15) {
                count1++;
            } else if (pyung_area < 30) {
                count2++;
            } else if (pyung_area < 50) {
                count3++;
            } else {
                count4++;
            }
        }
        System.out.println("count1 - "+count1);
        System.out.println("count2 - "+count2);
        System.out.println("count3 - "+count3);
        System.out.println("count4 - "+count4);
    }
    void J013(){
        int kor, eng, math;
        int total;
        double average;
        kor = sc.nextInt();
        eng = sc.nextInt();
        math = sc.nextInt();
        total = kor + eng + math;
        average = total / 3.0;
        System.out.println(total + " " + average);
        System.out.println("Korean - " + J013PF(kor));
        System.out.println("English - " + J013PF(eng));
        System.out.println("Math - " + J013PF(math));
    }
    String J013PF(int score){
        if(score >= 70){
            return "Pass";
        }else{
            return "Fail";
        }
    }
    void J023(){
        int count = sc.nextInt();
        int number;
        int totalsum = 0;
        double average;
        for(int i=0; i<count; i++){
            number = sc.nextInt();
            totalsum += number;
        }
        average = totalsum * 1.0 / count;
        System.out.println(totalsum);
        System.out.println(average + "\n");
    }
    void J029(){
        int[] number = new int[10];
        int count = 0;
        boolean dummy;
        System.out.print("Enter #"+(count+1)+" number > ");
        number[count] = sc.nextInt();
        for(count = 1; count<10; count++){
            dummy = true;
            while(dummy){
                System.out.print("Enter #"+(count+1)+" number > ");
                number[count] = sc.nextInt();
                for(int i=0; i<count; i++){
                    if(number[count] == number[i]){
                        dummy = true;
                        System.out.println("Duplicated! Retry.\n");
                        break;
                    }else{
                        dummy = false;
                    }
                }
            }
        }
        System.out.println("Numbers -");
        for(int i=0; i<10; i++) {
            System.out.print(" " + number[i]);
        }
        System.out.println();//줄바꿈..
    }
}
