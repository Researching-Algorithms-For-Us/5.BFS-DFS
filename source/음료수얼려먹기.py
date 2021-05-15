#source
#from collections import deque

def set_input():
    height, width = map(int, input().split())
    output = []
    for _ in range(height):
        value = list(map(int,input().split()))
        output.append(value)
    return height, width, output

def main(): 
    height, width, output= set_input()

    def dfs(y,x):
        y_list = [-1,0,1,0]
        x_list = [0,-1,0,1]
        if (x >= 0 and x < width and y >= 0 and y < height) and output[y][x] == 0:
            output[y][x] = 1
            for i in range(4):
                dfs(y+y_list[i],x+x_list[i])

    count = 0
    for w in range(width):
        for h in range(height):
            if output[h][w] == 0:
                dfs(h,w)
                count += 1
    print(count)
    
if __name__ == '__main__':
    main()
