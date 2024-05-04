package pstudio.j082;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main pstudio = new Main();
        pstudio.j082();
    }
    public void j082() {
        ArrayList<String> data = new ArrayList<>();
        int counter = 0;
        int overweightCount = 0;
        try {
            File myObj = new File("src/pstudio/j082/data.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data.add(myReader.nextLine());
                counter++;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        System.out.println("All "+counter+" persons.");
        for(String s : data) {
            String[] dummy = s.split(" ");
            int height = Integer.parseInt(dummy[0]);
            int weight = Integer.parseInt(dummy[1]);
            double bmi = weight / (height * height * 0.0001);
            if(bmi >= 25){
                overweightCount++;
            }
        }
        System.out.println("Total overweight persons: "+overweightCount+" ("+overweightCount*100.0/counter+")");
    }
}
