#include <iostream>
using namespace std;
void func(int key){
    int x = 4;
	char overflowme[32];
    int y = 5;
    cout<<&key<<"\n";
    cout<<&x<<"\n";
    cout<<&overflowme<<"\n";
    cout<<&y<<"\n";
}
int main(int argc, char* argv[]){
	func(0xdeadbeef);
	return 0;
}
