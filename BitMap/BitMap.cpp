#include <iostream>
#include <vector>
using namespace std;


//在C++中，对应的为<bitset>
//接口如下
//operator[] --- access bit
//count --- Count bit set
//size --- return size
//test --- return bit value
//to_string ---  

class BitMap{
public:
    BitMap(const int& size){
        bitmap.reserve(size>>3 +1);
    }

    void Set(const int& x){
        int index = x >> 3; 
        int bit = x % 8;
        bitmap[index] |= (1 << bit);
    }

    void Reset(const int& x){
        int index = x >> 3;
        int bit = x % 8;
        bitmap[index] &= ~(1 << bit);
    }

    bool Test(const int& x){
        int index = x >> 3;
        int bit = x % 8;
        return (bitmap[index] >> bit) & 1;
    }

private:
    vector<char> bitmap;
};


int main(){
    BitMap b1(20);
    b1.Set(10);
    b1.Set(20);
    b1.Set(10);
    cout<<b1.Test(10)<<endl;
    cout<<b1.Test(20)<<endl;
    return 0;
}
