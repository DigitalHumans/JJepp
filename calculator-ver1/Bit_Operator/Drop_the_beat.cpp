/*file name: Drop_the_beat.cpp
created: 2020-12-31
modified: 2020-12-31
author: Kwon  Soonhyung
*/
#include <iostream>
#include <bitset> //char형을 binary 형으로 출력하기 위한 라이브러리

using namespace std;

int main()
{
    char bit = 0b11111111;
    cout << bitset<8>(bit) << endl;

    bit = bit & ~(0x01 << 3); //비트 클리어
    cout << bitset<8>(bit) << endl;

    bit = bit & ~((0x01 << 7) | (0x01 << 5) | (0x01 << 1)); //비트 클리어
    cout << bitset<8>(bit) << endl;

    bit = bit | (0x01 << 5) | (0x01 << 3); //비트 세트
    cout << bitset<8>(bit) << endl;

    bool check = false;//특정 위치의 비트 검사 결과를 저장하는 변수
    if((0x01 << 7) & bit) check = true;
    else check = false;
    cout << "8번째 bit는 " << check << endl;

    if((0x01 << 6) & bit) check = true;
    else check = false;
    cout << "7번째 bit는 " << check << endl;


}