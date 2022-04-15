class PrimesBetween {
  public:
    int count(int start, int end) {
        int count = 0;
        for (int i=start; i<=end; i++) {
            if (isPrime(i))
                count++;
        }
        return count;
    }
    bool isPrime(int N) {
        if (N == 1)
            return false;
        if (N == 2)
            return true;
        for (int i=2; i<N; i++) {
            if (N % i == 0)
                return false;
        }
        return true;
    }
};
