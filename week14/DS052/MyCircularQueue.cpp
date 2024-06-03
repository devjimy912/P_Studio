void MyCircularQueue::initialize(){
    front = 0;
    rear = 0;
}
bool MyCircularQueue::isEmpty() const{
    if(front == rear){
        return true;
    }else{
        return false;
    }
}
bool MyCircularQueue::isFull() const{
    
}
void MyCircularQueue::enqueue(const element& e){
    if(isFull()){
	    cout << "Queue is full" << std::endl;
    }else {
        rear = (rear + 1) % maxsize;
        list[rear] = e;
    }
}
void MyCircularQueue::dequeue(){
    if(front == rear){
        // std::cout << "Queue underflow" << std::endl;
		return 0;
    }else {
        front = (front + 1) % maxsize;
    }
}
element MyCircularQueue::Front(){
    return list[front+1];
}
element MyCircularQueue::Rear(){
    return list[rear];
}
MyCircularQueue::MyCircularQueue(int = 10){
    maxsize = 10;
    front = 0;
    rear = 0;
    list = new element[maxsize];
}
MyCircularQueue::~MyCircularQueue(){
    delete[] list;
}
void MyCircularQueue::print(){

}

int MyCircularQueue::size() const{
    return 0;
}

void MyCircularQueue::printDetail() const{

}
