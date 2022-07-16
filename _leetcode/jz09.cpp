//
// Created by FranklinZQuantum on 2021/8/5.
//
/**
 * 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead操作返回 -1 )

 */
//_leetcode submit region begin(Prohibit modification and deletion)
#include <stack>
using namespace  std;

class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {

    }

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }

        }
        if(stack2.empty()){
            return -1;
        }else{
            int delItem=stack2.top();
            stack2.pop();
            return delItem;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
//_leetcode submit region end(Prohibit modification and deletion)