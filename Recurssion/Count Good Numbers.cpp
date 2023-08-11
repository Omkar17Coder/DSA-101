// In this code the We need to ensure the , selecting numbers in the range and also ensuring the every digit of the number is not equal to K and also 
// Every digit should be greater to the  sum of digits on right side.


bool Checker(int num, int digit, int sum,bool flag) {
    if (num <= 0) {
       return true;

    }
    
    if (num % 10 == digit) {
        return false;
    }
  
  if(sum==0 && flag){
	 flag=false;


  }
  else{

    if (num % 10 <= sum  ) {
        return false;
    }

  }
    
    return Checker(num / 10, digit, sum + num % 10,flag);
}

void Helper(vector<int> &result, int current, int end, int digit, int sum) {
    bool flag=true;
	if (current > end) {
	
        return;
    }
    
    if (Checker(current, digit, sum,flag)) {
		
        result.push_back(current);
    }

	
    
    Helper(result, current + 1, end, digit, sum);
}

vector<int> goodNumbers(int a, int b, int digit) {
    vector<int> ans;
    int sum = 0;
    Helper(ans, a, b, digit, sum);
    return ans;
}
