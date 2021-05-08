'''

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1 
5 17
예제 출력 1 
4

힌트
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.

N : 입력 위치
K : 결과 위치

# 17 = 2 * 5
# 5 -> 10 -> 9 -> 18 -> 18 -1
    
# 3 10 : 
# 3->4->5->10
# 3->6->12->11->10

# 경우수 3
# 뒤로 : x-1 
# 앞으로 : x+1
# 점프 : 2*x

'''
#number = list(map(int, input().split()))
from collections import deque

def set_input():
    value = list(map(int, input().split()))
    return value

def left(x):
    return x - 1

def right(x):
    return x + 1

def jump(x):
    return 2*x 

def main():
    value = set_input()

    x = value[0]
    target = value[1]
    max_root = 100001
    roots = [False]* max_root

    count = 0
    queue = deque([[x, count]])
    while queue:
        x = queue.popleft()
        position = x[0]
        count = x[1]
        if not roots[position]:
            roots[position] = True
            
            if position == target:
                break

            count += 1
            if right(position) < max_root:
                queue.append([right(position),count])
            if left(position) >= 0:
                queue.append([left(position),count])
            if jump(position) < max_root:
                queue.append([jump(position),count])

            #print(x)
    print(count)

if __name__ == '__main__':
    main()
