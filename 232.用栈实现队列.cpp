/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//仅使用两个栈实现先入先出队列。
//只能使用标准的栈操作，push to top, peek/pop from top, size, 和 is empty操作是合法的
//你可以使用list或者deque（双端队列）来模拟一个栈，只要是标准的栈操作即可，不必非要使用栈
class MyQueue {
private:
    //一个是输入栈，一个是输出栈
    //先放入输入栈的元素，转入到输出栈后恰好是栈顶的元素，结合栈的后进先出特性，就能模拟队列的先入先出效果。
    stack<int> inStack, outStack;
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    //默认构造函数
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    //当输入栈和输出栈都是空的，相当于队列是空的。
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};


//用vector实现
class MyQueue{
private:
    vector<int> temp;

public:
    //默认构造函数，不需要初始化赋值
    MyQueue(){}

    void push(int x){
        temp.push_back(x);
    };

    int pop(){
        int x = temp.back();
        temp.pop_back();
        return x;
    };

    int peek(){
        return temp.back();
    };

    bool empty(){
        return temp.empty();
    };

};

//用stack实现（自己写）
class MyQueue{
private:
    stack<int> instack, outstack;
    void in2out(){
        while(!instack.empty()){
            outstack.push(instack.top());
            instack.pop();
        }
    }
public:
    MyQueue(){}

    void push(int x){
        instack.push(x);
    }

    int pop(){
        if(outstack.empty()){
            in2out();
        }
        int x = outstack.top();
        outstack.pop();
        return x;
    }

    int peek(){
        if(outstack.empty()){
            in2out();
        }
        return outstack.top();
    }

    bool empty(){
        return instack.empty() && outstack.empty();
    }
};
