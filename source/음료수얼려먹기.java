import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static class Pair<T1, T2> {
        T1 first;
        T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }

        public T1 getFirst()
        {
            return first;
        }

        public T2 getSecond()
        {
            return second;
        }
    }

    static Integer[] dx = new Integer[] {
            1, 0, -1, 0
    };
    static Integer[] dy = new Integer[] {
            0, 1, 0, -1
    };
    public static boolean BFS(int Y, int X, int n, int m, Integer[][] Map, boolean[][] Visited)
    {
        if(Visited[Y][X] || Map[Y][X] == 1)
            return false;

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.add(new Pair(Y, X));
        Visited[Y][X] = true;

        while(queue.size() > 0)
        {
            var pos = queue.peek();
            queue.remove();

            for(int i=0; i<4; ++i)
            {
                int xpos = pos.getSecond() + dx[i];
                int ypos = pos.getFirst() + dy[i];

                if(xpos < 0 || xpos >= m || ypos < 0 || ypos >= n)
                    continue;

                if(Visited[ypos][xpos] || Map[ypos][xpos] == 1)
                    continue;

                queue.add(new Pair(ypos, xpos));
                Visited[ypos][xpos] = true;
            }
        }

        return true;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        Integer[][] Map = new Integer[n][];
        boolean[][] Visited = new boolean[Map.length][];

        for(int i=0; i<n; ++i)
        {
            String str = sc.nextLine();
            Map[i]= new Integer[str.length()];
            Visited[i] = new boolean[str.length()];

            for(int j=0;j<str.length(); ++j)
            {
                Map[i][j] = str.charAt(j) - '0';
            }
        }


        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(Visited[i][j])
                    continue;

                if(BFS(i, j, n, m, Map, Visited))
                    count++;
            }
        }

        System.out.println(count);
    }
}
