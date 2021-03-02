#include <iostream>
#include <cstdio>

using namespace std;

#define SIZE 3000

int pasture[SIZE][SIZE];
bool realcow[SIZE][SIZE];

int totaladded = 0;

void check(int i, int j);

void checkNeighbors(int i, int j) {
    check(i,j);
    check(i+1,j);
    check(i,j+1);
    check(i-1,j);
    check(i,j-1);
}

void addFakeCow(int i, int j) {
    pasture[i][j] = 0;
    realcow[i][j] = false;
    totaladded ++;

    // If isn't empty, add to their adj list
    if(pasture[i-1][j] >= 0) pasture[i-1][j]++;
    if(pasture[i+1][j] >= 0) pasture[i+1][j]++;
    if(pasture[i][j-1] >= 0) pasture[i][j-1]++;
    if(pasture[i][j+1] >= 0) pasture[i][j+1]++;

    // Find My Adj list!
    pasture[i][j] = 0;
    if(pasture[i-1][j] >= 0) pasture[i][j]++;
    if(pasture[i+1][j] >= 0) pasture[i][j]++;
    if(pasture[i][j-1] >= 0) pasture[i][j]++;
    if(pasture[i][j+1] >= 0) pasture[i][j]++;
    
    checkNeighbors(i,j);
}

void check(int i, int j) {
    if(pasture[i][j] == 3) {
        if(pasture[i-1][j] == -2) {
            addFakeCow(i-1,j);
        }if(pasture[i][j-1] == -2) {
            addFakeCow(i,j-1);
        }if(pasture[i+1][j] == -2) {
            addFakeCow(i+1,j);
        }if(pasture[i][j+1] == -2) {
            addFakeCow(i,j+1);
        }
    }
}

void addRealCow(int i, int j) {
    if(pasture[i][j] == -2) {

        // If isn't empty, add to their adj list
        if(pasture[i-1][j] >= 0) pasture[i-1][j]++;
        if(pasture[i+1][j] >= 0) pasture[i+1][j]++;
        if(pasture[i][j-1] >= 0) pasture[i][j-1]++;
        if(pasture[i][j+1] >= 0) pasture[i][j+1]++;

        // Find My Adj list!
        pasture[i][j] = 0;
        if(pasture[i-1][j] >= 0) pasture[i][j]++;
        if(pasture[i+1][j] >= 0) pasture[i][j]++;
        if(pasture[i][j-1] >= 0) pasture[i][j]++;
        if(pasture[i][j+1] >= 0) pasture[i][j]++;
    } else if(realcow[i][j] == 0) {
        // I am real now!
        realcow[i][j] = true;
        totaladded--;
    }

    // I am REAL!
    realcow[i][j] = true;
    checkNeighbors(i,j);
}

int main() {

    // Init Array

    // Empty = -2
    // Temporary Cow = -1
    // >=0 is how many adjacent cows
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            pasture[i][j] = -2;
        }
    }

    int n;
    scanf(" %d", &n);
    
    for(int i = 0; i < n; i++) {
        int a;
        int b;
        scanf(" %d %d", &a, &b);
        addRealCow(a+1000, b+1000);
        printf("%d\n", totaladded);
    }


    return 0;
}