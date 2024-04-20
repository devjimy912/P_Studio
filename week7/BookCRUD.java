package week7;

import java.util.ArrayList;

public class BookCRUD {
    private ArrayList<Book> bookList;

    public BookCRUD() {
        this.bookList = new ArrayList<>();
    }

    public void addBook(Book book) {
        bookList.add(book);
    }

    public void updateBook(String title, String newTitle,String author, String category,int price, int year) {
        for (Book book : bookList) {
            if (book.getTitle().equals(title)) {
                book.setTitle(newTitle);
                book.setAuthor(author);
                book.setCategory(category);
                book.setPrice(price);
                book.setPublishYear(year);
                System.out.println(title + " 책 정보가 업데이트 되었습니다.");
                return;
            }
        }
        System.out.println(title + " 책을 찾을 수 없습니다.");
    }

    public void printBooks() {
        for (Book book : bookList) {
            System.out.println(book.toString());
        }
    }

    public void deleteBook(String title) {
        for (int i = 0; i < bookList.size(); i++) {
            if (bookList.get(i).getTitle().equals(title)) {
                bookList.remove(i);
                System.out.println(title + " 책이 목록에서 삭제되었습니다.");
                return;
            }
        }
        System.out.println(title + " 책을 찾을 수 없습니다.");
    }
}