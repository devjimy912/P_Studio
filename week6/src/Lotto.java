import java.util.Arrays;
import java.util.Random;
public class Lotto {
    int[] numbers;

    public void lotto(){
        Random r = new Random();
        for(int i=0; i<6; i++){
            numbers[i] = r.nextInt();
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
}