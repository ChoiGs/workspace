#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution_64062(vector<int> stones, int k) {
    int answer = 0;
    
    int min_stone = *min_element(stones.begin(), stones.end());
    int max_stone = *max_element(stones.begin(), stones.end());
    
    int mid = 0;
    
    while(min_stone <= max_stone) {
        mid = (min_stone + max_stone) / 2;
        int skip_cnt = 0;
        int max_skip_cnt = 0;
        
        vector<int> temp(stones);
        for(int i=0;i<temp.size();i++) {
            temp[i] -= mid;
            
            if(temp[i] < 0) {
                skip_cnt += 1;
            }else {
                skip_cnt = 0;
            }
            
            max_skip_cnt = max(max_skip_cnt, skip_cnt);
        }
        
        if(max_skip_cnt < k) {
            answer = max(answer, mid);
            min_stone = mid + 1;
        }else{
            max_stone = mid -1;
        }
    }
    
    // while(1) {
    //     bool is_continue = true;
    //     for(int i=0;i<stones.size();i++) {
    //         int stone = stones[i];
            
    //         if(stone == 0) {
    //             is_continue = false;
    //             for(int j=1;j<k;j++) {
    //                 int next_stone = stones[i+j];
    //                 if(next_stone != 0) {
    //                     i += j;
    //                     is_continue = true;
    //                     break;
    //                 }
    //             }
    //             if(!is_continue)
    //                 return answer;
    //         }
    //         stones[i] -= 1;
    //     }
        
    //     if(is_continue == false) {
    //         break;
    //     }
    //     answer += 1;
    // }
    return answer;
}

int solution_42626(vector<int> scoville, int K) {
    int answer = 0;
    // 우선 순위 큐 생성 -> greater int 작은 수부터 출력
    priority_queue< int, vector<int>, greater<int> > scv_pq;
    for(int i=0; i < scoville.size(); i++) {
        scv_pq.push(scoville[i]);
    }
    // priority_queue< int, vector<int>, greater<int> > scv_pq(scoville.begin(), scoville.end());
    
    while(1) {
        if(scv_pq.size() <= 1 || scv_pq.top() >= K) {
            break;
        }
        int min = scv_pq.top();
        scv_pq.pop();
        int next_min = scv_pq.top();
        scv_pq.pop();
        
        scv_pq.push(min + (next_min * 2));
        answer += 1;
    }
    
    if (scv_pq.top() < K)
        return -1;
    
    return answer;
    
//     while(1) {
//         if(scoville.size() < 1) {
//             answer = -1;
//             break;
//         }
        
//         int new_csv = scoville[0] + (scoville[1] * 2);
//         answer += 1;
        
//         if(new_csv >= K && scoville[2] >= K) {
//             break;
//         }
        
//         scoville.erase(scoville.begin(), scoville.begin() + 2);
//         scoville.insert(scoville.begin(), new_csv);
//         sort(scoville.begin(), scoville.end());
        
//     }
//     return answer;
}


//입국 심사
using namespace std;
long long solution_43238(int n, vector<int> times) {
    long long answer = 0;
    
    long long min_time = 1;
    long long max_time = ((long long)*max_element(times.begin(), times.end())) * n;
    
    long long avg;
    while(min_time <= max_time) {
        cout << "min_time : " << min_time << endl;
        cout << "max_time : " << max_time << endl;
        avg = (min_time + max_time) / 2;
        cout << "avg : " << avg << endl;
        long long cnt = 0;
        for(int i = 0; i < times.size(); i++) {
            cnt += (avg / (long long)times[i]);
        }
        cout << "cnt : " << cnt << endl;
        
        if (cnt >= n) {
            max_time = avg - 1;
            answer = avg;
            cout << "answer : " << answer << endl;
        }
        else min_time = avg + 1;
        
        cout << endl;
    }
    return answer;
}