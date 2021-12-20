#include <iostream>

void Tower(int n , char a, char b, char c ) {
    if(n==1) {
        std::cout << a << "-------" << c << std::endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
    }

int main() {
    char a='A', b='B', c='C';
    int n;
    std::cin>>n;
    Tower(n,a,b,c);
}