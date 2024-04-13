import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

// J041
public class Lotto {
    int[] numbers = {0,0,0,0,0,0};

    public void lotto(){
        Random r = new Random();
        for(int i=0; i<6; i++){
            numbers[i] = r.nextInt(45);
            for(int j=0; j<i; j++){
                if(numbers[i] == numbers[j]){
                    i--;
                    break;
                }
            }
        }
    }
    public void printNumbers(){
        System.out.println(Arrays.toString(numbers));
    }
    public void remakeAuto(){
        lotto();
    }
    //J042
    public void make(){
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<6; i++){
            numbers[i] = sc.nextInt();
            for(int j=0; j<i; j++){
                if(numbers[i] == numbers[j]){
                    i--;
                    break;
                }
            }
            if(numbers[i] < 1 || numbers[i] > 45){
                System.out.println("Enter a number between 1 and 45");
                i--;
            }
        }
    }
    //J043
    public int checkLotto(int[] check){
        int count=0;
        Lotto thisLotto = new Lotto();
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<6; i++){
            thisLotto.numbers[i] = sc.nextInt();
            for(int j=0; j<i; j++) {
                if (thisLotto.numbers[i] == thisLotto.numbers[j]) {
                    i--;
                    break;
                }
            }
        }
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                if(thisLotto.numbers[i] == check[j]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}