#include <string>
#include <vector>

using namespace std;

int solution(string inputString) {
    
    int len = inputString.size();
    int answer = 0;
    int small = 0, middle = 0, large = 0, clamp = 0;
    int s_start = 0, m_start = 0, l_start = 0, c_start = 0;
    int s_end = 0, m_end = 0, l_end = 0, c_end = 0;
    for (int i = 0;i < len;i++){
        if (inputString[i] == '('){
            small = 1; s_start++;}
        else if (inputString[i] == '{'){
            middle =1 ; m_start++;}
        else if (inputString[i] == '['){
            large = 1; l_start++;}
        else if (inputString[i] == '<'){
            clamp = 1; c_start++;}
        else if (inputString[i] == ')'){
            if (small == 1){
                small = 0; answer++; s_end++;
            }
            else
                return -1;
        }
        else if (inputString[i] == '}'){
            if (middle == 1){
                middle = 0; answer++; m_end++;
            }
            else
                return -1;
        }
        else if (inputString[i] == ']'){
            if (large == 1){
                large = 0; answer++; l_end++;
            }
            else
                return -1;
        }
        else if (inputString[i] == '>'){
            if (clamp == 1){
                clamp = 0; answer++; c_end++;
            }
            else
                return -1;
        }
    }
    if (s_start != s_end || m_start != m_end || l_start != l_end || c_start != c_end)
        return -1;        
    return answer;
}