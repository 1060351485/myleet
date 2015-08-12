//
//  Sqrt.cpp
//  Sqrt
//
//  Created by Apple on 15/8/6.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

double sqrt(float x){
    
    float xhalf = 0.5f*x; int i = *(int*)&x; // get bits for floating
    i = 0x5f375a86-(i>>1); // gives initial guess
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    return 1/x;
}

double mysqrt(float x){
    int eps = 1/pow(10, 5);
    float val = x;//最终
    float last;//保存上一个计算的值
    do {
        last = val;
        val =(val + x/val) / 2;
    }while(abs(val-last) > 0);
    return val;
}
