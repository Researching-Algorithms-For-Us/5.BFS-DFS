#source

def set_input():
    height, width = map(int, input().split())
    output = []
    for _ in range(height):
        value = list(map(int,input().split()))
        output.append(value)
    return height, width, output

def main(): 
    height, width, output= set_input()
    stack = []
    
    y_list = [-1,0,1,0]
    x_list = [0,-1,0,1]

    stack.append((0,0))
    #print(stack)
    while stack:
        y, x = stack.pop(0)
        
        for i in range(4):
            tx = x + x_list[i]
            ty = y + y_list[i]
            if (tx >= 0 and tx < width and ty >= 0 and ty < height):
                if output[ty][tx] == 1:
                    output[ty][tx] = output[y][x] + 1
                    stack.append((ty,tx))
        #print(stack)
        #print(output)
    print(output[-1][-1])

if __name__ == '__main__':
    main()
