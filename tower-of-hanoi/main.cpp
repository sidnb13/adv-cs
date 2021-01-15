#include <iostream>
#include <cstdio>
#include <string>
#include "stack.h"

using namespace std;

const char T1[] = "T1", T2[] = "T2", T3[] = "T3";
int moveNum = 0;

static void showTowers(Stack* t1, Stack* t2, Stack* t3) {
    cout << T1 << ": ";
    t1->display();

    cout << T2 << ": ";
    t2->display();

    cout << T3 << ": ";
    t3->display();

    cout << endl;
}

/*void displayMovement(Disc* d, const string& from, const string& to) {
    printf("Disk %d was moved from \'%s\' to \'%s\'\n",d->getSize(),from.c_str(),to.c_str());
}*/

void moveDisks(int n, Stack *src, Stack *dest, Stack *spare) {
    if (n <= 0)
        return;

    moveDisks(n - 1, src, spare, dest); //move from 1st to 2nd

    moveNum++;
    printf("MOVE #%d:\n\n", moveNum);

    Disc *tmp = src->pop();
    dest->push(tmp); //move remaining disc on 1st to 3rd

    showTowers(src, spare, dest);

    moveDisks(n - 1, spare, dest, src); //move 2nd to 3rd and complete
}

void toh(int n) {
    int i, j = 0, numMoves = (int) pow(2,n) - 1;

    auto *t1 = new Stack();
    auto *t2 = new Stack();
    auto *t3 = new Stack();

    for (i = n; i >= 1; i--)
        t1->push(new Disc(i));

    cout << "---------------------STATS---------------------" << endl;
    printf("# of discs: %d\n# of moves: %d\n", n, numMoves);
    cout << "-----------------------------------------------" << endl << endl;

    printf("MOVE #%d (Original setup):\n\n", moveNum);
    showTowers(t1, t2, t3);

    moveDisks(n, t1, t3, t2);
}

int main() {
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    cout << endl;
    toh(n);
}
