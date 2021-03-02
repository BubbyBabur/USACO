#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 600

int pasture[MAXN][MAXN];

// Random helper arrays
int minrightbomb[MAXN][MAXN];
int minrightgold[MAXN][MAXN];

int main() {
    int n;
    scanf(" %d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            scanf(" %d", &val);
            if(val > 100) pasture[i][j] = 1;
            if(val == 100) pasture[i][j] = 0;
            if(val < 100) pasture[i][j] = -1;
        }
    }

    // Setup min right bomb and min right gold
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            if(pasture[i][j] < 0) {
                minrightbomb[i][j] = 0;
            } else {
                if(j == n-1) {
                    minrightbomb[i][j] = -1;
                } else if(minrightbomb[i][j+1] == -1) {
                    minrightbomb[i][j] = -1;
                } else {
                    minrightbomb[i][j] = minrightbomb[i][j+1]+1;
                }
            }

            if(pasture[i][j] == 0) {
                minrightgold[i][j] = 0;
            } else if(pasture[i][j] < 0) {
                minrightgold[i][j] = -1;
            } else {
                if(j == n-1) {
                    minrightgold[i][j] = -1;
                } else if(minrightgold[i][j+1] == -1) {
                    minrightgold[i][j] = -1;
                } else {
                    minrightgold[i][j] = minrightgold[i][j+1]+1;
                }
            }
        }
    }

    // Now for interesting part
    long long number = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            int firstindexofpossibleright = -1;
            int tostretch = -1;
            
            int maxright = minrightbomb[i][j];
            if(maxright < 0) maxright = n - j;

            for(int k = i; k < n; k++) {
                if( minrightbomb[k][j] < maxright && minrightbomb[k][j] >= 0 ){
                    maxright = minrightbomb[k][j];
                }
                if(minrightgold[k][j] != -1) {
                    firstindexofpossibleright = k;
                    tostretch = minrightgold[k][j];
                    break;
                }
            }

            if(firstindexofpossibleright < 0) continue;
            // if(maxright <= tostretch) continue;

            // cout << i << ", " << j << ", " << maxright << ", " << tostretch << endl;

            // Now there are valid rectangles!
            for(int k = firstindexofpossibleright; k < n; k++) {
                if( minrightbomb[k][j] < maxright && minrightbomb[k][j] >= 0 ){
                    maxright = minrightbomb[k][j];
                }

                if(minrightgold[k][j] != -1 && minrightgold[k][j] < tostretch) {
                    tostretch = minrightgold[k][j];
                }

                // If no longer valid continue
                if(maxright <= tostretch) continue;

                // maxright - tostretch possible rectangles
                number += maxright - tostretch;
            }

            // cout << i << ", " << j << ", " << maxright << ", " << tostretch << endl;
        }
    }
    // cout << minrightgold[1][0] << endl;
    cout << number << endl;
}