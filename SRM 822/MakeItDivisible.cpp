class MakeItDivisible {
  public:
    // Ex) 12
    //     12 % 7 => 5
    //     12 - 5 = 7 pos 1
    //     12 + (7 - 5) = 14 pos 2
    int change(int N) {
        if (N % 7 == 0) return N;
        int r = N % 7;
        int d = N % 10;
        if (d + (7 - r) < 10)
            return N + (7 - r);
        return N - r;
    }
};
