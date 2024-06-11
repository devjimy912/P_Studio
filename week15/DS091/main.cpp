#include <iostream>
#include <stack>

using namespace std;

int main(){
    //스택에 넣었다 빼는 것으로 한다
    // 스택을 두개 생성한다
    // 하나는 메인 나머지 하나는 서브
    // 메인에서 시작한다
    // 커서를 왼쪽으로 보내면 그만큼 메인스택에서 팝해서 서브 스택에 푸시한다
    // 커서를 오른쪽으로 보내면 반대로 작동
    //배열에 넣었다 빼기는 번거로우니
    //char로 받아서 스택에 바로 넣는걸로
    //넣기 전에 <,> 확인해주고

    char c;
    bool q = true;
    while(q){
        //일단 보류
        //q면 종료인데
        //지금은 문자열안에 q가 있으면 멈춰버림
        //그래서 문자열의 길이가 1이고 q인 경우로 바꿔야함
        cin >> c;
        if(c == 'q'){
            q = false;
        }else if(c == '<'){ //main -> sub

        }else if(c == '>'){ //sub -> main

        }else{

        }
    }
        
    return 0;
}