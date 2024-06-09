#ifndef COUPONSTACK_H
#define COUPONSTACK_H

#include <iostream>
#include <string>

typedef struct{
    int number;
    string name;
}coupon;

class CouponStack{
    public:
        int maxsize;
        int top;
        coupon *list;

        void initialize();
        bool isEmpty() const;
        bool isFull() const;
        void push(const coupon& item);
        coupon* pop() const;
        CouponStack(int = 10);
        ~CouponStack();
        void print();
        void rprint();
}

CouponStack::initialize(){
    top = -1;
    list = new coupon[maxsize];
}
inline bool CouponStack::isEmpty() const{
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
bool CouponStack::isFull() const{
    if(top+1 == maxsize){
        return true;
    }else{
        return false;
    }
}
void CouponStack::push(const coupon& item){
    //쿠폰 포인터로 뉴해서 생성하고 리스트에 넣음.
    //아니지.
    //여기선 생성된거 받아서 넣는거고
    //생성은 메인에서 하는 건가
    //생성이 아니라 그냥 메인에서 값만 던지는거
    //리스트에 그대로 박으면 됨.
    //딜리트 할 건 리스트 자체말곤 없음.
    top++;
    list[top] = item;
}
coupon* CouponStack::pop() const{
    //내용 리턴.
    //출력은 리턴 받아서 메인에서 할 거임.
    //내용 임시저장하고
    //딜리트하고
    //리턴하는 순서.
    //포인터로 보내면 딜리트 하면 안되잖아..
    //널포인터로 변경할까
    //이거도 이전에 했던 다른 거처럼 하면 됨.
    //top 하나 내리고
    //top+1해서 리턴하는 방식
    //어차피 배열로 생성되서 메모리 추가로 안먹으니
    //더 들어오면 덮어쓴다는 마인드
    top--;
    return list[top+1];
}
CouponStack::CouponStack(int num = 10){
    maxsize = num;
    initialize();
}
CouponStack::~CouponStack(){
    //리스트 지우기 전에
    //탑으로 내용 확인하고 하나씩 지워내린 다음 리스트 제거
    //근데 팝으로 하면 될듯
    //다른 거 생각할 필요없었음.
    //그냥 리스트 바로 삭제
    delete[] list;
}
void CouponStack::print(){
    //이건 탑에서 부터 내려오면서 출력하는건가 아니면 첫번째 부터 올라가는건가
    //심지어 메인에서 받는 명령어에 이건 쓰지도 않네..
    //스택이긴 한데 배열이니까 인덱스 접근해도 될듯.
    for(int i=0; i<top+1: i++){
        std::cout << list[i]->number <<" "<< list[i]->name << std::endl;
    }
}
void CouponStack::rprint(){
    //얘도 프린트랑 같음. 다른 건 그냥 팝이 추가된거?
    //출력방식이 인덱스에서 데이터 접근이 아니라
    //팝으로 데이터 받는거.
    
}

#endif