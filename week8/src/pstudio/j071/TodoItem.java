package pstudio.j071;
//d
import java.util.Date;
import java.text.SimpleDateFormat;

public class TodoItem {
    private String title;
    private String detail;
    private Date date;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDetail() {
        return detail;
    }

    public void setDetail(String description) {
        this.detail = description;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public TodoItem(String title, String detail) {
        this.title = title;
        this.detail = detail;
        this.date = new Date();
    }

    @Override
    public String toString() {
        return "["+ title +"]"
                + detail + " - " + new SimpleDateFormat("yyyy/MM/dd").format(date);
    }
}
