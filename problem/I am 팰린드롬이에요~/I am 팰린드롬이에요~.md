### I am 팰린드롬이에요~
---
**시간 제한 2초 메모리 제한 1024MB**  

문자열 $S$가 주어졌을 때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

- $index$ : $S$의 $index$번째 알파벳이 총 몇 개의 팰린드롬의 일부인지 출력하시오.

---

### 입력
첫째 줄에 문자열 $S$가 주어진다. 문자열의 길이는 100,000을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

둘째 줄에는 쿼리의 개수 $Q (1 \leq Q \leq 100,000)$이 주어진다.

셋째 줄부터 $Q$ 줄에는 쿼리가 한 줄에 하나씩 주어진다. $(1 \leq index \leq S의 길이)$

문자열의 인덱스는 $1$부터 시작한다.
```
abcdefef
5
4
5
6
7
8
```
### 출력
입력으로 주어진 쿼리의 결과를 주어진 순서대로 한 줄에 하나씩 출력한다.
```
1
2
3
3
2
```

### 힌트
abcdefef의 첫 번째 e는 {e}, {efe}의 일부이기 때문에 2.

abcdefef의 첫 번째 f는 {f}, {efe}, {fef}의 일부이기 때문에 3.

abcdefef의 두 번째 e는 {e}, {efe}, {fef}의 일부이기 때문에 3.

abcdefef의 두 번째 f는 {f}, {fef}의 일부이기 때문에 2.
