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
    public static boolean BFS(int Y, int X, int n, int m, Integer[][] Map)
    {
        if(Map[Y][X] == 0 || Map[Y][X] > 1)
            return false;

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        queue.add(new Pair(Y, X));

        while(queue.size() > 0)
        {
            var pos = queue.peek();
            queue.remove();

            int MoveCount = Map[pos.getFirst()][pos.getSecond()];

            for(int i=0; i<4; ++i)
            {
                int xpos = pos.getSecond() + dx[i];
                int ypos = pos.getFirst() + dy[i];

                if(xpos < 0 || xpos >= m || ypos < 0 || ypos >= n)
                    continue;

                if(Map[ypos][xpos] == 0 || Map[ypos][xpos] >= 2)
                    continue;

                queue.add(new Pair(ypos, xpos));
                Map[ypos][xpos] = MoveCount + 1;
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

        for(int i=0; i<n; ++i)
        {
            String str = sc.nextLine();
            Map[i]= new Integer[str.length()];

            for(int j=0;j<str.length(); ++j)
            {
                Map[i][j] = str.charAt(j) - '0';
            }
        }

        BFS(0,0, n, m, Map);



        for(int i=0; i<n; ++i)
        {
            for(int j=0;j<m; ++j)
            {
                System.out.print(Map[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println(Map[n-1][m-1]);
    }
}
