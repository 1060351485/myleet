//
//  62 Unique Path - C(n)(k).cpp
//  
//
//  Created by Apple on 15/7/22.
//
//

// it's a C(m+n-2)(m-1) problem, we need to move m+n-2 time, m-1(or n-1) of them is go down(or go left),
// so choose which m-1 move is go down

// AC
int uniquePaths(int m, int n) {
    double rslt = 1;
    for(int i = 1; i <= m-1;i++)
        rslt = rslt * (n-1+i)/i;
    return (int)rslt;
}

// WA
int uniquePaths(int m, int n) {
    double rslt = 1;
    for(int i = 1; i <= m-1;i++)
        rslt *= (n-1+i)/i; // when m=4, n=4, got WA,because (n-1+i) and i are int, easy to understand
    return (int)rslt;
}

// WA
int uniquePaths(int m, int n) {
    double rslt = 1;
    for(double i = 1; i <= m-1;i++)
        rslt *= (n-1+i)/i;   //when m=10, n=10 got WA, pricision problem,
    return (int)rslt;
}