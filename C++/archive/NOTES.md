# 1. Table of Contents

- [1. Table of Contents](#1-table-of-contents)
- [2. Notes](#2-notes)
  - [2.1. Why faster input/output code works and cout.tie(NULL) does literally nothing](#21-why-faster-inputoutput-code-works-and-couttienull-does-literally-nothing)
  - [2.2. What are the differences between array-like types and when to use them](#22-what-are-the-differences-between-array-like-types-and-when-to-use-them)
  - [2.3. Why hash maps are OP and how to use them](#23-why-hash-maps-are-op-and-how-to-use-them)
  - [2.4. Why pragmas are also OP and how to use them](#24-why-pragmas-are-also-op-and-how-to-use-them)

# 2. Notes

## 2.1. Why faster input/output code works and cout.tie(NULL) does literally nothing

> [https://stackoverflow.com/a/31165481](https://stackoverflow.com/a/31165481)

## 2.2. What are the differences between array-like types and when to use them

> [https://stackoverflow.com/q/4424579](https://stackoverflow.com/a/31165481)

## 2.3. Why hash maps are OP and how to use them

Hash maps (namely `unorderded_map` and `unorderded_set`) are data structures that provide efficient storage and retrieval values using hash functions. They are incredibly powerful due to their efficiency (O(1) average lookup/insert).

Though they can be nuked to match an array with specifically crafted inputs ([https://codeforces.com/blog/entry/62393](https://codeforces.com/blog/entry/62393)), utilizing them for an on-site competition should be fine.

## 2.4. Why pragmas are also OP and how to use them

[This blog entry](https://codeforces.com/blog/entry/96344) from Codeforces explains it very nicely:

[![https://codeforces.com/predownloaded/f9/1a/f91a4a1cd9da1af1b944492a5f836221ced2d8dd.png](https://codeforces.com/predownloaded/f9/1a/f91a4a1cd9da1af1b944492a5f836221ced2d8dd.png)](https://codeforces.com/predownloaded/f9/1a/f91a4a1cd9da1af1b944492a5f836221ced2d8dd.png)

You can check out all of them in [gcc's official guide](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html).

> Here is an example of a solution with pragmas (vdc_quatang.cpp):

[![https://imgur.com/faIAI4t.png](https://imgur.com/faIAI4t.png)](https://imgur.com/faIAI4t.png)

> And without pragmas:

[![https://imgur.com/sI0e0Kd.png](https://imgur.com/sI0e0Kd.png)](https://imgur.com/sI0e0Kd.png)

**Pragmas CAN and WILL slow down code or make them uncompilable with certain judge configurations:**

Example problem (private): [https://oj.vnoi.info/problem/chvpt_nd_chondtqg1_maxmin](https://oj.vnoi.info/problem/chvpt_nd_chondtqg1_maxmin)

[![https://imgur.com/u47IKwR.png](https://imgur.com/u47IKwR.png)](https://imgur.com/u47IKwR.png)
The two submissions are identical, except the upper one has the pragma ```O3``` and ```unroll-loops```.

In my experience, DMOJ, or at least the fork VNOJ, does not fare well with pragmas. Code with ```target``` pragmas straight up get CE on this platform.

Pragmas are not free performance. Research your contest environment before using them.