package pstudio.j085;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main pstudio = new Main();
        pstudio.j085();
    }
    public void j085() {
        String data = "";
        int AtoZ=0;
        int aToz=0;
        int spaces=0;
        try {
            File myObj = new File("src/pstudio/j085/data.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data = myReader.nextLine();
                for(char ch : data.toCharArray()) {
                    if(Character.isUpperCase(ch)) {
                        AtoZ++;
                    }
                    if(Character.isLowerCase(ch)) {
                        aToz++;
                    }
                    if(Character.isSpaceChar(ch)) {
                        spaces++;
                    }
                }
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        System.out.println("A~Z: "+AtoZ);
        System.out.println("a~z: "+aToz);
        System.out.println("spaces: "+spaces);
    }
}
