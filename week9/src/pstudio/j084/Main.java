package pstudio.j084;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main pstudio = new Main();
        pstudio.j084();
    }
    public void j084() {
        String data = "";
        ArrayList<String> words = new ArrayList<>();
        int counter = 0;
        String highest;
        String lowest;
        try {
            File myObj = new File("src/pstudio/j084/name.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data = myReader.nextLine();
                words.add(data);
                counter++;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        highest = words.get(0);
        lowest = words.get(0);
        for(String word : words) {
            if(word.length() > highest.length()) {
                highest = word;
            }
            if(word.length() < lowest.length()) {
                lowest = word;
            }
        }
        System.out.println("count: "+counter);
        System.out.println("Longest Name: "+highest);
        System.out.println("Shortest Name: "+lowest);
    }
}
