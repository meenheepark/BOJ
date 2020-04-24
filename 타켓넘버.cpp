#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(vector<int> numbers, int num, int sum, int target){
    if(num == (numbers.size()) && sum == target) ans+=1;
    
    if(num < numbers.size()){
        dfs(numbers, num+1, sum+numbers[num], target);
        dfs(numbers, num+1, sum-numbers[num], target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, 0, target);
    answer = ans;
    return answer;
}