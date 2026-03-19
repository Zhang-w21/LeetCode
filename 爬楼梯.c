int climbStairs(int n) {
    if(n==1)return 1;
    if(n==2)return 2;
    int step[n];
    int i;
    step[0]=1;
    step[1]=2;
    for(i=3;i<=n;i++){
        step[i-1]=step[i-2]+step[i-3];
    }
    return step[n-1];
}
