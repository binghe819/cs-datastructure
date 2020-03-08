# 2. 재귀 ( Recursion )
::동일한 패턴의 반복이 발생되고, 어떠한 조건에서 멈추는 함수가 필요하다고 재귀함수를 사용하면 된다.::

- - - -
## 1. 함수의 재귀적 호출의 이해

### 1-1. 재귀함수의 기본적인 이해
```
void Recursive(void)
{
	printf("Recursive call!\n");
	Recursive(); // 나 자신을 호출한다.
}
```
위 코드를 도식화하면 아래와 같다.
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/991D2E3B5B01C2761C.png)

### 1-2. 재귀함수의 흐름
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/991BBB3B5B01C31C1D.png)
* Recursive함수의 복사본이 만들어져서 복사본이 실행되는 구조라고 생각하면 쉽다.
* Recursive함수를 실행하는 중간에 다시 Recursive함수가 호출되면, Recursive 함수의 복사본을 하나 더 만들어서 복사본을 실행하게 됩니다.

### 1-3. 재귀함수의 기본조건
* 동일한 패턴의 반복
* 재귀함수의 탈출 조건
```
// 예제
void Recursive(int num)
{
	if ( num < 0 )
		return;
	printf("Recursive call! %d\n", num);
	Recursive(num-1);
}

int main(void)
{
	Recursive(4);
	return 0;
}

// 결과 값
Recursive call! 4
Recursive call! 3
Recursive call! 2
Recursive call! 1
Recursive call! 0
```
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/9970BD355B27691A0F.jpg)

### 1-4. 재귀함수의 디자인 사례
재귀함수는 자료구조나 알고리즘의 어려운 문제를 단순화하는데 사용되는 중요한 무기이다. 무엇보다도 재귀함수가 있기에 재귀적인 수학적 수식을 그대로 코드로 옮길 수 있다.

> 팩토리얼  
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/2714E0495449E46536.png)
* 위 그림에서 보이듯이 정수 n 팩토리얼은 정수 n과 n-1 팩토리얼의 곱으로 표현할 수 있으므로 리얼 f(n)은 수식적으로 다음과 같이 표현할 수 있다.
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/2419EB495449E4D432.png)
* 팩토리얼의 탈출 조건은 n이 0이 되었을 때이다.
```
int Factorial(int n)
{
	if(n == 0)
		return 1;
	else
		return n * Factorial(n-1);
}

int main()
{
	printf("1! = %d \n", Factorial(1));
	printf("2! = %d \n", Factorial(2));
	printf("3! = %d \n", Factorial(3));
	printf("4! = %d \n", Factorial(4));
	printf("5! = %d \n", Factorial(5));
	return 0;
}

// 결과 값
1! = 1 
2! = 2 
3! = 6 
4! = 24 
5! = 120 
```
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/994C86345B2773441D.jpg)
* 실제 그림처럼 과정이 이루어진다 먼저 factorial(3) 이 호출되고 그 다음 return 문에서 factorial(2)가 호출 그리고 factorial(2) return문에서 factorial(1)을 호출한다. 마지막으로 factorial(0)에서 return 1이 실행되고 반환하기 시작한다. 즉 ::매듭을 풀기 시작하는 것이다::
* 연산 실행은 3**2**1 순으로 되는줄 알았지만 실제로 연산은 return 1 이 되고나서 1 * 1 부터 시작한다. 즉 실제 연산은 1*1 -> 2 * 1 -> 3 * 2 이런식으로 이루어 진것이다.


- - - -
## 2. 재귀의 활용

### 2-1. 피보나치 수열
피보나치 수열은 재귀적인 형태를 띠는 대표적인 수열이다.
```
// 앞엣것 두 개 더해서 현재의 수를 만들어가는 수열이다.
// 수열의 n번째 값 = 수열의 n-1번째 값 + 수열의 n-2번째 값
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
```
따라서 수학적 정의는 다음과 같다.
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/99240F4F5B01CD9429.png)
위 공식을 코드화하면 아래와 같다.
```
int Fibo(int n)
{
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return Fibo(n-1) + Fibo(n-2);
}

int main()
{
	for(int i = 0; i < 15; i++)
		printf("%d ", Fibo(i));
	return 0;
}

// 결과 값
0 1 1 2 3 5 8 13 21 34 55 89 144 233
```

> 피보나치 수열의  수행 순서  
```
int Fibo(int n)
{
	printf("func all param %d \n", n);
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	else
		return Fibo(n-1) + Fibo(n-2);
}

int main()
{
	Fibo(5);
	return 0;
}

// 결과값
func all param 7 
func all param 6 
func all param 5 
func all param 4 
func all param 3 
func all param 2 
func all param 1 
func all param 2 
func all param 3 
func all param 2 
func all param 1 
func all param 4 
func all param 3 
func all param 2 
func all param 1 
func all param 2 
func all param 5 
func all param 4 
func all param 3 
func all param 2 
func all param 1 
func all param 2 
func all param 3 
func all param 2 
func all param 1 
```
결과를 보면 총 25회 함수 호출이 된다. ::이 말은 재귀 함수는 매우 많은 수의 함수 호출을 동반한다는 것이다. 그러므로 성능상의 불리함은 존재한다.::
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/996D21475BFE888F19.jpg)



- - - -
## 3. 이진 탐색 알고리즘의 재귀적 구현
이진 탐색 알고리즘의 특징은 ::두번 째 시도 이후부터는 탐색 대상을 찾을 때까지 동일한 패턴을 반복한다는 것이다.::

### 3-1. 이진 탐색의 반복
	* 탐색 범위의 중앙에 목표 값이 저장되었는지 확인
	* 저장되지 않았다면 탐색 범위를 반으로 줄여서 다시 탐색 시작

### 3-2. 이진 탐색의 탈출조건
	* 탐색 범위의 시작위치를 의미하는 first가 탐색 범위의 끝을 의미하는 last보다 커지는 경우

### 3-3. 구현
```
int BSearch(int arr[], int first, int last, int target)
{
    int mid;
    if(first > last) //앞 부분이 뒤보다 크다는 것은 전부 다 돌았다는 의미.
        return -1; // 못찾음
    
    mid = (first+last)/2;
    
    if(arr[mid] == target) // 찾은 경우
        return mid;
    else if(target < arr[mid]) // 타켓이 중앙값보다 작은 경우
        return BSearch(arr, first, mid-1, target);
    else // 타켓이 중앙값보다 큰 경우
        return BSearch(arr, mid+1, last, target);
}

int main(){    
    int arr[] = {1, 3, 5, 7, 9};
    
    int idx = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    int idx1 = BSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 4);
    
    printf("%d %d \n", idx, idx1);
    
    return 0;
}

// 결과 값
3(3번인덱스에서찾음) -1(못찾음)
```
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/CD2EAA9E-ECE5-4279-9489-62287B92D377.png)


- - - -
## 4. 하노이 타워
하노이 타워 문제는 재귀함수의 힘을 보이는 대표적인 예이다.

### 4-1. 하노이 타워 문제의 이해
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/2B8CFA90-D3CB-4081-8169-994EFE7774F9.png)
* 원반은 한 번에 하나씩만 옮길 수 있습니다. 그리고 옮기는 과정에서 작은 원반의 위에 큰 원반이 올려져서는 안됩니다.
* 위 그림에서는 3개를 했는데 이게 10개라도 똑같은 반복을 하게 됩니다.

### 4-2. 하노이 타워 반복 패턴
![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/B761D234-E471-42BF-99ED-EDA242985533.png) ![](%E1%84%8C%E1%85%A2%E1%84%80%E1%85%B1%20(%20Recursion%20)/264D51355701CCB129.png)
* 원반 3개를 A, B, C의 막대에 넣는다고 해보자.
	* 작은 원반 n-1 (2개)를 A에서 B로 이동.
	* 큰 원반 1개를 A에서 C로 이동.
	* 작은 원반 n-1 (2개)를 B에서 C로 이동.
* 	이렇듯, 원반 n개를 이동하는 문제는 원반 n-1개를 이동하는 문제로 세분화되고, 또 원반 n-1개를 이동하는 문제는 원반 n-2개를 이동하는 문제로 세분화된다.

### 4-3. 구현
```
// from에 꽂혀있는 num개의 원반을 by를 거쳐서 to로 이동.
void HanoiTowerMove(int num, char from, char by, char to)
{
    if(num == 1) // 이동할 원반의 수가 1개라면 ( 탈출의 조건 )
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
    else
    {
        HanoiTowerMove(num-1, from, to, by);
        printf("원반 %d을 %c에서 %c로 이동 \n", num,from, to);
        HanoiTowerMove(num-1, by, from, to);
    }
}


int main(){
    // 막대A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기.
    HanoiTowerMove(3, 'A', 'B', 'C');
    return 0;
}

// 결과값
원반 1을 A에서 C로 이동
원반 2을 A에서 B로 이동 
원반 1을 C에서 B로 이동
원반 3을 A에서 C로 이동 
원반 1을 B에서 A로 이동
원반 2을 B에서 C로 이동 
원반 1을 A에서 C로 이동
```

#CS/자료구조