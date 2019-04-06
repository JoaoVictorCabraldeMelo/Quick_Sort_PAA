void quicksort(float *vec, int inicio, int fim){
	int i=inicio, j=fim;
	float pivo, t;

	pivo = vec[(int) (fim + inicio)/2];
	while(i<j){
		while(pivo > *(vec + i)) i++;
		while(pivo < *(vec + j)) j--;
		if(i<= j){
			t = *(vec + i);
			vec[i] = *(vec + j);
			vec[j] = t;
			i++;
			j--;
			}
	}

	if(j>inicio)
		quicksort(vec, inicio, j);
	if(i<fim)	
		quicksort(vec, i, fim);
}
