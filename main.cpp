#include <iostream>
#include <cassert>
#include "queue.h"

using namespace std;

void queue_test();

int main() {
    queue_test();
    
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
    assert(q.size() == 333);
    assert(!q.empty());
    q.clear();
    printf("\tChecking for correct cleaning...\n");
    assert(q.size() == 0);
    assert(q.empty());
    printf("\tChecking for extension handling...\n");
    assert(q.extend_size(400));
    assert(!q.extend_size(-1));

    printf("\tTest cases: ok\n");
}