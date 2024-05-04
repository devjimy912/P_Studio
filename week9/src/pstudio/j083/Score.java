package pstudio.j083;

public class Score {
    private String name;
    private int kor, eng, mat;
    private int sum;
    private double avg;

    public Score(String name, int kor, int eng, int mat) {
        setName(name);
        setKor(kor);
        setEng(eng);
        setMat(mat);
    }

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public int getKor() {
        return kor;
    }
    public void setKor(int kor) {
        this.kor = kor;
    }

    public int getEng() {
        return eng;
    }
    public void setEng(int eng) {
        this.eng = eng;
    }

    public int getMat() {
        return mat;
    }
    public void setMat(int mat) {
        this.mat = mat;
    }

    public int getSum() {
        return sum;
    }
    public void setSum(int sum) {
        this.sum = sum;
    }

    public double getAvg() {
        return avg;
    }
    public void setAvg(double avg) {
        this.avg = avg;
    }

    @Override
    public String toString() {
        return getName()+" "+getKor()+" "+getEng()+" "+getMat();
    }
}
