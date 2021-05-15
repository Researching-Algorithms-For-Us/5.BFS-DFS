package Graph;

class Pair<T1, T2>
{
    private T1 first;
    private T2 second;

    public Pair(T1 t1, T2 t2)
    {
        first = t1;
        second = t2;
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