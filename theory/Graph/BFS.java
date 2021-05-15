package Graph;

import java.util.*;

/*
    우선 탐색
 */

public class BFS {
    Integer[][] Map;
    boolean[][] Visited;

    int StartX, StartY;
    int EndX, EndY;
    final Integer[]  DirectionX = new Integer[] {1, 0, -1 , 0};
    final Integer[]  DirectionY = new Integer[] {0, 1, 0, -1};
    
    final int BLANK = 0;
    final int Obstacle = 1;
    

    BFS(Integer[][] Map, int StartY, int StartX, int EndX, int EndY)
    {
        this.Map = Map;
        Visited = new boolean[Map.length][];

        for(int i=0; i<Map.length; ++i)
        {
            Visited[i] = new boolean[Map[i].length];
        }

        this.StartX = StartX;
        this.StartY = StartY;
        this.EndX = EndX;
        this.EndY = EndY;
    }

    void Search()
    {
        Queue<Pair<Integer, Integer>> PositionQueue = new LinkedList<Pair<Integer, Integer>>();
        
        {
            var Position = new Pair(StartY, StartX);
            PositionQueue.add(Position);
        }
        
        while(PositionQueue.size() > 0)
        {
            var Element = PositionQueue.peek();
            PositionQueue.remove();

            for(int i=0; i<4; ++i)
            {
                int ny = Element.getFirst() + DirectionY[i];
                int nx = Element.getSecond() + DirectionX[i];

                if(nx < 0 || nx >= EndX || ny < 0 || ny >= EndY)
                    continue;

                if(Visited[ny][nx] || Map[ny][nx] != BLANK)
                    continue;

                var Position = new Pair(ny, nx);
                Visited[ny][nx] = true;
                PositionQueue.add(Position);
            }
        }


    }
}
