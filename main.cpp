#include <iostream>
#include <cassert>

#include "queue.h"
#include "vector.h"
#include "stack.h"

using namespace std;

void queue_test();
void vector_test();
void stack_test();

int main() {
    //queue_test();
    //vector_test();
    stack_test();

    cin.get();
    return 0;
}

void queue_test() {
    printf("Test cases for queue\n");
    queue<int> q(10);
    for (int i = 0; i < 100; i++) {
        q.push(i);
    }

    printf("\tChecking for right assignment...\n");
    for (int i = 0; i < 100; i++) {
        assert(q.pop() == (99 - i));
    }

    for (int i = 0; i <= 333; i++) {
        q.push(i);
    }

    printf("\tChecking for right reassignment...\n");
    assert(q.pop() == 333);
    
    printf("\tChecking for right capaticy-size relation...\n");
    assert(q.capacity() > q.size());
    
    printf("\tChecking for right size...\n");
    assert(q.size() == 333 && !q.empty());
    
    printf("\tChecking for correct cleaning...\n");
    q.clear();
    assert(q.size() == 0 && q.empty());
    
    printf("\tChecking for extension handling...\n");
    assert(q.extend_size(400) && !q.extend_size(-1));

    printf("\tTest cases: ok\n");
}

void vector_test() {
    printf("Test cases for vector\n");
    vector<int> d(10, 7);

    printf("\tChecking constructor with default element...\n");
    assert(d.front() == d.back());
    
    printf("\tChecking for right assignment...\n");
    d.clear();
    for (int i = 0; i < 30; i++) {
        d.push_back(i);
        assert(d[i] == d.at(i));
    }

    printf("\tChecking for right capaticy-size relation...\n");
    assert(d.capacity() > d.size());
    
    printf("\tChecking for right size...\n");
    assert(d.size() == 30 && !d.empty());

    printf("\tChecking vector's insertion capability...\n");
    int te_before = d[3];
    d.insert(3, d[3]-2000);
    assert(te_before - 2000 == d.at(3));

    printf("\tChecking vector's resize capability...\n");
    int size_before = d.size();
    d.resize(d.size() - 3);
    assert(size_before - 3 == d.size());
    d.resize(size_before, 666);
    assert(d.back() == 666);

    printf("\tChecking vector's elements swapping capability...\n");
    int sec_before = d[1];
    d.swap(8, 1);
    assert(d[8] == sec_before);

    printf("\tChecking vector's elements erasing capability...\n");
    size_before = d.size();
    d.erase(3);
    assert(d.size() == size_before - 1);
    size_before = d.size();
    d.erase(1, 3);
    assert(d.size() == size_before - 2);
    
    printf("\tChecking correctness of vector's pop_back...\n");
    size_before = d.size();
    d.pop_back();
    assert(size_before > d.size());

    printf("\tChecking for correct cleaning...\n");
    d.clear();
    assert(d.size() == 0 && d.empty());

    printf("\tChecking for correct capacity extension...\n");
    assert(d.extend_size(200) && !d.extend_size(1));

    printf("\tChecking vector shrinking capability...\n");
    int cap_before = d.capacity();
    d.shrink_to_fit();
    assert(cap_before > d.capacity());

    printf("\tChecking vector's capability to work as string\n");
    vector<char> s(4, '\0');
    s[0] = 'c', s[1] = 'a', s[2] = 't';
    assert(string("cat") == string(s.data()));

    printf("\tTest cases: ok\n");
}

void stack_test() {
    printf("Test cases for stack\n");
    stack<int> d;

    for (int i = 1; i <= 100; i++) {
        d.push(i * 13);
    }

    printf("\tChecking for correct insertion and popping...\n");
    assert(d.pop() == 1300 && d.pop() == 1287 && d.pop() == 1274);

    printf("\tChecking for correct size calculation...\n");
    assert(d.size() == 97);

    stack<char> s;
    for (char c : "test string") {
        s.push(c);
    }
    s.push('\0'); // it is already contains \0, I know

    printf("\tNot only integers...\n");
    assert(s.size() == 13);


    printf("\tClear functioning...\n");
    s.clear();
    assert(s.size() == 0);

    for (char c : "\nko :sesac tseT\t") {
        s.push(c);
    }
    while (s.size() > 0) {
        cout << s.pop();
    }
}
