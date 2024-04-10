import java.util.Scanner;
import java.util.Arrays;
import java.io.*;

class Main {
    public static void main(String[] args){
        Main pstudio = new Main();
        pstudio.J031();
        pstudio.J032();
        pstudio.J033();
        pstudio.J034();
        pstudio.J035();
        pstudio.J036();
        pstudio.J037(); //Incomplete
    }

    void J031(){
        Scanner sc = new Scanner(System.in);
        String userID;
        String password;
        String name;
        userID = sc.next();
        password = sc.next();
        sc.nextLine(); //erase enter in buffer
        name = sc.nextLine();
        if(password.length() < 3){
            System.out.println("Error! password is too short.");
        }else{
            System.out.println(userID);
            System.out.println(password.substring(0,2) + password.substring(2).replaceAll(".","*"));
            System.out.println(name);
        }
    }
    void J032(){
        Scanner sc = new Scanner(System.in);
        String str;
        String reverse;
        str = sc.nextLine();
        StringBuilder strb = new StringBuilder(str);
        reverse = strb.reverse().toString();
        System.out.println(reverse);
    }
    void J033(){
        Scanner sc = new Scanner(System.in);
        int count;
        String name;
        String longest, shortest;
        count = sc.nextInt();
        sc.nextLine();
        name = sc.nextLine();
        longest = name;
        shortest = name;
        for(int i=1; i<count; i++){
            name = sc.nextLine();
            if(name.length() > longest.length()){
                longest = name;
            }
            if(name.length() < shortest.length()){
                shortest = name;
            }
        }
        System.out.println("Longest: "+longest);
        System.out.println("Shortest: "+shortest);
    }
    void J034(){
        Scanner sc = new Scanner(System.in);
        String[] usernames = {"kim","lee","park","hong","choi"};
        String[] passwords = {"1111","1234","3456","3535","7777"};
        String name;
        String pw;
        name = sc.nextLine();
        pw = sc.nextLine();
        if(!Arrays.asList(usernames).contains(name)){
            System.out.println("No user!");
        }else if(Arrays.asList(usernames).indexOf(name) == Arrays.asList(passwords).indexOf(pw)){
            System.out.println("Login OK!");
        }else{
            System.out.println("Incorrect password!");
        }
    }
    void J035(){
        Scanner sc = new Scanner(System.in);
        String str;
        int sum = 0;
        str = sc.nextLine();
        for(int i=0; i<4; i++){
            sum = Integer.parseInt(str.substring(i,i+1));
        }
        sum = sum + Integer.parseInt(str.substring(4,6)) + Integer.parseInt(str.substring(6));
        System.out.println(sum);
    }
    void J036(){
        Scanner sc = new Scanner(System.in);
        String str;
        String reverse;
        str = sc.nextLine();
        StringBuilder strb = new StringBuilder(str);
        reverse = strb.reverse().toString();
        if(reverse.equals(str)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
    void J037(){//문자열 속 알파벳이 같은 수로 있는가
        //1. 알파벳 별로 수를 저장한다.
        //2. 문자열을 비교해 같은 알파벳이 나오면 인덱스에 무관하게 지우고 같은 과정을 반복하고 마지막에 들다 알파벳이 없으면 같은 것으로 한다.
        //2번으로 하려면 추출하거나 문자열을 배열로 바꿔야하는데 반복의 특성상 배열이 변하니 문자 배열로 고치는 걸로 하고
        //반복해서 비교 후 알파벳이 전부 없어지면 같은거
        //하나라도 남거나 못 찾으면 다른거
        Scanner sc = new Scanner(System.in);
        String str1, str2;
        str1 = sc.nextLine();
        str2 = sc.nextLine();
        boolean dummy = true;
        char[] str1Array = str1.toCharArray();
        char[] str2Array = str2.toCharArray();
        for(int i=0; i<str1.length(); i++){
            dummy = true;
            if(Character.isAlphabetic(str1Array[i])) {
                for (int j = 0; j < str2.length(); j++) {
                    if (str1Array[i] == str2Array[j]) {
                        dummy = false;
                        str2Array[j] = '$';
                        break;
                    }
                }
            }
            if(dummy){
                break;
            }
        }
        if(dummy){
            System.out.println("No");
        }else{
            System.out.println("Yes");
        }
    }
}