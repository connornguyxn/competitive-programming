#undef _GLIBCXX_DEBUG // disable run-time bound checking
// #pragma GCC optimize("trapv") // abort() on integer overflow. increases runtime by ~10%
#pragma GCC optimize "Ofast,inline,unroll-loops" // optimize for speed
// note: change to O3 to disable fast-math for geometry problems
#pragma GCC target "movbe" // byte swap
#pragma GCC target "aes,pclmul,rdrnd" // encryption
#pragma GCC target "bmi,bmi2,lzcnt,popcnt" // bit manipulation
#pragma GCC target "avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2" // SIMD
// include headers *after* compile options
#include <bits/stdc++.h> // include everything
using namespace std; // use standard namespace for faster access
// aliases 
#define ll long long
#define ull unsigned long long
#define ld long double
#define nl '\n' // endl is stupid 

int main() {
    ios_base::sync_with_stdio(false); // turn off standard input buffer
    cin.tie(NULL); // turn off automatic output flushing
    // cout.tie(NULL); // does literally nothing because cout is already tied to NULL 
    // main code
    cout << cout.tie() << nl;




}


// pls be accepted :D
// #################################################################
// #                             _`                                #
// #                          _ooOoo_                              #
// #                         o8888888o                             #
// #                         88" . "88                             #
// #                         (| -_- |)                             #
// #                         O\  =  /O                             #
// #                      ____/`---'\____                          #
// #                    .'  \\|     |//  `.                        #
// #                   /  \\|||  :  |||//  \			           #
// #                  /  _||||| -:- |||||_  \			           #
// #                  |   | \\\  -  /'| |   |                      #
// #                  | \_|  `\`---'//  |_/ |                      #
// #                  \  .-\__ `-. -'__/-.  /                      #
// #                ___`. .'  /--.--\  `. .'___                    #
// #             ."" '<  `.___\_<|>_/___.' _> \"".                 #
// #            | | :  `- \`. ;`. _/; .'/ /  .' ; |                #
// #            \  \ `-.   \_\_`. _.'_/_/  -' _.' /                #
// #=============`-.`___`-.__\ \___  /__.-'_.'_.-'=================#
//                            `=--=-'
//           _.-/`)
//          // / / )
//       .=// / / / )
//      //`/ / / / /
//     // /     ` /
//    ||         /
//     \\       /
//      ))    .'
//     //    /