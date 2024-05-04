package pstudio.j083;

import java.util.ArrayList;

public class ScoreManager {
    ArrayList<Score> scores;
    int sumEng=0;
    int sumKor=0;
    int sumMat=0;
    double avgEng;
    double avgKor;
    double avgMat;
    Score highestScore;

    public ScoreManager() {
        scores = new ArrayList<>();
    }
    public void addScore(Score score){
        scores.add(score);
    }
    public void deleteScore(Score score){
        scores.remove(score);
    }
}
