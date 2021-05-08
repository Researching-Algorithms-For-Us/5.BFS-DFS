'''
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)
한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.

예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다.

(0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.)

입력의 첫 줄에는 테스트 케이스의 개수 T
그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 
K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다

'''
#number = list(map(int, input().split()))
from collections import deque

def set_input():
    count = int(input())
    steps = []
    for _ in range(count):
        v = list(map(int, input().split()))
        w = v[0]
        h = v[1]
        s = v[2]
        v_map = []
        for _ in range(s):
           v_map.append(list(map(int, input().split())))

        step = {
            'width' : w,
            'height' : h,
            'mapping' : v_map
        }
        steps.append(step)

    return steps

def submain(step):
    width = step['width']
    height = step['height']
    mapping = step['mapping']

    array = []
    mapping.sort()
    for _ in range(width):
        array.append([0 for _ in range(height)])

    for m in mapping:
        array[int(m[0])][int(m[1])] = 1

    dy = [0, 0, -1, 1]
    dx = [-1, 1, 0, 0]

    queue = deque([])
    count = 0
    for i in range(width):
        for j in range(height):
            if array[i][j] == 1:
                queue.append([i,j])
                array[i][j] =  -1
                while True:
                    x, y = queue.pop()
                    for d in range(4):
                        tx = dx[d]+x
                        ty = dy[d]+y
                        if 0 <= tx <  width and 0 <= ty < height:
                            if array[tx][ty] == 1:
                                array[tx][ty] = -1
                                queue.append([tx,ty])
                    
                    if not queue:
                        count += 1
                        break
    
    print(count)
    
def main():
    steps = set_input()
    for s in steps:
        submain(s)

if __name__ == '__main__':
    main()
