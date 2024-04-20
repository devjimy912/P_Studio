package week7;

public class Book {
    private String title;
    private String author;
    private String category;
    private int price;
    private int publishYear;

    public Book() {}
    public Book(String title, String author, String category, int price, int publishYear) {
        this.title = title;
        this.author = author;
        this.category = category;
        this.price = price;
        this.publishYear = publishYear;
    }

    public String getTitle() {
        return title;
    }
    public String getAuthor() {
        return author;
    }
    public String getCategory() {
        return category;
    }
    public int getPrice() {
        return price;
    }
    public int getPublishYear() {
        return publishYear;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
    public void setCategory(String category) {
        this.category = category;
    }
    public void setPrice(int price) {
        this.price = price;
    }
    public void setPublishYear(int publishYear) {
        this.publishYear = publishYear;
    }

    public String toString() {
        return "Book{" +
                "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", category='" + category + '\'' +
                ", price=" + price +
                ", publishYear=" + publishYear +
                '}';
    }
}
