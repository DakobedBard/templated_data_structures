



std::vector<int> getTestCase(int &x){

	int n;
	std::cin >> n;
	assert(n>=1 && n <= 100);

	int x;

	while(t--){
		std::vector<int> vec = getTestCase(x);
		std::cout <<((executeTestCase(vec, x)) ? 1:0) << std::endl;
	}

	return 0;

}

int main(){

}
