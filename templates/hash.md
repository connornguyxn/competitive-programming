---
date created: 2024-08-12, 10:01:19 +07:00
date modified: 2024-08-14, 06:33:22 +07:00
---

# Hash dãy (Rolling Hash)

> [!cite] Tài liệu
> - [Hash: A String Matching Algorithm | VNOI Wiki](https://wiki.vnoi.info/algo/string/hash)
> - [Hệ đếm – Wikipedia tiếng Việt](https://vi.wikipedia.org/wiki/H%E1%BB%87_%C4%91%E1%BA%BFm)

Mỗi dãy số có thể được coi là dãy các "chữ số" của một "số" được biểu diễn dưới hệ cơ số $BASE$. Biết vậy, ta có thể kết hợp các "chữ số" này lại thành "số" ban đầu và sử dụng nó để so sánh các dãy trong $O(1)$.

Do "số" ban đầu rất lớn và không thể lưu trữ hết được, ta sẽ chỉ lưu và sử dụng số dư của nó cho một số nguyên $MOD$ nào đó khi so sánh. Việc này về bản chất là sai vì nhiều dãy khác nhau sẽ có thể có cùng một mã hash, tuy nhiên tuỳ cài đặt mà tỉ lệ sai sót rất nhỏ và có thể chấp nhận được.

## Ứng dụng

- So sánh nhiều xâu/xâu con: [[#Lấy hash dãy con (tách giá trị hash)]], [[#Kết hợp giá trị hash]]
- Tăng/giảm giá trị của dãy và so sánh các dãy: [[#Thay đổi giá trị phần tử trong dãy]]

## Phân tích

> [!cite] Tài liệu
> [Analysis of polynomial hashing - Codeforces](https://codeforces.com/blog/entry/100027)

### Các giá trị cốt lõi và tỉ lệ trùng hash

- $BASE$: Quy ước hệ cơ số của dãy, tương đương với số giá trị khác nhau của mỗi phần tử trong dãy.
- $MOD$: Quyết định tổng số mã hash có thể tồn tại.

 Tỉ lệ hai dãy có cùng mã hash là $\approx 1/MOD$, điều kiện là một hàm tạo hash tối ưu sao cho các mã hash được phân bố đều ([[#Giảm thiểu tỉ lệ trùng hash]]).

### Tỉ lệ trùng hash khi so sánh nhiều dãy

> [!cite] Tài liệu
> - [Birthday attack - Wikipedia](https://en.wikipedia.org/wiki/Birthday_attack)

Tuy vậy, với các bài toán cần so sánh nhiều cặp dãy, ta có thể thấy tỉ lệ trùng hash sẽ lên khá cao một cách nhanh chóng.

Gọi $p(n, H)$ là tỉ lệ 2 mã hash trùng nhau khi chọn $n$ mã hash ngẫu nhiên trong $H$ mã hash có thể tồn tại, ta có công thức tính xấp xỉ:

$$
p(n, H) \approx \frac{n^2}{2H}
$$

Từ đó:

$$
\leftrightarrow n \approx \sqrt{2H * p(n, H)}
$$

Với $p(n, H) = 0.5$ và $H = 10^9 + 7$ (`MOD = 1e9 + 7`, [[#Định nghĩa các hằng số]]), ta có $n(p; M) \approx 31623$, tức chỉ cần tạo khoảng $3 * 10^4$ mã hash để tỉ lệ trùng gần như là lên đến 50%.

### Giảm thiểu tỉ lệ trùng hash

- Để có được tỉ lệ trùng hash $\approx 1/MOD$, giá trị $BASE$ và $MOD$ phải là 2 số nguyên tố cùng nhau: [language agnostic - Why should hash functions use a prime number modulus? - Stack Overflow](https://stackoverflow.com/questions/1145217/why-should-hash-functions-use-a-prime-number-modulus#:~:text=It%20turns%20out,simple%20predictable%20usage)
- Một số phương án tăng tổng số mã hash có thể tồn tại:
	- So sánh độ dài của dãy cùng với mã hash:
	- Tăng giá trị $MOD$: [[#Cài đặt nhanh và lười]]
	- Sử dụng nhiều $MOD$ hoặc $BASE$ khác nhau cùng lúc: [[#Cài đặt an toàn chắc cốp]]

## Cài đặt

Ta sẽ tạo hash cho `vector<int> a(n + 1)` với index từ 1.

Cũng có thể hash `string` vì nó về bản chất là `vector<char>` và `char` có thể được chuyển về `int` dưới dạng mã kí tự trong bảng mã ASCII.

Không thể hash `long long` trực tiếp do phép nhân luỹ thừa sẽ bị tràn số, trừ khi sử dụng Có thể sử dụng [[Nén số]] để chuyển các giá trị `long long` về `int`, sau đó hash dãy, hoặc sử dụng phương pháp [[Hash tập hợp (Zobrist Hash)]].

### Các hằng số

Nhằm [[#Giảm thiểu tỉ lệ trùng hash]] và để cho chắc cốp thì ta sẽ sử dụng 2 số nguyên tố:

- $BASE = 10^{6} + 3$: Do các bài toán yêu cầu tăng giảm phần tử thường có số truy vấn không quá $10^{6}$ (khi hash `int`) và số kí tự trong bảng mã ASCII là 256 (khi hash `string`), giá trị phần tử tối đa của dãy sẽ không vượt quá $10^6$.
- $MOD = 10^{9} + 7$ hoặc $10^{9} + 9$: Khi nhân không vượt quá giới hạn của kiểu dữ liệu.

Ngoài ra để phục vụ cho các thao tác trên dãy con, ta sẽ tính trước mảng `bp` là luỹ thừa của $BASE$ đến một giá trị $N$ là giới hạn độ dài của dãy.

```cpp
const ll BASE = 1e6 + 3;
const ll MOD = 1e9 + 7;
const ll N = 1e6;
vector<ll> bp(N + 1);

void prep() {
	bp[0] = 1;
	FOR(i, 1, N) bp[i] = bp[i - 1] * BASE % MOD;
}
```

### Tạo hash

Ta sẽ lưu một mảng `h` chứa mã hash các tiền tố của xâu để thực hiện các thao tác trên dãy con sau này.

```cpp
ll res = 1;
FOR(i, 0, a.size()) {
	res = (res * BASE % MOD + a[i]) % MOD;
}
```

### Lấy hash dãy con (tách giá trị hash)

`hash[L, R] = h[R] - h[L - 1] * bpow[R - L + 1]`.

Ví dụ với số base-10: `23 = 1234 - 12 * 100`

```cpp
ll get(int l, int r) {
	l++; r++;
	return (h1[r] - h1[l - 1] * bp1[r - l + 1] + MOD1 * MOD1) % MOD1;
}
```

### Kết hợp giá trị hash

`hash[x, y] + hash[y, z] = hash[x, y] * bp[y - z + 1] + hash[y, z]`.

Ví dụ với số base-10: `1234 = 12 * 100 + 34`

### Thay đổi giá trị phần tử trong dãy

Cộng/trừ $BASE^i$ để tăng/giảm giá trị tại vị trí $i$ của dãy.

## Các cài đặt cụ thể

### Cài đặt an toàn chắc cốp

Cài đặt trên sử dụng đồng thời 2 mã hash với 2 modulo nguyên tố khác nhau là $10^9 + 7$ và $10^9 + 9$, với $n$. Cài đặt này khá bất tiện ở chỗ ta sẽ phải quản lí cùng lúc 2 mã hash khác nhau với mỗi thao tác.

```cpp
const ll MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, BASE = 1e6 + 3;
const int N = 1e6;
vector<ll> bp1(N + 1), bp2(N + 1);
using pll = pair<ll, ll>;
////////////////////////////////////////
struct Hash {
    vector<ll> h1, h2;
    void init(vector<int> s) {
        s.insert(s.begin(), 0);
        h1.resize(s.size());
        h2.resize(s.size());
        FOR(i, 1, s.size() - 1) {
            h1[i] = (h1[i - 1] * BASE + s[i]) % MOD1;
            h2[i] = (h2[i - 1] * BASE + s[i]) % MOD2;
        }
    }
    ////////////////////////////////////////
    pll get(int l, int r) {
        l++; r++;
        ll v1 = (h1[r] - h1[l - 1] * bp1[r - l + 1] + MOD1 * MOD1) % MOD1;
        ll v2 = (h2[r] - h2[l - 1] * bp2[r - l + 1] + MOD2 * MOD2) % MOD2;
        return {v1, v2};
    }
};
////////////////////////////////////////
void prep() {
    bp1[0] = bp2[0] = 1;
    FOR(i, 1, N) {
        bp1[i] = bp1[i - 1] * BASE % MOD1;
        bp2[i] = bp2[i - 1] * BASE % MOD2;
    }
}
```

### Cài đặt nhanh và lười

> [!quote] Tài liệu
> - [modulo - Why only use primes for Hash function division method - Stack Overflow](https://stackoverflow.com/questions/12102625/why-only-use-primes-for-hash-function-division-method)
> - [On the mathematics behind rolling hashes and anti-hash tests - Codeforces](https://codeforces.com/blog/entry/60442)
> - [Anti-hash test. - Codeforces](https://codeforces.com/blog/entry/4898)

Không như các kiểu số nguyên `signed`, việc tính toán tràn giá trị trên các số `unsigned` là bình thường và đã được quy ước sẵn. Chúng tương đương với phép chia lấy dư cho giá trị lớn nhất của kiểu dữ liệu, tức $2^{64}$ với `unsigned long long`.

Biết vậy, ta sẽ lợi dụng tính chất này bằng cách sử dụng `unsigned long long` để tính toán mã hash và mặc kệ cho các phép tính tràn số, thực tế là tương tự với việc để giá trị $MOD$ là $2^{64}$. Mặc dù hàm hash với $MOD$ này có một điểm yếu chí mạng là [dãy Thue–Morse](https://en.wikipedia.org/wiki/Thue%E2%80%93Morse_sequence), với những contest offline thì cài đặt này vẫn có thể được sử dụng do bộ test thường được sinh ngẫu nhiên và không có tính toán.

Do lười nên ta sẽ sử dụng luôn `N = BASE = 1e6 + 3` :)

```cpp
const ull N = 1e6 + 3;
vector<ull> bp(N + 1);
////////////////////////////////////////
struct Hash {
    vector<ull> h;
    void init(vector<int> a) {
        a.insert(a.begin(), 0);
        h.resize(a.size());
        FOR(i, 1, a.size() - 1) {
            h[i] = h[i - 1] * N + (ull)a[i];
        }
    }
    ////////////////////////////////////////
    ull get(int l, int r) {
        l++; r++;
        return h[r] - h[l - 1] * bp[r - l + 1];
    }
};
////////////////////////////////////////
void prep() {
    bp[0] = 1;
    FOR(i, 1, N) bp[i] = bp[i - 1] * N;
}
```

### Các cài đặt khác (bài viết cũ)

- [[String Hashing]]
