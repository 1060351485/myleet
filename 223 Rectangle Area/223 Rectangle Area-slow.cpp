//
//  223 Rectangle Area-slow.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (D-B)*(C-A)+(G-E)*(H-F)-getXY(D,B,H,F)*getXY(C,A,G,E);
    }
    // D>=B,H>=F
    int getXY(int D, int B, int H, int F){
        if((B>=H)||(D<=F))
            return 0;
        vector<int>V(4);
        V[0] = D;V[1] = B; V[2] = H, V[3] = F;
        sort(V.begin(),V.end());
        return V[2]-V[1];  // if no overlap , v[2]-v[1] = 0, return 0
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int S = (D-B)*(C-A)+(G-E)*(H-F);
        if((H<=B)||(D<=F)||(C<=E)||(G<=A)) return S;  //in case of overflow, avoid calc overlap
        return S-(min(D,H)-max(B,F))*(min(C,G)-max(A,E)); //
//        return S-max(min(D,H)-max(B,F), 0)*max(min(C,G)-max(A,E), 0); //old ver

    }
};