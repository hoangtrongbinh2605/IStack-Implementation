#include "Stack.h"
#include <bits/stdc++.h>
using namespace std;
#define ipfile1 "input.txt"
#define ipfile2 "inputReverse.txt"

class UnitTest {
private:
    ifstream ip;
    ifstream ipR;
public:
    UnitTest() {
        ip.open(ipfile1);
        ipR.open(ipfile2);
        if (ip && ipR) {}
        else {
            throw exception();
        }
    }

    void testAll() {
        testStackEmptyFunc();
        testStackPopFunc();
        testStackPushFunc();
        testStackSizeFunc();
    }

    void testStackEmptyFunc() {
        Stack<string> myStack;
        assert(myStack.empty());
    }

    void testStackSizeFunc() {
        Stack<string> myStack;
        string s;
        int cnt = 0;
        while (getline(ip, s)) {
            myStack.push(s);
            ++cnt;
            assert(cnt == myStack.size());
        }
    }

    void testStackPushFunc() {
        Stack<string> myStack;
        string s;
        while (getline(ip, s)) {
            myStack.push(s);
            string tmp = myStack.top();
            assert(tmp == s);
        }
    }

    void testStackPopFunc() {
        Stack<string> myStack;
        string s;
        while (getline(ip, s)) {
            myStack.push(s);
        }
        while (getline(ipR, s)) {
            string tmp = myStack.top();
            myStack.pop();
            assert(tmp == s);
        }
    }
};

