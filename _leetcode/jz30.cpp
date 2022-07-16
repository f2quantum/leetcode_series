
# include "stack"

using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> dataStack;
    stack<int>  minStack;

    MinStack() {

    }

    void push(int x) {
        this->dataStack.push(x);
        if(this->minStack.size()==0){
            this->minStack.push(x);
        }else{
            if (this->minStack.top()>=x){
                this->minStack.push(x);
            }
        }
    }
    
    void pop() {
        int x = (int)this->dataStack.top();
        this->dataStack.pop();

        if(this->minStack.size()!=0){
            if(x== minStack.top())
                this->minStack.pop();
        }


    }
    
    int top() {
        return this->dataStack.top();
    }
    
    int min() {
        return this->minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */