

int numTrees(int n) {
	int *p = new int[n+1];
	p[0] = 1;
	p[1] = 1;
	for (int i = 2; i <= n; i++) {
		p[i] = 0;
		for (int j = 0;j <= i-1; j++)
		  p[i] += p[j]*p[i-j-1];
	}
	return p[n];
}
