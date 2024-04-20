package week7;

import java.util.ArrayList;

public class TodoCRUD {
    private ArrayList<Todo> todoList;

    public TodoCRUD() {
        this.todoList = new ArrayList<>();
    }

    public void addTodo(Todo todo) {
        todoList.add(todo);
    }

    public void updateTodo(int index, Todo newTodo) {
        if (index >= 0 && index < todoList.size()) {
            todoList.set(index, newTodo);
        } else {
            System.out.println("잘못된 인덱스입니다.");
        }
    }

    // 일정 목록 출력
    public void printTodos() {
        for (Todo todo : todoList) {
            System.out.println("제목: " + todo.getTitle() + ", 내용: " + todo.getContent() + ", 마감일: " + todo.getDueDate() + ", 카테고리: " + todo.getCategory());
        }
    }

    // 일정 삭제
    public void removeTodo(int index) {
        if (index >= 0 && index < todoList.size()) {
            todoList.remove(index);
        } else {
            System.out.println("잘못된 인덱스입니다.");
        }
    }
}