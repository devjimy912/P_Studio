package pstudio.j071;

import java.util.*;

public class TodoCRUD implements iCRUD{
    private ArrayList<TodoItem> list;
    public TodoCRUD() {
        this.list = new ArrayList<>();
    }

    @Override
    public int addItem() {
        String title, desc;
        Scanner sc = new Scanner(System.in);

        System.out.print("Add a todo item\n"+"Enter title: ");

        title = sc.nextLine().trim();
        if(isDuplicated(title)){
            System.out.println("Title can't be duplicated");
            return 1;
        }
        System.out.print("Enter detail: ");
        desc = sc.nextLine().trim();

        TodoItem t = new TodoItem(title, desc);
        this.list.add(t);
        System.out.println("Item Added");

        return 0;
    }

    @Override
    public int updateItem() {
        Scanner sc = new Scanner(System.in);
        String title;
        boolean tf = true;
        System.out.println("Edit a Todo item");
        System.out.print("Enter the title of the item to edit: ");
        title = sc.nextLine().trim();
        for (TodoItem i : this.list) {
            if(title.equals(i.getTitle())) {
                System.out.println(i.toString());
                System.out.print("Enter the detail: ");
                i.setDetail(sc.nextLine().trim());
                tf = false;
                System.out.println("item updated.");
                break;
            }
        }
        if(tf){
            System.out.println("Not found");
        }
        return 0;
    }

    @Override
    public int deleteItem() {
        Scanner sc = new Scanner(System.in);
        String title;
        boolean tf = true;
        System.out.println("Delete a Todo item");
        System.out.print("Enter the title of the item to remove: ");
        title = sc.nextLine().trim();
        for (TodoItem i : this.list) {
            if(title.equals(i.getTitle())) {
                this.list.remove(i);
                System.out.println("item deleted.");
                tf = false;
                break;
            }
        }
        if(tf){
            System.out.println("Not found");
        }
        return 0;
    }

    boolean isDuplicated(String title) {
        for (TodoItem i : this.list) {
            if (title.equals(i.getTitle())) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int printAll() {
        System.out.println("Total "+this.list.size()+" items");
        for (TodoItem i : this.list) {
            System.out.println(i.toString());
        }
        return 0;
    }

    public void sortByName(){
        Collections.sort(this.list, new TodoitemNameComparator());
    }
    public void sortByDate(){
        Collections.sort(this.list, new TodoitemDateComparator());
    }
    public  void reverseList(){
        Collections.reverse(this.list);
    }
}

class TodoitemNameComparator implements Comparator <TodoItem>{
    @Override
    public int compare(TodoItem o1, TodoItem o2) {
        return o1.getTitle().compareTo(o2.getTitle());
    }
}
class TodoitemDateComparator implements Comparator <TodoItem>{
    @Override
    public int compare(TodoItem o1, TodoItem o2) {
        return o1.getDate().compareTo(o2.getDate());
    }
}
