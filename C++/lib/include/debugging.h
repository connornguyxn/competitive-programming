// https://gist.github.com/SansPapyrus683/61b65d4d7ec223b48ebf5c3bb382ba8d
/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ios>*/
// github.com/rachitiitr/modern-cpp-tricks#solution-using-a-powerful-macro
#define vdb(...) logger(#__VA_ARGS__, __VA_ARGS__)
#define db(...) logger("", __VA_ARGS__)

#include <bits/stdc++.h>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    if (deq.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++) {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

// Source: https://stackoverflow.com/a/31116392/12128483
template<typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}

// https://stackoverflow.com/a/32449206
template<typename... Types>
std::ostream & operator<<(std::ostream & out, std::stack<Types...> s) {
    out << '[';
    while(!s.empty()) {
        out << s.top() << ", ";
        s.pop();
    };
    return out << ']';
}

// https://codeforces.com/blog/entry/91347
template<typename ...Args>
void logger(std::string vars, Args&&... vals) {
    // https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal
    std::cout << "[" << "\033[1;33m" << "debug" << "\033[0m" << "] ";
    if (!vars.empty()) {
        std::cout << vars << " = ";
    };
    std::string sep = "";
    // fold expression
    (..., (std::cout << sep << vals, sep = ", "));
    std::cout << '\n';
}

