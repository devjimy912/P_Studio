package pstudio.j083;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main pstudio = new Main();
        pstudio.j083();
    }
    public void j083() {
        String data = "";
        ScoreManager manager = new ScoreManager();
        try {
            File myObj = new File("src/pstudio/j083/data.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data = myReader.nextLine();
                String[] strings = data.split(" ");
                Score score = new Score(strings[0],Integer.parseInt(strings[1]),Integer.parseInt(strings[2]),Integer.parseInt(strings[3]));
                manager.addScore(score);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        manager.highestScore = manager.scores.get(0);
        for(Score i : manager.scores){
            manager.sumKor += i.getKor();
            manager.sumEng += i.getEng();
            manager.sumMat += i.getMat();
            i.setSum(i.getEng()+i.getMat()+i.getKor());
            i.setAvg(i.getSum()/3.0);
            if(i.getAvg() > manager.highestScore.getAvg()){
                manager.highestScore = i;
            }
        }
        manager.avgKor = manager.sumKor*1.0/manager.scores.size();
        manager.avgEng = manager.sumEng*1.0/manager.scores.size();
        manager.avgMat = manager.sumMat*1.0/manager.scores.size();

        System.out.println("Sum Kor: " + manager.sumKor + ", Avg Kor: " + manager.avgKor);
        System.out.println("Sum Eng: " + manager.sumEng + ", Avg Eng: " + manager.avgEng);
        System.out.println("Sum Mat: " + manager.sumMat + ", Avg Mat: " + manager.avgMat);
        for(Score i : manager.scores){
            System.out.println(i.getName()+" "+i.getSum()+" "+i.getAvg());
        }
        System.out.println("Highest score: "+manager.highestScore.toString());
    }
}
