//
// Created by xuanni on 8/25/21.
//
#include "heap.h"

bool Heap::empty() {
    int len=vdata.size();
    if(len==0){
        return true;
    }else{
        return false;
    }
}

void Heap::pop() {
    int len = vdata.size();

    std::swap(vdata[0],vdata[len-1]);

    vdata.pop_back();

    for(int i = len/2; i >= 1;--i){
        int minC = min(i);
        if(vdata[minC]<vdata[i-1]){
            std::swap(vdata[i-1],vdata[minC]);
        }
    }
  //  int len = vdata.size();
   // int now = 1;
   // vdata[now] = vdata[len--];

  //  while((now*2 <= len &&vdata[now]<vdata[now*2])||(now*2+1 <= len && vdata[now]<vdata[now*2+1])){
   //     if(vdata[now*2]>vdata[now*2+1]){
    //        std::swap(vdata[now],vdata[now*2]);
   //         now = now*2;
     //   }else if (vdata[now*2]<vdata[now*2+1]){
     //       std::swap(vdata[now],vdata[now*2+1]);
     //       now = now*2 +1;
    //    }
   //}
}

void Heap::push(int value){
    vdata.push_back(value);
    int len = vdata.size();

    for(int i  = len/2; i>=1;--i){
        int minC = min(i);
        if(vdata[minC] < vdata[i-1]){
            std::swap(vdata[i-1],vdata[minC]);
        }
    }
   // int len=vdata.size();
   // int pre = len;
   // vdata[++len] = value;

  //  while(vdata[pre]>vdata[pre/2] && pre>1){
  //      std::swap(vdata[pre],vdata[pre/2]);
  //      pre = pre/2;
  //  }
}

int Heap::top(){
    return vdata[0];
}

int Heap::min(int value)const{
    int left = value*2, right = value*2 +1;
    int len = vdata.size();

    if(left-1< len && right-1 < len){
        if(vdata[left-1]>vdata[right-1]){
            return right-1;
        }else{
            return left-1;
        }
    }
    if(left-1<len){return left-1;}
    if(right-1<len){return right-1;}

    return 0;
}
