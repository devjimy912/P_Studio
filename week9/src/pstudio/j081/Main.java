package pstudio.j081;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main pstudio = new Main();
        pstudio.j081();
    }
    public void j081(){
        String data = "";
        try {
            File myObj = new File("src/pstudio/j081/data.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data = myReader.nextLine();
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        String[] words = data.split(" ");
        int max = Integer.parseInt(words[0]);
        int min = Integer.parseInt(words[0]);
        for(String word : words) {
            int num = Integer.parseInt(word);
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
        System.out.println("Maximum number: "+max);
        System.out.println("Minimum number: "+min);
    }
}
