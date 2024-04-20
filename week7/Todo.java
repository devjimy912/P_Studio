package week7;

public class Todo {
    private String title;
    private String content;
    private String dueDate;
    private String category;

    public Todo() {
    }
    public Todo(String title, String content, String dueDate, String category) {
        this.title = title;
        this.content = content;
        this.dueDate = dueDate;
        this.category = category;
    }

    public Todo(String title, String content, String dueDate) {
        this(title, content, dueDate, ""); // 카테고리는 기본값으로 빈 문자열 설정
    }

    public String getTitle() {
        return title;
    }
    public String getContent() {
        return content;
    }
    public String getDueDate() {
        return dueDate;
    }
    public String getCategory() {
        return category;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    public void setContent(String content) {
        this.content = content;
    }
    public void setDueDate(String dueDate) {
        this.dueDate = dueDate;
    }
    public void setCategory(String category) {
        this.category = category;
    }
}

