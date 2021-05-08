'''

'''
#number = list(map(int, input().split()))
from collections import deque

def set_input():
    sizes = list(map(int, input().split()))
    
    x = sizes[0]
    y = sizes[1]
    z = sizes[2]
    box = []
    tomatos = []
    for i in range(z):
        tmp = []
        for j in range(y):
            line = list(map(int, input().split()))
            tmp.append(line)
            for lidx, l in enumerate(line):
                if l == 1:
                    tomatos.append([i,j,lidx])
            
        box.append(tmp)
    return box, tomatos, sizes

def zero_chech(sz,sy,sx,box):
    result = 0
    for z in range(sz):
        for y in range(sy):
            for x in range(sx):
                if box[z][y][x] == 0:
                    return -1
                result = max(result, box[z][y][x])
    return 0 if result == 1 or result == -1 else result - 1

def main():
    box, tomatos, sizes = set_input()
    
    #print(box, tomatos)
    sx = sizes[0]
    sy = sizes[1]
    sz = sizes[2]

    check = [[[False for _ in range(sx)] for _ in range(sy)] for _ in range(sz)]
    for t in tomatos:
        check[t[0]][t[1]][t[2]] = True

    dzs = [0, 0, 0, 0, -1, 1]
    dys = [0, 0, -1, 1, 0, 0]
    dxs = [-1, 1, 0, 0, 0, 0]

    queue = deque(tomatos)

    #print(box)
    while queue:
        queue_value = queue.popleft()
        tomato = queue_value

        for dx, dy, dz in zip(dxs,dys,dzs):
            x = tomato[2]
            y = tomato[1]
            z = tomato[0]

            #value = box[z][y][x]
            tx = x+dx
            ty = y+dy
            tz = z+dz

            #check = False
            if 0 <= tx < sx and 0 <= ty < sy and 0 <= tz < sz and not check[tz][ty][tx]:
                if box[tz][ty][tx] == 0:
                    box[tz][ty][tx] = box[z][y][x]+1
                    queue.append([ tz,ty,tx ])
                    check[tz][ty][tx] = True

    result = zero_chech(sz,sy,sx,box)
    print(result)

if __name__ == '__main__':
    main()
