#define SIZE 50
struct library{
    char name[50]; //book name
    int number; //book number
    int isCheckOut; //0:in, 1:out
    char author[50]; //author
    char publisher[50]; //publisher
};
int addData(int count, struct library* c[]);
void readData(int count, struct library* c[]);
void editData(int count, struct library* c[]);
int deleteData(int count, struct library* c[]);
void searchData(int count, struct library* c[]);
void saveData(int count, struct library* c[]);
void printBookInfo(int num, struct library* c[]);
void loanSystem(int num, struct library* c[]);
void bookPush(int num, struct library* c[]);
void bookPull(int num, struct library* c[]);