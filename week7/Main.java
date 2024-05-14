package week7;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
/*
        System.out.println("J052");
        Score J052 = new Score();
        J052.Score(5);
        J052.getScore();
        J052.printScore();

        System.out.println("J053");
        System.out.print("Enter student number: ");
        J052.printScore(scanner.nextInt());

        System.out.println("J054");
        J052.printScore(scanner.nextInt(),scanner.next());

        System.out.println("J055");
        BMICalculator J055 = new BMICalculator();
        J055.getHW();
        J055.printBMI();
        */

        System.out.println("J062");
        BookCRUD J062 = new BookCRUD();
        J062.addBook(new Book("자바의 정석", "남궁성", "교육", 30000, 2020));
        J062.addBook(new Book("효과적인 자바", "조슈아 블로크", "프로그래밍", 45000, 2018));
        J062.printBooks();
        J062.updateBook("자바의 정석","자바의 정석", "남궁성", "교육", 32000, 2021);
        J062.printBooks();
        J062.deleteBook("효과적인 자바");
        J062.printBooks();

        System.out.println("J063");
        TodoCRUD J063 = new TodoCRUD();
        J063.addTodo(new Todo("Java 공부하기", "자바 기본 문법 익히기", "2024-04-25", "공부"));
        J063.addTodo(new Todo("운동하기", "저녁에 조깅하기", "2024-04-20", "건강"));
        J063.printTodos();
        Todo updatedTodo = new Todo("Java 공부하기", "자바 기본 문법과 라이브러리 익히기", "2024-04-30", "공부");
        J063.updateTodo(0, updatedTodo);
        J063.printTodos();
        J063.removeTodo(1);
        J063.printTodos();
    }
}
